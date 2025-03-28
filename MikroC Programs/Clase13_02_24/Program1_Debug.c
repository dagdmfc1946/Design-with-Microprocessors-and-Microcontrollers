//unsigned short a;
void main() {
             OSCCON = 0b11110000; // OSCCON.F7 === 8 ó 32 MHz Para que el clock opere a 8 MHz
             TRISA = 0; // Puerto A
             //TRISB = 0;  // Todo el puerto B de salida
             ansela = 0;
             //anselb = 0; // Todos los pines del puerto B, digitales (pueden ser ADC)
             while (1){
                       LATA = 0;  // Saca por el puerto A un 0
                       //LATB = 0;  // Saca por el puerto B un 0
                       //a = a + 2;
                       //asm nop;   // No hace nada
                       //asm nop;
                       LATA = 0B11111111;     // Pone todo el puerto A en 1
                       //LATB = 0B11111111;   // Pone todo el puerto B en 1
                       //asm nop;
                       //asm nop;
                       //LATB = 0xAA;
                       //LATB = 0x55;
                       }
}