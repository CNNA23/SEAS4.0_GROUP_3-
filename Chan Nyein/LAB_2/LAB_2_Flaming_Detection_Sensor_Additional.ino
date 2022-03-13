
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
int Led = LED_BUILTIN; //define LED pin
int sensorD0 = D1; //define sensor digital output
int val; //define digital variable val

void setup() {
  pinMode(Led,OUTPUT); //define the LED pin as an output pin
  pinMode(sensorD0,INPUT); //define the sensor D0 as an input in
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
  val=digitalRead(sensorD0);//read the sensor digital output
  if(val==HIGH)//when the digital output detects a flame,the LED is turned on
  {
    digitalWrite(Led, HIGH);
    Serial.println("FIRE FIRE");
      }
   else
    {
     digitalWrite(Led,LOW);
     Serial.println("SAFE");
     }
   delay(500);  
}
   
 
 
