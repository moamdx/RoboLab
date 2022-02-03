int ledPin=5;
String state;
double potValue;
int light;
void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("led on == enter on,led off==enter off");
}

void loop() {

  if (Serial.available()>0)
  {
    state=Serial.readString();
    Serial.println(state);
    if(state=="on")
    {
      digitalWrite(ledPin,HIGH);
    }
    if(state=="off")
    {
      digitalWrite(ledPin,LOW);
    }
  }


}
