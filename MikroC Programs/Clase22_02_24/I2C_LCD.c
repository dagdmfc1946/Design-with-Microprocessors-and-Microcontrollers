// // RB1 Pin 7 === SDA; RB4 pin 10 === SCL. PIC16F1827
// // RA2 Pin 5 === SDA; RA1 pin 06 === SCL. PIC12F1822
// #include <stdint.h>
// //#define i2c_soft
// #ifndef SOFT_I2C
// #define LCD_I2C_Start I2C1_Start
// #define LCD_I2C_Write I2C1_Wr
// #define LCD_I2C_Stop I2C1_Stop
// #else
// #define LCD_I2C_Start Soft_I2C_Start
// #define LCD_I2C_Write Soft_I2C_Write
// #define LCD_I2C_Stop Soft_I2C_Stop
// #endif

// #define LCD_BACKLIGHT             0x08
// #define LCD_NOBACKLIGHT           0x00
// #define LCD_FIRST_ROW             0x80
// #define LCD_SECOND_ROW            0xC0
// #define LCD_THIRD_ROW             0x94
// #define LCD_FOURTH_ROW            0xD4
// #define LCD_CLEAR                 0x01
// #define LCD_RETURN_HOME           0x02
// #define LCD_ENTRY_MODE_SET        0x04
// #define LCD_CURSOR_OFF            0x0C
// #define LCD_UNDERLINE_ON          0x0E
// #define LCD_BLINK_CURSOR_ON       0x0F
// #define LCD_MOVE_CURSOR_LEFT      0x10
// #define LCD_MOVE_CURSOR_RIGHT     0x14
// #define LCD_TURN_ON               0x0C
// #define LCD_TURN_OFF              0x08
// #define LCD_SHIFT_LEFT            0x18
// #define LCD_SHIFT_RIGHT           0x1E
// #ifndef LCD_TYPE
// #define LCD_TYPE 2 // 0=5x7, 1=5x10, 2=2 lines
// #endif
// unsigned int m; //--------------------------------------------------------------------void
// Expander_Write(uint8_t value);
// void LCD_Write_Nibble(uint8_t n);
// void LCD_Cmd_(uint8_t Command);
// void LCD_Goto(uint8_t col, uint8_t row);
// void LCD_PutC(char LCD_Char);
// void LCD_Print(char* LCD_Str);
// void LCD_Begin(uint8_t _i2c_addr);
// void Backlight();
// void noBacklight();
// bit RS;
// unsigned short i2c_addr, backlight_val = LCD_BACKLIGHT;
// void Expander_Write(uint8_t value){
     // LCD_I2C_Start();
     // LCD_I2C_Write(i2c_addr);
     // LCD_I2C_Write(value | backlight_val);
     // LCD_I2C_Stop();
// }
// void LCD_Write_Nibble(uint8_t n){ //ok
     // n |= RS;
     // Expander_Write(n & 0xFB);   
     // //delay_us(1);
     // asm nop; //0,6 uS
     // Expander_Write(n | 0x04);
     // //delay_us(1);
     // asm nop; //0,6 uS
     // Expander_Write(n & 0xFB);
     // //delay_us(100);
     // for (m = 0; m < 20; m = m +1){}//asm: nop 1 = 5 us
// }
// void LCD_Cmd_(uint8_t Command){ //ok
     // RS = 0;
     // LCD_Write_Nibble(Command & 0xF0);
     // LCD_Write_Nibble((Command << 4) & 0xF0);
     // if((Command == LCD_CLEAR) || (Command == LCD_RETURN_HOME))
     // //delay_ms(2);
     // for (m = 0; m < 400; m = m +1){}//asm: nop 1 = 5 us
// }
// void LCD_Goto(uint8_t col, uint8_t row){
     // switch(row){
                 // case 2:
                 // LCD_Cmd_(LCD_SECOND_ROW + col - 1);
                 // break;
                 // case 3:
                 // LCD_Cmd_(LCD_THIRD_ROW + col - 1);
                 // break;
                 // case 4:
                 // LCD_Cmd_(LCD_FOURTH_ROW + col - 1);
                 // break;
                 // default: // case 1:
                 // LCD_Cmd_(LCD_FIRST_ROW + col - 1);
                 // }
// }
// void LCD_PutC(char LCD_Char){
     // RS = 1;
     // LCD_Write_Nibble(LCD_Char & 0xF0);
     // LCD_Write_Nibble((LCD_Char << 4) & 0xF0);
// }
// void LCD_Print(char* LCD_Str){
     // uint8_t i = 0;
     // RS = 1;
     // while(LCD_Str[i] != '\0'){
                      // LCD_Write_Nibble(LCD_Str[i] & 0xF0);
                      // LCD_Write_Nibble( (LCD_Str[i++] << 4) & 0xF0 );
                      // }
// }
// void LCD_Begin(uint8_t _i2c_addr){ // ok
     // i2c_addr = _i2c_addr;
     // Expander_Write(0);
     // //delay_ms(40);
     // for (m = 0; m < 8000; m = m +1){}//asm: nop 1 = 5 us
     // LCD_Cmd_(3);
     // //delay_ms(5);
     // for (m = 0; m < 1000; m = m +1){}//asm: nop 1 = 5 us
     // LCD_Cmd_(3);
     // //delay_ms(5);
     // for (m = 0; m < 1000; m = m +1){}//asm: nop 1 = 5 us
     // LCD_Cmd_(3);
     // //delay_ms(5);
     // for (m = 0; m < 1000; m = m +1){}//asm: nop 1 = 5 us
     // LCD_Cmd_(LCD_RETURN_HOME);
     // //delay_ms(5);
     // for (m = 0; m < 1000; m = m +1){}//asm: nop 1 = 5 us
     // LCD_Cmd_(0x20 | (LCD_TYPE << 2));
     // //delay_ms(50);
     // for (m = 0; m < 10000; m = m +1){}//asm: nop 1 = 5 us
     // LCD_Cmd_(LCD_TURN_ON);
     // //delay_ms(50);
     // for (m = 0; m < 10000; m = m +1){}//asm: nop 1 = 5 us
     // LCD_Cmd_(LCD_CLEAR);
     // //delay_ms(50);
     // for (m = 0; m < 10000; m = m +1){}//asm: nop 1 = 5 us
     // LCD_Cmd_(LCD_ENTRY_MODE_SET | LCD_RETURN_HOME);
     // //delay_ms(50);
     // for (m = 0; m < 10000; m = m +1){}//asm: nop 1 = 5 us
// }
// void Backlight() { //ok
     // backlight_val = LCD_BACKLIGHT;
     // Expander_Write(0);
// }
// void noBacklight(){//ok
     // backlight_val = LCD_NOBACKLIGHT;
     // Expander_Write(0);
// }
// //The PIC12F1822 I2C module with SDA on pin RA2 (#5) and SCL on pin RA1 (#6).
// //PIC12F1822 microcontroller runs with its internal oscillator @ 8 MHz, MCLR pin is configured as
// //an input pin.
// /*
// * Interfacing PIC12F1822 microcontroller with I2C LCD screen
// * C Code for mikroC PRO for PIC compiler
// * Internal oscillator used @ 8MHz
// * This is a free software with NO WARRANTY
// * http://simple-circuit.com/
// */
// // include I2C LCD driver source file
// //#include "I2C_LCD1.c"
// //#include "C:\descargas\I2C_LCD1.c"
// char i = 0, text[4];
// void main(){
     // OSCCON = 0xf0; // set internal oscillator to 32 MHz
     // I2C1_Init(100000); // initialize I2C bus with clock frequency of 100kHz
     // LCD_Begin(0x4e); // 7e PCF8574A initialize LCD module with I2C address = 0x4E 01001110 esp32 dir 27 0010 0111
     // LCD_Goto(2, 1); // move cursor to column 2, row 1
     // LCD_Print("Hello, world!");
     // while(1){ 
             // // store 'i' into 'text' ( '0' for ASCII format )
             // text[0] = i / 100 + '0'; // store hundreds
             // text[1] = (i / 10) % 10 + '0'; // store tens
             // text[2] = i % 10 + '0'; // store ones
             // LCD_Goto(5, 2); // move cursor to column 5, row 2
             // LCD_Print(text); // print 'text'
             // i++; // increment i
             // delay_ms(500); // wait 0.5 second
             // }
// }



/**********************************************************************************
 * I2C_LCD.c                                                                      *
 * MikroC PRO for PIC compiler LCD driver for I2C LCDs with HD44780 compliant     *
 *   controllers.                                                                 *
 * https://simple-circuit.com/                                                    *
 *                                                                                *
 *********************************************************************************/
//    RB1 Pin 7 === SDA; RB4 pin 10 === SCL. PIC16F1827

//    RA2 Pin 5 === SDA; RA1 pin 06 === SCL. PIC12F1822

// ***
#include <stdint.h>
//#define i2c_soft

#ifndef  SOFT_I2C
#define LCD_I2C_Start  I2C1_Start
#define LCD_I2C_Write  I2C1_Wr
#define LCD_I2C_Stop   I2C1_Stop
#else
#define LCD_I2C_Start  Soft_I2C_Start
#define LCD_I2C_Write  Soft_I2C_Write
#define LCD_I2C_Stop   Soft_I2C_Stop
#endif

#define LCD_BACKLIGHT          0x08
#define LCD_NOBACKLIGHT        0x00
#define LCD_FIRST_ROW          0x80
#define LCD_SECOND_ROW         0xC0
#define LCD_THIRD_ROW          0x94
#define LCD_FOURTH_ROW         0xD4
#define LCD_CLEAR              0x01
#define LCD_RETURN_HOME        0x02
#define LCD_ENTRY_MODE_SET     0x04
#define LCD_CURSOR_OFF         0x0C
#define LCD_UNDERLINE_ON       0x0E
#define LCD_BLINK_CURSOR_ON    0x0F
#define LCD_MOVE_CURSOR_LEFT   0x10
#define LCD_MOVE_CURSOR_RIGHT  0x14
#define LCD_TURN_ON            0x0C
#define LCD_TURN_OFF           0x08
#define LCD_SHIFT_LEFT         0x18
#define LCD_SHIFT_RIGHT        0x1E

#ifndef LCD_TYPE
#define LCD_TYPE 2           // 0=5x7, 1=5x10, 2=2 lines
#endif

unsigned int m; //---------------------------------------------------------------------
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
unsigned short i2c_addr, backlight_val = LCD_BACKLIGHT;

void Expander_Write(uint8_t value)
                                  {
                                    LCD_I2C_Start();
                                    LCD_I2C_Write(i2c_addr);
                                    LCD_I2C_Write(value | backlight_val);
                                    LCD_I2C_Stop();
                                  }

void LCD_Write_Nibble(uint8_t n)   //ok
                                {
                                  n |= RS;
                                  Expander_Write(n & 0xFB);
                                  //delay_us(1);
                                  asm nop;  //0,6 uS
                                  Expander_Write(n | 0x04);
                                  //delay_us(1);
                                  asm nop;  //0,6 uS
                                  Expander_Write(n & 0xFB);
                                  //delay_us(100);
                                  for (m = 0; m < 20; m = m +1){}//asm: nop   1 = 5 us
                                  }

void LCD_Cmd_(uint8_t Command)   //ok
                              {
                                RS = 0;
                                LCD_Write_Nibble(Command & 0xF0);
                                LCD_Write_Nibble((Command << 4) & 0xF0);
                                if((Command == LCD_CLEAR) || (Command == LCD_RETURN_HOME))
                                  //delay_ms(2);
                                  for (m = 0; m < 400; m = m +1){}//asm: nop   1 = 5 us
                              }

void LCD_Goto(uint8_t col, uint8_t row)
                                        {
                                          switch(row)
                                          {
                                            case 2:
                                              LCD_Cmd_(LCD_SECOND_ROW + col - 1);
                                              break;
                                            case 3:
                                              LCD_Cmd_(LCD_THIRD_ROW  + col - 1);
                                              break;
                                            case 4:
                                              LCD_Cmd_(LCD_FOURTH_ROW + col - 1);
                                            break;
                                            default:      // case 1:
                                              LCD_Cmd_(LCD_FIRST_ROW  + col - 1);
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

void LCD_Begin(uint8_t _i2c_addr)             // ok
                                {
                                  i2c_addr = _i2c_addr;
                                  Expander_Write(0);

                                  //delay_ms(40);
                                  for (m = 0; m < 8000; m = m +1){}//asm: nop   1 = 5 us
                                  LCD_Cmd_(3);
                                  //delay_ms(5);
                                  for (m = 0; m < 1000; m = m +1){}//asm: nop   1 = 5 us
                                  LCD_Cmd_(3);
                                  //delay_ms(5);
                                  for (m = 0; m < 1000; m = m +1){}//asm: nop   1 = 5 us
                                  LCD_Cmd_(3);
                                  //delay_ms(5);
                                  for (m = 0; m < 1000; m = m +1){}//asm: nop   1 = 5 us
                                  LCD_Cmd_(LCD_RETURN_HOME);
                                  //delay_ms(5);
                                  for (m = 0; m < 1000; m = m +1){}//asm: nop   1 = 5 us
                                  LCD_Cmd_(0x20 | (LCD_TYPE << 2));
                                  //delay_ms(50);
                                  for (m = 0; m < 10000; m = m +1){}//asm: nop   1 = 5 us
                                  LCD_Cmd_(LCD_TURN_ON);
                                  //delay_ms(50);
                                  for (m = 0; m < 10000; m = m +1){}//asm: nop   1 = 5 us
                                  LCD_Cmd_(LCD_CLEAR);
                                  //delay_ms(50);
                                  for (m = 0; m < 10000; m = m +1){}//asm: nop   1 = 5 us
                                  LCD_Cmd_(LCD_ENTRY_MODE_SET | LCD_RETURN_HOME);
                                  //delay_ms(50);
                                  for (m = 0; m < 10000; m = m +1){}//asm: nop   1 = 5 us
                                }

void Backlight() {                      //ok
                    backlight_val = LCD_BACKLIGHT;
                    Expander_Write(0);
                 }

void noBacklight() {                   //ok
                      backlight_val = LCD_NOBACKLIGHT;
                      Expander_Write(0);
                    }

// ***




char i = 0, text[4];

void main()
          {
TRISA = 0;                               //estado en 0 = pin de salida
    ANSELA = 0;                              // ansel en 0 = pin digital
    OSCCON = 0b11110011;             //debemos especificarle al PIC que vamos a trabajar a 32MHz usando el PLL (8x4 MHz) ya que necesitamos una
                                       //alta velocidad para que no se vean los cambios de la señal que se le envian a los leds y se vea una imagen "estatica" o "fija" para el ojo humano
     LATA.F1 = 0;

                                                                                // initialize LCD module with I2C address = 0x4E  0100 1110     esp32 dir 27   0010 0111

            LCD_Goto(2, 1);                                                     // move cursor to column 2, row 1
            LCD_Print("Hello, world!");

            while(1)
                    {                                                                                // store 'i' into 'text' ( '0' for ASCII format )
                      text[0] =  i / 100      + '0';                            // store hundreds
                      text[1] = (i / 10) % 10 + '0';                            // store tens
                      text[2] =  i % 10       + '0';                            // store ones

                      LCD_Goto(5, 2);                                           // move cursor to column 5, row 2
                      LCD_Print(text);                                          // print 'text'

                      i++;                                                      // increment i
                      delay_ms(500);                                            // wait 0.5 second
                    }
                    

         }