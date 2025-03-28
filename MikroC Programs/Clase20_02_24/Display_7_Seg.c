const unsigned short DIGITOS[] = {
                                 0x3F, //C�digo del d�gito 0
                                 0x06, //C�digo del d�gito 1
                                 0x5B, //C�digo del d�gito 2
                                 0x4F, //C�digo del d�gito 3
                                 0x66, //C�digo del d�gito 4
                                 0x6D, //C�digo del d�gito 5
                                 0x7D, //C�digo del d�gito 6
                                 0x07, //C�digo del d�gito 7
                                 0x7F, //C�digo del d�gito 8
                                 0x6F, //C�digo del d�gito 9
                                 };
//const unsigned short DIGITOS[] = {0x3F,06,0x5b,0x4f,0x66,0x6d, 0x7d,07, 0x7f,0x6f};
void main(void){
                  unsigned short CONTADOR=0;
                  // Habilita oscilador interno a 8 Mhz o 32 Mhz
                  OSCCON.F0=0; // spll ircf ircf ircf ircf x scs scs
                  OSCCON.F1=0;
                  OSCCON.F3=0;
                  OSCCON.F4=1;
                  OSCCON.F5=1;
                  OSCCON.F6=1;
                  OSCCON.F7=1; // PLL Habilitado = 1/ deshabilitado = 0
                  TRISB = 0;
                  // Configura todos los 8 bits del puerto B como salida (O)
                  ANSELB = 0;
                  // Configura todos los 8 bits del puerto B como I/O digitales (no A/D)
                  while(1){ // Bucle infinito.
                  //asm clrwdt;
                  LATB = DIGITOS [CONTADOR];
                  // Se visualiza el digito correspondiente al n�mero guardado en la variable CONTADOR (PORTB).
                  CONTADOR++; // Se incrementa el valor del conteo.
                  delay_ms(500); // Se hace un retardo de 1/2 segundo.
                  if (contador == 10) contador = 0;
                  }
}