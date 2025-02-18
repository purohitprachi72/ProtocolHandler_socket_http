#ifndef WEBSOCKETPROTOCOL_H
#define WEBSOCKETPROTOCOL_H

#include "protocolhandler.h"
#include <WebSocketsClient.h>

class WebSocketProtocol : public SelectProtocol
{
private:
    WebSocketsServer ws = WebSocketsServer(81);
    const char* address;
    uint16_t port;
    const char* url = "/";
    bool websocket_flag = false;
    bool isConnected = false;

    static void webSocketEventStatic(WStype_t type, uint8_t* payload, size_t length, void* user);
    void webSocketEvent(WStype_t type, uint8_t* payload, size_t length);

public:
    void handleProtocol() override;
    // WebSocketProtocol(const char* address, uint16_t port, char* wifi_ssid, char* wifi_password);
};

#endif // WEBSOCKETPROTOCOL_H