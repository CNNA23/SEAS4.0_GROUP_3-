//This code turns on the LED with "E" and turns off with "O"

byte receivedByte = 0;

void setup() {
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(230400);
}

void loop() {
  if (Serial.available() > 0)
  {
    //If there is a character, read it
    receivedByte = Serial.read();
    if(receivedByte == 69 || receivedByte == 101)
    {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED on");
    }
  }
  else if (receivedByte == 79 || receivedByte == 111) 
  {
    digitalWrite(LED_BUILTIN, HIGH); 
    Serial.println("LED off");
  }
 }
