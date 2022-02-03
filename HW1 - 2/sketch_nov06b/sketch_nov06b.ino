int ledPin=5;
int state;
double potValue;
int light;
void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("led on == enter 1,led off==enter 2");
}

void loop() {

  if (Serial.available()>0)
  {
    state=Serial.parseInt();
    Serial.print(state);
    if(state==1)
    {
      digitalWrite(ledPin,HIGH);
    }
    if(state==2)
    {
      digitalWrite(ledPin,LOW);
    }
  }


}
