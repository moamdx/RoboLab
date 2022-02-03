int servoPin=6;
int t=20000;
void setup() {
  pinMode(servoPin,OUTPUT);

}

void loop() {
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(1000);//1000us=1ms angle=0 , 1500us=1.5ms angle=90 , 2000us=2ms angle=180
  digitalWrite(servoPin,LOW);
  delayMicroseconds(t-1000);
}
