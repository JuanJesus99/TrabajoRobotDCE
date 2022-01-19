/*
 * Fichero .c de la libreria OPTICAL
 *
 * Created: 24/05/2021 19:37:39
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#include "OPTICAL.h"

void sensor_sonar_sonido (unsigned char input)
{
	unsigned int value = 0;
	switch (input)
	{
		case 'A':
		case 'a':
			value = func_ADC(sensor1);
		
			m_usb_tx_string("Valor leido del sensor 1: ");
			m_usb_tx_char('\t');
			m_usb_tx_uint(value);
			m_usb_tx_char('\n');
			m_usb_tx_char('\r');
		
			if(value<NEGRO)
				playSOUND(BUZZER,SONIDO_NEGRO);
			else if(value>BLANCO)
				playSOUND(BUZZER,SONIDO_BLANCO);
			else
				playSOUND(BUZZER,SONIDO_OTRO_COLOR);
		
			break;
		
		case 'B':
		case 'b':
			value = func_ADC(sensor2);
			
			m_usb_tx_string("Valor leido del sensor 2: ");
			m_usb_tx_char('\t');
			m_usb_tx_uint(value);
			m_usb_tx_char('\n');
			m_usb_tx_char('\r');
			
			if(value<NEGRO)
				playSOUND(BUZZER,SONIDO_NEGRO);
			else if(value>BLANCO)
				playSOUND(BUZZER,SONIDO_BLANCO);
			else
				playSOUND(BUZZER,SONIDO_OTRO_COLOR);
			
			break;
		
		case 'C':
		case 'c':
			value = func_ADC(sensor3);
		
			m_usb_tx_string("Valor leido del sensor 3: ");
			m_usb_tx_char('\t');
			m_usb_tx_uint(value);
			m_usb_tx_char('\n');
			m_usb_tx_char('\r');
		
			if(value<NEGRO)
				playSOUND(BUZZER,SONIDO_NEGRO);
			else if(value>BLANCO)
				playSOUND(BUZZER,SONIDO_BLANCO);
			else
				playSOUND(BUZZER,SONIDO_OTRO_COLOR);
		
			break;
		
		case 'D':
		case 'd':
			value = func_ADC(sensor4);
			
			m_usb_tx_string("Valor leido del sensor 4: ");
			m_usb_tx_char('\t');
			m_usb_tx_uint(value);
			m_usb_tx_char('\n');
			m_usb_tx_char('\r');
			
			if(value<NEGRO)
				playSOUND(BUZZER,SONIDO_NEGRO);
			else if(value>BLANCO)
				playSOUND(BUZZER,SONIDO_BLANCO);
			else
				playSOUND(BUZZER,SONIDO_OTRO_COLOR);
			
			break;
		
		case 'E':
		case 'e':
			value = func_ADC(sensor5);
			
			m_usb_tx_string("Valor leido del sensor 5: ");
			m_usb_tx_char('\t');
			m_usb_tx_uint(value);
			m_usb_tx_char('\n');
			m_usb_tx_char('\r');
			
			if(value<NEGRO)
				playSOUND(BUZZER,SONIDO_NEGRO);
			else if(value>BLANCO)
				playSOUND(BUZZER,SONIDO_BLANCO);
			else
				playSOUND(BUZZER,SONIDO_OTRO_COLOR);
			
			break;
		
		case 'H':	// Call the main menu in anytime
		case 'h':
			m_usb_tx_char(12);	//Limpia la pantalla
			mainMenu();
			break;
		
		default:
			m_usb_tx_string("I don't know what to do with that key.\n\r");
			m_usb_tx_string("\r\n");
			break;
	}
}

