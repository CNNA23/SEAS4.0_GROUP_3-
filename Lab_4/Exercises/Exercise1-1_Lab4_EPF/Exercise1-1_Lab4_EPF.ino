#include "dweetESP8266.h"

#define THIG_NAME "i4et-group3-WL-EPF"

// WiFi network parameters
//const char* ssid = "SEAS40";
//const char* password = "12345678";

const char* ssid = "sercommBA9719";
const char* password = "DFDMXMKGDU3QKD53";

dweet DweetClient;
char *key = "temperature"; //parameter sent to Dweet.io

void setup() {
  //Start serial
  Serial.begin(115200);
  //Small delay
  delay(10);
  
  //Connecting to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wi-Fi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  String value = DweetClient.getDweet(THIG_NAME, key);
  Serial.println(value);

}
