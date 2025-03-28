
_InitMain:

	BCF        TRISA+0, 0
	BCF        TRISA+0, 1
	BCF        TRISA+0, 4
	BCF        TRISA+0, 5
	BSF        LATA+0, 4
	BSF        LATA+0, 5
	CLRF       FARG_SPI1_Init_Advanced_master+0
	CLRF       FARG_SPI1_Init_Advanced_data_sample+0
	CLRF       FARG_SPI1_Init_Advanced_clock_idle+0
	MOVLW      1
	MOVWF      FARG_SPI1_Init_Advanced_transmit_edge+0
	CALL       _SPI1_Init_Advanced+0
L_end_InitMain:
	RETURN
; end of _InitMain

_signal_sen:

	MOVF       FARG_signal_sen_values+1, 0
	MOVWF      R0
	MOVLW      0
	BTFSC      FARG_signal_sen_values+1, 7
	MOVLW      255
	MOVWF      R1
	MOVLW      15
	ANDWF      R0, 0
	MOVWF      FARG_SPI1_Write_data_+0
	MOVLW      48
	IORWF       FARG_SPI1_Write_data_+0, 1
	BCF        LATA+0, 5
	CALL       _SPI1_Write+0
	MOVF       FARG_signal_sen_values+0, 0
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	BSF        LATA+0, 5
	BCF        LATA+0, 4
	BSF        LATA+0, 4
L_end_signal_sen:
	RETURN
; end of _signal_sen

_main:

	MOVLW      243
	MOVWF      OSCCON+0
	CALL       _InitMain+0
L_main0:
	MOVF       _i+0, 0
	MOVWF      R0
	MOVF       _i+1, 0
	MOVWF      R1
	LSLF       R0, 1
	RLF        R1, 1
	MOVLW      _sen+0
	ADDWF      R0, 0
	MOVWF      FSR0L
	MOVLW      hi_addr(_sen+0)
	ADDWFC     R1, 0
	MOVWF      FSR0H
	MOVF       INDF0+0, 0
	MOVWF      FARG_signal_sen_values+0
	ADDFSR     0, 1
	MOVF       INDF0+0, 0
	MOVWF      FARG_signal_sen_values+1
	CALL       _signal_sen+0
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
	MOVF       _i+1, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L__main7
	MOVLW      104
	XORWF      _i+0, 0
L__main7:
	BTFSS      STATUS+0, 2
	GOTO       L_main2
	CLRF       _i+0
	CLRF       _i+1
L_main2:
	MOVLW      2
	MOVWF      R13
L_main3:
	DECFSZ     R13, 1
	GOTO       L_main3
	NOP
	GOTO       L_main0
L_end_main:
	GOTO       $+0
; end of _main
