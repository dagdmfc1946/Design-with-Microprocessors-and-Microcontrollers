char  keypadPort at PORTB;
char texto[10],tecla,tex[4];
int sins;
unsigned short kp;
unsigned int retardo=100;
unsigned int final=50;
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

sbit led at LATA7_bit;
char tec=0;
char teclado_deco()
{
    //char tec=0;
    unsigned int retardo;
    tec = Keypad_Key_Press();     //mejor
    if (tec!=0)
    {
               sins=11;
               ByteToStr(sins,tex);

               Lcd_Out(1,8,tex);
        switch (tec)
        {
            case 1: retardo=100;Lcd_Out(2,8, "100 "); break;
            case 2: retardo=300;Lcd_Out(2,8, "300 "); break;
            case 3: retardo=700;Lcd_Out(2,8, "700 "); break;
            case 4: retardo=800;Lcd_Out(2,8, "800 "); break;
            case 5: retardo=1000;Lcd_Out(2,8, "1000"); break;
            case 6: retardo=1500;Lcd_Out(2,8, "1500"); break;
            case 7: retardo=2000;Lcd_Out(2,8, "2000"); break;
            case 8: retardo=2500;Lcd_Out(2,8, "2500"); break;
            case 9: retardo=3500;Lcd_Out(2,8, "3500"); break;
            case 10: retardo=4000;Lcd_Out(2,8, "4000"); break;
            case 11: retardo=5000;Lcd_Out(2,8, "5000"); break;
            case 12: retardo=6000;Lcd_Out(2,8, "6000"); break;
            case 13: retardo=6500;Lcd_Out(2,8, "6500"); break;
            case 14: retardo=7000;Lcd_Out(2,8, "7000"); break;
            case 15: retardo=7500;Lcd_Out(2,8, "7500"); break;
            case 16: retardo=8000;Lcd_Out(2,8, "8000"); break;
        }//Fin del switch
        Delay_us(900);
        final=retardo/2;

        return (final);
    }//si hay una tecla valida
}

void miretardo(signed int valor)
{
    while (valor > 0)
    {
        Delay_us(900);
        teclado_deco();
        valor--;
    }
}

void main() {
    char key_pressed;
    OSCCON = 0b01110000;
    ANSELA=0;
    ANSELB=0;
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1, 1, "TECLADO");
    Lcd_Out(2, 1, "ms");
    Keypad_Init();

    TRISA7_bit = 0; //salida led
    led = 1;

    Lcd_Out(2,8,"100 ");
    // Bucle principal
    while (1) {
        led = ~led; //invierte el led
        miretardo(final);

    }
}