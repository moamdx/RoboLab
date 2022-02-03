#include<Servo.h>
Servo myservo;
int servoPin=6;
void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin,OUTPUT);
  myservo.attach(servoPin,1000,2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);
}
