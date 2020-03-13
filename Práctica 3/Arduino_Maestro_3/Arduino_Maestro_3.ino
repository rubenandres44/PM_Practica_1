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
  //pinMode(y,INPUT);
  //pinMode(z,INPUT);
  
  Wire.begin();
  Serial.begin(9600);
}

void loop() {

  valX=analogRead(x);
  //valY=analogRead(y);
  //valZ=analogRead(z);

  Serial.print("X = ");
  Serial.println(valX);
  /*
  Serial.print("Y = ");
  Serial.println(valY);
  Serial.print("Z = ");
  Serial.println(valZ);
  */
  posX=map(valX,360,380,-90,90);//360
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
