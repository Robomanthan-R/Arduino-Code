#define led1 13
#define led2 12
void setup() {
  // put your setup code here, to run once:
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
delay(2000);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
delay(1000);
}
