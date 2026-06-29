#include "display/hud.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <string.h>

#define HUD_ENABLE_GPIO 48
#define HUD_UART_TX 1
#define HUD_UART_RX 2

static const char *TAG = "hud";

void hud_init(void) {
    gpio_reset_pin(HUD_ENABLE_GPIO);
    gpio_set_direction(HUD_ENABLE_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(HUD_ENABLE_GPIO, 1);

    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_driver_install(UART_NUM_2, 1024, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_2, &uart_config);
    uart_set_pin(UART_NUM_2, HUD_UART_TX, HUD_UART_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

// HUD link is a line-oriented text protocol: UTF-8, newline-terminated, 115200.
// The display board handles wrapping/scrolling. Also echoed to the log so you
// can watch transcripts on the serial monitor before the optics are attached.
void hud_show_n(const char *text, size_t n) {
    uart_write_bytes(UART_NUM_2, text, n);
    uart_write_bytes(UART_NUM_2, "\n", 1);
    ESP_LOGI(TAG, "%.*s", (int)n, text);
}

void hud_show(const char *text) {
    hud_show_n(text, strlen(text));
}
