#include "net/glare_net.h"
#include "glare_config.h"
#include "utils/microphones.h"
#include "display/hud.h"

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_log.h"
#include "esp_websocket_client.h"

static const char *TAG = "glare_net";

#define WIFI_CONNECTED BIT0
static EventGroupHandle_t s_wifi;
static esp_websocket_client_handle_t s_ws;
static volatile bool s_ws_up;

static void on_wifi(void *arg, esp_event_base_t base, int32_t id, void *data) {
    if (base == WIFI_EVENT && id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (base == WIFI_EVENT && id == WIFI_EVENT_STA_DISCONNECTED) {
        xEventGroupClearBits(s_wifi, WIFI_CONNECTED);
        esp_wifi_connect();  // keep retrying, it's a wearable
    } else if (base == IP_EVENT && id == IP_EVENT_STA_GOT_IP) {
        xEventGroupSetBits(s_wifi, WIFI_CONNECTED);
    }
}

static void wifi_start(void) {
    s_wifi = xEventGroupCreate();
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t init = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&init));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, on_wifi, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, on_wifi, NULL, NULL));

    wifi_config_t wc = {
        .sta = { .ssid = GLARE_WIFI_SSID, .password = GLARE_WIFI_PASS },
    };
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wc));
    ESP_ERROR_CHECK(esp_wifi_start());
}

static void on_ws(void *arg, esp_event_base_t base, int32_t id, void *data) {
    esp_websocket_event_data_t *ev = data;
    switch (id) {
    case WEBSOCKET_EVENT_CONNECTED:
        s_ws_up = true;
        hud_show("[listening]");
        break;
    case WEBSOCKET_EVENT_DISCONNECTED:
        s_ws_up = false;
        break;
    case WEBSOCKET_EVENT_DATA:
        // text frames (opcode 0x1) carry a transcript line. Short lines arrive in
        // one frame; a multi-frame line would need reassembly, not bothering yet.
        if (ev->op_code == 0x01 && ev->data_len > 0)
            hud_show_n(ev->data_ptr, ev->data_len);
        break;
    default:
        break;
    }
}

static void stream_task(void *arg) {
    static int16_t pcm[GLARE_AUDIO_CHUNK];
    for (;;) {
        size_t n = microphones_read(pcm, GLARE_AUDIO_CHUNK);
        if (s_ws_up && n)
            esp_websocket_client_send_bin(s_ws, (const char *)pcm, n * sizeof(int16_t), portMAX_DELAY);
    }
}

void glare_net_start(void) {
    wifi_start();
    hud_show("connecting wifi...");
    xEventGroupWaitBits(s_wifi, WIFI_CONNECTED, pdFALSE, pdTRUE, portMAX_DELAY);
    ESP_LOGI(TAG, "wifi up, connecting to %s", GLARE_WS_URI);

    esp_websocket_client_config_t cfg = { .uri = GLARE_WS_URI };
    s_ws = esp_websocket_client_init(&cfg);
    esp_websocket_register_events(s_ws, WEBSOCKET_EVENT_ANY, on_ws, NULL);
    esp_websocket_client_start(s_ws);

    xTaskCreate(stream_task, "mic_stream", 8192, NULL, 5, NULL);
}
