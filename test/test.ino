#include <Arduino.h>
#include "websocketprotocol.h"
#include "httpprotocol.h"

// Replace with your actual WiFi credentials.
const char* ssid = "ssid";
const char* password = "password";

// Create instances of the protocol classes.
// (The HTTP protocol uses port 80 and the WebSocket server uses port 81.)
WebSocketProtocol wsProtocol("192.168.1.100", 81, ssid, password);
HttpProtocol httpProtocol("192.168.1.100", 80, ssid, password);

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Initialize each protocol
  httpProtocol.handleProtocol();
  wsProtocol.handleProtocol();
}

void loop() {
  // Example: Send HTTP POST data every 10 seconds.
  String data = "{\"sensor\": \"temperature\", \"value\": 23.5}";
  httpProtocol.sendData(data);
  
  // Process WebSocket events.
  wsProtocol.loopProtocol();
  
  delay(10000);
}
