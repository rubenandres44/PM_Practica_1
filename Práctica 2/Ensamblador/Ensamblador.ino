void setup() {

DDRB = DDRB | B00110011; // Data Direction Register B: Inputs 0-6, Output 7
//13=PB5
//12=PB4
//10=PB2
//9=PB1
//8=PB0
}

void loop() {

  asm (
"inicio: \n\t" 
//"sbi 0x05,0x05 \n\t" //Coloca 1 en bit 5 del RI/O 5
//"cbi 0x05,0x05 \n\t"//Coloca 0 en bit 5 del RI/O 5

"sbi 0x05,0x00 \n\t"
"sbi 0x05,0x01 \n\t"
"sbi 0x05,0x04 \n\t"
"sbi 0x05,0x05 \n\t"
//1 segundo
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"sbi 0x05,0x00 \n\t"
"cbi 0x05,0x01 \n\t"
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"sbi 0x05,0x00 \n\t"
"sbi 0x05,0x01 \n\t"
"cbi 0x05,0x04 \n\t"
//2 segundos
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"sbi 0x05,0x00 \n\t"
"cbi 0x05,0x01 \n\t"
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"sbi 0x05,0x00 \n\t"
"sbi 0x05,0x01 \n\t"
"sbi 0x05,0x04 \n\t"
"cbi 0x05,0x05 \n\t"
//3 segundos
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"cbi 0x05,0x01 \n\t"
"sbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"sbi 0x05,0x00 \n\t"
"sbi 0x05,0x01 \n\t"
"cbi 0x05,0x04 \n\t"
//4 segundos
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"sbi 0x05,0x00 \n\t"
"cbi 0x05,0x01 \n\t"
"call tiempo \n\t"
"cbi 0x05,0x00 \n\t"
"call tiempo \n\t"
"sbi 0x05,0x00 \n\t"
"sbi 0x05,0x01 \n\t"
"sbi 0x05,0x04 \n\t"
"sbi 0x05,0x05 \n\t"

"jmp main \n\t"//main

"tiempo: \n\t"
"LDI r22, 20 \n\t"//15
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
