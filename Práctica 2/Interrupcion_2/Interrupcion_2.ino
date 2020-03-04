//Interrupción con lenguaje ensamblador usando push button
int LED=8;
int contador=0;
int estadoBoton;

void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
Serial.begin(9600);

{
cli();
DDRD &= ~(1 << DDD1);
PORTD |= (1 << PORTD3);
EICRA |= (1 << ISC10);
EIMSK |= (1 << INT1);
sei();
}

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED,HIGH);
delay(1000);
digitalWrite(LED,LOW);
delay(1000);

}


ISR(INT1_vect){
  contador++;
  Serial.println(contador);
}
