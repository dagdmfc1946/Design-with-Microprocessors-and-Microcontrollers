// PARCIAL 2 (Corrección) - DISEÑO CON uP y uC. 2024-1.
// NOMBRE: Diego Andrés García Díaz.
// CÓDIGO: 2195533.
// -----------------------------------------------------------------------------

char keypadPort at PORTB;  // Puesto del micro para conectar el teclado.
unsigned int T_variable = 200;   // Variable que contiene un retardo.
unsigned int T_end = 100;        // Variable que contiene la mitad del retardo.

// LCD module connections.
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
// End LCD module connections.

sbit LED_PIN at LATA7_bit;  // Se define el pin LATA7 del micro para controlar el LED.

char key = 0; // Variable que almacena la tecla presionada.
char f_keypad(){ // Función para detectar que tecla del teclado se presiono.
    unsigned int T_variable;
    key = Keypad_Key_Click();  // Se detecta la tecla presionada.
    if (key != 0){ // Se verifica si se presiona alguna tecla.
        switch (key){ // Según la tecla presionada se realiza la acción correspondiente.
            case 1:  T_variable = 100;  Lcd_Out(2, 8, "100 "); break;  // Periodo mínimo.
            case 2:  T_variable = 500;  Lcd_Out(2, 8, "500 "); break;
            case 3:  T_variable = 1000; Lcd_Out(2, 8, "1000"); break;
            case 4:  T_variable = 1500; Lcd_Out(2, 8, "1500"); break;
            case 5:  T_variable = 2000; Lcd_Out(2, 8, "2000"); break;
            case 6:  T_variable = 2500; Lcd_Out(2, 8, "2500"); break;
            case 7:  T_variable = 3000; Lcd_Out(2, 8, "3000"); break;
            case 8:  T_variable = 3500; Lcd_Out(2, 8, "3500"); break;
            case 9:  T_variable = 4500; Lcd_Out(2, 8, "4500"); break;
            case 10: T_variable = 5000; Lcd_Out(2, 8, "5000"); break;
            case 11: T_variable = 5500; Lcd_Out(2, 8, "5500"); break;
            case 12: T_variable = 6000; Lcd_Out(2, 8, "6000"); break;
            case 13: T_variable = 6500; Lcd_Out(2, 8, "6500"); break;
            case 14: T_variable = 7000; Lcd_Out(2, 8, "7000"); break;
            case 15: T_variable = 7500; Lcd_Out(2, 8, "7500"); break;
            case 16: T_variable = 8000; Lcd_Out(2, 8, "8000"); break;  // Periodo máximo.
        }
        Delay_us(800); // Breve retardo para visualizar mejor los datos en la LCD.
        T_end = T_variable/2;
        return(T_end);
    }
}

void Periodo_Variable(signed int Period){  // Función para tener un periodo variable
    int i;
    for (i = Period; i > 0; i--){
        Delay_us(800);
        f_keypad(); // Se llama la función y se ejecuta "Period" veces,
                    // También maneja la entrada del teclado y realiza la acción
                    // correspondiente según la tecla presionada.
    }
}

void main() {
    OSCCON = 0b11110011;  // Configurar el oscilador interno a 32 MHz.
    ANSELA = 0;           // Configurar pines A como digitales.
    ANSELB = 0;           // Configurar pines B como digitales.
    TRISA = 0x00; // Configurar puerto A como salida (para LCD).
    TRISB = 0xFF; // Configurar puerto B como entrada (para teclado matricial).
    Lcd_Init();           // Inicializar LCD.
    Lcd_Cmd(_LCD_CLEAR);  // Limpiar pantalla.
    Lcd_Cmd(_LCD_CURSOR_OFF); // Desactiva el cursor.
    Lcd_Out(1, 1, "T:  100-8000 [ms]"); // Mensaje en LCD.
    Lcd_Out(2,1, "New T: ");  // Mensaje en LCD.
    Lcd_Out(2,13, "[ms]");    // Mensaje en LCD.
    Keypad_Init();        // Inicializar teclado matricial.
    TRISA7_bit = 0; // Configurar RA7 como salida (para LED).
    while (1){  // Bucle para poder visualizar el periodo de oscilación del LED
                // (Se finaliza el bucle manualmente).
        LED_PIN = ~LED_PIN;  // Estado del LED (ON - OFF).
        Periodo_Variable(T_end);  // Se llama la función que controla el periodo, acá se
                                 // controla la duración del nuevo periodo de oscilación que
                                 // tendrá el LED, según este configurada la función "f_keypad()". 
    }
}