#pragma once

// Edit these for your network / backend, or override with -D build flags.
#ifndef GLARE_WIFI_SSID
#define GLARE_WIFI_SSID "your-ssid"
#endif
#ifndef GLARE_WIFI_PASS
#define GLARE_WIFI_PASS "your-pass"
#endif

// Transcription backend. lang query param picks the output language;
// the server does the speech-to-text + translation, we just stream audio.
#ifndef GLARE_WS_URI
#define GLARE_WS_URI "ws://192.168.1.50:8765/?lang=en"
#endif

#define GLARE_SAMPLE_RATE 16000
#define GLARE_AUDIO_CHUNK 1024   // samples per ws frame (~64ms @16k)
#define MIC_GAIN_SHIFT 14        // 32-bit mic sample -> int16, raise to get quieter
