#ifndef HTTPPROTOCOL_H
#define HTTPPROTOCOL_H

#include "protocolhandler.h"
#include <HTTPClient.h>

class HttpProtocol : public SelectProtocol {
private:
  HTTPClient http;
  const char* address;
  uint16_t port;
  bool first = false;
  bool replace = true;

public:
  HttpProtocol(const char* address, uint16_t port, char* wifi_ssid, char* wifi_password);
  void handleProtocol() override;
  void sendData(const String& data);
};

#endif  // HTTPPROTOCOL_H