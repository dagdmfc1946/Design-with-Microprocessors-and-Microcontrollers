// PARCIAL 1 - DISEÑO CON uP y uC. 2024-1.
// NOMBRE: Diego Andrés García Díaz.
// CÓDIGO: 2195533.
// -----------------------------------------------------------------------------
// Función para los ceros '0'.
void zero(){
     PORTA.F0 = 1;
     PORTA.F0 = 0;
     delay_us(1);
}
// Función para los unos '1'.
void one(){
     PORTA.F0 = 1;
     delay_us(1);
     PORTA.F0 = 0;
}
// -----------------------------------------------------------------------------
// Ahora se crearán funciones para cada uno de los colores que se usarán:
// Negro, Azul, Oliva, Turquesa, Morado. Según el datasheet de 'WS2812', 
// los colores RGB se deben estar en el siguiente orden dentro de la función:
// G (GREEN), R (RED), B(BLUE).
void NG (void){ // COLOR NEGRO
     // G (GREEN)
       zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // R (RED)
       zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // B (BLUE)
       zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
}
// -----------------------------------------------------------------------------
void AZ (void){ // COLOR AZUL
     // G (GREEN)
       zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // R (RED)
       zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // B (BLUE)
       one(); one(); one(); one(); one(); one(); one(); one();
}
// -----------------------------------------------------------------------------
void OL (void){ // COLOR OLIVA
     // G (GREEN)
       one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // R (RED)
       one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // B (BLUE)
       zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
}
// -----------------------------------------------------------------------------
void TQ (void){ // COLOR TURQUESA
     // G (GREEN)
       one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // R (RED)
       zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // B (BLUE)
       one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
}
// -----------------------------------------------------------------------------
void MR (void){ // COLOR MORADO
     // G (GREEN)
       zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // R (RED)
       one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
     // B (BLUE)
       one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
}
// -----------------------------------------------------------------------------
void EME(){  // LETRA M
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
     NG(); NG(); NG(); TQ(); TQ(); NG(); NG(); NG();
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
     NG(); NG(); TQ(); NG(); NG(); TQ(); NG(); NG();
     NG(); NG(); TQ(); NG(); NG(); TQ(); NG(); NG();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
}
// -----------------------------------------------------------------------------
void AAA(){  // LETRA A
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
     NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
     NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
     NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
     NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
     NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
     NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
}
// -----------------------------------------------------------------------------
void EFE(){  // LETRA F
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
     NG(); NG(); NG(); NG(); NG(); NG(); TQ(); TQ();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
     NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
}
// -----------------------------------------------------------------------------
void EEE(){  // LETRA E
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
     NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
     NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
     NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
     NG(); NG(); NG(); NG(); NG(); NG(); OL(); OL();
     NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
     NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
}
// -----------------------------------------------------------------------------
void DD(){  // LETRA D
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); AZ();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); NG(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); NG(); NG();
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); AZ();
}
// -----------------------------------------------------------------------------
void AA(){  // LETRA A
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
}
// -----------------------------------------------------------------------------
void GGG(){  // LETRA G
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); AZ();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); AZ();
     NG(); NG(); AZ(); AZ(); NG(); NG(); NG(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
     NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
}

void DDD(){  // LETRA D
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); MR();
     NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
     NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
     NG(); NG(); NG(); NG(); NG(); NG(); NG(); MR();
}
// -----------------------------------------------------------------------------
void main() {
     TRISA = 0;       // Todo el Puerto A de salida.
     ANSELA = 0;      // Todos los pines del Puerto A son digitales.
     OSCCON = 0b11110011;  // Para que el clock opere a 32 MHz usando el PLL (8x4 MHz), debido a que
                           // se necesita alta velocidad para evitar ver cambios en la señal que se
                           // envia a los LEDs con el fin de ver una imagen fija para el ojo humano.          
     LATA.F0 = 0;     // Se define el pin que se trabajará como salida (RA0).
     delay_us(50);    // Retraso de 50 us.
     while(1){        // Ciclo while para mostrar en las matrices los respectivos simbolos
              EME();    // Muestra la letra M.
              AAA();    // Muestra la letra A.
              EFE();    // Muestra la letra F.
              EEE();    // Muestra la letra E.
              delay_us(50);    // Retraso de 50 us.
              delay_ms(1000);  // Retraso de 1000 ms.
              DD();     // Muestra la letra D.
              AA();     // Muestra la letra A.
              GGG();    // Muestra la letra G.
              DDD();    // Muestra la letra D.
              delay_us(50);    // Retraso de 50 us.
              delay_ms(1000);  // Retraso de 1000 ms.
              EME();    // Muestra la letra M.
              EFE();    // Muestra la letra F.
              DD();     // Muestra la letra D.
              GGG();    // Muestra la letra G.
              delay_us(50);    // Retraso de 50 us.
              delay_ms(1000);  // Retraso de 1000 ms.
              DD();     // Muestra la letra D.
              AA();     // Muestra la letra A.
              EME();    // Muestra la letra M.
              AAA();    // Muestra la letra A.
              delay_us(50);    // Retraso de 50 us.
              delay_ms(1000);  // Retraso de 1000 ms.
              }
}