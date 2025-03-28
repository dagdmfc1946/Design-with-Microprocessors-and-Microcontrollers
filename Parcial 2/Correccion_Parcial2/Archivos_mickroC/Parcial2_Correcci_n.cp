#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Parcial 2/Archivos_mickroC/Parcial2_Correcci_n.c"





char keypadPort at PORTB;
unsigned int T_variable = 200;
unsigned int T_end = 100;


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


sbit LED_PIN at LATA7_bit;

char key = 0;
char f_keypad(){
 unsigned int T_variable;
 key = Keypad_Key_Click();
 if (key != 0){
 switch (key){
 case 1: T_variable = 100; Lcd_Out(2, 8, "100 "); break;
 case 2: T_variable = 500; Lcd_Out(2, 8, "500 "); break;
 case 3: T_variable = 1000; Lcd_Out(2, 8, "1000"); break;
 case 4: T_variable = 1500; Lcd_Out(2, 8, "1500"); break;
 case 5: T_variable = 2000; Lcd_Out(2, 8, "2000"); break;
 case 6: T_variable = 2500; Lcd_Out(2, 8, "2500"); break;
 case 7: T_variable = 3000; Lcd_Out(2, 8, "3000"); break;
 case 8: T_variable = 3500; Lcd_Out(2, 8, "3500"); break;
 case 9: T_variable = 4500; Lcd_Out(2, 8, "4500"); break;
 case 10: T_variable = 5000; Lcd_Out(2, 8, "5000"); break;
 case 11: T_variable = 5500; Lcd_Out(2, 8, "5500"); break;
 case 12: T_variable = 6000; Lcd_Out(2, 8, "6000"); break;
 case 13: T_variable = 6500; Lcd_Out(2, 8, "6500"); break;
 case 14: T_variable = 7000; Lcd_Out(2, 8, "7000"); break;
 case 15: T_variable = 7500; Lcd_Out(2, 8, "7500"); break;
 case 16: T_variable = 8000; Lcd_Out(2, 8, "8000"); break;
 }
 Delay_us(800);
 T_end = T_variable/2;
 return(T_end);
 }
}

void Periodo_Variable(signed int Period){
 int i;
 for (i = Period; i > 0; i--){
 Delay_us(800);
 f_keypad();


 }
}

void main() {
 OSCCON = 0b11110011;
 ANSELA = 0;
 ANSELB = 0;
 TRISA = 0x00;
 TRISB = 0xFF;
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1, 1, "T:  100-8000 [ms]");
 Lcd_Out(2,1, "New T: ");
 Lcd_Out(2,13, "[ms]");
 Keypad_Init();
 TRISA7_bit = 0;
 while (1){

 LED_PIN = ~LED_PIN;
 Periodo_Variable(T_end);


 }
}
