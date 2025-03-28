
_zero:

;Parcial_1_2195533.c,6 :: 		void zero(){
;Parcial_1_2195533.c,7 :: 		PORTA.F0 = 1;
	BSF        PORTA+0, 0
;Parcial_1_2195533.c,8 :: 		PORTA.F0 = 0;
	BCF        PORTA+0, 0
;Parcial_1_2195533.c,9 :: 		delay_us(1);
	MOVLW      2
	MOVWF      R13
L_zero0:
	DECFSZ     R13, 1
	GOTO       L_zero0
	NOP
;Parcial_1_2195533.c,10 :: 		}
L_end_zero:
	RETURN
; end of _zero

_one:

;Parcial_1_2195533.c,12 :: 		void one(){
;Parcial_1_2195533.c,13 :: 		PORTA.F0 = 1;
	BSF        PORTA+0, 0
;Parcial_1_2195533.c,14 :: 		delay_us(1);
	MOVLW      2
	MOVWF      R13
L_one1:
	DECFSZ     R13, 1
	GOTO       L_one1
	NOP
;Parcial_1_2195533.c,15 :: 		PORTA.F0 = 0;
	BCF        PORTA+0, 0
;Parcial_1_2195533.c,16 :: 		}
L_end_one:
	RETURN
; end of _one

_NG:

;Parcial_1_2195533.c,22 :: 		void NG (void){ // COLOR NEGRO
;Parcial_1_2195533.c,24 :: 		zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,26 :: 		zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,28 :: 		zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,29 :: 		}
L_end_NG:
	RETURN
; end of _NG

_AZ:

;Parcial_1_2195533.c,31 :: 		void AZ (void){ // COLOR AZUL
;Parcial_1_2195533.c,33 :: 		zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,35 :: 		zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,37 :: 		one(); one(); one(); one(); one(); one(); one(); one();
	CALL       _one+0
	CALL       _one+0
	CALL       _one+0
	CALL       _one+0
	CALL       _one+0
	CALL       _one+0
	CALL       _one+0
	CALL       _one+0
;Parcial_1_2195533.c,38 :: 		}
L_end_AZ:
	RETURN
; end of _AZ

_OL:

;Parcial_1_2195533.c,40 :: 		void OL (void){ // COLOR OLIVA
;Parcial_1_2195533.c,42 :: 		one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _one+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,44 :: 		one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _one+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,46 :: 		zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,47 :: 		}
L_end_OL:
	RETURN
; end of _OL

_TQ:

;Parcial_1_2195533.c,49 :: 		void TQ (void){ // COLOR TURQUESA
;Parcial_1_2195533.c,51 :: 		one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _one+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,53 :: 		zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,55 :: 		one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _one+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,56 :: 		}
L_end_TQ:
	RETURN
; end of _TQ

_MR:

;Parcial_1_2195533.c,58 :: 		void MR (void){ // COLOR MORADO
;Parcial_1_2195533.c,60 :: 		zero(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,62 :: 		one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _one+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,64 :: 		one(); zero(); zero(); zero(); zero(); zero(); zero(); zero();
	CALL       _one+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
	CALL       _zero+0
;Parcial_1_2195533.c,65 :: 		}
L_end_MR:
	RETURN
; end of _MR

_EME:

;Parcial_1_2195533.c,67 :: 		void EME(){  // LETRA M
;Parcial_1_2195533.c,68 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,69 :: 		NG(); NG(); NG(); TQ(); TQ(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,70 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,71 :: 		NG(); NG(); TQ(); NG(); NG(); TQ(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,72 :: 		NG(); NG(); TQ(); NG(); NG(); TQ(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,73 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,74 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,75 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,76 :: 		}
L_end_EME:
	RETURN
; end of _EME

_AAA:

;Parcial_1_2195533.c,78 :: 		void AAA(){  // LETRA A
;Parcial_1_2195533.c,79 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,80 :: 		NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,81 :: 		NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,82 :: 		NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,83 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,84 :: 		NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,85 :: 		NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,86 :: 		NG(); NG(); OL(); OL(); OL(); OL(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,87 :: 		}
L_end_AAA:
	RETURN
; end of _AAA

_EFE:

;Parcial_1_2195533.c,89 :: 		void EFE(){  // LETRA F
;Parcial_1_2195533.c,90 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,91 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
;Parcial_1_2195533.c,92 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
;Parcial_1_2195533.c,93 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
;Parcial_1_2195533.c,94 :: 		NG(); NG(); NG(); NG(); NG(); NG(); TQ(); TQ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
;Parcial_1_2195533.c,95 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
;Parcial_1_2195533.c,96 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
;Parcial_1_2195533.c,97 :: 		NG(); NG(); TQ(); TQ(); TQ(); TQ(); TQ(); TQ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
	CALL       _TQ+0
;Parcial_1_2195533.c,98 :: 		}
L_end_EFE:
	RETURN
; end of _EFE

_EEE:

;Parcial_1_2195533.c,100 :: 		void EEE(){  // LETRA E
;Parcial_1_2195533.c,101 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,102 :: 		NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
;Parcial_1_2195533.c,103 :: 		NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
;Parcial_1_2195533.c,104 :: 		NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
;Parcial_1_2195533.c,105 :: 		NG(); NG(); NG(); NG(); NG(); NG(); OL(); OL();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
;Parcial_1_2195533.c,106 :: 		NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
;Parcial_1_2195533.c,107 :: 		NG(); NG(); OL(); OL(); OL(); OL(); OL(); OL();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
	CALL       _OL+0
;Parcial_1_2195533.c,108 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,109 :: 		}
L_end_EEE:
	RETURN
; end of _EEE

_DD:

;Parcial_1_2195533.c,111 :: 		void DD(){  // LETRA D
;Parcial_1_2195533.c,112 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); AZ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
;Parcial_1_2195533.c,113 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,114 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
;Parcial_1_2195533.c,115 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
;Parcial_1_2195533.c,116 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
;Parcial_1_2195533.c,117 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
;Parcial_1_2195533.c,118 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,119 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); AZ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
;Parcial_1_2195533.c,120 :: 		}
L_end_DD:
	RETURN
; end of _DD

_AA:

;Parcial_1_2195533.c,122 :: 		void AA(){  // LETRA A
;Parcial_1_2195533.c,123 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,124 :: 		NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,125 :: 		NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,126 :: 		NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,127 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,128 :: 		NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,129 :: 		NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,130 :: 		NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,131 :: 		}
L_end_AA:
	RETURN
; end of _AA

_GGG:

;Parcial_1_2195533.c,133 :: 		void GGG(){  // LETRA G
;Parcial_1_2195533.c,134 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,135 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
;Parcial_1_2195533.c,136 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); AZ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
;Parcial_1_2195533.c,137 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); AZ();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
;Parcial_1_2195533.c,138 :: 		NG(); NG(); AZ(); AZ(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,139 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
;Parcial_1_2195533.c,140 :: 		NG(); NG(); AZ(); AZ(); AZ(); AZ(); AZ(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _AZ+0
	CALL       _NG+0
;Parcial_1_2195533.c,141 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,142 :: 		}
L_end_GGG:
	RETURN
; end of _GGG

_DDD:

;Parcial_1_2195533.c,144 :: 		void DDD(){  // LETRA D
;Parcial_1_2195533.c,145 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); MR();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
;Parcial_1_2195533.c,146 :: 		NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,147 :: 		NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
;Parcial_1_2195533.c,148 :: 		NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
;Parcial_1_2195533.c,149 :: 		NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
;Parcial_1_2195533.c,150 :: 		NG(); NG(); MR(); MR(); MR(); MR(); MR(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
;Parcial_1_2195533.c,151 :: 		NG(); NG(); MR(); MR(); MR(); MR(); NG(); NG();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _MR+0
	CALL       _NG+0
	CALL       _NG+0
;Parcial_1_2195533.c,152 :: 		NG(); NG(); NG(); NG(); NG(); NG(); NG(); MR();
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _NG+0
	CALL       _MR+0
;Parcial_1_2195533.c,153 :: 		}
L_end_DDD:
	RETURN
; end of _DDD

_main:

;Parcial_1_2195533.c,155 :: 		void main() {
;Parcial_1_2195533.c,156 :: 		TRISA = 0;       // Todo el Puerto A de salida.
	CLRF       TRISA+0
;Parcial_1_2195533.c,157 :: 		ANSELA = 0;      // Todos los pines del Puerto A son digitales.
	CLRF       ANSELA+0
;Parcial_1_2195533.c,158 :: 		OSCCON = 0b11110011;  // Para que el clock opere a 32 MHz usando el PLL (8x4 MHz), debido a que
	MOVLW      243
	MOVWF      OSCCON+0
;Parcial_1_2195533.c,161 :: 		LATA.F0 = 0;     // Se define el pin que se trabajará como salida (RA0).
	BCF        LATA+0, 0
;Parcial_1_2195533.c,162 :: 		delay_us(50);    // Retraso de 50 us.
	MOVLW      133
	MOVWF      R13
L_main2:
	DECFSZ     R13, 1
	GOTO       L_main2
;Parcial_1_2195533.c,163 :: 		while(1){        // Ciclo while para mostrar en las matrices los respectivos simbolos
L_main3:
;Parcial_1_2195533.c,164 :: 		EME();    // Muestra la letra M.
	CALL       _EME+0
;Parcial_1_2195533.c,165 :: 		AAA();    // Muestra la letra A.
	CALL       _AAA+0
;Parcial_1_2195533.c,166 :: 		EFE();    // Muestra la letra F.
	CALL       _EFE+0
;Parcial_1_2195533.c,167 :: 		EEE();    // Muestra la letra E.
	CALL       _EEE+0
;Parcial_1_2195533.c,168 :: 		delay_us(50);    // Retraso de 50 us.
	MOVLW      133
	MOVWF      R13
L_main5:
	DECFSZ     R13, 1
	GOTO       L_main5
;Parcial_1_2195533.c,169 :: 		delay_ms(1000);  // Retraso de 1000 ms.
	MOVLW      41
	MOVWF      R11
	MOVLW      150
	MOVWF      R12
	MOVLW      127
	MOVWF      R13
L_main6:
	DECFSZ     R13, 1
	GOTO       L_main6
	DECFSZ     R12, 1
	GOTO       L_main6
	DECFSZ     R11, 1
	GOTO       L_main6
;Parcial_1_2195533.c,170 :: 		DD();     // Muestra la letra D.
	CALL       _DD+0
;Parcial_1_2195533.c,171 :: 		AA();     // Muestra la letra A.
	CALL       _AA+0
;Parcial_1_2195533.c,172 :: 		GGG();    // Muestra la letra G.
	CALL       _GGG+0
;Parcial_1_2195533.c,173 :: 		DDD();    // Muestra la letra D.
	CALL       _DDD+0
;Parcial_1_2195533.c,174 :: 		delay_us(50);    // Retraso de 50 us.
	MOVLW      133
	MOVWF      R13
L_main7:
	DECFSZ     R13, 1
	GOTO       L_main7
;Parcial_1_2195533.c,175 :: 		delay_ms(1000);  // Retraso de 1000 ms.
	MOVLW      41
	MOVWF      R11
	MOVLW      150
	MOVWF      R12
	MOVLW      127
	MOVWF      R13
L_main8:
	DECFSZ     R13, 1
	GOTO       L_main8
	DECFSZ     R12, 1
	GOTO       L_main8
	DECFSZ     R11, 1
	GOTO       L_main8
;Parcial_1_2195533.c,176 :: 		EME();    // Muestra la letra M.
	CALL       _EME+0
;Parcial_1_2195533.c,177 :: 		EFE();    // Muestra la letra F.
	CALL       _EFE+0
;Parcial_1_2195533.c,178 :: 		DD();     // Muestra la letra D.
	CALL       _DD+0
;Parcial_1_2195533.c,179 :: 		GGG();    // Muestra la letra G.
	CALL       _GGG+0
;Parcial_1_2195533.c,180 :: 		delay_us(50);    // Retraso de 50 us.
	MOVLW      133
	MOVWF      R13
L_main9:
	DECFSZ     R13, 1
	GOTO       L_main9
;Parcial_1_2195533.c,181 :: 		delay_ms(1000);  // Retraso de 1000 ms.
	MOVLW      41
	MOVWF      R11
	MOVLW      150
	MOVWF      R12
	MOVLW      127
	MOVWF      R13
L_main10:
	DECFSZ     R13, 1
	GOTO       L_main10
	DECFSZ     R12, 1
	GOTO       L_main10
	DECFSZ     R11, 1
	GOTO       L_main10
;Parcial_1_2195533.c,182 :: 		DD();     // Muestra la letra D.
	CALL       _DD+0
;Parcial_1_2195533.c,183 :: 		AA();     // Muestra la letra A.
	CALL       _AA+0
;Parcial_1_2195533.c,184 :: 		EME();    // Muestra la letra M.
	CALL       _EME+0
;Parcial_1_2195533.c,185 :: 		AAA();    // Muestra la letra A.
	CALL       _AAA+0
;Parcial_1_2195533.c,186 :: 		delay_us(50);    // Retraso de 50 us.
	MOVLW      133
	MOVWF      R13
L_main11:
	DECFSZ     R13, 1
	GOTO       L_main11
;Parcial_1_2195533.c,187 :: 		delay_ms(1000);  // Retraso de 1000 ms.
	MOVLW      41
	MOVWF      R11
	MOVLW      150
	MOVWF      R12
	MOVLW      127
	MOVWF      R13
L_main12:
	DECFSZ     R13, 1
	GOTO       L_main12
	DECFSZ     R12, 1
	GOTO       L_main12
	DECFSZ     R11, 1
	GOTO       L_main12
;Parcial_1_2195533.c,188 :: 		}
	GOTO       L_main3
;Parcial_1_2195533.c,189 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
