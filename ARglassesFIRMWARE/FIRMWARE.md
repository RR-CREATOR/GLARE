# GLARE firmware

ESP32-S3 firmware for the GLARE AR glasses. Captures audio from the SPH0645
mics, streams it to a transcription backend over WiFi, and renders the returned
transcript on the HUD — the live transcription feature from the project README.

## How live transcription works

```
SPH0645 mic --I2S--> ESP32-S3 --WiFi/websocket--> server (Whisper STT + translate)
                         ^                              |
                         |          transcript text     |
                       HUD  <----- (ws text frame) ------
```

- The glasses open a websocket to `GLARE_WS_URI` and stream 16 kHz mono PCM
  (`s16le`) as binary frames.
- The server transcribes (and optionally translates) and replies with the
  transcript as a **text** frame.
- `glare_net.c` hands each text frame to `hud_show_n()`, which writes it to the
  HUD over UART and also echoes it to the serial log.

Output language is chosen by the `?lang=` query param in `GLARE_WS_URI` — the
server side does the work, so adding languages doesn't touch the firmware.

## Configure

Edit `include/glare_config.h` (or pass `-D` build flags):

```c
#define GLARE_WIFI_SSID "your-ssid"
#define GLARE_WIFI_PASS "your-pass"
#define GLARE_WS_URI    "ws://<your-host>:8765/?lang=en"
```

## Build & flash

Requires ESP-IDF 5.1 (PlatformIO `espressif32@6.5.0`, set in `platformio.ini`).

```
pio run -t upload -t monitor
```

The websocket and led_strip components are pulled automatically via
`src/idf_component.yml`.

## Run the transcription server

```
cd backend
pip install -r requirements.txt
python server.py        # ws://0.0.0.0:8765
```

Any backend that speaks the same protocol works; `server.py` is a faster-whisper
reference. Point `GLARE_WS_URI` at the machine running it.

## Tuning

- `MIC_GAIN_SHIFT` in `glare_config.h` — mic level. Raise if audio clips, lower
  if it's too quiet.
- `GLARE_AUDIO_CHUNK` — samples per websocket frame (latency vs. overhead).

## Not done yet

The other peripherals (`gps`, `i2c_devices`, `led`, `brightness`) initialize but
aren't used by the transcript path — they're left as their bring-up stubs.
Multi-frame transcript reassembly is skipped (short lines fit one frame); the
second mic is initialized but only mic1 is streamed.
