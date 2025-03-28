#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Realizado_Clase/Clase14_03_24_EUSART_BASICO/EUSART_Basico.c"
void main( void )
 {

 char DATO;
 ANSELA = 0;
 TRISA = 0;
 ANSELB = 0;
 TRISB = 0x22;


 OSCCON = 0b11110000;
 APFCON0.F7 = 0;
 APFCON1.F0 = 0;
 UART1_Init(57600);
 Delay_ms(100);
 UART1_Write_Text("Bienvenido al simulador:");
 UART1_Write(13);
 UART1_Write(10);

 UART1_Write_Text("Pulse una tecla!...");
 UART1_Write(13);
 UART1_Write(10);
 while(1)
 {

 if(UART1_Data_Ready()==1)
 {

 DATO = UART1_Read();

 UART1_Write_Text("Usted pulso la tecla: ");
 UART1_Write(DATO);
 UART1_Write(13);
 UART1_Write(10);
 }
 }
 }
