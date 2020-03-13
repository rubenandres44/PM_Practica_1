#include <Wire.h>

int pin5=5;//Entrada 2 puente H
int pin6=6;//Entrada 7 puente H
int posX;
int posY;
int posZ;

int voltX;
int voltY;
int voltZ;

void setup() {
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  
  Wire.begin(1);
  Wire.onReceive(receiveEvent);

  Serial.begin(9600);

}

void receiveEvent(int howMany){
//Lectura de bytes
  //Si hay tres bytes disponibles
  /*
  if(Wire.available()==3){
    posX=Wire.read();
    Serial.print("Pos X = ");
    Serial.println(posX);
  }
  //Si hay dos bytes disponibles  
  if(Wire.available()==2){
    posY=Wire.read();
    //Serial.print("Pos Y = ");
    //Serial.println(posY);
    
  }
  
  //Si hay un byte disponible
  if(Wire.available()==1){
    posZ=Wire.read();
    //Serial.print("Pos Z = ");
    //Serial.println(posZ);
  }
  */

  if(Wire.available()==1){
    posX=Wire.read();
    Serial.print("Pos X = ");
    Serial.println(posX);
  }
  
  voltX=map(posX,-90,90,0,255);
  //voltY=map(posY,-90,90,0,255);
  //voltZ=map(posZ,-90,90,0,255);

  Serial.print("Volt X = ");
  Serial.println(voltX);

  analogWrite(pin5,voltX);
  analogWrite(pin6,0);

}

void loop() {
  //analogWrite(pin5,voltX);
  //analogWrite(pin6,0);
}
