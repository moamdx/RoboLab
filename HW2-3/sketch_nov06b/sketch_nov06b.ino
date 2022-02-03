int ledPin=5;
int pot=A4;
int en=11;
int RM1=8;
int RM2=7;
int LM1=10;
int LM2=9;
double potValue;
String state;
int light;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  Serial.begin(9600);
  Serial.println("forward=F ,backward=B,left=L,right=R,stop=S");
}

void loop() {
  int speedm=255;
  if(Serial.available()>0)
  {
    state = Serial.readString();
    Serial.println(speedm);
    if(state=="F")
    {
      forward(speedm);
      Serial.println("forward");
    }
     if(state=="B")
    {
      backward(speedm);
      Serial.println("backward");
    } 
     if(state=="L")
     {
      left(speedm);
      Serial.println("left");
     }
     if(state=="R")
     {
      right(speedm);
      Serial.println("right");
     }
         
  }
}

void forward (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          //saatgard
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
  }
void backward (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,HIGH);
          //saatgard
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
  }
void left (int sm)
  {
           analogWrite(en,sm);
           //saatgard
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          //saatgard
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
  }
void right (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,HIGH);
          //saatgard
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
  }
void stop (int sm)
  {
           analogWrite(en,sm);
          //saatgard
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,LOW);
          //saatgard
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,LOW);
  }
