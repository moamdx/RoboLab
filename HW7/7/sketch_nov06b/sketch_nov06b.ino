int ledPin=5;
int pot=A4;
int en=11;
int RM1=8;
int RM2=7;
int LM1=10;
int LM2=9;
int RSen=A0;
int LSen=A2;
int MSen=A1;
int MS;

int trigPin=12;
int echoPin=13;

long duration;
int distance;

int ledArray[]={2,3,4};
float whiteArray[]={171,309,439};
float blackArray[]={505,702,825};
float colorArray[]={0,0,0};
int ldrOut=A3;
int ldr;

double potValue;
String state;
int light;
int speedm;
double vth=4.1;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RSen,INPUT);
  pinMode(LSen,INPUT);
  pinMode(MSen,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(ledArray[0],OUTPUT);
  pinMode(ledArray[1],OUTPUT);
  pinMode(ledArray[2],OUTPUT);
  pinMode(ldrOut,INPUT);
  
  Serial.begin(9600);
  Serial.println("forward=F ,backward=B,left=L,right=R,stop=S");
}

void loop() {
  potValue=analogRead(pot); //0-1023
  speedm=potValue*255/1023; //0-255

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034)/2;
  Serial.print("distance= ");
  Serial.println(distance);
  
  int RS=digitalRead(RSen);
  int LS=digitalRead(LSen);
  double Msensor=analogRead(MSen);
  double MS1=Msensor*5/1023; //0-5
  double vth = 4.1; 
  if (MS1>vth)
    MS=1;
    else if (MS1<vth)
    MS=1;
  //Serial.println(RSen);  
  //Serial.println(LSen);


 if(distance>25)
  {
      //color recognition
      if((RS==0 && MS==1 && LS==0) || (RS==1 && MS==1 && LS==1) )
      {
        stopm();
        checkColor();
        int R=colorArray[0];
        int G=colorArray[1];
        int B=colorArray[2];
      }
      if((RS==0 && MS==0 && LS==0) )
      {
             stopm ();
             Serial.println("Stop");
      }
      if((RS==1 && MS==0 && LS==0) || (RS==1 && MS==1 && LS==0))
      {
             left(speedm);
             Serial.println("left");
      }
      if((RS==0 && MS==0 && LS==1) || (RS==0 && MS==1 && LS==1))
      {
             right(speedm);
             Serial.println("right");
      }
      if((RS==1 && MS==0 && LS==1))
      {
             forward(speedm);
             Serial.println("forward");
      }
      else
      {
        stopm();
        Serial.println("stop ultrasonic");
      }
  }

  
    
      if (R>=160 && G<=100 && B<=100 && R>G && R>B)
    {
      Serial.println("color is red");
      while(analogRead(A1)*5/1023)>2)
      {
        right(speedm);
        Serial.println("RIGHT");
        );
      } 
    }
    if (B>=160 && G<=100 && B<=100 && B>G && B>R)
    {
      Serial.println("color is blue");
      while(analogRead(A1)*5/1023)>2)
      {
        left(speedm);
        Serial.println("LEFT");
      } 
    }
    if (G>=160 && R<=100 && B<=100 && G>R && G>B)
    {
      Serial.println("color is green");
      while(analogRead(A1)*5/1023)>2)
      {
        right(speedm);
        Serial.println("180");
      } 
      
    }
    if (G>=200 && R<=200 && B>=200 )
    {
      Serial.println("color is white");
        forward(speedm);
        
    }
    else ()
    {
      stopm();
    }  
    if (G<40 && R<40 && B<40 )
    {
      Serial.println("color is black");
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
void stopm ()
  {
           analogWrite(en,0);
          
  }
void checkColor(){
  Serial.println("put color sample");
  Serial.println("start checking");
  for (int i=0;i<=2;i++)
  {
    digitalWrite(ledArray[i],HIGH);
    delay(100);
    //ldr=analogRead(ldrOut);
    getReading(5);
    digitalWrite(ledArray[i],LOW);
    colorArray[i]=((ldr-blackArray[i])/(whiteArray[i]-blackArray[i]))*255;
    colorArray[i]=max(min(255,colorArray[i]),0); 
    
  }
  Serial.print("colorArray[] = { ");
  Serial.print(colorArray[0] , " , ");
  Serial.print(colorArray[1] , " , ");
  Serial.print(colorArray[2] , " , ");
  Serial.print("} ");   
}
int getReading(int times)
{
  int a;
  int b=0;
  for (int i=0;i<=times;i++)
  {
    a=analogRead(ldrOut);
    b=a+b;
    delay(10);
  }
  ldr=b/times;
  return (ldr);
}
