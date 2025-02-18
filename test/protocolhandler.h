#ifndef SELECTPROTOCOL_H
#define SELECTPROTOCOL_H

#include <stdio.h>
#include "WiFi.h"
// #include <WebSocketsClient.h>
// #include <HTTPClient.h>

class SelectProtocol {
private:
  const char* ssid;
  const char* password;
public:
  SelectProtocol(int protocol, const char* address, uint16_t port, char* wifi_ssid, char* wifi_password);
  // ~SelectProtocol(); //destructor - cleans up after object is deleted
  virtual void handleProtocol() = 0;
  void init_wifi();
  bool connect_to_wifi();
};

#endif  // SELECTPROTOCOL_H