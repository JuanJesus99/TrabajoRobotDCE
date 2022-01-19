/*
 * Programa final del robot. El robot lee por los sensores infrarrojos 
 * y se mueve siguiendo un camino marcado con el color negro. 
 *
 * El programa cuenta con una máquina de estados que son:
 *
 * Init: Con el robot parado emite un sonido para indicar que va a empezar
 *
 * Move: Estado que se encarga de mover el robot siguiendo las lineas. Si
 * en este estado no se encuentra la linea negra las tres primeras veces nos 
 * mandara al estado STOP y la ultima al estado END.
 *
 * Move_back: Mueve el robot hacia atras para intentar volver a encontrar
 * de nuevo la linea negra.
 *
 * End: Estado final del robot.
 *
 * Created: 24/05/2021 19:57:26
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#define F_CPU 16000000UL
#include<util/delay.h>
#include <avr/io.h>


#include "BUZZER.h"
#include "WHEELS.h"


typedef enum
{
	INIT,
	MOVE,
	STOP,
	MOVE_BACK,
	END
} State_t;



int main(void)
{
	State_t current_State = INIT;
	State_t next_State = INIT;
	uint8_t value = 0;
	uint8_t flag = 0;
	
	//--- Setup -------------------------
	initBuzzer();		// Configuracion del zumbador
	initADC();			// Configuracion del convertidor analogico digital
	initWHEELS();		// Configuracion de las ruedas
	
	// Configuracion del timer 4
	TMR4_PWM_Phase_Init();
	TMR4_PWM_Phase_Start();
	
	stop();	//Comenzamos con el robot parado
	_delay_ms(1000);
	
	
	//--- Loop -------------------------
	while (1)
	{
		switch(current_State)
		{
			case INIT:
				playSOUND(BUZZER,START_SOUND);
				_delay_ms(1000);
				next_State = MOVE;
				break;
			
			case MOVE:
				flag = moveRobot(func_ADC(sensor3), func_ADC(sensor2), func_ADC(sensor4));
				if(flag == 1)
					value++;
				else
					value = 0;
				
				if(value != 0 && value%50 == 0 && value != 200)
					next_State = STOP;
				else if (value >= 200)
				{
					next_State = END;
					for(int i = 0; i<5; i++)
					{
						playSOUND(BUZZER,END_SOUND);
					}
				}
					
				break;
				
			case STOP:
				stop();
				_delay_ms(2000);
				for(int i = 0; i<3; i++)
				{
					playSOUND(BUZZER,STOP_SOUND);
					_delay_ms(500);
				}
				_delay_ms(2000);
				next_State = MOVE_BACK;
				break;
				
			case MOVE_BACK:
				backward(SPEEP_WHEEL_LEFT,SPEEP_WHEEL_RIGHT);
				_delay_ms(200);
				stop();
				next_State = MOVE;
				break;
				
			case END:
				
			break;
			
			default:
				next_State = INIT;
		}
		
		current_State = next_State;
		
		
	}
}