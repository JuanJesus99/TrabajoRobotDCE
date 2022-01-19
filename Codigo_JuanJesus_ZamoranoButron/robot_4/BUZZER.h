/*
 * Libreria de funciones que se encargan de gestionar el zumbador
 *
 * Created: 24/05/2021 18:14:52
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER 2

#define START_SOUND 1000
#define STOP_SOUND 100
#define END_SOUND 1500

/*
 * Funcion de inicializacion del zumbador
 */
static inline void initBuzzer()
{
	DDRB |= (1<<BUZZER);
}

/*
 *	Funcion que hace sonar un sonido. Este sonido se emitira a 
 *	traves del zumbador con un periodo de son.
 */
static inline void playSOUND(uint8_t LED, uint16_t son)
{
	for(int i = 0; i<300; i++)
	{
		PORTB ^= (1<<LED);
		_delay_us(son);
	}
}

#endif