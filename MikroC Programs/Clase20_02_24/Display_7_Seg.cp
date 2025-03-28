#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/MikroC Programs/Clase20_02_24/Display_7_Seg.c"
const unsigned short DIGITOS[] = {
 0x3F,
 0x06,
 0x5B,
 0x4F,
 0x66,
 0x6D,
 0x7D,
 0x07,
 0x7F,
 0x6F,
 };

void main(void){
 unsigned short CONTADOR=0;

 OSCCON.F0=0;
 OSCCON.F1=0;
 OSCCON.F3=0;
 OSCCON.F4=1;
 OSCCON.F5=1;
 OSCCON.F6=1;
 OSCCON.F7=1;
 TRISB = 0;

 ANSELB = 0;

 while(1){

 LATB = DIGITOS [CONTADOR];

 CONTADOR++;
 delay_ms(500);
 if (contador == 10) contador = 0;
 }
}
