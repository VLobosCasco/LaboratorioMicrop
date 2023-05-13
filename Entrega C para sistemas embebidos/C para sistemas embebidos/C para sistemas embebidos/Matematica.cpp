#include "Header.h"


int32_t SumarArray(int16_t* x, int16_t xn) {

	int32_t suma = 0;
	for (int i = 0; i < xn; i++) { suma += x[i]; }
	return suma;
}

int16_t MultiplicarSat(int16_t n1, int16_t n2) {

	int16_t multiplicacion = n1 * n2;
	uint16_t Accesos = 0;


	if ((n1 > 0 && n2 > 0) || (n1 < 0 && n2 < 0))
	{
		if (multiplicacion < 0)
			multiplicacion = SAT16_MAX;

	}
	else {
		if (multiplicacion > 0)
			multiplicacion = SAT16_MIN;
	}

	printf("Acceso %d\n", CuentaAccesos());

	return multiplicacion;
}
uint16_t CuentaAccesos(void) {
	static uint16_t Accesos = 0;
	Accesos++;
	return Accesos;
}