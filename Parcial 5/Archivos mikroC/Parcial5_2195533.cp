#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Parcial 5/Archivos mikroC/Parcial5_2195533.c"
#line 36 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Parcial 5/Archivos mikroC/Parcial5_2195533.c"
signed int VELOCIDAD;


void M_DSTOP(){
  LATC0_bit =0;
  LATC1_bit =0;
}


void M_DADELANTE(){
  LATC0_bit =1;
  LATC1_bit =0;
}


void M_DATRAS(){
  LATC0_bit =0;
  LATC1_bit =1;
}


void M_ISTOP(){
  LATC2_bit =0;
  LATC4_bit =0;
}


void M_IADELANTE(){
  LATC2_bit =0;
  LATC4_bit =1;
}


void M_IATRAS(){
  LATC2_bit =1;
  LATC4_bit =0;
}


 void Robot_QUIETO(){
 M_DSTOP();
 M_ISTOP();
}


void Robot_ADELANTE(signed int VEL){
 signed int VEL_D, VEL_I;

 VEL_D =  120  + VEL;
 VEL_I =  120  - VEL;


 if (VEL_D >= 255) VEL_D = 255;
 if (VEL_D <= 0) VEL_D = 0;
 if (VEL_I >= 255) VEL_I = 255;
 if (VEL_I <= 0) VEL_I = 0;

 PWM1_Set_Duty(VEL_D);
 PWM2_Set_Duty(VEL_I);
 M_DADELANTE();
 M_IADELANTE();
}


void Robot_ATRAS(unsigned char VEL){
 PWM1_Set_Duty(VEL);
 PWM2_Set_Duty(VEL);
 M_DATRAS();
 M_IATRAS();
}


void Robot_IZQUIERDA(unsigned char VEL){
 PWM1_Set_Duty(VEL);
 PWM2_Set_Duty(VEL);
 M_DADELANTE();
 M_IATRAS();
}


void Robot_DERECHA(unsigned char VEL){
 PWM1_Set_Duty(VEL);
 PWM2_Set_Duty(VEL);
 M_IADELANTE();
 M_DATRAS();
}

void LEER_SENSORES(){
 if (( RA2_bit == 1 ) && ( RA4_bit == 1 ) &&( RA5_bit == 1 ) ) VELOCIDAD =  90 ;
 else if (( RA2_bit == 1 ) && ( RA4_bit == 1 ) && ( RA5_bit == 0 ) ) VELOCIDAD = - 90 ;
 else if (( RA2_bit == 1 ) && ( RA4_bit == 0 ) && ( RA5_bit == 1 ) ) VELOCIDAD = - 90 ;
 else if (( RA2_bit == 1 ) && ( RA4_bit == 0 ) && ( RA5_bit == 0 ) ) VELOCIDAD = - 90 ;
 else if (( RA2_bit == 0 ) && ( RA4_bit == 1 ) && ( RA5_bit == 1 ) ) VELOCIDAD =  90 ;
 else if (( RA2_bit == 0 ) && ( RA4_bit == 1 ) && ( RA5_bit == 0 ) ) VELOCIDAD = 0;
 else if (( RA2_bit == 0 ) && ( RA4_bit == 0 ) && ( RA5_bit == 1 ) ) VELOCIDAD =  90 ;
 else if (( RA2_bit == 0 ) && ( RA4_bit == 0 ) && ( RA5_bit == 0 ) ) VELOCIDAD = 0;
}


void main(){

 OSCCON=0;
 OSCTUNE=0;

 SCS1_bit=0;
 SCS0_bit=0;


 IRCF3_bit=1;
 IRCF2_bit=1;
 IRCF1_bit=1;
 IRCF0_bit=0;


 ANSELA=0;
 ANSELC=0;



  TRISA2_bit =1;
  TRISA4_bit =1;
  TRISA5_bit =1;


  TRISC0_bit =0;
  TRISC1_bit =0;
  TRISC2_bit =0;
  TRISC4_bit =0;


 TRISC3_bit=0;
 TRISC5_bit=0;

 SPLLEN_bit=0;

 PWM1_Init(250);
 PWM2_Init(250);

 PWM1_Set_Duty(127);
 PWM2_Set_Duty(127);

 PWM1_Start();
 PWM2_Start();
 while (1){
 LEER_SENSORES();
 Robot_ADELANTE(VELOCIDAD);

 }
}
