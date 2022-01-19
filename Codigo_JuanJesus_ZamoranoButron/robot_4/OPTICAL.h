/*
 * Libreria de funciones que gestionan los sensores opticos
 *
 * Created: 24/05/2021 19:38:10
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#ifndef OPTICAL_H
#define OPTICAL_H

#include "m_general.h"
#include "m_usb.h"
#include "ADC.h"
#include "BUZZER.h"

#define BUZZER 2

#define sensor1 7
#define sensor2 6
#define sensor3 5
#define sensor4 4
#define sensor5 1

#define BLANCO 950
#define NEGRO 880

#define SONIDO_BLANCO 2000
#define SONIDO_NEGRO 1000
#define SONIDO_OTRO_COLOR 100

/*
 * Funcion que muestra un menu por pantalla
 */
static inline void mainMenu (void)
{
	m_usb_tx_string(" -----------------------------------------------------------------------\r\n"
	" Selecciona el sensor que quieres utilizar:\r\n"
	" -----------------------------------------------------------------------\r\n"
	" Presiona 'a' para el sensor 1 \r\n"
	" Presiona 'b' para el sensor 2 \r\n"
	" Presiona 'c' para el sensor 3 \r\n"
	" Presiona 'd' para el sensor 4 \r\n"
	" Presiona 'e' para el sensor 5 \r\n"
	" -----------------------------------------------------------------------\r\n"
	" Press 'h' in anytime to show the MENU\r\n"
	"---------------------------------------------------------------------------\r\n");
}

/*
 * Funcion realizada para probar los diferentes sensores.
 * El valor leido sera mostrado por pantalla y segun sea este
 * sonara un sonido u otro diferenciando entre blanco, negro u
 * otro color
 */
void sensor_sonar_sonido (unsigned char input);

#endif