/*
 * Programa de test del movimiento de las ruedas en los 5 estados:
 * hacia delante, hacia atras, giro a la derecha, giro a la izquierda y parado.
 *
 * Created: 24/05/2021 12:03:24
 *  Author: JUAN JESUS ZAMORANO BUTRON
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
		stop();
		_delay_ms(2000);
		backward(178,178);
		_delay_ms(2000);
		turn_left(178,178);
		_delay_ms(2000);
		forward(178,178);
		_delay_ms(2000);
		turn_right(178,178);
		_delay_ms(2000);
	}
}