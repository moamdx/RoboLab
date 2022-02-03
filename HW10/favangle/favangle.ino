#include<Servo.h>
Servo myservo;
int servoPin=6;
void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin,OUTPUT);
  myservo.attach(servoPin,1000,2000);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    int angle=Serial.parseInt();
    Serial.println(angle);
    myservo.write(angle);
  }
}
