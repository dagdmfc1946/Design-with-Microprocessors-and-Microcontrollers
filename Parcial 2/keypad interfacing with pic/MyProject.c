/* KEYPAD INTERFACING WITH PIC16F877A */
  int kpi;
// Keypad module connections
char keypadPort at PORTD;
// End Keypad module connections

// LCD Module connections
sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;

sbit LCD_D7 at RB7_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D4 at RB4_bit;
// End LCD module connections

// LCD Pin direction
sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;

sbit LCD_D7_Direction at TRISB7_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB4_bit;
// End of LCD Pin direction

void main() {
Lcd_Init();                         // Initialize LCD
Lcd_Cmd(_LCD_CLEAR);               // Clear Display
Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor Off
Lcd_Out(1,1,"KEYPAD INTERFACE");  // Write "KEYPAD INTERFACE" in the first row
delay_ms(500);                     // Delay of 0.5s
Lcd_Cmd(_LCD_CLEAR);              // Clear Display
delay_ms(500);                    // Delay of 0.5s
Keypad_Init();                   // Initialize Keypad
Lcd_Out(1,1,"PRESS A KEY");      // Write "PRESS A KEY" in the first row
delay_ms(500);                    // Delay of 0.5s
Lcd_Cmd(_LCD_CLEAR);              // Clear Display
 do
  {
    kpi = 0; // Reset key code variable
    // Wait for key to be pressed and released
    do
      kpi = Keypad_Key_Click(); // Store key code in kpi variable
    while (!kpi);
    switch (kpi)
    {
      case 1: kpi = 55; break; // 7 - Cmp kpi with equivalent ASCII code of 7, break if equal
      case 2: kpi = 52; break; // 4
      case 3: kpi = 49; break; // 1
      case 4: kpi = 32; break; // Space
      case 5: kpi = 56; break; // 8
      case 6: kpi = 53; break; // 5
      case 7: kpi = 50; break; // 2
      case 8: kpi = 48; break; // 0
      case 9: kpi = 57; break; // 9
      case 10: kpi = 54; break; // 6
      case 11: kpi = 51; break; // 3
      case 12: kpi = 61; break; // =
      case 13: kpi = 47; break; // /
      case 14: kpi = 42; break; // x
      case 15: kpi = 45; break; // -
      case 16: kpi = 43; break; // +
    }
    Lcd_Chr(1, 2, kpi); // Print key ASCII value on Lcd
  } while (1);
 }