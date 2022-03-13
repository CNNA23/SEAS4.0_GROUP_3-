int adc_id = A0;
int HistoryValue = 0;
char printBuffer[128];
int limit = 500; // Limit set manually

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(adc_id); //get adc value
  if (((HistoryValue >= value) && ((HistoryValue - value) > 10)) || ((HistoryValue < value) && ((value - HistoryValue) > 10)))
  {
    sprintf(printBuffer, "ADC%d level is %d\n", adc_id, value);
    Serial.print(printBuffer);
    HistoryValue = value;

    if (HistoryValue > 0.9*limit)
    {
     Serial.print("\nTurn the pump off, water level at 90% of the total capability\n");
    }
  }
}
