// C++ code

 int ledpin = 12;
 int ldrPin = 11;


void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop()
{
  int ldrStatus = digitalRead(ldrPin);
  
  if(ldrStatus == 1)
  {
    
  digitalWrite(ledpin, HIGH);
  Serial.print("Current Light Intensity Value is - ");
  Serial.println(ldrStatus);
  }
  
  else{
  digitalWrite(ledpin, LOW);
  Serial.print("Current Light Intensity Value is - ");
  Serial.println(ldrStatus);
  }
}