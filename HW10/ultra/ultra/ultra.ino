#include<Servo.h>
Servo myservo;
int servoPin=6;
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

int trigPin=12;
int echoPin=13;

long duration;
int distance;

int d;

void setup() {
 
  pinMode(led,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(inRM1,OUTPUT);
  pinMode(inRM2,OUTPUT);
  pinMode(inLM1,OUTPUT);
  pinMode(inLM2,OUTPUT);
  pinMode(pot,INPUT);
  pinMode(RightSen,INPUT);
  pinMode(LeftSen,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(servoPin,OUTPUT);
  myservo.attach(servoPin,1000,2000);
  myservo.write(90);
  Serial.begin(9600);

}

void loop() {
  potValue=analogRead(pot); //0-1023
  speedm=potValue*255/1023; //0-255
  int RS=digitalRead(RightSen);
  int LS=digitalRead(LeftSen);
  d=ultra();
  if(d>20)
  {
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
      Serial.println("F");
    }
  }
  else
  {
    stopm();
    myservo.write(0);
    delay(1000);
    d=ultra();
    if (d>=20)
    {
      myservo.write(90);
      delay(1000);
      right(speedm);
      delay(300);
    }
    else
    {
      myservo.write(180);
      delay(1000);
      d=ultra();

      if (d>=20)
      {
        myservo.write(90);
        delay(1000);
        left(speedm);
        delay(300);
        Serial.println("l");
      }
      else
      {
        myservo.write(90);
        delay(1000);
        Serial.println("s");
      }
    }
  }

}



void forward (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(inRM1,HIGH);
          digitalWrite(inRM2,LOW);
          //saatgard
          digitalWrite(inLM1,HIGH);
          digitalWrite(inLM2,LOW);
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
int ultra()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034)/2;
  return(distance);
}
