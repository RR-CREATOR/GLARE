#include "utils/microphones.h"
#include "driver/i2s_std.h"

#define MIC1_SD 13
#define MIC1_CLK 12
#define MIC1_WS 11

#define MIC2_SD 7
#define MIC2_CLK 15
#define MIC2_WS 16

void microphones_init(void) {
    i2s_chan_handle_t rx_chan1;
    i2s_chan_config_t chan_cfg1 = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_0, I2S_ROLE_MASTER);
    i2s_new_channel(&chan_cfg1, &rx_chan1, NULL);

    i2s_std_config_t std_cfg1 = {
        .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(MIC1_CLK),
        .slot_cfg = I2S_STD_MSB_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO),
        .gpio_cfg = {
            .mclk = I2S_GPIO_UNUSED,
            .bclk = MIC1_CLK,
            .ws = MIC1_WS,
            .dout = I2S_GPIO_UNUSED,
            .din = MIC1_SD
        }
    };
    i2s_channel_init_std_mode(rx_chan1, &std_cfg1);

    i2s_chan_handle_t rx_chan2;
    i2s_chan_config_t chan_cfg2 = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_1, I2S_ROLE_MASTER);
    i2s_new_channel(&chan_cfg2, &rx_chan2, NULL);

    i2s_std_config_t std_cfg2 = {
        .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(MIC2_CLK),
        .slot_cfg = I2S_STD_MSB_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO),
        .gpio_cfg = {
            .mclk = I2S_GPIO_UNUSED,
            .bclk = MIC2_CLK,
            .ws = MIC2_WS,
            .dout = I2S_GPIO_UNUSED,
            .din = MIC2_SD
        }
    };
    i2s_channel_init_std_mode(rx_chan2, &std_cfg2);
}
