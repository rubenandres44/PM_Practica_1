/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
int sensorPin = A0;
int sensorPot = A1;
int sensorValue;
long potenValue;
int posicion;
int valor;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensorPin,INPUT);
  //pinMode(sensorPot,INPUT);

  Serial.println("Inicio de sketch - valores potenciometro");
}

// the loop function runs over and over again forever
void loop() {
  sensorValue=analogRead(sensorPin);
  potenValue=analogRead(sensorPot);
  posicion=map(potenValue,0,1023,0,100);
  valor=map(sensorValue,0,1024,0,100);
  Serial.print("El valor del sensor es = ");
  Serial.println(sensorValue);
  Serial.print("El valor del potenciometro es = ");
  Serial.println(potenValue);
  Serial.print("Porcentaje del potenciometro = ");
  Serial.println(posicion);
  Serial.print("Porcentaje del sensor = ");
  Serial.println(valor);
  Serial.println();
  if(valor<posicion)
  {
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    digitalWrite(LED_BUILTIN,HIGH);
  }
  delay(2000);
}
