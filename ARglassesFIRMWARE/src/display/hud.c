#include "display/hud.h"
#include "driver/uart.h"
#include "driver/gpio.h"

#define HUD_ENABLE_GPIO 48
#define HUD_UART_TX 1
#define HUD_UART_RX 2

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
