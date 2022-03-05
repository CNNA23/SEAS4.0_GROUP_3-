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

//input variable in bytes(0-255)
byte receiveByte = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(230400);
  delay(4500);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("The LED is off. Press A to turn it and L to turn it off-->");
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()>0)
  {
  receiveByte=Serial.read();
  if(receiveByte==65){//65 is the ASCII code for A
  digitalWrite(LED_BUILTIN, LOW);   
  //  Serial.println(receiveByte);
  Serial.println("LED is turned ON");
  }
 else if(receiveByte==76){//76 is the ASCII code for L
  digitalWrite(LED_BUILTIN, HIGH);   
  //  Serial.println(receiveByte);
  Serial.println("LED is turned OFF");
  }
  
 else{
  Serial.println("Invalid error, try again");  //wait for a second
 }
  
 }
  
}
