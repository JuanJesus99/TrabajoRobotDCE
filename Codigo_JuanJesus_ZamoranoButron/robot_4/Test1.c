/*
 * Programa de test del movimiento de las ruedas en los dos sentidos de giro
 *
 * Created: 24/05/2021 10:44:33
 * Author : JUAN JESUS ZAMORANO BUTRON
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include "WHEELS.h"


int main(void)
{
	//--- Setup -------------------------
	initWHEELS();			// Configuracion de las ruedas
	
	// Configuracion del timer 4
    TMR4_PWM_Phase_Init();
    TMR4_PWM_Phase_Duty(255-178,178);
    TMR4_PWM_Phase_Start();
	
	//--- Loop -------------------------
    while (1) 
    {
		_delay_ms(2000);
		PORTD ^= (1<<PORTD6);
		PORTE ^= (1<<PORTE6);
    }
}