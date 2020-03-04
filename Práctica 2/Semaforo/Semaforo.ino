void setup() {
  // put your setup code here, to run once:
DDRB = DDRB | B00111111; // Data Direction Register B: Inputs 6-7, Output 0-5
//13=PB5:Rojo1
//12=PB4:Amarillo1
//11=PB3:Verde1
//10=PB2:Rojo2
//9=PB1:Amarillo2
//8=PB0:Verde2
}

void loop() {
  // put your main code here, to run repeatedly:
asm (
"inicio: \n\t" 
//"sbi 0x05,0x05 \n\t" //Coloca 1 en bit 5 del RI/O 5
//"cbi 0x05,0x05 \n\t"//Coloca 0 en bit 5 del RI/O 5
"sbi 0x05,0x05 \n\t"//Enciende rojo1
"sbi 0x05,0x00 \n\t"//Enciende verde2
"call tiempo \n\t"//1 segundo
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"//Apaga verde2
"sbi 0x05,0x01 \n\t"//Enciende amarillo2
"call tiempo \n\t"
"cbi 0x05,0x01 \n\t"//Apaga amarillo2
"cbi 0x05,0x05 \n\t"//Apaga rojo1

"sbi 0x05,0x03 \n\t"//Enciende verde1
"sbi 0x05,0x02 \n\t"//Enciende rojo2

"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"call tiempo \n\t"
"cbi 0x05,0x03 \n\t"//Apga verde1
"sbi 0x05,0x04 \n\t"//Enciende amarillo1
"call tiempo \n\t"
"cbi 0x05,0x04 \n\t"//Apaga amarillo1
"sbi 0x05,0x05 \n\t"//Enciende rojo1
"cbi 0x05,0x02 \n\t"//Apaga rojo2
"sbi 0x05,0x00 \n\t"//Enciende verde2

"jmp main \n\t"//main

"tiempo: \n\t"
"LDI r22, 40 \n\t"//15
"LOOP_3: \n\t"
"LDI r21, 255 \n\t"
"LOOP_2: \n\t"
"LDI r20, 255 \n\t"
"LOOP_1: \n\t"
"DEC r20 \n\t"
"BRNE LOOP_1 \n\t"
"DEC r21 \n\t"
"BRNE LOOP_2 \n\t"
"DEC r22 \n\t"
"BRNE LOOP_3 \n\t"
"ret \n\t"
);
}
