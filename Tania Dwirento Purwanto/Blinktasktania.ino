/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board

// input variable in bytes (0-255)
byte receivedByte = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(D4, OUTPUT);
  Serial.begin(230400);
  delay(3000);
  digitalWrite(D4, HIGH);   // the LED off
  Serial.println("For operation, press T to turn the LED on and A to turn the LED off:");
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available()>0)
  {
    receivedByte=Serial.read();
    if (receivedByte==84)     // ASCII code for T
  {
  digitalWrite(D4, LOW);   // turn the LED on (HIGH is the voltage level)
  Serial.println ("LED is turned ON");
  }
  else if (receivedByte==65)  // ASCII code for A
  {
  digitalWrite(D4, HIGH);    // turn the LED off by making the voltage LOW
  Serial.println ("LED is turned OFF");
  }
  else{
  Serial.println("Invalid command, please try again by putting 'T' to turn on or 'A' to turn off");
  }
  }
}
