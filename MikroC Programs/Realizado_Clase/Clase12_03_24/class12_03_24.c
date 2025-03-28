// Tomado de https://microcontrollerslab.com/max7219-interfacing-8-digit-7-segment-display-pic16f877a/
//------------------------------------------------------------------------------
#define DECODE_MODE_REG     0x09                                                // Ver tabla 2 MAX 7219
#define INTESITY_REG        0x0A
#define SCAN_LIMIT_REG      0x0B
#define SHUTDOWN_REG        0x0C
#define DISPLAY_TEST_REG    0x0F
//------------------------------------------------------------------------------
#define DISABLE_DECODE      0x00
#define DECODE_ALL          0xFF
#define BRIGHTNESS          0x0F
#define SCAN_LOW_NIBBLE     0x03
#define SCAN_ALL_DIGITS     0x07
#define SHUTDOWN_MODE       0x00
#define NORMAL_OPERATION    0x01
#define DISABLE_TEST_MODE   0x00
#define ENABLE_TEST_MODE    0x01
//------------------------------------------------------------------------------
sbit MAX7219_CS_LOAD at RB5_bit;                                                // Debe definirse el de SS (MOSI, MISO y SCLK esta definidos por HW (En SPI por SW, son reubicables)
sbit MAX7219_CS_LOAD_DIRECTION at TRISB5_bit;


void MAX7219_write(char reg1, char data1)
                    {
                      MAX7219_CS_LOAD  = 0;
                      SPI1_Write(reg1);
                      SPI1_Write(data1);
                      MAX7219_CS_LOAD  = 1;
                    }

void MAX7219_init()
                    {
                      SPI1_Init();
                      MAX7219_write(DECODE_MODE_REG,DECODE_ALL);
                      MAX7219_write(INTESITY_REG,BRIGHTNESS);
                      MAX7219_write(SCAN_LIMIT_REG,SCAN_ALL_DIGITS);
                      MAX7219_write(SHUTDOWN_REG,NORMAL_OPERATION);
                      MAX7219_write(DISPLAY_TEST_REG,ENABLE_TEST_MODE);
                      MAX7219_write(DISPLAY_TEST_REG,DISABLE_TEST_MODE);
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
                      SPI1_Write(SHUTDOWN_REG);
                      SPI1_Write(DISABLE_DECODE);
                      MAX7219_CS_LOAD=1;
                    }

void Max7219DisplayOn()
                    {
                      MAX7219_CS_LOAD=0;
                      SPI1_Write(SHUTDOWN_REG);
                      SPI1_Write(NORMAL_OPERATION);
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
           MAX7219_CS_LOAD = 0;                                                 // Deselect DAC
           MAX7219_CS_LOAD_DIRECTION = 0;                                       // Set CS# pin as Output
           SPI1_Init();                                                         // Initialize SPI module

           MAX7219_init();

           Max7219DisplayOn();
           Delay_ms(100);
           while(1)
                  {
                    for(i=12345678;i<99999999;i++)                              // Count From 0 To 99999999 And Display on 8 Seven segments
                                        {
                                           Max7219Print(i,7);
                                           Delay_ms(1000);
                                        }
                  }
          }
