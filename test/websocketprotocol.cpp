#include "websocketprotocol.h"

// Initialize the static instance pointer.
WebSocketProtocol* WebSocketProtocol::instance = nullptr;

WebSocketProtocol::WebSocketProtocol(const char* address, uint16_t port, 
                                     const char* wifi_ssid, const char* wifi_password,
                                     const char* url)
  : SelectProtocol(WEBSOCKET_PROTOCOL, address, port, wifi_ssid, wifi_password),
    ws(port),
    url(url),
    websocket_flag(false),
    isConnected(false)
{
  instance = this;
}

void WebSocketProtocol::handleProtocol()
{
  // Start the WebSocket server
  ws.begin();
  ws.onEvent(webSocketEventStatic);
  Serial.println("WebSocket server started");
}

void WebSocketProtocol::webSocketEventStatic(uint8_t num, WStype_t type, uint8_t* payload, size_t length)
{
  if(instance) {
    instance->webSocketEvent(num, type, payload, length);
  }
}

void WebSocketProtocol::webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length)
{
  switch(type) {
    case WStype_DISCONNECTED:
      Serial.printf("[WSc] Client %u disconnected\n", num);
      isConnected = false;
      break;
    case WStype_CONNECTED:
      Serial.printf("[WSc] Client %u connected\n", num);
      isConnected = true;
      break;
    case WStype_TEXT:
      Serial.printf("[WSc] Received text from %u: %s\n", num, payload);
      break;
    case WStype_BIN:
      Serial.printf("[WSc] Received binary data from %u, length: %u\n", num, length);
      break;
    default:
      break;
  }
}

void WebSocketProtocol::sendData(String& data)
{
  // Broadcast the data to all connected WebSocket clients.
  ws.broadcastTXT(data);
}

void WebSocketProtocol::loopProtocol() {
  // This method should be called periodically from loop() to process WebSocket events.
  ws.loop();
}
