
_main:

	CLRF       ANSELA+0
	CLRF       TRISA+0
	CLRF       ANSELB+0
	MOVLW      34
	MOVWF      TRISB+0
	MOVLW      240
	MOVWF      OSCCON+0
	BCF        APFCON0+0, 7
	BCF        APFCON1+0, 0
	BSF        BAUDCON+0, 3
	MOVLW      138
	MOVWF      SPBRG+0
	CLRF       SPBRG+1
	BSF        TXSTA+0, 2
	CALL       _UART1_Init+0
	MOVLW      5
	MOVWF      R11
	MOVLW      15
	MOVWF      R12
	MOVLW      241
	MOVWF      R13
L_main0:
	DECFSZ     R13, 1
	GOTO       L_main0
	DECFSZ     R12, 1
	GOTO       L_main0
	DECFSZ     R11, 1
	GOTO       L_main0
	MOVLW      ?ICS?lstr1_EUSART_Basico+0
	MOVWF      FSR0L
	MOVLW      hi_addr(?ICS?lstr1_EUSART_Basico+0)
	MOVWF      FSR0H
	MOVLW      ?lstr1_EUSART_Basico+0
	MOVWF      FSR1L
	MOVLW      hi_addr(?lstr1_EUSART_Basico+0)
	MOVWF      FSR1H
	MOVLW      25
	MOVWF      R0
	MOVLW      1
	MOVWF      R1
	CALL       ___CC2DW+0
	MOVLW      ?lstr1_EUSART_Basico+0
	MOVWF      FARG_UART1_Write_Text_uart_text+0
	MOVLW      hi_addr(?lstr1_EUSART_Basico+0)
	MOVWF      FARG_UART1_Write_Text_uart_text+1
	CALL       _UART1_Write_Text+0
	MOVLW      13
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
	MOVLW      10
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
	MOVLW      ?ICS?lstr2_EUSART_Basico+0
	MOVWF      FSR0L
	MOVLW      hi_addr(?ICS?lstr2_EUSART_Basico+0)
	MOVWF      FSR0H
	MOVLW      ?lstr2_EUSART_Basico+0
	MOVWF      FSR1L
	MOVLW      hi_addr(?lstr2_EUSART_Basico+0)
	MOVWF      FSR1H
	MOVLW      20
	MOVWF      R0
	MOVLW      1
	MOVWF      R1
	CALL       ___CC2DW+0
	MOVLW      ?lstr2_EUSART_Basico+0
	MOVWF      FARG_UART1_Write_Text_uart_text+0
	MOVLW      hi_addr(?lstr2_EUSART_Basico+0)
	MOVWF      FARG_UART1_Write_Text_uart_text+1
	CALL       _UART1_Write_Text+0
	MOVLW      13
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
	MOVLW      10
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
L_main1:
	CALL       _UART1_Data_Ready+0
	MOVF       R0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main3
	CALL       _UART1_Read+0
	MOVF       R0, 0
	MOVWF      main_DATO_L0+0
	MOVLW      ?ICS?lstr3_EUSART_Basico+0
	MOVWF      FSR0L
	MOVLW      hi_addr(?ICS?lstr3_EUSART_Basico+0)
	MOVWF      FSR0H
	MOVLW      ?lstr3_EUSART_Basico+0
	MOVWF      FSR1L
	MOVLW      hi_addr(?lstr3_EUSART_Basico+0)
	MOVWF      FSR1H
	MOVLW      23
	MOVWF      R0
	MOVLW      1
	MOVWF      R1
	CALL       ___CC2DW+0
	MOVLW      ?lstr3_EUSART_Basico+0
	MOVWF      FARG_UART1_Write_Text_uart_text+0
	MOVLW      hi_addr(?lstr3_EUSART_Basico+0)
	MOVWF      FARG_UART1_Write_Text_uart_text+1
	CALL       _UART1_Write_Text+0
	MOVF       main_DATO_L0+0, 0
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
	MOVLW      13
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
	MOVLW      10
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
L_main3:
	GOTO       L_main1
L_end_main:
	GOTO       $+0
; end of _main
