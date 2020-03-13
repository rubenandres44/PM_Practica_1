//Arduino Maestro Acelerómetro

#include <Wire.h>

int x=10;
//int y=9;
//int z=8;
int posX;
//int posY;
//int posZ;

int valX;
//int valY;
//int valZ;

void setup() {
  pinMode(x,INPUT);
  pinMode(A0,INPUT);
  //pinMode(y,INPUT);
  //pinMode(z,INPUT);
  
  Wire.begin();
  Serial.begin(9600);
}

void loop() {

  valX=analogRead(A0);
  //valY=analogRead(y);
  //valZ=analogRead(z);

  Serial.print("X = ");
  Serial.println(valX);
  if(valX > 400) valX = 400;
  if(valX < 270) valX = 270;
  /*
  Serial.print("Y = ");
  Serial.println(valY);
  Serial.print("Z = ");
  Serial.println(valZ);
  */
  
  posX=map(valX,270,400,0,255);//360
  //posY=map(valY,200,400,-90,90);
  //posZ=map(valZ,200,400,-90,90);
  
  Serial.print("Pos X = ");
  Serial.println(posX);
  /*
  Serial.print("Y = ");
  Serial.println(posY);
  Serial.print("Z = ");
  Serial.println(posZ);
  */
  Wire.beginTransmission(1);
  Wire.write(posX);
  
  //Wire.write(posY);
  //Wire.write(posZ);
  Wire.endTransmission();
  
  delay(250);

}
