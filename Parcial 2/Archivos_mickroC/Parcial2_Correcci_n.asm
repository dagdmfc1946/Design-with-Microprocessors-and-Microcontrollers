
_f_keypad:

	CALL       _Keypad_Key_Click+0
	MOVF       R0, 0
	MOVWF      _key+0
	MOVF       R0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad0
	GOTO       L_f_keypad1
L_f_keypad3:
	MOVLW      100
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      0
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      ?lstr1_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr1_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr1_Parcial2_Correcci_n+2
	MOVLW      32
	MOVWF      ?lstr1_Parcial2_Correcci_n+3
	CLRF       ?lstr1_Parcial2_Correcci_n+4
	MOVLW      ?lstr1_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr1_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad4:
	MOVLW      244
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      1
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      53
	MOVWF      ?lstr2_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr2_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr2_Parcial2_Correcci_n+2
	MOVLW      32
	MOVWF      ?lstr2_Parcial2_Correcci_n+3
	CLRF       ?lstr2_Parcial2_Correcci_n+4
	MOVLW      ?lstr2_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr2_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad5:
	MOVLW      232
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      3
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      ?lstr3_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr3_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr3_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr3_Parcial2_Correcci_n+3
	CLRF       ?lstr3_Parcial2_Correcci_n+4
	MOVLW      ?lstr3_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr3_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad6:
	MOVLW      220
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      5
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      ?lstr4_Parcial2_Correcci_n+0
	MOVLW      53
	MOVWF      ?lstr4_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr4_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr4_Parcial2_Correcci_n+3
	CLRF       ?lstr4_Parcial2_Correcci_n+4
	MOVLW      ?lstr4_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr4_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad7:
	MOVLW      208
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      7
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      50
	MOVWF      ?lstr5_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr5_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr5_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr5_Parcial2_Correcci_n+3
	CLRF       ?lstr5_Parcial2_Correcci_n+4
	MOVLW      ?lstr5_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr5_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad8:
	MOVLW      196
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      9
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      50
	MOVWF      ?lstr6_Parcial2_Correcci_n+0
	MOVLW      53
	MOVWF      ?lstr6_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr6_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr6_Parcial2_Correcci_n+3
	CLRF       ?lstr6_Parcial2_Correcci_n+4
	MOVLW      ?lstr6_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr6_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad9:
	MOVLW      184
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      11
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      51
	MOVWF      ?lstr7_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr7_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr7_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr7_Parcial2_Correcci_n+3
	CLRF       ?lstr7_Parcial2_Correcci_n+4
	MOVLW      ?lstr7_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr7_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad10:
	MOVLW      172
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      13
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      51
	MOVWF      ?lstr8_Parcial2_Correcci_n+0
	MOVLW      53
	MOVWF      ?lstr8_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr8_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr8_Parcial2_Correcci_n+3
	CLRF       ?lstr8_Parcial2_Correcci_n+4
	MOVLW      ?lstr8_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr8_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad11:
	MOVLW      148
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      17
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      52
	MOVWF      ?lstr9_Parcial2_Correcci_n+0
	MOVLW      53
	MOVWF      ?lstr9_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr9_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr9_Parcial2_Correcci_n+3
	CLRF       ?lstr9_Parcial2_Correcci_n+4
	MOVLW      ?lstr9_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr9_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad12:
	MOVLW      136
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      19
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      53
	MOVWF      ?lstr10_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr10_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr10_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr10_Parcial2_Correcci_n+3
	CLRF       ?lstr10_Parcial2_Correcci_n+4
	MOVLW      ?lstr10_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr10_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad13:
	MOVLW      124
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      21
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      53
	MOVWF      ?lstr11_Parcial2_Correcci_n+0
	MOVLW      53
	MOVWF      ?lstr11_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr11_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr11_Parcial2_Correcci_n+3
	CLRF       ?lstr11_Parcial2_Correcci_n+4
	MOVLW      ?lstr11_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr11_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad14:
	MOVLW      112
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      23
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      54
	MOVWF      ?lstr12_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr12_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr12_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr12_Parcial2_Correcci_n+3
	CLRF       ?lstr12_Parcial2_Correcci_n+4
	MOVLW      ?lstr12_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr12_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad15:
	MOVLW      100
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      25
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      54
	MOVWF      ?lstr13_Parcial2_Correcci_n+0
	MOVLW      53
	MOVWF      ?lstr13_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr13_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr13_Parcial2_Correcci_n+3
	CLRF       ?lstr13_Parcial2_Correcci_n+4
	MOVLW      ?lstr13_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr13_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad16:
	MOVLW      88
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      27
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      55
	MOVWF      ?lstr14_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr14_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr14_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr14_Parcial2_Correcci_n+3
	CLRF       ?lstr14_Parcial2_Correcci_n+4
	MOVLW      ?lstr14_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr14_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad17:
	MOVLW      76
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      29
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      55
	MOVWF      ?lstr15_Parcial2_Correcci_n+0
	MOVLW      53
	MOVWF      ?lstr15_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr15_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr15_Parcial2_Correcci_n+3
	CLRF       ?lstr15_Parcial2_Correcci_n+4
	MOVLW      ?lstr15_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr15_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad18:
	MOVLW      64
	MOVWF      f_keypad_T_variable_L0+0
	MOVLW      31
	MOVWF      f_keypad_T_variable_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      56
	MOVWF      ?lstr16_Parcial2_Correcci_n+0
	MOVLW      48
	MOVWF      ?lstr16_Parcial2_Correcci_n+1
	MOVLW      48
	MOVWF      ?lstr16_Parcial2_Correcci_n+2
	MOVLW      48
	MOVWF      ?lstr16_Parcial2_Correcci_n+3
	CLRF       ?lstr16_Parcial2_Correcci_n+4
	MOVLW      ?lstr16_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr16_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_f_keypad2
L_f_keypad1:
	MOVF       _key+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad3
	MOVF       _key+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad4
	MOVF       _key+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad5
	MOVF       _key+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad6
	MOVF       _key+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad7
	MOVF       _key+0, 0
	XORLW      6
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad8
	MOVF       _key+0, 0
	XORLW      7
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad9
	MOVF       _key+0, 0
	XORLW      8
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad10
	MOVF       _key+0, 0
	XORLW      9
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad11
	MOVF       _key+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad12
	MOVF       _key+0, 0
	XORLW      11
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad13
	MOVF       _key+0, 0
	XORLW      12
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad14
	MOVF       _key+0, 0
	XORLW      13
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad15
	MOVF       _key+0, 0
	XORLW      14
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad16
	MOVF       _key+0, 0
	XORLW      15
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad17
	MOVF       _key+0, 0
	XORLW      16
	BTFSC      STATUS+0, 2
	GOTO       L_f_keypad18
L_f_keypad2:
	MOVLW      9
	MOVWF      R12
	MOVLW      78
	MOVWF      R13
L_f_keypad19:
	DECFSZ     R13, 1
	GOTO       L_f_keypad19
	DECFSZ     R12, 1
	GOTO       L_f_keypad19
	NOP
	MOVF       f_keypad_T_variable_L0+0, 0
	MOVWF      R0
	MOVF       f_keypad_T_variable_L0+1, 0
	MOVWF      R1
	LSRF       R1, 1
	RRF        R0, 1
	MOVF       R0, 0
	MOVWF      _T_end+0
	MOVF       R1, 0
	MOVWF      _T_end+1
	GOTO       L_end_f_keypad
L_f_keypad0:
L_end_f_keypad:
	RETURN
; end of _f_keypad

_Periodo_Variable:

	MOVF       FARG_Periodo_Variable_Period+0, 0
	MOVWF      Periodo_Variable_i_L0+0
	MOVF       FARG_Periodo_Variable_Period+1, 0
	MOVWF      Periodo_Variable_i_L0+1
L_Periodo_Variable20:
	MOVLW      128
	MOVWF      R0
	MOVLW      128
	XORWF      Periodo_Variable_i_L0+1, 0
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__Periodo_Variable28
	MOVF       Periodo_Variable_i_L0+0, 0
	SUBLW      0
L__Periodo_Variable28:
	BTFSC      STATUS+0, 0
	GOTO       L_Periodo_Variable21
	MOVLW      9
	MOVWF      R12
	MOVLW      78
	MOVWF      R13
L_Periodo_Variable23:
	DECFSZ     R13, 1
	GOTO       L_Periodo_Variable23
	DECFSZ     R12, 1
	GOTO       L_Periodo_Variable23
	NOP
	CALL       _f_keypad+0
	MOVLW      1
	SUBWF      Periodo_Variable_i_L0+0, 1
	MOVLW      0
	SUBWFB     Periodo_Variable_i_L0+1, 1
	GOTO       L_Periodo_Variable20
L_Periodo_Variable21:
L_end_Periodo_Variable:
	RETURN
; end of _Periodo_Variable

_main:

	MOVLW      243
	MOVWF      OSCCON+0
	CLRF       ANSELA+0
	CLRF       ANSELB+0
	CLRF       TRISA+0
	MOVLW      255
	MOVWF      TRISB+0
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
	MOVLW      ?ICS?lstr17_Parcial2_Correcci_n+0
	MOVWF      FSR0L
	MOVLW      hi_addr(?ICS?lstr17_Parcial2_Correcci_n+0)
	MOVWF      FSR0H
	MOVLW      ?lstr17_Parcial2_Correcci_n+0
	MOVWF      FSR1L
	MOVLW      hi_addr(?lstr17_Parcial2_Correcci_n+0)
	MOVWF      FSR1H
	MOVLW      18
	MOVWF      R0
	MOVLW      1
	MOVWF      R1
	CALL       ___CC2DW+0
	MOVLW      ?lstr17_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr17_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      78
	MOVWF      ?lstr18_Parcial2_Correcci_n+0
	MOVLW      101
	MOVWF      ?lstr18_Parcial2_Correcci_n+1
	MOVLW      119
	MOVWF      ?lstr18_Parcial2_Correcci_n+2
	MOVLW      32
	MOVWF      ?lstr18_Parcial2_Correcci_n+3
	MOVLW      84
	MOVWF      ?lstr18_Parcial2_Correcci_n+4
	MOVLW      58
	MOVWF      ?lstr18_Parcial2_Correcci_n+5
	MOVLW      32
	MOVWF      ?lstr18_Parcial2_Correcci_n+6
	CLRF       ?lstr18_Parcial2_Correcci_n+7
	MOVLW      ?lstr18_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr18_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      13
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      91
	MOVWF      ?lstr19_Parcial2_Correcci_n+0
	MOVLW      109
	MOVWF      ?lstr19_Parcial2_Correcci_n+1
	MOVLW      115
	MOVWF      ?lstr19_Parcial2_Correcci_n+2
	MOVLW      93
	MOVWF      ?lstr19_Parcial2_Correcci_n+3
	CLRF       ?lstr19_Parcial2_Correcci_n+4
	MOVLW      ?lstr19_Parcial2_Correcci_n+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr19_Parcial2_Correcci_n+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	CALL       _Keypad_Init+0
	BCF        TRISA7_bit+0, BitPos(TRISA7_bit+0)
L_main24:
	MOVLW
	XORWF      LATA7_bit+0, 1
	MOVF       _T_end+0, 0
	MOVWF      FARG_Periodo_Variable_Period+0
	MOVF       _T_end+1, 0
	MOVWF      FARG_Periodo_Variable_Period+1
	CALL       _Periodo_Variable+0
	GOTO       L_main24
L_end_main:
	GOTO       $+0
; end of _main
