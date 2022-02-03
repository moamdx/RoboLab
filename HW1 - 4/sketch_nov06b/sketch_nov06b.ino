int ledPin=5;
String state;
double potValue;
int light;
void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("enter 0-255");
}

void loop() {

  if (Serial.available()>0)
  {
    light=Serial.parseInt();
    Serial.println(light);
    analogWrite(ledPin,light);
  }


}
