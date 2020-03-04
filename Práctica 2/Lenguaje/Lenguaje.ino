int LED1=13;
int LED2=12;
int LED3=9;
int LED4=8;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED1,HIGH);
digitalWrite(LED2,HIGH);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
//1 segundo
delay(250);
digitalWrite(LED1,LOW);
delay(250);
digitalWrite(LED1,HIGH);
digitalWrite(LED2,LOW);
delay(250);
digitalWrite(LED1,LOW);
delay(250);
digitalWrite(LED1,HIGH);
digitalWrite(LED2,HIGH);
digitalWrite(LED3,LOW);
//2 segundos
delay(250);
digitalWrite(LED1,LOW);
delay(250);
digitalWrite(LED1,HIGH);
digitalWrite(LED2,LOW);
delay(250);
digitalWrite(LED1,LOW);
delay(250);
digitalWrite(LED1,HIGH);
digitalWrite(LED2,HIGH);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,LOW);
//3 segundos
delay(250);
digitalWrite(LED1,LOW);
delay(250);
digitalWrite(LED1,HIGH);
digitalWrite(LED2,LOW);
delay(250);
digitalWrite(LED1,LOW);
delay(250);
digitalWrite(LED1,HIGH);
digitalWrite(LED2,HIGH);
digitalWrite(LED3,LOW);
//4 segundos
delay(250);
digitalWrite(LED1,LOW);
delay(250);
digitalWrite(LED1,HIGH);
digitalWrite(LED2,LOW);
delay(250);
digitalWrite(LED1,LOW);
delay(250);
digitalWrite(LED1,HIGH);
digitalWrite(LED2,HIGH);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
}
