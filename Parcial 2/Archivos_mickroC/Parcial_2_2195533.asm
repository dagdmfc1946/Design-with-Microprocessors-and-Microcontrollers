
_main:

	MOVLW      100
	MOVWF      main_period_L0+0
	MOVLW      0
	MOVWF      main_period_L0+1
	CLRF       ANSELA+0
	CLRF       ANSELB+0
	CLRF       TRISA+0
	MOVLW      255
	MOVWF      TRISB+0
	BCF        TRISA7_bit+0, BitPos(TRISA7_bit+0)
	CALL       _Lcd_Init+0
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      80
	MOVWF      ?lstr1_Parcial_2_2195533+0
	MOVLW      101
	MOVWF      ?lstr1_Parcial_2_2195533+1
	MOVLW      114
	MOVWF      ?lstr1_Parcial_2_2195533+2
	MOVLW      105
	MOVWF      ?lstr1_Parcial_2_2195533+3
	MOVLW      111
	MOVWF      ?lstr1_Parcial_2_2195533+4
	MOVLW      100
	MOVWF      ?lstr1_Parcial_2_2195533+5
	MOVLW      111
	MOVWF      ?lstr1_Parcial_2_2195533+6
	MOVLW      58
	MOVWF      ?lstr1_Parcial_2_2195533+7
	MOVLW      32
	MOVWF      ?lstr1_Parcial_2_2195533+8
	CLRF       ?lstr1_Parcial_2_2195533+9
	MOVLW      ?lstr1_Parcial_2_2195533+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr1_Parcial_2_2195533+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      ?lstr2_Parcial_2_2195533+0
	MOVLW      48
	MOVWF      ?lstr2_Parcial_2_2195533+1
	MOVLW      48
	MOVWF      ?lstr2_Parcial_2_2195533+2
	MOVLW      32
	MOVWF      ?lstr2_Parcial_2_2195533+3
	MOVLW      109
	MOVWF      ?lstr2_Parcial_2_2195533+4
	MOVLW      115
	MOVWF      ?lstr2_Parcial_2_2195533+5
	CLRF       ?lstr2_Parcial_2_2195533+6
	MOVLW      ?lstr2_Parcial_2_2195533+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr2_Parcial_2_2195533+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	CALL       _Keypad_Init+0
L_main0:
	CALL       _Keypad_Key_Click+0
	MOVF       R0, 0
	MOVWF      main_key_L1+0
	MOVF       R0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_main2
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      84
	MOVWF      ?lstr3_Parcial_2_2195533+0
	MOVLW      101
	MOVWF      ?lstr3_Parcial_2_2195533+1
	MOVLW      99
	MOVWF      ?lstr3_Parcial_2_2195533+2
	MOVLW      108
	MOVWF      ?lstr3_Parcial_2_2195533+3
	MOVLW      97
	MOVWF      ?lstr3_Parcial_2_2195533+4
	MOVLW      32
	MOVWF      ?lstr3_Parcial_2_2195533+5
	MOVLW      112
	MOVWF      ?lstr3_Parcial_2_2195533+6
	MOVLW      117
	MOVWF      ?lstr3_Parcial_2_2195533+7
	MOVLW      108
	MOVWF      ?lstr3_Parcial_2_2195533+8
	MOVLW      115
	MOVWF      ?lstr3_Parcial_2_2195533+9
	MOVLW      97
	MOVWF      ?lstr3_Parcial_2_2195533+10
	MOVLW      100
	MOVWF      ?lstr3_Parcial_2_2195533+11
	MOVLW      97
	MOVWF      ?lstr3_Parcial_2_2195533+12
	MOVLW      58
	MOVWF      ?lstr3_Parcial_2_2195533+13
	CLRF       ?lstr3_Parcial_2_2195533+14
	MOVLW      ?lstr3_Parcial_2_2195533+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr3_Parcial_2_2195533+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      5
	MOVWF      FARG_Lcd_Chr_column+0
	MOVF       main_key_L1+0, 0
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
	GOTO       L_main3
L_main5:
	MOVLW      128
	XORWF      main_period_L0+1, 0
	MOVWF      R0
	MOVLW      128
	XORLW      31
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main13
	MOVLW      64
	SUBWF      main_period_L0+0, 0
L__main13:
	BTFSC      STATUS+0, 0
	GOTO       L_main6
	MOVLW      100
	ADDWF      main_period_L0+0, 1
	MOVLW      0
	ADDWFC     main_period_L0+1, 1
L_main6:
	GOTO       L_main4
L_main7:
	MOVLW      128
	MOVWF      R0
	MOVLW      128
	XORWF      main_period_L0+1, 0
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main14
	MOVF       main_period_L0+0, 0
	SUBLW      100
L__main14:
	BTFSC      STATUS+0, 0
	GOTO       L_main8
	MOVLW      100
	SUBWF      main_period_L0+0, 1
	MOVLW      0
	SUBWFB     main_period_L0+1, 1
L_main8:
	GOTO       L_main4
L_main9:
	GOTO       L_main4
L_main3:
	MOVF       main_key_L1+0, 0
	XORLW      65
	BTFSC      STATUS+0, 2
	GOTO       L_main5
	MOVF       main_key_L1+0, 0
	XORLW      66
	BTFSC      STATUS+0, 2
	GOTO       L_main7
	GOTO       L_main9
L_main4:
	MOVF       main_period_L0+0, 0
	MOVWF      FARG_IntToStr_input+0
	MOVF       main_period_L0+1, 0
	MOVWF      FARG_IntToStr_input+1
	MOVLW      _period_str+0
	MOVWF      FARG_IntToStr_output+0
	MOVLW      hi_addr(_period_str+0)
	MOVWF      FARG_IntToStr_output+1
	CALL       _IntToStr+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _period_str+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(_period_str+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	MOVLW      52
	MOVWF      R12
	MOVLW      241
	MOVWF      R13
L_main10:
	DECFSZ     R13, 1
	GOTO       L_main10
	DECFSZ     R12, 1
	GOTO       L_main10
	NOP
	NOP
L_main2:
	MOVLW
	XORWF      RA7_bit+0, 1
	MOVLW      52
	MOVWF      R12
	MOVLW      241
	MOVWF      R13
L_main11:
	DECFSZ     R13, 1
	GOTO       L_main11
	DECFSZ     R12, 1
	GOTO       L_main11
	NOP
	NOP
	GOTO       L_main0
L_end_main:
	GOTO       $+0
; end of _main
