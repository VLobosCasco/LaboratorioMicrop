#pragma once
#ifndef HeaderAntirrebotes_h
#define HeaderAntirrebotes_h

//#INCLUDES
#include <iostream>
#include <stdio.h>
#include <stdint.h>

//-------------------Direcciones de memoria-------------------

volatile uint32_t* PINSEL_4 = (volatile uint32_t*)0x4002c010UL;	// - configurar entrada como GPIO
volatile uint32_t* PINMODEO_OD_2 = (volatile uint32_t*)0x4002c070UL;	// - configurar el modo electrico del pin
volatile uint32_t* FIODIR_2 = (volatile uint32_t*)0x2009c040UL;	// - configurar si es entrada (0) o salida (1)
volatile uint32_t* FIOPIN_2 = (volatile uint32_t*)0x2009C054UL;	//

//FUNCIONES
void ApagarBit(volatile uint32_t* registro, uint8_t nBit);
void EncenderBit(volatile uint32_t* registro, uint8_t nBit);
uint8_t ConsultarBit(volatile uint32_t* var, uint8_t nBit);
void mde_antirrebotes(void);
void SysTick_Handler(void);
void Inicializar_KIT(void);
void init(void);
void Inicializar_KIT(void);


//ENUM
typedef enum {
	PRESIONADO,
	SUELTO,
	MANTENIDO
}estados_boton;

//EXTERN
volatile uint32_t SysTicks = 0;
volatile uint8_t timeout;
volatile int pulsado;
estados_boton estados;
extern int led_time;
#endif