#pragma once

// Brings up WiFi, opens the transcription websocket, then streams mic audio
// out and renders returned transcript text on the HUD. Blocks until WiFi is up.
void glare_net_start(void);
