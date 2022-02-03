int ledArray[]={2,3,4};
float whiteArray[]={0,0,0};
float blackArray[]={0,0,0};
float colorArray[]={0,0,0};
int ldrOut=A3;
int ldr;
void setup(){
  pinMode(ledArray[0],OUTPUT);
  pinMode(ledArray[1],OUTPUT);
  pinMode(ledArray[2],OUTPUT);
  pinMode(ldrOut,INPUT);
  Serial.begin(9600);
  setBalance();
}

void loop() {
  if (Serial.available()>0)
  {
    int state=Serial.parseInt();
    if (state ==1)
    {
      checkColor();
    }
  }

}
void setBalance() {
  Serial.println("put white sample");
  delay(5000);
  Serial.println("start checking");
  for(int i=0;i<=2;i++)
  {
    digitalWrite(ledArray[i],HIGH);
    delay(100);
    //ldr=analogRead(ldrOut);//0-1023
    getReading(5);
    digitalWrite(ledArray[i],LOW);
    whiteArray[i]=ldr;
  }
  Serial.print("whiteArray[] = { ");
  Serial.print(whiteArray[0]);
  Serial.print(whiteArray[1]);
  Serial.print(whiteArray[2]);
  Serial.print("} ");  
  //black
  Serial.println("put black sample");
  delay(5000);
  Serial.println("start checking");
  for(int i=0;i<=2;i++)
  {
    digitalWrite(ledArray[i],HIGH);
    delay(100);
    ldr=analogRead(ldrOut);//0-1023
    digitalWrite(ledArray[i],LOW);
    blackArray[i]=ldr;
  }
  Serial.print("blackArray[] = { ");
  Serial.print(blackArray[0]);
  Serial.print(blackArray[1]);
  Serial.print(blackArray[2]);
  Serial.print("} ");  
}

void checkColor(){
  Serial.println("put color sample");
  delay (5000);
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
void printColor(){
  int R=colorArray[0];
  int G=colorArray[1];
  int B=colorArray[2];
  if (R>=160 && G<=100 && B<=100 && R>G && R>B)
  {
    Serial.println("color is red");
  }
  if (B>=160 && G<=100 && B<=100 && B>G && B>R)
  {
    Serial.println("color is blue");
  }
  if (G>=160 && R<=100 && B<=100 && G>R && G>B)
  {
    Serial.println("color is green");
  }
  if (G>=200 && R<=200 && B>=200 )
  {
    Serial.println("color is white");
  }
  if (G<40 && R<40 && B<40 )
  {
    Serial.println("color is black");
  }
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
