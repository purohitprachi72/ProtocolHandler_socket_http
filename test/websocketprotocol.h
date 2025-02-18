#ifndef WEBSOCKETPROTOCOL_H
#define WEBSOCKETPROTOCOL_H

#include "protocolhandler.h"
#include <WebSocketsClient.h>

class WebSocketProtocol : public SelectProtocol {
private:
  WebSocketsClient ws;
  const char* address;
  uint16_t port;
  const char* url = "/";
  bool websocket_flag = false;
  bool isConnected = false;

protected:
  static void webSocketEvent(WStype_t type, uint8_t* payload, size_t length, void* user);

public:
  WebSocketProtocol(const char* address, uint16_t port, char* wifi_ssid, char* wifi_password);
  void handleProtocol() override;
  void webSocketEvent(WStype_t type, uint8_t* payload, size_t length);
};

#endif  // WEBSOCKETPROTOCOL_H