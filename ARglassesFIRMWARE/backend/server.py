#!/usr/bin/env python3
"""Reference transcription backend for GLARE.

The glasses stream 16 kHz mono PCM (s16le) over a websocket; we run Whisper on a
rolling window and send each transcript line back as a text frame, which the
firmware renders on the HUD.

    pip install -r requirements.txt
    python server.py            # ws://0.0.0.0:8765

The ?lang= query param the firmware sends picks the output language. Whisper can
transcribe in the spoken language or translate to English (task="translate").
For other target languages, pipe `text` through a translator before sending.
"""
import asyncio
import urllib.parse

import numpy as np
import websockets
from faster_whisper import WhisperModel

SAMPLE_RATE = 16000
WINDOW_S = 5         # seconds of audio Whisper sees each pass
STEP_S = 1.5         # transcribe this often

model = WhisperModel("base", device="cpu", compute_type="int8")


async def handle(ws):
    lang = urllib.parse.parse_qs(urllib.parse.urlparse(ws.request.path).query).get("lang", ["en"])[0]
    task = "translate" if lang == "en" else "transcribe"

    buf = np.zeros(0, dtype=np.int16)
    step = int(STEP_S * SAMPLE_RATE)
    window = int(WINDOW_S * SAMPLE_RATE)
    pending = 0
    last = ""

    async for chunk in ws:
        if not isinstance(chunk, (bytes, bytearray)):
            continue
        buf = np.concatenate([buf, np.frombuffer(chunk, dtype=np.int16)])[-window:]
        pending += len(chunk) // 2
        if pending < step:
            continue
        pending = 0

        audio = buf.astype(np.float32) / 32768.0
        segments, _ = model.transcribe(audio, language=None if task == "translate" else lang, task=task)
        text = " ".join(s.text.strip() for s in segments).strip()
        if text and text != last:
            last = text
            await ws.send(text)


async def main():
    async with websockets.serve(handle, "0.0.0.0", 8765, max_size=None):
        print("GLARE transcription server on ws://0.0.0.0:8765")
        await asyncio.Future()


if __name__ == "__main__":
    asyncio.run(main())
