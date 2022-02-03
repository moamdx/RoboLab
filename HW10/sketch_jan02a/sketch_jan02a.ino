int led=5;
int en=11;
int inRM1=8;
int inRM2=7;
int inLM1=10;
int inLM2=9;
int pot=A4;
double potValue;
int speedm;
int RightSen=A0;
int LeftSen=A2;
int MSen=A1;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(inRM1,OUTPUT);
  pinMode(inRM2,OUTPUT);
  pinMode(inLM1,OUTPUT);
  pinMode(inLM2,OUTPUT);
  pinMode(pot,INPUT);
  pinMode(RightSe,INPUT);
  pinMode(LightSen,INPUT);
  Serial.begin(9600);

  

}

void loop() {
  potValue=analogRead(pot); //0-1023
  speedm=potValue*255/1023; //0-255
  int RS=digitalRead(RightSen);
  int LS=digitalRead(LeftSen);

  if(RS==0 && LS==0)
  {
    backward(speedm);
    delay(600);
    right(speedm);
    delay(400);
    Serial.println("B-R");
  }
  if(RS==1 && LS==0)
  {
    right(speedm);
    delay(300);
    Serial.println("R");
  }
  if(LS==1 && RS==0)
  {
    left(speedm);
    delay(300);
    Serial.println("L");
  }
  if(LS==1 && RS==1)
  {
    forward(speedm);
    delay(300);
    Serial.println("L");
  }

}



void forward (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(inRM1,HIGH);
          digitalWrite(RM2,LOW);
          //saatgard
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
  }
void backward (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(inRM1,LOW);
          digitalWrite(inRM2,HIGH);
          //saatgard
          digitalWrite(inLM1,LOW);
          digitalWrite(inLM2,HIGH);
  }
void left (int sm)
  {
           analogWrite(en,sm);
           //saatgard
          digitalWrite(inRM1,HIGH);
          digitalWrite(inRM2,LOW);
          //saatgard
          digitalWrite(inLM1,LOW);
          digitalWrite(inLM2,HIGH);
  }
void right (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(inRM1,LOW);
          digitalWrite(inRM2,HIGH);
          //saatgard
          digitalWrite(inLM1,HIGH);
          digitalWrite(inLM2,LOW);
  }
void stopm ()
  {
           analogWrite(en,0);
          
  }
