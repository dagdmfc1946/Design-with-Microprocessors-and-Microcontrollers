#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Clase12_03_24/class12_03_24.c"
#line 19 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Clase12_03_24/class12_03_24.c"
sbit MAX7219_CS_LOAD at RB5_bit;
sbit MAX7219_CS_LOAD_DIRECTION at TRISB5_bit;


void MAX7219_write(char reg1, char data1)
 {
 MAX7219_CS_LOAD = 0;
 SPI1_Write(reg1);
 SPI1_Write(data1);
 MAX7219_CS_LOAD = 1;
 }

void MAX7219_init()
 {
 SPI1_Init();
 MAX7219_write( 0x09 , 0xFF );
 MAX7219_write( 0x0A , 0x0F );
 MAX7219_write( 0x0B , 0x07 );
 MAX7219_write( 0x0C , 0x01 );
 MAX7219_write( 0x0F , 0x01 );
 MAX7219_write( 0x0F , 0x00 );
 }

void Max7219Print(unsigned long Number, unsigned short NumberOfDigits)
 {
 long i;
 for(i=1;Number>0||i-NumberOfDigits<=0;Number/=10,i++)
 {
 MAX7219_CS_LOAD=0;
 SPI1_Write(i);
 SPI1_Write(Number%10);
 MAX7219_CS_LOAD=1;
 }
 }

void Max7219DisplayOff()
 {
 MAX7219_CS_LOAD=0;
 SPI1_Write( 0x0C );
 SPI1_Write( 0x00 );
 MAX7219_CS_LOAD=1;
 }

void Max7219DisplayOn()
 {
 MAX7219_CS_LOAD=0;
 SPI1_Write( 0x0C );
 SPI1_Write( 0x01 );
 MAX7219_CS_LOAD=1;
 }

void Max7219UpdateIntensity(char OnValue)
 {
 if(OnValue>=0&&OnValue<=15)
 {
 MAX7219_CS_LOAD=0;
 SPI1_Write(0x0a);
 SPI1_Write(OnValue);
 MAX7219_CS_LOAD=1;
 }
 }
unsigned long i;

void main()
 {

 OSCCON = 0b01110000;
 TRISB = 0;
 ANSELB = 0;
 MAX7219_CS_LOAD = 0;
 MAX7219_CS_LOAD_DIRECTION = 0;
 SPI1_Init();

 MAX7219_init();

 Max7219DisplayOn();
 Delay_ms(100);
 while(1)
 {
 for(i=12345678;i<99999999;i++)
 {
 Max7219Print(i,7);
 Delay_ms(1000);
 }
 }
 }
