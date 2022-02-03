int Rled=4;
int Yled=6;
int Gled=8;
void setup() {
  pinMode(Rled,OUTPUT);
  pinMode(Yled,OUTPUT);
  pinMode(Gled,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  trafficLight();

}
void trafficLight()
{
  digitalWrite(Rled,LOW);
  digitalWrite(Yled,HIGH);
  digitalWrite(Gled,LOW);
  delay(3000);
  digitalWrite(Rled,HIGH);
  digitalWrite(Yled,LOW);
  digitalWrite(Gled,LOW);
  delay(10000);
  digitalWrite(Rled,LOW);
  digitalWrite(Yled,LOW);
  digitalWrite(Gled,HIGH);
  delay(10000);
}
