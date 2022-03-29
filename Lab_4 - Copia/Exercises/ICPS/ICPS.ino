//Link for data visualization: https://dweet.io/follow/i4et-group3-WL-EPF
//Link for freeboard: https://freeboard.io/board/nyMLc-

//Definitions and inclusions
#include "dweetESP8266.h" //Dweet library
#include "pitches.h" //Buzzer library
#include <NewPingESP8266.h> //sonar library
#define THIG_NAME "i4et-group3-WL-EPF" //Dweet thing name
#define TRIGGER_PIN D1 //US trigger pin
#define ECHO_PIN    D2 //US echo pin
#define MAX_DISTANCE 500 // maximum distance we want to ping for (in centimeters). Maximum sensor distance is 400-500cm.

NewPingESP8266 sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); //Initialization of the sonar

dweet DweetClient;
//parameter sent to Dweet.io
char *key = "Water_Level"; 
char *key2 = "Water_Level_US";
char *key3 = "Alarm_status";

//Variables definition

int limit_WL = 500; // Limit set manually for water level sensor
int adc_id = A0;
int HistoryValue = 0;
float tank_depth = 500;
float limit_US = 500; //Limit set manually for US
float measure; 
int buzzer = D8; //Data pin of the active buzzer
int RelayState = 0; //Alarm status at beginning 
int redpin = D7; //Pin for red LED

// WiFi network parameters
//const char* ssid = "SEAS40";
//const char* password = "12345678";
const char* ssid = "sercommBA9719";
const char* password = "DFDMXMKGDU3QKD53";

void setup() {
  //Start serial
  Serial.begin(115200);
  pinMode(redpin, OUTPUT);
  analogWrite(redpin, 0);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer, LOW);
  
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

//To store a number composed by up to 16 characters
char val1[16]; //For Water Level sensor
char val2[16]; //For US measurement
char val3[16]; //For Relay state

void loop() {
  delay(100);
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  int value = analogRead(adc_id); //get adc value
  measure = tank_depth - (uS/US_ROUNDTRIP_CM); //To measure in same direction as the WL sensor
  value = 0.1449*value+measure; //WL sensor calibration considering US measurements
  
  if (((HistoryValue >= value) && ((HistoryValue - value) > 10)) || ((HistoryValue < value) && ((value - HistoryValue) > 10)))
  {
    HistoryValue = value;  
  }
  while ((HistoryValue > 0.9*limit_WL) || (measure > 0.9*limit_US))
  {
   Serial.println("\nTurn the pump off, water level at 90% of the total capability\n");
   analogWrite(redpin, 255);
   unsigned char i;
   for(i=0;i<100;i++)
   {
        digitalWrite(buzzer,HIGH);
        delay(10);
        digitalWrite(buzzer,LOW);
        delay(10);
    }
   //Reupdating measurments and posting on dweet.io
   value = analogRead(adc_id);
   value = 0.1449*value+measure;
   HistoryValue = value;
   uS = sonar.ping();
   measure = tank_depth - (uS/US_ROUNDTRIP_CM);
   RelayState = 1;
   itoa(value, val1, 10); 
   itoa(measure, val2, 10);
   itoa(RelayState, val3, 10);
   DweetClient.add(key, val1);
   DweetClient.add(key2, val2);
   DweetClient.add(key3, val3);
   DweetClient.sendAll(THIG_NAME);
   }
  delay(1000);
  //Turning alarms off
  if((HistoryValue < 0.9*limit_WL) || (measure < 0.9*limit_US))
  {
    analogWrite(redpin, 0);
    digitalWrite(buzzer,LOW);
    RelayState = 0;
  }
  //Posting variables on dweet.io
  //Convert an integer into a char array
  itoa(value, val1, 10); 
  itoa(measure, val2, 10);
  itoa(RelayState, val3, 10); 
  Serial.printf("\nWater level sensor: %dcm\nUS measurement: %.0fcm\n", value, measure);
  DweetClient.add(key, val1);
  DweetClient.add(key2, val2);
  DweetClient.add(key3, val3);
  DweetClient.sendAll(THIG_NAME);
}
