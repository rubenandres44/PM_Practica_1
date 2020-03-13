//Arduino Maestro

#include <Wire.h>

int pin8=8;
int pin9=9;
int bit0;
int bit1;

void setup() {
  pinMode(pin8,INPUT);
  pinMode(pin9,INPUT);
  
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  
  bit0=digitalRead(pin8);//lee un cero
  bit1=digitalRead(pin9);
  Serial.println(bit0);
  Serial.println(bit1);

  Wire.beginTransmission(1);
  Wire.write(bit0);
  Wire.write(bit1);
  Wire.endTransmission();

  delay(250);

}
