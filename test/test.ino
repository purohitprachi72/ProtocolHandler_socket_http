#include "websocketprotocol.h"
#include "httpprotocol.h"

WebSocketProtocol ws("192.168.1.100", 80, "ssid", "password");
HttpProtocol hp("192.168.1.100", 80, "ssid", "password");

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Collect data
  String data = "{\"sensor\": \"temperature\", \"value\": 23.5}";

  // Send data periodically
  hp.sendData(data);

  // Wait for a while before sending the next data
  delay(10000);  // 10 seconds delay
}