
_M_DSTOP:

	BCF        LATC0_bit+0, BitPos(LATC0_bit+0)
	BCF        LATC1_bit+0, BitPos(LATC1_bit+0)
L_end_M_DSTOP:
	RETURN
; end of _M_DSTOP

_M_DADELANTE:

	BSF        LATC0_bit+0, BitPos(LATC0_bit+0)
	BCF        LATC1_bit+0, BitPos(LATC1_bit+0)
L_end_M_DADELANTE:
	RETURN
; end of _M_DADELANTE

_M_DATRAS:

	BCF        LATC0_bit+0, BitPos(LATC0_bit+0)
	BSF        LATC1_bit+0, BitPos(LATC1_bit+0)
L_end_M_DATRAS:
	RETURN
; end of _M_DATRAS

_M_ISTOP:

	BCF        LATC2_bit+0, BitPos(LATC2_bit+0)
	BCF        LATC4_bit+0, BitPos(LATC4_bit+0)
L_end_M_ISTOP:
	RETURN
; end of _M_ISTOP

_M_IADELANTE:

	BCF        LATC2_bit+0, BitPos(LATC2_bit+0)
	BSF        LATC4_bit+0, BitPos(LATC4_bit+0)
L_end_M_IADELANTE:
	RETURN
; end of _M_IADELANTE

_M_IATRAS:

	BSF        LATC2_bit+0, BitPos(LATC2_bit+0)
	BCF        LATC4_bit+0, BitPos(LATC4_bit+0)
L_end_M_IATRAS:
	RETURN
; end of _M_IATRAS

_Robot_QUIETO:

	CALL       _M_DSTOP+0
	CALL       _M_ISTOP+0
L_end_Robot_QUIETO:
	RETURN
; end of _Robot_QUIETO

_Robot_ADELANTE:

	MOVLW      120
	ADDWF      FARG_Robot_ADELANTE_VEL+0, 0
	MOVWF      R1
	MOVLW      0
	ADDWFC     FARG_Robot_ADELANTE_VEL+1, 0
	MOVWF      R2
	MOVF       R1, 0
	MOVWF      Robot_ADELANTE_VEL_D_L0+0
	MOVF       R2, 0
	MOVWF      Robot_ADELANTE_VEL_D_L0+1
	MOVF       FARG_Robot_ADELANTE_VEL+0, 0
	SUBLW      120
	MOVWF      Robot_ADELANTE_VEL_I_L0+0
	MOVF       FARG_Robot_ADELANTE_VEL+1, 0
	BTFSS      STATUS+0, 0
	ADDLW      1
	CLRF       Robot_ADELANTE_VEL_I_L0+1
	SUBWF      Robot_ADELANTE_VEL_I_L0+1, 1
	MOVLW      128
	XORWF      R2, 0
	MOVWF      R0
	MOVLW      128
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__Robot_ADELANTE53
	MOVLW      255
	SUBWF      R1, 0
L__Robot_ADELANTE53:
	BTFSS      STATUS+0, 0
	GOTO       L_Robot_ADELANTE0
	MOVLW      255
	MOVWF      Robot_ADELANTE_VEL_D_L0+0
	CLRF       Robot_ADELANTE_VEL_D_L0+1
L_Robot_ADELANTE0:
	MOVLW      128
	MOVWF      R0
	MOVLW      128
	XORWF      Robot_ADELANTE_VEL_D_L0+1, 0
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__Robot_ADELANTE54
	MOVF       Robot_ADELANTE_VEL_D_L0+0, 0
	SUBLW      0
L__Robot_ADELANTE54:
	BTFSS      STATUS+0, 0
	GOTO       L_Robot_ADELANTE1
	CLRF       Robot_ADELANTE_VEL_D_L0+0
	CLRF       Robot_ADELANTE_VEL_D_L0+1
L_Robot_ADELANTE1:
	MOVLW      128
	XORWF      Robot_ADELANTE_VEL_I_L0+1, 0
	MOVWF      R0
	MOVLW      128
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__Robot_ADELANTE55
	MOVLW      255
	SUBWF      Robot_ADELANTE_VEL_I_L0+0, 0
L__Robot_ADELANTE55:
	BTFSS      STATUS+0, 0
	GOTO       L_Robot_ADELANTE2
	MOVLW      255
	MOVWF      Robot_ADELANTE_VEL_I_L0+0
	CLRF       Robot_ADELANTE_VEL_I_L0+1
L_Robot_ADELANTE2:
	MOVLW      128
	MOVWF      R0
	MOVLW      128
	XORWF      Robot_ADELANTE_VEL_I_L0+1, 0
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__Robot_ADELANTE56
	MOVF       Robot_ADELANTE_VEL_I_L0+0, 0
	SUBLW      0
L__Robot_ADELANTE56:
	BTFSS      STATUS+0, 0
	GOTO       L_Robot_ADELANTE3
	CLRF       Robot_ADELANTE_VEL_I_L0+0
	CLRF       Robot_ADELANTE_VEL_I_L0+1
L_Robot_ADELANTE3:
	MOVF       Robot_ADELANTE_VEL_D_L0+0, 0
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
	MOVF       Robot_ADELANTE_VEL_I_L0+0, 0
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
	CALL       _M_DADELANTE+0
	CALL       _M_IADELANTE+0
L_end_Robot_ADELANTE:
	RETURN
; end of _Robot_ADELANTE

_Robot_ATRAS:

	MOVF       FARG_Robot_ATRAS_VEL+0, 0
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
	MOVF       FARG_Robot_ATRAS_VEL+0, 0
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
	CALL       _M_DATRAS+0
	CALL       _M_IATRAS+0
L_end_Robot_ATRAS:
	RETURN
; end of _Robot_ATRAS

_Robot_IZQUIERDA:

	MOVF       FARG_Robot_IZQUIERDA_VEL+0, 0
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
	MOVF       FARG_Robot_IZQUIERDA_VEL+0, 0
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
	CALL       _M_DADELANTE+0
	CALL       _M_IATRAS+0
L_end_Robot_IZQUIERDA:
	RETURN
; end of _Robot_IZQUIERDA

_Robot_DERECHA:

	MOVF       FARG_Robot_DERECHA_VEL+0, 0
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
	MOVF       FARG_Robot_DERECHA_VEL+0, 0
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
	CALL       _M_IADELANTE+0
	CALL       _M_DATRAS+0
L_end_Robot_DERECHA:
	RETURN
; end of _Robot_DERECHA

_LEER_SENSORES:

	BTFSS      RA2_bit+0, BitPos(RA2_bit+0)
	GOTO       L_LEER_SENSORES6
	BTFSS      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_LEER_SENSORES6
	BTFSS      RA5_bit+0, BitPos(RA5_bit+0)
	GOTO       L_LEER_SENSORES6
L__LEER_SENSORES44:
	MOVLW      90
	MOVWF      _VELOCIDAD+0
	MOVLW      0
	MOVWF      _VELOCIDAD+1
	GOTO       L_LEER_SENSORES7
L_LEER_SENSORES6:
	BTFSS      RA2_bit+0, BitPos(RA2_bit+0)
	GOTO       L_LEER_SENSORES10
	BTFSS      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_LEER_SENSORES10
	BTFSC      RA5_bit+0, BitPos(RA5_bit+0)
	GOTO       L_LEER_SENSORES10
L__LEER_SENSORES43:
	MOVLW      166
	MOVWF      _VELOCIDAD+0
	MOVLW      255
	MOVWF      _VELOCIDAD+1
	GOTO       L_LEER_SENSORES11
L_LEER_SENSORES10:
	BTFSS      RA2_bit+0, BitPos(RA2_bit+0)
	GOTO       L_LEER_SENSORES14
	BTFSC      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_LEER_SENSORES14
	BTFSS      RA5_bit+0, BitPos(RA5_bit+0)
	GOTO       L_LEER_SENSORES14
L__LEER_SENSORES42:
	MOVLW      166
	MOVWF      _VELOCIDAD+0
	MOVLW      255
	MOVWF      _VELOCIDAD+1
	GOTO       L_LEER_SENSORES15
L_LEER_SENSORES14:
	BTFSS      RA2_bit+0, BitPos(RA2_bit+0)
	GOTO       L_LEER_SENSORES18
	BTFSC      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_LEER_SENSORES18
	BTFSC      RA5_bit+0, BitPos(RA5_bit+0)
	GOTO       L_LEER_SENSORES18
L__LEER_SENSORES41:
	MOVLW      166
	MOVWF      _VELOCIDAD+0
	MOVLW      255
	MOVWF      _VELOCIDAD+1
	GOTO       L_LEER_SENSORES19
L_LEER_SENSORES18:
	BTFSC      RA2_bit+0, BitPos(RA2_bit+0)
	GOTO       L_LEER_SENSORES22
	BTFSS      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_LEER_SENSORES22
	BTFSS      RA5_bit+0, BitPos(RA5_bit+0)
	GOTO       L_LEER_SENSORES22
L__LEER_SENSORES40:
	MOVLW      90
	MOVWF      _VELOCIDAD+0
	MOVLW      0
	MOVWF      _VELOCIDAD+1
	GOTO       L_LEER_SENSORES23
L_LEER_SENSORES22:
	BTFSC      RA2_bit+0, BitPos(RA2_bit+0)
	GOTO       L_LEER_SENSORES26
	BTFSS      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_LEER_SENSORES26
	BTFSC      RA5_bit+0, BitPos(RA5_bit+0)
	GOTO       L_LEER_SENSORES26
L__LEER_SENSORES39:
	CLRF       _VELOCIDAD+0
	CLRF       _VELOCIDAD+1
	GOTO       L_LEER_SENSORES27
L_LEER_SENSORES26:
	BTFSC      RA2_bit+0, BitPos(RA2_bit+0)
	GOTO       L_LEER_SENSORES30
	BTFSC      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_LEER_SENSORES30
	BTFSS      RA5_bit+0, BitPos(RA5_bit+0)
	GOTO       L_LEER_SENSORES30
L__LEER_SENSORES38:
	MOVLW      90
	MOVWF      _VELOCIDAD+0
	MOVLW      0
	MOVWF      _VELOCIDAD+1
	GOTO       L_LEER_SENSORES31
L_LEER_SENSORES30:
	BTFSC      RA2_bit+0, BitPos(RA2_bit+0)
	GOTO       L_LEER_SENSORES34
	BTFSC      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_LEER_SENSORES34
	BTFSC      RA5_bit+0, BitPos(RA5_bit+0)
	GOTO       L_LEER_SENSORES34
L__LEER_SENSORES37:
	CLRF       _VELOCIDAD+0
	CLRF       _VELOCIDAD+1
L_LEER_SENSORES34:
L_LEER_SENSORES31:
L_LEER_SENSORES27:
L_LEER_SENSORES23:
L_LEER_SENSORES19:
L_LEER_SENSORES15:
L_LEER_SENSORES11:
L_LEER_SENSORES7:
L_end_LEER_SENSORES:
	RETURN
; end of _LEER_SENSORES

_main:

	CLRF       OSCCON+0
	CLRF       OSCTUNE+0
	BCF        SCS1_bit+0, BitPos(SCS1_bit+0)
	BCF        SCS0_bit+0, BitPos(SCS0_bit+0)
	BSF        IRCF3_bit+0, BitPos(IRCF3_bit+0)
	BSF        IRCF2_bit+0, BitPos(IRCF2_bit+0)
	BSF        IRCF1_bit+0, BitPos(IRCF1_bit+0)
	BCF        IRCF0_bit+0, BitPos(IRCF0_bit+0)
	CLRF       ANSELA+0
	CLRF       ANSELC+0
	BSF        TRISA2_bit+0, BitPos(TRISA2_bit+0)
	BSF        TRISA4_bit+0, BitPos(TRISA4_bit+0)
	BSF        TRISA5_bit+0, BitPos(TRISA5_bit+0)
	BCF        TRISC0_bit+0, BitPos(TRISC0_bit+0)
	BCF        TRISC1_bit+0, BitPos(TRISC1_bit+0)
	BCF        TRISC2_bit+0, BitPos(TRISC2_bit+0)
	BCF        TRISC4_bit+0, BitPos(TRISC4_bit+0)
	BCF        TRISC3_bit+0, BitPos(TRISC3_bit+0)
	BCF        TRISC5_bit+0, BitPos(TRISC5_bit+0)
	BCF        SPLLEN_bit+0, BitPos(SPLLEN_bit+0)
	BSF        T2CON+0, 0
	BSF        T2CON+0, 1
	MOVLW      124
	MOVWF      PR2+0
	CALL       _PWM1_Init+0
	BSF        T2CON+0, 0
	BSF        T2CON+0, 1
	MOVLW      124
	MOVWF      PR2+0
	CALL       _PWM2_Init+0
	MOVLW      127
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
	MOVLW      127
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
	CALL       _PWM1_Start+0
	CALL       _PWM2_Start+0
L_main35:
	CALL       _LEER_SENSORES+0
	MOVF       _VELOCIDAD+0, 0
	MOVWF      FARG_Robot_ADELANTE_VEL+0
	MOVF       _VELOCIDAD+1, 0
	MOVWF      FARG_Robot_ADELANTE_VEL+1
	CALL       _Robot_ADELANTE+0
	GOTO       L_main35
L_end_main:
	GOTO       $+0
; end of _main
