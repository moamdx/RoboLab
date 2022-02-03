int ledPin=5;
int pot=A4;
int en=11;
int RM1=8;
int RM2=7;
int LM1=10;
int LM2=9;
double potValue;
int light;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(en,255);
  //saatgard
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
  //chpgard
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
}
