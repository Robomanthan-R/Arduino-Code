#define ir 12
#define led1 2
#define led2 4

int irstate = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ir, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  irstate = digitalRead(ir);
  if(irstate == LOW){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  delay(200);

}
