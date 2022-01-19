
/*
 * Libreria de funciones que se encargan de configurar y gestionar el convertidor analogico digital.
 *
 * Created: 19/05/2021 12:38:25
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#ifndef ADC_H
#define ADC_H

#include<avr/interrupt.h>

/*
 * Inicializo el convertidor analogico digital para su uso
 * Ponemos a 0 los registros ADMUX y ADCSRA.
 * Configuramos los diferentes flag poniendo el factor de division en 128.
 */
void initADC();

/*
 * Leemos el valor del ADC de el canal indicado.
 * En esta funcion leeremos el valor del ADC, descartando el primer valor
 * y haciendo una media aritmetica de los dieciseis valores siguientes.
 */
uint16_t func_ADC(uint8_t ADC_channel);

#endif