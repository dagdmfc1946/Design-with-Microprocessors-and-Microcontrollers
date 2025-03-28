// DEFINIR VELOCIDADES
//#define velo_linea   150
//#define velo_giro     50
#define velo_BASE   120
#define velo_giro   90

// DEFINIR NIVELES DIGIRALES PARA LA LINEA A SEGUIR
#define negro 1
#define blanco 0

// DEFINIR COMO ENTRADA LOS PINES DE LOS SENSORES
#define SI RA2_bit   // Sensor de la izquierda
#define SC RA4_bit   // Sensor del centro
#define SD RA5_bit   // Sensor de la derecha

// CONFIGURACIÓN DE LOS LOS PINES DEL SENSOR PARA ENTRADA/SALIDA
#define SI_DIR TRISA2_bit   //sensor de la izquierda
#define SC_DIR TRISA4_bit   //sensor del centro
#define SD_DIR TRISA5_bit   //sensor d ela derecha

// DEFINIR COMO SALIDA LOS PINES DEL MOTOR DE LA DERECHA
#define MD1 LATC0_bit
#define MD2 LATC1_bit

// CONFIGURACIÓN DE LOS PINES DEL MOTOR DE LA DERECHA SALIDA
#define MD1_DIR TRISC0_bit
#define MD2_DIR TRISC1_bit

// DEFINIR COMO SALIDA LOS PINES DEL MOTOR DE LA IZQUIERDA
#define MI1  LATC2_bit
#define MI2  LATC4_bit

// CONFIGURACIóN DE LOS PINES DEL MOTOR DE LA IZQUIERDA SALIDA
#define MI1_DIR TRISC2_bit
#define MI2_DIR TRISC4_bit

signed int velocidad;

// Motor deracha STOP
void   md_quieto(){
  MD1=0;
  MD2=0;
}

// Motor derecha ADELANTE
void   md_alante(){
  MD1=1;
  MD2=0;
}

// Motor derecha ATRAS
void   md_atras(){
  MD1=0;
  MD2=1;
}

// Motor izquierda STOP
void   mi_quieto(){
  MI1=0;
  MI2=0;
}

// Motor izquierda ADELANTE
void   mi_alante(){
  MI1=0;
  MI2=1;
}

// Motor izquierda ATRAS
void   mi_atras(){
  MI1=1;
  MI2=0;
}

// SE QUEDA QUIETO 
 void quieto(){
  md_quieto();
  mi_quieto();
}
 
// VA HACIA ADELANTE
//void alante(unsigned char velo){
//  PWM1_Set_Duty(velo);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
//  PWM2_Set_Duty(velo);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
//  md_alante();
//  mi_alante();
//}

void alante(signed int velo){
 signed int veld,veli;
 veld=velo_BASE+velo;
 veli=velo_BASE-velo;

 if (veld>=255) veld=255;
 if (veld<=0) veld=0;
 if (veli>=255) veli=255;
 if (veli<=0) veli=0;

 PWM1_Set_Duty(veld);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
 PWM2_Set_Duty(veli);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
 md_alante();
 mi_alante();
}

// VA HACIA ATRAS
void atras(unsigned char velo){
 PWM1_Set_Duty(velo);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
 PWM2_Set_Duty(velo);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
 md_atras();
 mi_atras();
}

// VA HACIA LA IZQUIERDA
void izquierda(unsigned char velo){
  PWM1_Set_Duty(velo);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
  PWM2_Set_Duty(velo);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
  md_alante();
  mi_atras();
}

// VA HACIA LA DERECHA
void derecha(unsigned char velo){
 PWM1_Set_Duty(velo);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
 PWM2_Set_Duty(velo);// VELOCIDAD INICIAL DEL PWM D ELOS MOTORES
 mi_alante();
 md_atras();
}

// DETECCIÓN DE LOS SENSORES
//void analiza_sensores(){
//   if ((SI==negro) &&  (SC==negro) &&(SD==negro) )           izquierda(velo_giro);
//   else if  ((SI==negro) &&  (SC==negro) && (SD==blanco) )  izquierda(velo_giro);
//   else if  ((SI==negro) &&  (SC==blanco) && (SD==negro) )     alante(velo_giro);  // imposible
//   else if  ((SI==negro) &&  (SC==blanco) && (SD==blanco) )   izquierda(velo_giro);
//   else if  ((SI==blanco) &&  (SC==negro) && (SD==negro) )    derecha(velo_giro);
//   else if  ((SI==blanco) &&  (SC==negro) && (SD==blanco) )    alante(velo_linea);
//   else if  ((SI==blanco) &&  (SC==blanco) && (SD==negro) )   derecha(velo_giro);
//   else if  ((SI==blanco) &&  (SC==blanco) && (SD==blanco) )   alante(velo_linea);  //
//}

void analiza_sensores(){
     if ((SI==negro) &&  (SC==negro) &&(SD==negro) )           velocidad = velo_giro;
     else  if  ((SI==negro) &&  (SC==negro) && (SD==blanco) )   velocidad = -velo_giro;
     else if  ((SI==negro) &&  (SC==blanco) && (SD==negro) )    velocidad = -velo_giro;  // VALOR IMPOSIBLE
     else if  ((SI==negro) &&  (SC==blanco) && (SD==blanco) )    velocidad = -velo_giro;
     else if  ((SI==blanco) &&  (SC==negro) && (SD==negro) )     velocidad = velo_giro;
     else if  ((SI==blanco) &&  (SC==negro) && (SD==blanco) )    velocidad = 0;
     else if  ((SI==blanco) &&  (SC==blanco) && (SD==negro) )    velocidad = velo_giro;
     else if  ((SI==blanco) &&  (SC==blanco) && (SD==blanco) )   velocidad = 0;
}
                
// FUNCIÓN PRICIPAL
void main(){
   // CONFIGURACIÓN DEL OSCILADOR
   OSCCON=0;
   OSCTUNE=0; // FRECUENCIA DE ENTRADA
   //SCS1_bit=1;
   //SCS0_bit=0;
   
   // Para Trabajar a 32 MHz con PLL
   // OSILADOR EN PALABRA DE CONFIGURACIÓN
   SCS1_bit=0;
   SCS0_bit=0;
   
   //OSCILADOR INTERNO 8 MHZ
   IRCF3_bit=1;
   IRCF2_bit=1;
   IRCF1_bit=1;
   IRCF0_bit=0;

   // TODO DIGITAL
   ANSELA=0;
   ANSELC=0;

   // CONFIGURACIÓN DE ENTRADAS Y SALIDAS
   // ENTRADAS SENSORES
   SI_DIR=1;
   SC_DIR=1;
   SD_DIR=1;

   // SALIDAS MOTORES
   MD1_DIR=0;
   MD2_DIR=0;
   MI1_DIR=0;
   MI2_DIR=0;

   // SALIDA PINES PWM
   TRISC3_bit=0;
   TRISC5_bit=0;

   SPLLEN_bit=0; // prende el PLL por 4  da 32MHZ  si es cero da 8 MHZ

   PWM1_Init(250);
   PWM2_Init(250);
                                    
   PWM1_Set_Duty(127);// VELOCIDAD INICIAL DEL PWM DE LOS MOTORES
   PWM2_Set_Duty(127);// VELOCIDAD INICIAL DEL PWM DE LOS MOTORES

   PWM1_Start();
   PWM2_Start();
   //ENTRADA LED
   while (1){
      analiza_sensores();
      alante(velocidad);
      //Delay_ms(1);
   }
}