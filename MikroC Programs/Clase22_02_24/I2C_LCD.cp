#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/MikroC Programs/Clase22_02_24/I2C_LCD.c"
#line 1 "d:/program files/mikroelectronica/mikroc pro for pic/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;



typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 36 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/MikroC Programs/Clase22_02_24/I2C_LCD.c"
unsigned int m;
Expander_Write(uint8_t value);
void LCD_Write_Nibble(uint8_t n);
void LCD_Cmd_(uint8_t Command);
void LCD_Goto(uint8_t col, uint8_t row);
void LCD_PutC(char LCD_Char);
void LCD_Print(char* LCD_Str);
void LCD_Begin(uint8_t _i2c_addr);
void Backlight();
void noBacklight();
bit RS;
unsigned short i2c_addr, backlight_val =  0x08 ;
void Expander_Write(uint8_t value){
  I2C1_Start ();
  I2C1_Wr (i2c_addr);
  I2C1_Wr (value | backlight_val);
  I2C1_Stop ();
}
void LCD_Write_Nibble(uint8_t n){
 n |= RS;
 Expander_Write(n & 0xFB);

 asm nop;
 Expander_Write(n | 0x04);

 asm nop;
 Expander_Write(n & 0xFB);

 for (m = 0; m < 20; m = m +1){}
}
void LCD_Cmd_(uint8_t Command){
 RS = 0;
 LCD_Write_Nibble(Command & 0xF0);
 LCD_Write_Nibble((Command << 4) & 0xF0);
 if((Command ==  0x01 ) || (Command ==  0x02 ))

 for (m = 0; m < 400; m = m +1){}
}
void LCD_Goto(uint8_t col, uint8_t row){
 switch(row){
 case 2:
 LCD_Cmd_( 0xC0  + col - 1);
 break;
 case 3:
 LCD_Cmd_( 0x94  + col - 1);
 break;
 case 4:
 LCD_Cmd_( 0xD4  + col - 1);
 break;
 default:
 LCD_Cmd_( 0x80  + col - 1);
 }
}
void LCD_PutC(char LCD_Char){
 RS = 1;
 LCD_Write_Nibble(LCD_Char & 0xF0);
 LCD_Write_Nibble((LCD_Char << 4) & 0xF0);
}
void LCD_Print(char* LCD_Str){
 uint8_t i = 0;
 RS = 1;
 while(LCD_Str[i] != '\0'){
 LCD_Write_Nibble(LCD_Str[i] & 0xF0);
 LCD_Write_Nibble( (LCD_Str[i++] << 4) & 0xF0 );
 }
}
void LCD_Begin(uint8_t _i2c_addr){
 i2c_addr = _i2c_addr;
 Expander_Write(0);

 for (m = 0; m < 8000; m = m +1){}
 LCD_Cmd_(3);

 for (m = 0; m < 1000; m = m +1){}
 LCD_Cmd_(3);

 for (m = 0; m < 1000; m = m +1){}
 LCD_Cmd_(3);

 for (m = 0; m < 1000; m = m +1){}
 LCD_Cmd_( 0x02 );

 for (m = 0; m < 1000; m = m +1){}
 LCD_Cmd_(0x20 | ( 2  << 2));

 for (m = 0; m < 10000; m = m +1){}
 LCD_Cmd_( 0x0C );

 for (m = 0; m < 10000; m = m +1){}
 LCD_Cmd_( 0x01 );

 for (m = 0; m < 10000; m = m +1){}
 LCD_Cmd_( 0x04  |  0x02 );

 for (m = 0; m < 10000; m = m +1){}
}
void Backlight() {
 backlight_val =  0x08 ;
 Expander_Write(0);
}
void noBacklight(){
 backlight_val =  0x00 ;
 Expander_Write(0);
}
#line 153 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/MikroC Programs/Clase22_02_24/I2C_LCD.c"
char i = 0, text[4];
void main(){
 OSCCON = 0xf0;
 I2C1_Init(100000);
 LCD_Begin(0x4e);
 LCD_Goto(2, 1);
 LCD_Print("Hello, world!");
 while(1){

 text[0] = i / 100 + '0';
 text[1] = (i / 10) % 10 + '0';
 text[2] = i % 10 + '0';
 LCD_Goto(5, 2);
 LCD_Print(text);
 i++;
 delay_ms(500);
 }
}
