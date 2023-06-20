#include "HeaderLed.h"

void ApagarBit(volatile uint32_t* registro, uint8_t nBit)
{
	*registro = *registro & (~(0x01 << nBit));
}
void EncenderBit(volatile uint32_t* registro, uint8_t nBit)
{
	*registro = *registro | (0x01 << nBit);
}
uint8_t ConsultarBit(volatile uint32_t* var, uint8_t nBit)
{
	// Para consultar uso un AND: fuerzo todos los bits a 0 excepto el nBit
	if ((*var & (0x01 << nBit)) == 0) //yo se que es 0 solamente si esta apagado el bit de interes
	{
		//si el resultado es 0, el bit consultado era 0.
		return 0;
	}
	else {
		// si el resultado es 1, el bit consultado era 1
		return 1;
	}
}
void InvertirBit(volatile uint32_t* var, uint8_t nBit)
{
	// Para invertir uso un XOR :
	//si el resultado es 0, el nBit era 1.
	// si el resultado es 1, el nBit era 0
	*var = *var ^ (0x01 << nBit);
}
void SysTick_Handler(void)
{
	SysTicks++;
	if (SysTicks >= led_time)
	{
		timeout = 1;
		SysTicks = 0;
	}
	return;
}
void mde_intercambiar_frecuencias(void)
{
	switch(tiempos)
	{
	case ms_100:
		if (ConsultarBit(keyxPRESSO2, 0) == 1)
		{
			tiempos = ms_300;
			led_time = 300;
		}
		break;
	case ms_300:
		if (ConsultarBit(keyxPRESSO2, 0) == 1)
		{
			tiempos = ms_500;
			led_time = 500;
		}
		break;
	case ms_500:
		if (ConsultarBit(keyxPRESSO2, 0) == 1)
		{
			tiempos = ms_1000;
			led_time = 1000;
		}
		break;
	case ms_1000:
		if (ConsultarBit(keyxPRESSO2, 0) == 1)
		{
			tiempos = ms_100;
			led_time = 100;
		}
		break;
	default:
		tiempos = ms_100;
		break;
	}
}
void mde_parpadeo(void)
{
	switch (estado_led)
	{
	case ON:
		if (timeout == 1)
		{
			ApagarBit(LEDXPress, 0);
			estado_led = OFF;
			timeout = 0;
		}
		break;
	case OFF:
		if (timeout == 1)
		{
			EncenderBit(LEDXPress, 0);
			estado_led = ON;
			timeout = 0;
		}
		break;
	default:
		init();
		break;
	}
	return;
}
void init(void)
{
	tiempos = ms_100;
	led_time = 100;
	estado_led = OFF;
	timeout = 0;
	return;
}
void Inicializar_KIT(void)
{
	//LED
	// quiero PONER 00 bit 12 y 13 para el P0,22
	ApagarBit(PINSEL_1, 12); //con estos dos (12,13) estamos pidiendo que P0 este en GPIO
	ApagarBit(PINSEL_1, 13);
	// quiero PONER 0 el bit 22 para el P0,22
	ApagarBit(PINMODEO_OD_0, 22);
	// quiero PONER 1 el bit 22 para el P0,22
	EncenderBit(FIODIR_0, 22); //quiero que el pin 22 sea una salida
	// quiero PONER 1(OFF)/0(ON) el bit 22 para el P0,22
	InvertirBit(FIOPIN_0, 22); //le cambio el estado icial

	//KEY --> esto es para el pin del boton
	// quiero PONER 00 bit 20 y 21 para el P2,10
	ApagarBit(PINSEL_4, 20); // tambien quiero que el boton este en GPIO
	ApagarBit(PINSEL_4, 21);
	// quiero PONER 0 el bit 22 para el P2,10
	ApagarBit(PINMODEO_OD_2, 22);
	// quiero PONER 0 el bit 10 para el P2,10
	ApagarBit(FIODIR_2, 10); //quiero que este pin este como entrada (0)
	// quiero LEER el estado del pin P2,10
	ConsultarBit(FIOPIN_2, 10); //configuro que voy a consultar/leer el pin
}