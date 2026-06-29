#include "utils/brightness.h"
#include "utils/microphones.h"
#include "utils/gps.h"
#include "utils/i2c_devices.h"
#include "display/hud.h"
#include "net/glare_net.h"
#include "nvs_flash.h"

void app_main(void) {
    // WiFi stores calibration data in NVS, so bring it up first.
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    hud_init();
    brightness_init();
    microphones_init();
    gps_init();
    i2c_devices_init();

    hud_show("GLARE");
    glare_net_start();  // blocks until WiFi is up, then runs live transcription
}
