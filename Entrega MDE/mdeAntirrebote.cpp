#include "HeaderAntirrebotes.h"
void ApagarBit(volatile uint32_t* registro, uint8_t nBit)
{
	// Forzar el bit nBit a 0
	*registro = *registro & (~(0x01 << nBit));
}
void EncenderBit(volatile uint32_t* registro, uint8_t nBit)
{
	// Forzar el bit nBit a 1
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
void SysTick_Handler(void) 
{
	SysTicks++;
	if (SysTicks >= led_time)
	{
		timeout = 1;
		SysTicks = 0;
	}
	mde_antirrebotes();
	return;
}
void mde_antirrebotes(void)
{
	static uint8_t cont_mantenido = 0; // cuantas veces la tecla estuvo en el mismo estado

	switch (estados)
	{
	case MANTENIDO:
		if (ConsultarBit(FIOPIN_2, 10) == 1 && cont_mantenido >= 5)
		{
			estados = PRESIONADO;
			cont_mantenido = 0;
		}
		else if (ConsultarBit(FIOPIN_2, 10) == 0)
		{
			estados = SUELTO;
			cont_mantenido = 0;
		}
		else
			cont_mantenido++;
		break;

	case PRESIONADO:
		if (ConsultarBit(FIOPIN_2, 10) == 1)
			estados = MANTENIDO;
		break;

	case SUELTO:
		if (ConsultarBit(FIOPIN_2, 10) == 0)
			estados = MANTENIDO;
		break;

	default:
		estados = MANTENIDO;
	}
}
void Inicializar_KIT(void)
{
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
void init(void) 
{
	estados = MANTENIDO;
	timeout = 0;
	return;
}