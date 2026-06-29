#include "utils/microphones.h"
#include "glare_config.h"
#include "driver/i2s_std.h"
#include "freertos/FreeRTOS.h"

// SPH0645 are 24-bit mics: 32-bit slots, mono, SEL tied low -> left channel.
static i2s_chan_handle_t mic1, mic2;

static void mic_setup(i2s_port_t port, int bclk, int ws, int sd, i2s_chan_handle_t *out) {
    i2s_chan_config_t chan = I2S_CHANNEL_DEFAULT_CONFIG(port, I2S_ROLE_MASTER);
    i2s_new_channel(&chan, NULL, out);  // rx only

    i2s_std_config_t cfg = {
        .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(GLARE_SAMPLE_RATE),
        .slot_cfg = I2S_STD_MSB_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_32BIT, I2S_SLOT_MODE_MONO),
        .gpio_cfg = {
            .mclk = I2S_GPIO_UNUSED,
            .bclk = bclk,
            .ws = ws,
            .dout = I2S_GPIO_UNUSED,
            .din = sd,
        },
    };
    i2s_channel_init_std_mode(*out, &cfg);
    i2s_channel_enable(*out);
}

void microphones_init(void) {
    mic_setup(I2S_NUM_0, MIC1_CLK, MIC1_WS, MIC1_SD, &mic1);
    mic_setup(I2S_NUM_1, MIC2_CLK, MIC2_WS, MIC2_SD, &mic2);
    // mic2 is wired up for future stereo/beamforming; transcription only uses mic1.
    (void)mic2;
}

size_t microphones_read(int16_t *out, size_t samples) {
    int32_t raw[256];
    size_t done = 0;
    while (done < samples) {
        size_t want = samples - done;
        if (want > 256) want = 256;
        size_t got = 0;
        if (i2s_channel_read(mic1, raw, want * sizeof(int32_t), &got, portMAX_DELAY) != ESP_OK) break;
        got /= sizeof(int32_t);
        for (size_t i = 0; i < got; i++) out[done + i] = raw[i] >> MIC_GAIN_SHIFT;
        done += got;
    }
    return done;
}
