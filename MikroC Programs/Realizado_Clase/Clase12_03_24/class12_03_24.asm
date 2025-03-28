
_MAX7219_write:

	BCF        RB5_bit+0, BitPos(RB5_bit+0)
	MOVF       FARG_MAX7219_write_reg1+0, 0
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	MOVF       FARG_MAX7219_write_data1+0, 0
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	BSF        RB5_bit+0, BitPos(RB5_bit+0)
L_end_MAX7219_write:
	RETURN
; end of _MAX7219_write

_MAX7219_init:

	CALL       _SPI1_Init+0
	MOVLW      9
	MOVWF      FARG_MAX7219_write_reg1+0
	MOVLW      255
	MOVWF      FARG_MAX7219_write_data1+0
	CALL       _MAX7219_write+0
	MOVLW      10
	MOVWF      FARG_MAX7219_write_reg1+0
	MOVLW      15
	MOVWF      FARG_MAX7219_write_data1+0
	CALL       _MAX7219_write+0
	MOVLW      11
	MOVWF      FARG_MAX7219_write_reg1+0
	MOVLW      7
	MOVWF      FARG_MAX7219_write_data1+0
	CALL       _MAX7219_write+0
	MOVLW      12
	MOVWF      FARG_MAX7219_write_reg1+0
	MOVLW      1
	MOVWF      FARG_MAX7219_write_data1+0
	CALL       _MAX7219_write+0
	MOVLW      15
	MOVWF      FARG_MAX7219_write_reg1+0
	MOVLW      1
	MOVWF      FARG_MAX7219_write_data1+0
	CALL       _MAX7219_write+0
	MOVLW      15
	MOVWF      FARG_MAX7219_write_reg1+0
	CLRF       FARG_MAX7219_write_data1+0
	CALL       _MAX7219_write+0
L_end_MAX7219_init:
	RETURN
; end of _MAX7219_init

_Max7219Print:

	MOVLW      1
	MOVWF      Max7219Print_i_L0+0
	CLRF       Max7219Print_i_L0+1
	CLRF       Max7219Print_i_L0+2
	CLRF       Max7219Print_i_L0+3
L_Max7219Print0:
	MOVF       FARG_Max7219Print_Number+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__Max7219Print20
	MOVF       FARG_Max7219Print_Number+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__Max7219Print20
	MOVF       FARG_Max7219Print_Number+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__Max7219Print20
	MOVF       FARG_Max7219Print_Number+0, 0
	SUBLW      0
L__Max7219Print20:
	BTFSS      STATUS+0, 0
	GOTO       L__Max7219Print15
	MOVF       Max7219Print_i_L0+0, 0
	MOVWF      R1
	MOVF       Max7219Print_i_L0+1, 0
	MOVWF      R2
	MOVF       Max7219Print_i_L0+2, 0
	MOVWF      R3
	MOVF       Max7219Print_i_L0+3, 0
	MOVWF      R4
	MOVF       FARG_Max7219Print_NumberOfDigits+0, 0
	SUBWF      R1, 1
	MOVLW      0
	SUBWFB     R2, 1
	SUBWFB     R3, 1
	SUBWFB     R4, 1
	MOVLW      128
	MOVWF      R0
	MOVLW      128
	XORWF      R4, 0
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__Max7219Print21
	MOVF       R3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__Max7219Print21
	MOVF       R2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__Max7219Print21
	MOVF       R1, 0
	SUBLW      0
L__Max7219Print21:
	BTFSC      STATUS+0, 0
	GOTO       L__Max7219Print15
	GOTO       L_Max7219Print1
L__Max7219Print15:
	BCF        RB5_bit+0, BitPos(RB5_bit+0)
	MOVF       Max7219Print_i_L0+0, 0
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	MOVLW      10
	MOVWF      R4
	CLRF       R5
	CLRF       R6
	CLRF       R7
	MOVF       FARG_Max7219Print_Number+0, 0
	MOVWF      R0
	MOVF       FARG_Max7219Print_Number+1, 0
	MOVWF      R1
	MOVF       FARG_Max7219Print_Number+2, 0
	MOVWF      R2
	MOVF       FARG_Max7219Print_Number+3, 0
	MOVWF      R3
	CALL       _Div_32x32_U+0
	MOVF       R8, 0
	MOVWF      R0
	MOVF       R9, 0
	MOVWF      R1
	MOVF       R10, 0
	MOVWF      R2
	MOVF       R11, 0
	MOVWF      R3
	MOVF       R0, 0
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	BSF        RB5_bit+0, BitPos(RB5_bit+0)
	MOVLW      10
	MOVWF      R4
	CLRF       R5
	CLRF       R6
	CLRF       R7
	MOVF       FARG_Max7219Print_Number+0, 0
	MOVWF      R0
	MOVF       FARG_Max7219Print_Number+1, 0
	MOVWF      R1
	MOVF       FARG_Max7219Print_Number+2, 0
	MOVWF      R2
	MOVF       FARG_Max7219Print_Number+3, 0
	MOVWF      R3
	CALL       _Div_32x32_U+0
	MOVF       R0, 0
	MOVWF      FARG_Max7219Print_Number+0
	MOVF       R1, 0
	MOVWF      FARG_Max7219Print_Number+1
	MOVF       R2, 0
	MOVWF      FARG_Max7219Print_Number+2
	MOVF       R3, 0
	MOVWF      FARG_Max7219Print_Number+3
	MOVLW      1
	ADDWF      Max7219Print_i_L0+0, 1
	MOVLW      0
	ADDWFC     Max7219Print_i_L0+1, 1
	ADDWFC     Max7219Print_i_L0+2, 1
	ADDWFC     Max7219Print_i_L0+3, 1
	GOTO       L_Max7219Print0
L_Max7219Print1:
L_end_Max7219Print:
	RETURN
; end of _Max7219Print

_Max7219DisplayOff:

	BCF        RB5_bit+0, BitPos(RB5_bit+0)
	MOVLW      12
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	CLRF       FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	BSF        RB5_bit+0, BitPos(RB5_bit+0)
L_end_Max7219DisplayOff:
	RETURN
; end of _Max7219DisplayOff

_Max7219DisplayOn:

	BCF        RB5_bit+0, BitPos(RB5_bit+0)
	MOVLW      12
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	MOVLW      1
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	BSF        RB5_bit+0, BitPos(RB5_bit+0)
L_end_Max7219DisplayOn:
	RETURN
; end of _Max7219DisplayOn

_Max7219UpdateIntensity:

	MOVLW      0
	SUBWF      FARG_Max7219UpdateIntensity_OnValue+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_Max7219UpdateIntensity7
	MOVF       FARG_Max7219UpdateIntensity_OnValue+0, 0
	SUBLW      15
	BTFSS      STATUS+0, 0
	GOTO       L_Max7219UpdateIntensity7
L__Max7219UpdateIntensity16:
	BCF        RB5_bit+0, BitPos(RB5_bit+0)
	MOVLW      10
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	MOVF       FARG_Max7219UpdateIntensity_OnValue+0, 0
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
	BSF        RB5_bit+0, BitPos(RB5_bit+0)
L_Max7219UpdateIntensity7:
L_end_Max7219UpdateIntensity:
	RETURN
; end of _Max7219UpdateIntensity

_main:

	MOVLW      112
	MOVWF      OSCCON+0
	CLRF       TRISB+0
	CLRF       ANSELB+0
	BCF        RB5_bit+0, BitPos(RB5_bit+0)
	BCF        TRISB5_bit+0, BitPos(TRISB5_bit+0)
	CALL       _SPI1_Init+0
	CALL       _MAX7219_init+0
	CALL       _Max7219DisplayOn+0
	MOVLW      5
	MOVWF      R11
	MOVLW      15
	MOVWF      R12
	MOVLW      241
	MOVWF      R13
L_main8:
	DECFSZ     R13, 1
	GOTO       L_main8
	DECFSZ     R12, 1
	GOTO       L_main8
	DECFSZ     R11, 1
	GOTO       L_main8
L_main9:
	MOVLW      78
	MOVWF      _i+0
	MOVLW      97
	MOVWF      _i+1
	MOVLW      188
	MOVWF      _i+2
	MOVLW      0
	MOVWF      _i+3
L_main11:
	MOVLW      5
	SUBWF      _i+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main26
	MOVLW      245
	SUBWF      _i+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main26
	MOVLW      224
	SUBWF      _i+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main26
	MOVLW      255
	SUBWF      _i+0, 0
L__main26:
	BTFSC      STATUS+0, 0
	GOTO       L_main12
	MOVF       _i+0, 0
	MOVWF      FARG_Max7219Print_Number+0
	MOVF       _i+1, 0
	MOVWF      FARG_Max7219Print_Number+1
	MOVF       _i+2, 0
	MOVWF      FARG_Max7219Print_Number+2
	MOVF       _i+3, 0
	MOVWF      FARG_Max7219Print_Number+3
	MOVLW      7
	MOVWF      FARG_Max7219Print_NumberOfDigits+0
	CALL       _Max7219Print+0
	MOVLW      41
	MOVWF      R11
	MOVLW      150
	MOVWF      R12
	MOVLW      127
	MOVWF      R13
L_main14:
	DECFSZ     R13, 1
	GOTO       L_main14
	DECFSZ     R12, 1
	GOTO       L_main14
	DECFSZ     R11, 1
	GOTO       L_main14
	MOVLW      1
	ADDWF      _i+0, 1
	MOVLW      0
	ADDWFC     _i+1, 1
	ADDWFC     _i+2, 1
	ADDWFC     _i+3, 1
	GOTO       L_main11
L_main12:
	GOTO       L_main9
L_end_main:
	GOTO       $+0
; end of _main
