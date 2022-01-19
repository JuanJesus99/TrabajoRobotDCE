/*
 * Libreria de funciones que se encargan de gestionar los diferentes TIMERS.
 * Esta en concreto gestiona el TIMER4.
 *
 * Created: 24/05/2021 11:59:23
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#ifndef TIMERS_H
#define TIMERS_H

#include <avr/io.h>

/*
 * Funcion de inicializacion y configuracion de las flag correspondientes para 
 * que el timer funcione correctamente.
 */
static inline void TMR4_PWM_Phase_Init(void)
{
	TCNT4=0;
	
	//Configuración del timer en fase correcta
	TCCR4D |= (1<<WGM40);
	TCCR4C |= (1<<COM4D1) | (1<<PWM4D);
	TCCR4A |= (1<< COM4A0) | (1<<PWM4A);
}

/*
 * Funcion que configura el ciclo de trabajo del timer. Esta funcion recibe dos
 * parametros que son los que se asignaran a la rueda izquierda y derecha.
 */
static inline void TMR4_PWM_Phase_Duty(uint8_t valueOCR4A, uint8_t valueOCR4D)
{
	OCR4A = valueOCR4A;
	OCR4D = valueOCR4D;
}

/*
 * Funcion que inicializa el timer y configura el divisor de frecuencia de 64 bit.
 */
static inline void TMR4_PWM_Phase_Start(void)
{
	TCCR4B |= (1<<CS42) | (1<<CS41) | (1<<CS40); //Divisor de 64
}

#endif