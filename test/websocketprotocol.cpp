#include "websocketprotocol.h"

// WebSocketProtocol::WebSocketProtocol(const char* address, uint16_t port, char* wifi_ssid, char* wifi_password) : 
// SelectProtocol(0, address, port, wifi_ssid, wifi_password), address(address), port(port)
// {
//     // handleProtocol() will be called in the base class constructor if WiFi is connected
// }

void WebSocketProtocol::handleProtocol()
{
    // ws.begin(address, port, url);
    // ws.onEvent(webSocketEventStatic, this);
    // ws.setReconnectInterval(0); // Disable auto-reconnect

    ws.begin();
    ws.onEvent(webSocketEventStatic); //passing static cb
}

void WebSocketProtocol::webSocketEventStatic(WStype_t type, uint8_t* payload, size_t length, void* user)
{
    // WebSocketProtocol* self = static_cast<WebSocketProtocol*>(user);
    // self->webSocketEvent(type, payload, length);

    WebSocketProtocol* instance = static_cast<WebSocketProtocol*>(user);
    if(instance) {
        instance->webSocketEvent(type, payload, length);
    }
}

void WebSocketProtocol::webSocketEvent(WStype_t type, uint8_t* payload, size_t length)
{
    switch (type) {
        case WStype_DISCONNECTED:
            websocket_flag = false;
            isConnected = false;
            break;
        case WStype_CONNECTED:
            Serial.printf("[WSc] Connected to url: %s\n", payload);
            isConnected = true;
            break;
        case WStype_TEXT:
            Serial.printf("[WSc] get text: %s\n", payload);
            websocket_flag = false;
            break;
        case WStype_BIN:
            Serial.printf("[WSc] get binary length: %u\n", length);
            break;
        case WStype_ERROR:
        case WStype_FRAGMENT_TEXT_START:
        case WStype_FRAGMENT_BIN_START:
        case WStype_FRAGMENT:
        case WStype_FRAGMENT_FIN:
        case WStype_PING:
        case WStype_PONG:
            break;
    }
}