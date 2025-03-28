#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Parcial 3/Archivos_mikroC/Parcial_3_2195533.c"
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
#line 42 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Parcial 3/Archivos_mikroC/Parcial_3_2195533.c"
unsigned int m;
void Expander_Write(uint8_t value);
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

void Expander_Write(uint8_t value)
 {
  I2C1_Start ();
  I2C1_Wr (i2c_addr);
  I2C1_Wr (value | backlight_val);
  I2C1_Stop ();
 }

void LCD_Write_Nibble(uint8_t n)
 {
 n |= RS;
 Expander_Write(n & 0xFB);

 asm nop;
 Expander_Write(n | 0x04);

 asm nop;
 Expander_Write(n & 0xFB);

 for (m = 0; m < 20; m = m +1){}
 }

void LCD_Cmd_(uint8_t Command)
 {
 RS = 0;
 LCD_Write_Nibble(Command & 0xF0);
 LCD_Write_Nibble((Command << 4) & 0xF0);
 if((Command ==  0x01 ) || (Command ==  0x02 ))

 for (m = 0; m < 400; m = m +1){}
 }

void LCD_Goto(uint8_t col, uint8_t row)
 {
 switch(row)
 {
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

void LCD_PutC(char LCD_Char)
 {
 RS = 1;
 LCD_Write_Nibble(LCD_Char & 0xF0);
 LCD_Write_Nibble((LCD_Char << 4) & 0xF0);
 }

void LCD_Print(char* LCD_Str)
 {
 uint8_t i = 0;
 RS = 1;
 while(LCD_Str[i] != '\0')
 {
 LCD_Write_Nibble(LCD_Str[i] & 0xF0);
 LCD_Write_Nibble( (LCD_Str[i++] << 4) & 0xF0 );
 }
 }

void LCD_Begin(uint8_t _i2c_addr)
 {
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
 LCD_Cmd_(0x20 | ( 4  << 2));

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

void noBacklight() {
 backlight_val =  0x00 ;
 Expander_Write(0);
 }



char keypadPort at PORTA;


char tecla;
char texto[10];
char retardo_cad[10];
unsigned int retardo=100;

enum teclado_estado {n1,n2,n3,n4,en};
char estado_teclado=n1;
char tec=0;
char teclado_deco(){
 char tec;
 tec = Keypad_Key_Press();
 if (tec!=0){
 switch (tec){
 case 1:tec='7';break;
 case 2:tec='8';break;
 case 3:tec='9';break;
 case 4:tec='/';break;
 case 5:tec='4';break;
 case 6:tec='5';break;
 case 7:tec='6';break;
 case 8:tec='*';break;
 case 9:tec='1';break;
 case 10:tec='2';break;
 case 11:tec='3';break;
 case 12:tec='-';break;
 case 13:tec='E';break;
 case 14:tec='0';break;
 case 15:tec='=';break;
 case 16:tec='A';break;
 }
 return (tec);
 }
}

void teclado_estado(){
 tecla=teclado_deco();
 switch (estado_teclado){
 case n1:
 if ( (tecla!=0) && (isdigit(tecla))){
  PORTA.F5 =1;
 retardo_cad[0]=tecla;
 estado_teclado=n2;

 LCD_Goto(2,8);
 LCD_PutC(tecla);
 Delay_ms(400);
 }
 break;
 case n2:
 if ((tecla!=0) && (isdigit(tecla))){
 retardo_cad[1]=tecla;
 estado_teclado=n3;

 LCD_Goto(2,9);
 LCD_PutC(tecla);
 Delay_ms(400);
 }
 break;
 case n3:
 if ((tecla!=0) && (isdigit(tecla))){
 retardo_cad[2]=tecla;
 estado_teclado=n4;

 LCD_Goto(2,10);
 LCD_PutC(tecla);
 Delay_ms(400);
 }
 break;
 case n4:
 if ((tecla!=0) && (isdigit(tecla))){
 retardo_cad[3]=tecla;
 estado_teclado=en;

 LCD_Goto(2,11);
 LCD_PutC(tecla);
 Delay_ms(400);
 }
 break;
 case en:
 if ((tecla!=0) && (tecla!='=')){
  PORTA.F5 =0;
  PORTA.F4 =1;
 estado_teclado=n1;

 LCD_Goto(2,8);
 LCD_Print("      ");
 Delay_ms(600);
 }

 else if ((tecla!=0) && (tecla=='=')){
  PORTA.F5 =0;
 retardo_cad[4]=0;
 retardo=atoi(retardo_cad);
 estado_teclado=n1;

 LCD_Goto(2,8);
 LCD_Print("      ");
 Delay_ms(600);
 }
 break;
 }
}

void miretardo(signed int valoor){
 while (valoor>0){
 Delay_us(800);
 teclado_estado();
 valoor--;
 }
}

char usuario[5]=" ";
char fija[5]="791A";
int i=0, error=0;
void main(){

 ANSELA=0;
 OSCCON = 0b11110011;
 TRISA4_bit=0;
  PORTA.F4 =1;
 TRISA5_bit=0;
  PORTA.F5 =0;


 LCD_Cmd_( 0x01 );
 LCD_Cmd_( 0x0C );
 Keypad_Init();

 LCD_Goto(1,6);
 LCD_Print("PASSWORD: ");

 LCD_Goto(2,1);
 LCD_Print("PASS: ");

 while (1){
  PORTA.F4 =~ PORTA.F4 ;
 miretardo(retardo);

 usuario[i]= teclado();

 LCD_PutC('*');
 i++;
 if(i==4){
 LCD_Cmd_(1);

 LCD_Goto(1,1);
 LCD_Print("VALIDANDO");
 for(i=0; i<=3; i++){
 if(fija[i] != usuario[i]){
 error++;
 }

 LCD_Goto(2,i+1);
 LCD_PutC('*');
 delay_ms(200);
 }
 if(error==0){
 verde=1;
 rojo = 0;
 LCD_Cmd_(1);

 LCD_Goto(1,1);
 LCD_Print("CONTRASENA VALIDA");
 }
 else{
 verde=0;
 rojo = 1;
 LCD_Cmd_(1);

 LCD_Goto(1,1);
 LCD_Print("ERRPR CONTRASENA");
 }
 delay_ms(2000);
 LCD_Cmd_(1);

 LCD_Goto(1,1);
 LCD_Print("DIGITE CONTRASENA";

 LCD_Goto(2,1);
 LCD_Print("PASS:");
 i=0;
 error=0;
 }
 }
}




 while(1){


 }
}
