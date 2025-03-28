
_teclado_deco:

	CLRF       teclado_deco_tec_L0+0
	CALL       _Keypad_Key_Press+0
	MOVF       R0, 0
	MOVWF      teclado_deco_tec_L0+0
	MOVF       R0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco0
	MOVLW      11
	MOVWF      _sins+0
	MOVLW      0
	MOVWF      _sins+1
	MOVLW      11
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _tex+0
	MOVWF      FARG_ByteToStr_output+0
	MOVLW      hi_addr(_tex+0)
	MOVWF      FARG_ByteToStr_output+1
	CALL       _ByteToStr+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _tex+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(_tex+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco1
L_teclado_deco3:
	MOVLW      100
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      0
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      ?lstr1_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr1_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr1_evaluacio_2+2
	MOVLW      32
	MOVWF      ?lstr1_evaluacio_2+3
	CLRF       ?lstr1_evaluacio_2+4
	MOVLW      ?lstr1_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr1_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco4:
	MOVLW      44
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      1
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      51
	MOVWF      ?lstr2_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr2_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr2_evaluacio_2+2
	MOVLW      32
	MOVWF      ?lstr2_evaluacio_2+3
	CLRF       ?lstr2_evaluacio_2+4
	MOVLW      ?lstr2_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr2_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco5:
	MOVLW      188
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      2
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      55
	MOVWF      ?lstr3_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr3_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr3_evaluacio_2+2
	MOVLW      32
	MOVWF      ?lstr3_evaluacio_2+3
	CLRF       ?lstr3_evaluacio_2+4
	MOVLW      ?lstr3_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr3_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco6:
	MOVLW      32
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      3
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      56
	MOVWF      ?lstr4_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr4_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr4_evaluacio_2+2
	MOVLW      32
	MOVWF      ?lstr4_evaluacio_2+3
	CLRF       ?lstr4_evaluacio_2+4
	MOVLW      ?lstr4_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr4_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco7:
	MOVLW      232
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      3
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      ?lstr5_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr5_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr5_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr5_evaluacio_2+3
	CLRF       ?lstr5_evaluacio_2+4
	MOVLW      ?lstr5_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr5_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco8:
	MOVLW      220
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      5
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      ?lstr6_evaluacio_2+0
	MOVLW      53
	MOVWF      ?lstr6_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr6_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr6_evaluacio_2+3
	CLRF       ?lstr6_evaluacio_2+4
	MOVLW      ?lstr6_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr6_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco9:
	MOVLW      208
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      7
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      50
	MOVWF      ?lstr7_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr7_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr7_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr7_evaluacio_2+3
	CLRF       ?lstr7_evaluacio_2+4
	MOVLW      ?lstr7_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr7_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco10:
	MOVLW      196
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      9
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      50
	MOVWF      ?lstr8_evaluacio_2+0
	MOVLW      53
	MOVWF      ?lstr8_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr8_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr8_evaluacio_2+3
	CLRF       ?lstr8_evaluacio_2+4
	MOVLW      ?lstr8_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr8_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco11:
	MOVLW      172
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      13
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      51
	MOVWF      ?lstr9_evaluacio_2+0
	MOVLW      53
	MOVWF      ?lstr9_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr9_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr9_evaluacio_2+3
	CLRF       ?lstr9_evaluacio_2+4
	MOVLW      ?lstr9_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr9_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco12:
	MOVLW      160
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      15
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      52
	MOVWF      ?lstr10_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr10_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr10_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr10_evaluacio_2+3
	CLRF       ?lstr10_evaluacio_2+4
	MOVLW      ?lstr10_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr10_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco13:
	MOVLW      136
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      19
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      53
	MOVWF      ?lstr11_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr11_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr11_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr11_evaluacio_2+3
	CLRF       ?lstr11_evaluacio_2+4
	MOVLW      ?lstr11_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr11_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco14:
	MOVLW      112
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      23
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      54
	MOVWF      ?lstr12_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr12_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr12_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr12_evaluacio_2+3
	CLRF       ?lstr12_evaluacio_2+4
	MOVLW      ?lstr12_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr12_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco15:
	MOVLW      100
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      25
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      54
	MOVWF      ?lstr13_evaluacio_2+0
	MOVLW      53
	MOVWF      ?lstr13_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr13_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr13_evaluacio_2+3
	CLRF       ?lstr13_evaluacio_2+4
	MOVLW      ?lstr13_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr13_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco16:
	MOVLW      88
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      27
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      55
	MOVWF      ?lstr14_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr14_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr14_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr14_evaluacio_2+3
	CLRF       ?lstr14_evaluacio_2+4
	MOVLW      ?lstr14_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr14_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco17:
	MOVLW      76
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      29
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      55
	MOVWF      ?lstr15_evaluacio_2+0
	MOVLW      53
	MOVWF      ?lstr15_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr15_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr15_evaluacio_2+3
	CLRF       ?lstr15_evaluacio_2+4
	MOVLW      ?lstr15_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr15_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco18:
	MOVLW      64
	MOVWF      teclado_deco_retardo_L0+0
	MOVLW      31
	MOVWF      teclado_deco_retardo_L0+1
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      56
	MOVWF      ?lstr16_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr16_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr16_evaluacio_2+2
	MOVLW      48
	MOVWF      ?lstr16_evaluacio_2+3
	CLRF       ?lstr16_evaluacio_2+4
	MOVLW      ?lstr16_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr16_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	GOTO       L_teclado_deco2
L_teclado_deco1:
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco3
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco4
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco5
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco6
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco7
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      6
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco8
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      7
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco9
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      8
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco10
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      9
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco11
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      10
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco12
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      11
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco13
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      12
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco14
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      13
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco15
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      14
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco16
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      15
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco17
	MOVF       teclado_deco_tec_L0+0, 0
	XORLW      16
	BTFSC      STATUS+0, 2
	GOTO       L_teclado_deco18
L_teclado_deco2:
	MOVLW      10
	MOVWF      R12
	MOVLW      88
	MOVWF      R13
L_teclado_deco19:
	DECFSZ     R13, 1
	GOTO       L_teclado_deco19
	DECFSZ     R12, 1
	GOTO       L_teclado_deco19
	NOP
	MOVF       teclado_deco_retardo_L0+0, 0
	MOVWF      R0
	MOVF       teclado_deco_retardo_L0+1, 0
	MOVWF      R1
	LSRF       R1, 1
	RRF        R0, 1
	MOVF       R0, 0
	MOVWF      _final+0
	MOVF       R1, 0
	MOVWF      _final+1
	GOTO       L_end_teclado_deco
L_teclado_deco0:
L_end_teclado_deco:
	RETURN
; end of _teclado_deco

_miretardo:

L_miretardo20:
	MOVLW      128
	MOVWF      R0
	MOVLW      128
	XORWF      FARG_miretardo_valor+1, 0
	SUBWF      R0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__miretardo27
	MOVF       FARG_miretardo_valor+0, 0
	SUBLW      0
L__miretardo27:
	BTFSC      STATUS+0, 0
	GOTO       L_miretardo21
	MOVLW      10
	MOVWF      R12
	MOVLW      88
	MOVWF      R13
L_miretardo22:
	DECFSZ     R13, 1
	GOTO       L_miretardo22
	DECFSZ     R12, 1
	GOTO       L_miretardo22
	NOP
	CALL       _teclado_deco+0
	MOVLW      1
	SUBWF      FARG_miretardo_valor+0, 1
	MOVLW      0
	SUBWFB     FARG_miretardo_valor+1, 1
	GOTO       L_miretardo20
L_miretardo21:
L_end_miretardo:
	RETURN
; end of _miretardo

_main:

	MOVLW      112
	MOVWF      OSCCON+0
	CLRF       ANSELA+0
	CLRF       ANSELB+0
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
	MOVLW      84
	MOVWF      ?lstr17_evaluacio_2+0
	MOVLW      69
	MOVWF      ?lstr17_evaluacio_2+1
	MOVLW      67
	MOVWF      ?lstr17_evaluacio_2+2
	MOVLW      76
	MOVWF      ?lstr17_evaluacio_2+3
	MOVLW      65
	MOVWF      ?lstr17_evaluacio_2+4
	MOVLW      68
	MOVWF      ?lstr17_evaluacio_2+5
	MOVLW      79
	MOVWF      ?lstr17_evaluacio_2+6
	CLRF       ?lstr17_evaluacio_2+7
	MOVLW      ?lstr17_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr17_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      109
	MOVWF      ?lstr18_evaluacio_2+0
	MOVLW      115
	MOVWF      ?lstr18_evaluacio_2+1
	CLRF       ?lstr18_evaluacio_2+2
	MOVLW      ?lstr18_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr18_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
	CALL       _Keypad_Init+0
	BCF        TRISA7_bit+0, BitPos(TRISA7_bit+0)
	BSF        LATA7_bit+0, BitPos(LATA7_bit+0)
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      ?lstr19_evaluacio_2+0
	MOVLW      48
	MOVWF      ?lstr19_evaluacio_2+1
	MOVLW      48
	MOVWF      ?lstr19_evaluacio_2+2
	MOVLW      32
	MOVWF      ?lstr19_evaluacio_2+3
	CLRF       ?lstr19_evaluacio_2+4
	MOVLW      ?lstr19_evaluacio_2+0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      hi_addr(?lstr19_evaluacio_2+0)
	MOVWF      FARG_Lcd_Out_text+1
	CALL       _Lcd_Out+0
L_main23:
	MOVLW
	XORWF      LATA7_bit+0, 1
	MOVF       _final+0, 0
	MOVWF      FARG_miretardo_valor+0
	MOVF       _final+1, 0
	MOVWF      FARG_miretardo_valor+1
	CALL       _miretardo+0
	GOTO       L_main23
L_end_main:
	GOTO       $+0
; end of _main
