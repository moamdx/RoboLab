int ledPin=5;
int pot=A4;
int en=11;
int RM1=8;
int RM2=7;
int LM1=10;
int LM2=9;
double potValue;
int state;
int light;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  Serial.begin(9600);
  Serial.println("RM===saat gard && LM==saat gard ==0 , RM==saat gaed && LM==pad saat gard ==1 , RM===pad  saat gard && LM==saat gard ==2 , RM==pad gaed && LM==pad saat gard ==3");
}

void loop() {
  analogWrite(en,255);
  if(Serial.available()>0)
  {
    state = Serial.parseInt();
    Serial.println(state);
    if(state==0)
    {
        //saatgard
        digitalWrite(RM1,HIGH);
        digitalWrite(RM2,LOW);
        //saatgard
        digitalWrite(LM1,HIGH);
        digitalWrite(LM2,LOW);
    }
        if(state==1)
    {
        //saatgard
        digitalWrite(RM1,HIGH);
        digitalWrite(RM2,LOW);
        //saatgard
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,HIGH);
    }
        if(state==2)
    {
        //saatgard
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,HIGH);
        //saatgard
        digitalWrite(LM1,HIGH);
        digitalWrite(LM2,LOW);
    }
        if(state==3)
    {
        //saatgard
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,HIGH);
        //saatgard
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,HIGH);
    }
            if(state==4)
    {
        //saatgard
        digitalWrite(RM1,LOW);
        digitalWrite(RM2,LOW);
        //saatgard
        digitalWrite(LM1,LOW);
        digitalWrite(LM2,LOW);
        analogWrite(en,0);
    }
  }

}
