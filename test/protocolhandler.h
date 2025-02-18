#ifndef PROTOCOLHANDLER_H
#define PROTOCOLHANDLER_H

#include <Arduino.h>
#include <WiFi.h>

// Protocol type definitions (if needed)
#define WEBSOCKET_PROTOCOL 0
#define HTTP_PROTOCOL      1

class SelectProtocol {
protected:
  uint8_t protocol;
  const char* address;
  uint16_t port;
  const char* wifi_ssid;
  const char* wifi_password;

public:
  SelectProtocol(uint8_t protocol, const char* address, uint16_t port, 
                 const char* wifi_ssid, const char* wifi_password)
    : protocol(protocol), address(address), port(port),
      wifi_ssid(wifi_ssid), wifi_password(wifi_password)
  {
    if(WiFi.status() != WL_CONNECTED) {
      Serial.print("Connecting to WiFi");
      WiFi.begin(wifi_ssid, wifi_password);
      int retries = 0;
      while(WiFi.status() != WL_CONNECTED && retries < 20) {
        delay(500);
        Serial.print(".");
        retries++;
      }
      Serial.println();
      if(WiFi.status() == WL_CONNECTED) {
        Serial.println("WiFi connected");
      }
      else {
        Serial.println("WiFi connection failed");
      }
    }
  }

  virtual ~SelectProtocol() {}

  // Called to perform any protocol-specific initialization.
  virtual void handleProtocol() = 0;
};

#endif // PROTOCOLHANDLER_H
