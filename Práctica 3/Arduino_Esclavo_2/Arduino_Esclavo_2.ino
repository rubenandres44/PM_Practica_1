#include <Wire.h>

int pin5=5;//Entrada 2 puente H
int pin6=6;//Entrada 7 puente H
int bit0;
int bit1;

int cont=0;
int volt0;
int volt1;

void setup() {
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  
  Wire.begin(1);
  Wire.onReceive(receiveEvent);

  Serial.begin(9600);

}

void receiveEvent(int howMany){
//Lectura de bytes
  //Si hay dos bytes disponibles  
  if(Wire.available()==2){
    bit0=Wire.read();
    //Serial.print("Bit 0= ");
    //Serial.println(bit0);
  }
  //Si hay un byte disponible
  if(Wire.available()==1){
    bit1=Wire.read();
    //Serial.print("Bit 1= ");
    //Serial.println(bit1);
  }

  if(bit0==1){
    
    if(cont<5){
      cont++;
      Serial.println(cont);
    }
    
    //cont++;
    //Serial.println(cont);
  }
  if(bit1==1){
    
    if(cont>-5){
      cont--;
      Serial.println(cont);
    }
    
    //cont--;
    //Serial.println(cont);
  }


}

void loop() {
  if(cont>0){
    volt0=cont*51;
    analogWrite(pin5,volt0);
    analogWrite(pin6,0);
  }
  else{
    if(cont<0){
      volt1=cont*51*-1;
      analogWrite(pin5,0);
      analogWrite(pin6,volt1);
    }
  }
  //analogWrite(pin5,volt0);
  //analogWrite(pin6,volt1);  
}
