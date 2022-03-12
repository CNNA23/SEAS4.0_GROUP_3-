int buzzer = D1; //data pin of the active buzzer

// input variable in bytes (0-255)
byte receivedByte = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT); //the buzzer pin is set as an output pin
  Serial.begin(230400);
  delay(3000);
  digitalWrite(buzzer, LOW);   // the buzzer off
  Serial.println("For operation, press T to turn the buzzer on and A to turn the buzzer off:");
}

void loop() {
   if (Serial.available()>0)
  {
    receivedByte=Serial.read();
    if (receivedByte==84)     // ASCII code for T
  {
  digitalWrite(buzzer, HIGH);   // turn the buzzer on (HIGH is the voltage level)
  Serial.println ("Buzzer is turned ON");
  }
  else if (receivedByte==65)  // ASCII code for A
  {
  digitalWrite(buzzer, LOW);    // turn the buzzer off by making the voltage LOW
  Serial.println ("Buzzer is turned OFF");
  }
  else{
  Serial.println("Invalid command, please try again by putting 'T' to turn on or 'A' to turn off");
  }
  }
}
