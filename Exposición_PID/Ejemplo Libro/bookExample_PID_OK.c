// Ejemplo LIBRO: Capitulo 14 - Control PID.

//Declaraci�n de constantes y variables.
const float Kp=1.08, Ki=52.42718447, Kd=0.005562, Fs =  152.5878906;
//Declaraci�n de coeficientes de integraci�n y derivaci�n.
const float Fi=Ki/(2.0*Fs), Fd=2.0*Fs*Kd;
 
float SENSOR, PUNTO_DE_CONTROL=127.0, YN=0.0;
int ADQUI;
unsigned short SALIDA;

float e0=0.0, e1=0.0, yi0=0.0, yi1=0.0, yd0=0.0, yd1=0.0, ypid=0.0;

//Funci�n de interrupciones para el Timer 0.
void interrupt()
{
     if( INTCON.F2 )// 6,5536ms :: 152,5878906 Hz
     {
         //Adquisici�n de la variable controlada.
         SENSOR = (float)((ADC_Read(1)>>2)&0xFF);
         //Adquisici�n del punto de control.
         PUNTO_DE_CONTROL = (float)((ADC_Read(0)>>2)&0xFF);
         //Calculo del nivel de error.
         e0 = PUNTO_DE_CONTROL - SENSOR;
         //Ecuaci�n en diferencias.
         //Ecuaci�n integral.
         yi0=Fi*(e0+e1)+yi1;
         //Ecuaci�n derivativa.
         yd0=Fd*(e0-e1)-yd1;
         //Resultado PID.
         ypid=Kp*e0+yi0+yd0;
         //Ajuste y correcci�n de la SALIDA Y(n)
         //delimitada por los l�mites 0 y 255.
         YN += ypid;
         if(YN>255.0)YN=255.0;
         if(YN<0.0)YN=0.0;
         SALIDA = (unsigned short)(YN);
         PWM1_Set_Duty(SALIDA);
         //Actualizaci�n de muestras.
         e1=e0;
         yi1=yi0; 
         yd1=yd0; 
         INTCON.F2=0;
     }
}

void main( void )
{
       //Configuraci�n del modulo PWM.
       PWM1_Init(10000);
       PWM1_Start();
       //Configuraci�n de la interrupci�n de Timer 0.
       //a 6,5536ms
       OPTION_REG = 0b00000110;
       INTCON = 0b10100000;
       while( 1 ) //Bucle infinito. 
       {
       }
}
