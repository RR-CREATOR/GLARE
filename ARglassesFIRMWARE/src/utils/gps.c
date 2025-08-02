#include "utils/gps.h"
#include "driver/gpio.h"
#include "driver/uart.h"

#define GPS_RX 17
#define GPS_TX 18
#define GPS_RST 47

void gps_init(void) {
    gpio_reset_pin(GPS_RST);
    gpio_set_direction(GPS_RST, GPIO_MODE_OUTPUT);
    gpio_set_level(GPS_RST, 1);

    uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_driver_install(UART_NUM_1, 1024, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, GPS_TX, GPS_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}
