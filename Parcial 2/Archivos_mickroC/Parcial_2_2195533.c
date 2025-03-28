// PARCIAL 2 - DISEÑO CON uP y uC. 2024-1.
// NOMBRE: Diego Andrés García Díaz.
// CÓDIGO: 2195533.
// -----------------------------------------------------------------------------

#define LED_PIN     PORTA.F7
#define MIN_PERIOD  100  // Periodo mínimo de oscilación (en ms)
#define MAX_PERIOD  8000 // Periodo máximo de oscilación (en ms)

// LCD module connections
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
// End LCD module connections

// Keypad module connections
char keypadPort at PORTB;
char period_str[8]; // Cadena de caracteres para almacenar el periodo
char keypad_map[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
// Keypad module connections

void main() {
    int period = 100; // Inicializar el periodo con el mínimo
    
    ANSELA = 0;  // Configurar pines A como digitales
    ANSELB = 0;  // Configurar pines B como digitales
    
    TRISA = 0x00; // Configurar puerto A como salida (para LCD)
    TRISB = 0xFF; // Configurar puerto B como entrada (para teclado matricial)
    TRISA7_bit = 0; // Configurar RA7 como salida (para LED)
    
    // Inicializar LCD
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1, 1, "Periodo: ");
    Lcd_Out(2, 1, "100 ms");
    
    // Inicializar teclado matricial
    Keypad_Init();
    
    //char period_str[8]; // Cadena de caracteres para almacenar el periodo
    
    while (1) {
      char key = Keypad_Key_Click();
      if (key != 0) {
            // Realimentación visual
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Out(1, 1, "Tecla pulsada:");  
            Lcd_Chr(2, 5, key);
            // Ajustar el periodo según la tecla pulsada
            switch (key) {
                case 'A': // Incrementar el periodo
                    if (period < 8000)
                        period += 100;
                    break;
                case 'B': // Decrementar el periodo
                    if (period > 100)
                        period -= 100;
                    break;
                default:
                    break;
            }
            // Convertir el periodo a una cadena de caracteres
            IntToStr(period, period_str);
            Lcd_Out(2, 8, period_str); // Mostrar el nuevo periodo en el LCD
            Delay_ms(5);
            //Delay_ms(period / 2); // Esperar la mitad del periodo
        }
        // Encender y apagar el LED con el periodo especificado
        RA7_bit = !RA7_bit;
        Delay_ms(5);
        //Delay_ms(period / 2);
    }
}