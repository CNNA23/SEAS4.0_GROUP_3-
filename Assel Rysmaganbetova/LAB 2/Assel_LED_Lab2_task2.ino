int redpin = D1; //pin for the red LED
int greenpin = D2; //pin for the green LED
int bluepin = D3; //pin for the blue LED

//input variable in bytes(0-255)
byte receiveByte = 0;

int val;
void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  Serial.begin(230400);
  delay(4500);
  analogWrite (D1, val);
  analogWrite(D2, 0); 
  analogWrite(D3, 0); 
  
  Serial.println ("The Red LED is turned on. Press B to turn Blue LED and G to turn Green LED-->");
  
}

void loop() {
  
  for(val=255; val>0; val--)
  if(Serial.available()>0)
  {
  receiveByte=Serial.read();
  if(receiveByte==82){//82 is the ASCII code for R
  analogWrite(D2, 128-val);  
  analogWrite(D3, 0);   
  analogWrite(D1, 0);   
  
  //  Serial.println(receiveByte);
  Serial.println("RED LED is turned ON");
  delay(4500);
  }
 else if(receiveByte==66){//66 is the ASCII code for B
  analogWrite(D1, val);   
  analogWrite(D2, 0); 
  analogWrite(D3, 0); 
  //  Serial.println(receiveByte);
  Serial.println("BLUE LED is turned ON");
  delay(4500);
 }
  else if(receiveByte==71){//71 is the ASCII code for G
  analogWrite(D3, 255-val);   
  analogWrite(D1, 0);   
  analogWrite(D2, 0); 
  //  Serial.println(receiveByte);
  Serial.println("Green LED is turned ON"); 
  delay(4500);
   }
   
  }
}
