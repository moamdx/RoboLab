#include <LiquidCrystal.h>
int Rled=4;
int Yled=6;
int Gled=8;
int sensor=2;
int RS=A0;
int RW=A1;
int E=A2;
int D4=10;
int D5=11;
int D6=12;
int D7=13;
LiquidCrystal lcd(RS,RW,E,D4,D5,D6,D7);

void setup() {
   
  pinMode(Rled,OUTPUT);
  pinMode(Yled,OUTPUT);
  pinMode(Gled,OUTPUT);
  pinMode(sensor,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),printState,RISING); 
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  if (digitalRead(sensor)==1)
  {
    printState();
  }
  trafficLight();

}
void trafficLight()
{
  digitalWrite(Rled,LOW);
  digitalWrite(Yled,HIGH);
  digitalWrite(Gled,LOW);
  
  lcd.clear();
  lcd.setCursor(8,0);
  lcd.print(3);
  delay(1000);
  lcd.clear();
  lcd.setCursor(8,0);
  lcd.print(2);
  delay(1000);
  lcd.clear();
  lcd.setCursor(8,0);
  lcd.print(1);
  delay(1000);
  lcd.clear();
  lcd.setCursor(8,0);
  lcd.print(0);
  delay(1000);
  
  digitalWrite(Rled,HIGH);
  digitalWrite(Yled,LOW);
  digitalWrite(Gled,LOW);
  delay(10000);
  if(digitalRead(sensor)==1)
  {
    Serial.println("go");
  }
  digitalWrite(Rled,LOW);
  digitalWrite(Yled,LOW);
  digitalWrite(Gled,HIGH);
  delay(10000);
}
void printState()
{
  int R=digitalRead(Rled);
  int G=digitalRead(Gled);
  int Y=digitalRead(Yled);
  if(R==1)
  {
    Serial.println("red led in on");
    Serial.write(1);
  }
  if(G==1)
  {
    Serial.println("green led in on");
    Serial.write(0);
  }
  if(Y==1)
  {
    Serial.println("yellow led in on");
    Serial.write(2);
  }
}
