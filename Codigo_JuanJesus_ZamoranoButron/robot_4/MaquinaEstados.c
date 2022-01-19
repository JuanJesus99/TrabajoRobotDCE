/*
 * Programa final que usa una maquina de estados. Estos estados seran:
 * Init: El robot esta parado y suena un beep
 * Test: El robot ejecuta el programa de testRobot.
 * Stop: El robot se para y suenan tres beep.
 *
 * Created: 24/05/2021 12:31:25
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include "WHEELS.h"
#include "BUZZER.h"


typedef enum
{
	INIT,
	TEST,
	STOP
} State_t;

int main(void)
{
	State_t current_State = INIT;
	State_t next_State = INIT;
	
	//--- Setup -------------------------
	initBuzzer();		// Configuracion del zumbador
	initWHEELS();		// Configuracion de las ruedas
	
	// Configuracion del timer 4
	TMR4_PWM_Phase_Init();
	TMR4_PWM_Phase_Start();
	
	stop(); //Comenzamos con el robot parado
	_delay_ms(1000);
	
	//--- Loop -------------------------
	while (1)
	{
		switch(current_State)
		{
			case INIT:
				playSOUND(BUZZER,START_SOUND);
				_delay_ms(1000);
				next_State = TEST;
				break;
				
			case TEST:
				testRobot();
				next_State = STOP;
				break;
			
			case STOP:
				stop();
				_delay_ms(3000);
				for(int i = 0; i<3; i++)
				{
					playSOUND(BUZZER,END_SOUND);
					_delay_ms(1000);
				}
				next_State = INIT;
				break;
			
			default:
				next_State = INIT;
		}
		
		current_State = next_State;
	}
}