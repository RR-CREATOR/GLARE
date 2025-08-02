#include "utils/led.h"
#include "led_strip.h"

led_strip_handle_t strip;

void led_init(void) {
    led_strip_config_t strip_cfg = {
        .strip_gpio_num = LED_DATA,
        .max_leds = 1,
        .led_pixel_format = LED_PIXEL_FORMAT_GRB,
        .led_model = LED_MODEL_WS2812
    };

    led_strip_rmt_config_t rmt_cfg = {
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = 10 * 1000 * 1000,
        .flags.with_dma = false
    };

    led_strip_new_rmt_device(&strip_cfg, &rmt_cfg, &strip);
    led_strip_set_pixel(strip, 0, 255, 0, 0);  // red
    led_strip_refresh(strip, 100);
}
