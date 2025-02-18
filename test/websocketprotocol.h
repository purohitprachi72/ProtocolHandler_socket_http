#ifndef WEBSOCKETPROTOCOL_H
#define WEBSOCKETPROTOCOL_H

#include "protocolhandler.h"
#include <WebSocketsServer.h>

class WebSocketProtocol : public SelectProtocol
{
private:
  WebSocketsServer ws;
  const char* url;
  bool websocket_flag;
  bool isConnected;

  // Static pointer for the (single) instance
  static WebSocketProtocol* instance; 

  // Static callback function that forwards events to the instance method
  static void webSocketEventStatic(uint8_t num, WStype_t type, uint8_t* payload, size_t length);
  void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length);

public:
  // The constructor now also accepts an optional URL path.
  WebSocketProtocol(const char* address, uint16_t port, 
                    const char* wifi_ssid, const char* wifi_password,
                    const char* url = "/");
  void handleProtocol() override;
  
  // Method to send data over all connected WebSocket clients.
  void sendData(String& data);
  
  // Expose the WebSocket loop so that events can be processed in loop().
  void loopProtocol();
};

#endif // WEBSOCKETPROTOCOL_H
