#ifndef HTTPPROTOCOL_H
#define HTTPPROTOCOL_H

#include "protocolhandler.h"
#include <HTTPClient.h>

class HttpProtocol : public SelectProtocol {
private:
  HTTPClient http;

public:
  HttpProtocol(const char* address, uint16_t port, 
               const char* wifi_ssid, const char* wifi_password);
  void handleProtocol() override;
  void sendData(const String& data);
};

#endif  // HTTPPROTOCOL_H
