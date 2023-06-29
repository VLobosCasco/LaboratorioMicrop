#pragma once
#ifndef HeaderLed_h
#define HeaderLed_h

//#INCLUDES
#include <iostream>
#include <stdio.h>
#include <stdint.h>

//-------------------Direcciones de memoria-------------------

volatile uint32_t* PINSEL_1 = (volatile uint32_t*)0x4002C004UL; 	// - configurar entrada como GPIO
volatile uint32_t* PINSEL_4 = (volatile uint32_t*)0x4002c010UL;	// - configurar entrada como GPIO

volatile uint32_t* PINMODEO_OD_0 = (volatile uint32_t*)0x4002C068UL; 	// - configurar el modo electrico del pin
volatile uint32_t* PINMODEO_OD_2 = (volatile uint32_t*)0x4002c070UL;	// - configurar el modo electrico del pin

volatile uint32_t* FIODIR_0 = (volatile uint32_t*)0x2009C000UL;	// - configurar si es entrada (0) o salida (1)
volatile uint32_t* FIODIR_2 = (volatile uint32_t*)0x2009c040UL;	// - configurar si es entrada (0) o salida (1)

//DIR DE MEMORIA DE REGISTROS DE LECTURA/ESCRITURA DE LOS PINS:
volatile uint32_t* FIOPIN_0 = (volatile uint32_t*)0x2009C014UL;	// - configurar el estado del pin o leer el estado del pin
volatile uint32_t* FIOPIN_2 = (volatile uint32_t*)0x2009C054UL;	//

//FUNCIONES
void ApagarBit(volatile uint32_t* registro, uint8_t nBit);
void EncenderBit(volatile uint32_t* registro, uint8_t nBit);
uint8_t ConsultarBit(volatile uint32_t* var, uint8_t nBit);
void InvertirBit(volatile uint32_t* var, uint8_t nBit);
void SysTick_Handler(void);
void mde_intercambiar_frecuencias(void);
void mde_parpadeo(void);
void init(void);
void Inicializar_KIT(void);


//ENUM
typedef enum {
	ms_100,
	ms_300,
	ms_500,
	ms_1000,
}tiempo;
typedef enum {
	ON,
	OFF,
}estados;

//EXTERN
volatile uint32_t led_time;
volatile uint32_t SysTicks = 0;
volatile uint8_t timeout;
volatile tiempo tiempos;
volatile estados estado_led;

#endif