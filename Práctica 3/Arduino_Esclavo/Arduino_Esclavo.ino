#include <Wire.h>

int pin5=5;//Entrada 2 puente H
int pin6=6;//Entrada 7 puente H
int bit0;
int bit1;

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
    Serial.print("Bit 0= ");
    Serial.println(bit0);
  }
  //Si hay un byte disponible
  if(Wire.available()==1){
    bit1=Wire.read();
    Serial.print("Bit 1= ");
    Serial.println(bit1);
  }
//Accion del motor
//si no funciona poner else
/*  
  if(bit1==1 && bit0==1){
    //Freno pasivo
    digitalWrite(pin5,HIGH);
    digitalWrite(pin6,HIGH);
  }
  else{
    if(bit1==1 && bit0==0){
      
      //Rotación anti horaria
      digitalWrite(pin5,LOW);
      digitalWrite(pin6,HIGH);
    }
    else{
      if(bit1==0 && bit0==1){
        
        //Rotación horaria
        digitalWrite(pin5,HIGH);
        digitalWrite(pin6,LOW);
      }
      else{
        if(bit1==0 && bit0==0){
          //Freno pasivo
          digitalWrite(pin5,LOW);
          digitalWrite(pin6,LOW);
        }
      }
    }
  }
  */
}

void loop() {
  //delay(300);
  if(bit1==1 && bit0==1){
    //Freno pasivo
    digitalWrite(pin5,HIGH);
    digitalWrite(pin6,HIGH);
  }
  else{
    if(bit1==1 && bit0==0){
      
      //Rotación anti horaria
      digitalWrite(pin5,LOW);
      digitalWrite(pin6,HIGH);
    }
    else{
      if(bit1==0 && bit0==1){
        
        //Rotación horaria
        digitalWrite(pin5,HIGH);
        digitalWrite(pin6,LOW);
      }
      else{
        if(bit1==0 && bit0==0){
          //Freno pasivo
          digitalWrite(pin5,LOW);
          digitalWrite(pin6,LOW);
        }
      }
    }
  }
  
}
