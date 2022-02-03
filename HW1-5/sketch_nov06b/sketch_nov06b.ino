int ledPin=5;
int pot=A4;
double potValue;
String state;
int light;
int speedm;
void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
    potValue=analogRead(pot);
    light=potValue*255/1023;
    light=Serial.parseInt();
    Serial.println(light);
    analogWrite(ledPin,light);
        
}

          
