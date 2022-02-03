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
int speedm;
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
    //forward ==> 6s
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
          delay(6000);

          //left ==> 2s  
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
          delay(2000);

          //forward ==> 4s
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
          delay(4000);

          //left ==> 2s  
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
          delay(2000);

          //backward ==> 5s  
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,HIGH);
          
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
          delay(5000);

          //right ==> 2s  
           digitalWrite(RM1,LOW);
          digitalWrite(RM2,HIGH);
          
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
          delay(2000);

          //backward ==> 4s  
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,HIGH);
          
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
          delay(4000);


          //left ==> 1s  
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
          delay(1000);
          

          //stop ==> 7s  
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,LOW);

          digitalWrite(LM1,LOW);
          digitalWrite(LM2,LOW);
          delay(7000);
         
          
}

          
