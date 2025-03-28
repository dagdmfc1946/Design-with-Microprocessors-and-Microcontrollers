#line 1 "D:/INGENIERIA ELECTRONICA/11. Onceavo Semestre/Diseño con uP y uC/Parcial 1/Archivos_mikroC/Parcial_1_2195533.c"





void zero(){
 PORTA.F0 = 1;
 PORTA.F0 = 0;
 delay_us(1);
}

void one(){
 PORTA.F0 = 1;
 delay_us(1);
 PORTA.F0 = 0;
}





void NG (void){

 zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
}

void AZ (void){

 zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 one(); one(); one(); one(); one(); one(); one(); one();
}

void OL (void){

 one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
}

void TQ (void){

 one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
}

void MR (void){

 zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();

 one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
}

void EME(){
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
 NG(); NG(); NG(); TQ(); TQ(); NG(); NG(); NG();
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
 NG(); NG(); TQ(); NG(); NG(); TQ(); NG(); NG();
 NG(); NG(); TQ(); NG(); NG(); TQ(); NG(); NG();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
}

void AAA(){
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
 NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
 NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
 NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
 NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
 NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
 NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
}

void EFE(){
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
 NG(); NG(); NG(); NG(); NG(); NG(); TQ(); TQ();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
 NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
}

void EEE(){
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
 NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
 NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
 NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
 NG(); NG(); NG(); NG(); NG(); NG(); OL(); OL();
 NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
 NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
}

void DD(){
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); AZ();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); NG(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); NG(); NG();
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); AZ();
}

void AA(){
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
}

void GGG(){
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); AZ();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); AZ();
 NG(); NG(); AZ(); AZ(); NG(); NG(); NG(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
 NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
}

void DDD(){
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); MR();
 NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
 NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
 NG(); NG(); NG(); NG(); NG(); NG(); NG(); MR();
}

void main() {
 TRISA = 0;
 ANSELA = 0;
 OSCCON = 0b11110011;


 LATA.F0 = 0;
 delay_us(50);
 while(1){
 EME();
 AAA();
 EFE();
 EEE();
 delay_us(50);
 delay_ms(1000);
 DD();
 AA();
 GGG();
 DDD();
 delay_us(50);
 delay_ms(1000);
 EME();
 EFE();
 DD();
 GGG();
 delay_us(50);
 delay_ms(1000);
 DD();
 AA();
 EME();
 AAA();
 delay_us(50);
 delay_ms(1000);
 }
}
