#include "utils/brightness.h"
#include "driver/ledc.h"
#include "driver/gpio.h"

#define BRT_PWM 9
#define BRT_NEG 10

void brightness_init(void) {
    gpio_reset_pin(BRT_NEG);
    gpio_set_direction(BRT_NEG, GPIO_MODE_OUTPUT);
    gpio_set_level(BRT_NEG, 0);

    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .duty_resolution = LEDC_TIMER_10_BIT,
        .freq_hz = 5000,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .gpio_num = BRT_PWM,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = LEDC_CHANNEL_0,
        .timer_sel = LEDC_TIMER_0,
        .duty = 512,
        .hpoint = 0
    };
    ledc_channel_config(&ledc_channel);
}
