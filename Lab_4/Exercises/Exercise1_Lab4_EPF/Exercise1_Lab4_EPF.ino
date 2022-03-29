#include "dweetESP8266.h"

#define THIG_NAME "i4et-group3-WL-EPF"

// WiFi network parameters
//const char* ssid = "SEAS40";
//const char* password = "12345678";

const char* ssid = "sercommBA9719";
const char* password = "DFDMXMKGDU3QKD53";

dweet DweetClient;
int i=20; // Random initial value
float f=30.1; // Random initial value
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

char val[16]; //To store a number composed by up to 16 characters

void loop() {

  //EXAMPLE 1: Sending an integer to Dweet.io
  itoa(i, val, 10); //Convert an integer into a char array
  Serial.println(val);
  DweetClient.add(key, val);
  DweetClient.sendAll(THIG_NAME);
  i++; //Increases "i" by 1

  //EXAMPLE 2: Sending a float to Dweet.io
  /*
   String temp = String(f,2); //"f" converted to String with 2 decimals
   temp.charArray(val); //temp is converted to a char array
   Serial.println(val);
   DweetClient.add(key, val);
   DweetClient.sendALL(THIG_NAME);
   f = f+0.1;
   */

   //Every 5 seconds, a new value is uploaded
   delay(5000);
}
