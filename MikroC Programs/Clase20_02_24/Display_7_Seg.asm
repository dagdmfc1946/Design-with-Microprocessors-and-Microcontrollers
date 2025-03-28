
_main:

;Display_7_Seg.c,14 :: 		void main(void){
;Display_7_Seg.c,15 :: 		unsigned short CONTADOR=0;
	CLRF       main_CONTADOR_L0+0
;Display_7_Seg.c,17 :: 		OSCCON.F0=0; // spll ircf ircf ircf ircf x scs scs
	BCF        OSCCON+0, 0
;Display_7_Seg.c,18 :: 		OSCCON.F1=0;
	BCF        OSCCON+0, 1
;Display_7_Seg.c,19 :: 		OSCCON.F3=0;
	BCF        OSCCON+0, 3
;Display_7_Seg.c,20 :: 		OSCCON.F4=1;
	BSF        OSCCON+0, 4
;Display_7_Seg.c,21 :: 		OSCCON.F5=1;
	BSF        OSCCON+0, 5
;Display_7_Seg.c,22 :: 		OSCCON.F6=1;
	BSF        OSCCON+0, 6
;Display_7_Seg.c,23 :: 		OSCCON.F7=1; // PLL Habilitado = 1/ deshabilitado = 0
	BSF        OSCCON+0, 7
;Display_7_Seg.c,24 :: 		TRISB = 0;
	CLRF       TRISB+0
;Display_7_Seg.c,26 :: 		ANSELB = 0;
	CLRF       ANSELB+0
;Display_7_Seg.c,28 :: 		while(1){ // Bucle infinito.
L_main0:
;Display_7_Seg.c,30 :: 		LATB = DIGITOS [CONTADOR];
	MOVLW      _DIGITOS+0
	MOVWF      FSR0L
	MOVLW      hi_addr(_DIGITOS+0)
	MOVWF      FSR0H
	MOVF       main_CONTADOR_L0+0, 0
	ADDWF      FSR0L, 1
	BTFSC      STATUS+0, 0
	INCF       FSR0H, 1
	MOVF       INDF0+0, 0
	MOVWF      LATB+0
;Display_7_Seg.c,32 :: 		CONTADOR++; // Se incrementa el valor del conteo.
	INCF       main_CONTADOR_L0+0, 1
;Display_7_Seg.c,33 :: 		delay_ms(500); // Se hace un retardo de 1/2 segundo.
	MOVLW      21
	MOVWF      R11
	MOVLW      75
	MOVWF      R12
	MOVLW      190
	MOVWF      R13
L_main2:
	DECFSZ     R13, 1
	GOTO       L_main2
	DECFSZ     R12, 1
	GOTO       L_main2
	DECFSZ     R11, 1
	GOTO       L_main2
	NOP
;Display_7_Seg.c,34 :: 		if (contador == 10) contador = 0;
	MOVF       main_CONTADOR_L0+0, 0
	XORLW      10
	BTFSS      STATUS+0, 2
	GOTO       L_main3
	CLRF       main_CONTADOR_L0+0
L_main3:
;Display_7_Seg.c,35 :: 		}
	GOTO       L_main0
;Display_7_Seg.c,36 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
