// #include "protocolhandler.h"

// SelectProtocol::SelectProtocol(int protocol, const char* address, uint16_t port, char* wifi_ssid, char* wifi_password) {
//   this->ssid = wifi_ssid;
//   this->password = wifi_password;
//   init_wifi();
//   if (connect_to_wifi()) {
//     // handleProtocol();
//     if (protocol == 0) {
//       // handle ws
//       handleProtocol();
//     } else if (protocol == 1) {
//       // handle http
//       handleProtocol();
//     } else {
//       printf("Invalid protocol\n Protocol = 0 for websocket \n Protocol = 1 for http\n");
//     }
//   } else {
//     printf("Failed to connect to wifi\n");
//   }
// }

// void SelectProtocol::init_wifi() {
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//   }
// }

// bool SelectProtocol::connect_to_wifi() {
//   unsigned long lastTimeStamp = millis();
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     if ((millis() - lastTimeStamp) > 30 * 1000) {
//       delay(5000);
//       WiFi.reconnect();
//     }
//   }

//   return WiFi.status() == WL_CONNECTED;
// }