void main( void )
                  {
                                                                                        // Declaración de variables.
                  char DATO;
                  ANSELA = 0;
                  TRISA  = 0;
                  ANSELB = 0;
                  TRISB  = 0x22;
                  //TRISB.F2 = 1;
                  //TRISB.F5 = 0;
                  OSCCON = 0b11110000;
                  APFCON0.F7 = 0;                                                       // RX = RB1 (RB2)                  // APFCON.B7 = 0    RX = RA1 (1 == RA5)
                  APFCON1.F0 = 0;                                                       // TX = RB2 (RB5)                  // APFCON.B2 = 0    TX = RA0 (1 == RA4)
                  UART1_Init(57600);                                                     // Inicio del módulo USART.
                  Delay_ms(100);                                                        // Wait for UART module to stabilize
                  UART1_Write_Text("Bienvenido al simulador:");
                  UART1_Write(13);                                                      // Se transmite el ASCII del ENTER.
                  UART1_Write(10);                                                      // Se transmite el ASCII del retroceso del carro.

                  UART1_Write_Text("Pulse una tecla!...");
                  UART1_Write(13);                                                      // Se transmite el ASCII del ENTER.
                  UART1_Write(10);                                                      // Se transmite el ASCII del retroceso del carro.
                  while(1)                                                              // Bucle infinito.
                          {
                                                                                        // La sentencia if evalúa si un dato está listo para leer.
                          if(UART1_Data_Ready()==1)
                                                    {
                                                                                        // Se lee el DATO del buffer.
                                                    DATO = UART1_Read();
                                                                                        // Se imprime el texto de realimentación.
                                                    UART1_Write_Text("Usted pulso la tecla: ");
                                                    UART1_Write(DATO);                  // Se transmite el DATO recibido.
                                                    UART1_Write(13);                    // Se transmite el ASCII del ENTER.
                                                    UART1_Write(10);                    // Se transmite el ASCII del retroceso del carro.
                                                    }
                          }
                  }
