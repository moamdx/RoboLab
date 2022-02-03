int ledPin=5;

double potValue;
int light;
void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {

  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
  delay(1000);

}
