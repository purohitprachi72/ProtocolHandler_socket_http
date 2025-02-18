#include "httpprotocol.h"

HttpProtocol::HttpProtocol(const char* address, uint16_t port, 
                           const char* wifi_ssid, const char* wifi_password)
  : SelectProtocol(HTTP_PROTOCOL, address, port, wifi_ssid, wifi_password)
{
  // Additional HTTP initialization (if any) can be placed here.
}

void HttpProtocol::handleProtocol() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("HTTP protocol ready to send data");
  }
  else {
    Serial.println("WiFi not connected – HTTP protocol not initialized");
  }
}

void HttpProtocol::sendData(const String& data) {
  // Build the URL string (e.g., "http://192.168.1.100:80/data")
  String url = "http://" + String(address) + ":" + String(port) + "/data";
  Serial.println("Sending HTTP data to: " + url);
  
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST(data);
  
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("HTTP response: " + payload);
  }
  else {
    Serial.print("HTTP POST failed, error: ");
    Serial.println(http.errorToString(httpCode));
  }
  http.end();
}
