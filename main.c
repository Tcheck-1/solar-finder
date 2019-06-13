
#include <Servo.h>;
const int pResistor = A0;
const int pResistor2 = A1;
Servo Axe1;
float DiffValue;
float ValueR;
float ValueR2;
float delta;
float getDiffValue (){
  ValueR=analogRead(pResistor);
  ValueR2=analogRead(pResistor2);
  DiffValue=(ValueR/(ValueR2+5));
  return DiffValue;
}
float position = 7;

void setup() {
  Axe1.attach(9);
  Serial.begin(9600);
  pinMode(pResistor,INPUT);
  pinMode(pResistor2,INPUT);
  Axe1.write(position);
}

void loop() {

  ValueR = analogRead(pResistor);
  Serial.print("Value 1 : ");
  Serial.println(ValueR);
  ValueR2 = analogRead(pResistor2);
  Serial.print("Value 2 : ");
  Serial.println(ValueR2);
  diffValue = getDiffValue();
  Serial.print("Différence : ");
  Serial.println(DiffValue);

  while(diffValue<.95 || diffValue>1.05){
    delta = diffValue-1; // delta < 0 if diff < 1 & delta > 0 if diff > 1
    position+=delta;
    Axe1.write(position);
    delay(15);
    diffValue = getDiffValue();
  }

  delay(200);
}
