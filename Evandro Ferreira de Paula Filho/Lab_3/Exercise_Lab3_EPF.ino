#include <ESP8266WiFi.h>

// WiFi network parameters
const char* ssid = "SEAS40";
const char* password = "12345678";


//Host to connect to an WiFi client parameters
const char* host = "postman-echo.com";
WiFiClient client;
const int httpPort=80;

void setup() {
  // Start serial
  Serial.begin(115200);
  // a small delay is added to initialize the serial port
  delay(10);

  // Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // a 5 sec delay is added for WiFi initialization and avoid continous loop requests
  delay(5000);
  Serial.print("connecting to ");
  Serial.println(host);
  
  // A connection to the website is oppened 
  if (!client.connect(host, httpPort))
  {
    Serial.println("connection failed");
    return;
  }

  // The specific URL is indicated and the connection request is sent
  String url = "/get?value=test";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + "HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

  // Wait 5 seconds for the serve response
  unsigned long timeout = millis();
  while (client.available() == 0)
  {
    if (millis() - timeout > 10000)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  while(client.available())
  { //The server response is processed
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");
}
