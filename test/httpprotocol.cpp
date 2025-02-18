#include "httpprotocol.h"

HttpProtocol::HttpProtocol(const char* address, uint16_t port, char* wifi_ssid, char* wifi_password)
  : SelectProtocol(1, address, port, wifi_ssid, wifi_password), address(address), port(port) {
  // handleProtocol();
}

void HttpProtocol::handleProtocol() {
  if (WiFi.status() == WL_CONNECTED) {
    printf("HTTP initialized and ready to sent data\n");
  } else {
    printf("WiFi not connected\n");
  }
}

void HttpProtocol::sendData(const String& data) {
  http.begin("http://" + String(address) + ":" + String(port) + "/data");
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST(data);
  if (httpCode > 0) {
    String payload = http.getString();
    printf("HTTP response: %s\n", payload.c_str());
  } else {
    printf("HTTP POST failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}