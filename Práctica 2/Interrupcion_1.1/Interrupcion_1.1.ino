//Interrupción con interruptor óptico
int LED=8;
int contador=0;
int estadoBoton;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
pinMode(3,INPUT);
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(3),interrumpe,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED,HIGH);
delay(1000);
digitalWrite(LED,LOW);
delay(1000);

}

void interrumpe(){
  contador++;
  Serial.println(contador);
}
