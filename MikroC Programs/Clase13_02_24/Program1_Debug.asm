
_main:

;Program1_Debug.c,2 :: 		void main() {
;Program1_Debug.c,3 :: 		OSCCON = 0b11110000; // OSCCON.F7 === 8 ó 32 MHz Para que el clock opere a 8 MHz
	MOVLW      240
	MOVWF      OSCCON+0
;Program1_Debug.c,4 :: 		TRISA = 0; // Puerto A
	CLRF       TRISA+0
;Program1_Debug.c,6 :: 		ansela = 0;
	CLRF       ANSELA+0
;Program1_Debug.c,8 :: 		while (1){
L_main0:
;Program1_Debug.c,9 :: 		LATA = 0;  // Saca por el puerto A un 0
	CLRF       LATA+0
;Program1_Debug.c,14 :: 		LATA = 0B11111111;     // Pone todo el puerto A en 1
	MOVLW      255
	MOVWF      LATA+0
;Program1_Debug.c,20 :: 		}
	GOTO       L_main0
;Program1_Debug.c,21 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
