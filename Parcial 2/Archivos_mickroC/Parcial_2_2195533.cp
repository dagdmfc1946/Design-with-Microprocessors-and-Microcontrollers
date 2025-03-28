#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Parcial 2/Archivos_mickroC/Parcial_2_2195533.c"










sbit LCD_RS at RA0_bit;
sbit LCD_EN at RA1_bit;
sbit LCD_D4 at RA2_bit;
sbit LCD_D5 at RA3_bit;
sbit LCD_D6 at RA4_bit;
sbit LCD_D7 at RA6_bit;

sbit LCD_RS_Direction at TRISA0_bit;
sbit LCD_EN_Direction at TRISA1_bit;
sbit LCD_D4_Direction at TRISA2_bit;
sbit LCD_D5_Direction at TRISA3_bit;
sbit LCD_D6_Direction at TRISA4_bit;
sbit LCD_D7_Direction at TRISA6_bit;



char keypadPort at PORTB;
char period_str[8];
char keypad_map[4][4] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};


void main() {
 int period = 100;

 ANSELA = 0;
 ANSELB = 0;

 TRISA = 0x00;
 TRISB = 0xFF;
 TRISA7_bit = 0;


 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1, 1, "Periodo: ");
 Lcd_Out(2, 1, "100 ms");


 Keypad_Init();



 while (1) {
 char key = Keypad_Key_Click();
 if (key != 0) {

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1, 1, "Tecla pulsada:");
 Lcd_Chr(2, 5, key);

 switch (key) {
 case 'A':
 if (period < 8000)
 period += 100;
 break;
 case 'B':
 if (period > 100)
 period -= 100;
 break;
 default:
 break;
 }

 IntToStr(period, period_str);
 Lcd_Out(2, 8, period_str);
 Delay_ms(5);

 }

 RA7_bit = !RA7_bit;
 Delay_ms(5);

 }
}
