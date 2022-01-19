/*
 * Fichero .c de la libreria WHEELS
 *
 * Created: 24/05/2021 11:51:58
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#include "WHEELS.h"

void testRobot()
{
	forward(SPEEP_WHEEL_LEFT,SPEEP_WHEEL_RIGHT);
	_delay_ms(2000);
	turn_left(SPEEP_WHEEL_LEFT,SPEEP_WHEEL_RIGHT);
	_delay_ms(2000);
	backward(SPEEP_WHEEL_LEFT,SPEEP_WHEEL_RIGHT);
	_delay_ms(2000);
	turn_right(SPEEP_WHEEL_LEFT,SPEEP_WHEEL_RIGHT);
	_delay_ms(2000);
	stop();
	_delay_ms(2000);
}


uint8_t moveRobot(uint16_t central, uint16_t left, uint16_t right)
{
	if(central < NEGRO)
	{
		forward(SPEEP_WHEEL_LEFT,SPEEP_WHEEL_RIGHT);
	}
	else if (left < NEGRO)
	{
		turn_left(SPEEP_WHEEL_LEFT,SPEEP_WHEEL_RIGHT);
	}
	else if (right < NEGRO)
	{
		turn_right(SPEEP_WHEEL_LEFT,SPEEP_WHEEL_RIGHT);
	}
	else
	{
		return 1;
	}
	return 0;
}