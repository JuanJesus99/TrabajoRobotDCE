
/*
 * Fichero .c de la libreria ADC
 *
 * Created: 19/05/2021 12:38:25
 *  Author: JUAN JESUS ZAMORANO BUTRON
 */ 

#include "ADC.h"

void initADC()
{
	ADMUX = 0x00;
	ADCSRA= 0x00;
	
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

uint16_t func_ADC(uint8_t ADC_channel)
{
	uint16_t ADC_accum=0;
	//----- Delete a previous setup ------
	ADMUX=0x00;
	ADCSRA=0x00;
	//----- Initialize the ADC -----------
	ADMUX |= (ADC_channel << MUX0);		// Channel is selected
	ADMUX |= (1 << REFS0);				//
	ADCSRA |= (7 << ADPS0);				// Set pre-scaler
	ADCSRA |= (1<<ADEN);				// Enable ADC (ADEN = '1')
	//----- The first readout is throw away
	ADCSRA |= (1 << ADSC);					//Start a conversion
	while ((ADCSRA & (1 << ADIF))==0);		// Wait for conversion  completes
	ADCSRA |= (1 << ADIF);					// Clear interrupt flag.
	//---------N Samples are acquired to average--------------------
	for (uint8_t i=16;i>0;i--)
	{
		ADCSRA |= (1 << ADSC);				// Start a conversion
		while ((ADCSRA & (1 << ADIF))==0);  // Wait for conversion  completes
		ADCSRA |= (1 << ADIF);				// Clear interrupt flag.
		ADC_accum +=ADC;
	}
	ADCSRA &= ~(1 << ADEN);
	return (ADC_accum >> 4);
}