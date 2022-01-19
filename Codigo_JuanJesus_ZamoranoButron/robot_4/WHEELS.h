/*
 * Libreria de funciones que se encargan de gestionar los diferentes movimientos de las ruedas.
 *
 * Created: 24/05/2021 11:51:44
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#ifndef WHEELS_H
#define WHEELS_H

#include "TIMERS.h"
#include "OPTICAL.h"
#include "m_general.h"
#include "m_usb.h"
#include "ADC.h"

#define SPEEP_WHEEL_LEFT 50
#define SPEEP_WHEEL_RIGHT 50


/*
 * Funcion de inicializacion de las ruedas
 */
static inline void initWHEELS()
{
	DDRD |= (1<<DDD7) | (1<<DDD6);
	DDRC |= (1<<PORTC6);
	DDRE |= (1<<PORTE6);
}


/*
 * Funcion que se encarga de parar las ruedas
 */
static inline void stop()
{
	TMR4_PWM_Phase_Duty(255,0);
}

/*
 * Funcion que hace que el robot vaya hacia delante
 */
static inline void forward(uint8_t speedLeft, uint8_t speedRight)
{
	PORTD &= (~(1<<PORTD6));
	PORTE &= (~(1<<PORTE6));
	
	TMR4_PWM_Phase_Duty(255-speedLeft,speedRight);
}

/*
 * Funcion que hace que el robot vaya hacia atras
 */
static inline void backward(uint8_t speedLeft, uint8_t speedRight)
{
	PORTD |= ((1<<PORTD6));
	PORTE |= ((1<<PORTE6));
	
	TMR4_PWM_Phase_Duty(255-speedLeft,speedRight);
}

/*
 * Funcion que hace que el robot gire a la derecha
 */
static inline void turn_right(uint8_t speedLeft, uint8_t speedRight)
{
	PORTD &= (~(1<<PORTD6));
	PORTE |= ((1<<PORTE6));
	
	TMR4_PWM_Phase_Duty(255-speedLeft,speedRight);
}

/*
 * Funcion que hace que el robot gire a la izquierda
 */
static inline void turn_left(uint8_t speedLeft, uint8_t speedRight)
{
	PORTD |= ((1<<PORTD6));
	PORTE &= (~(1<<PORTE6));
	
	TMR4_PWM_Phase_Duty(255-speedLeft,speedRight);
}

/*
 * Funcion de test de movimientos del robot
 */
void testRobot();


/*
 * Funcion que controla el movimiento del robot.
 * Mientras que el sensor central lee negro el robot ira hacia delante. Cuando este
 * sensor no lea negro, se comprobaran el izquierdo y derecho para hacerlo girar al
 * lado que le corresponda.
 */
uint8_t moveRobot(uint16_t central, uint16_t left, uint16_t rigth);

#endif