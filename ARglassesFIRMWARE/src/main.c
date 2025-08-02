#include "utils/brightness.h"
#include "utils/microphones.h"
#include "utils/gps.h"
#include "utils/i2c_devices.h"
#include "display/hud.h"
#include "driver/gpio.h"
#include "driver/uart.h"

#define HUD_ENABLE_GPIO 48
#define HUD_UART_TX 1
#define HUD_UART_RX 2

void app_main(void) {
    gpio_reset_pin(HUD_ENABLE_GPIO);
    gpio_set_direction(HUD_ENABLE_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(HUD_ENABLE_GPIO, 1);

    brightness_init();
    microphones_init();
    gps_init();
    i2c_devices_init();
}
