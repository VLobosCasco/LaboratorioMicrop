
#include "Header.h"


int main()
{
	// Variables
	int16_t vector[N] = { 2,4,6,8,10,12,14,16,18,20 };
	int16_t Num1Sat = -500;
	int16_t Num2Sat = 500;

	//Ejercicio 1
	int32_t suma = SumarArray(vector, N);
	printf("La suma es: %d\n", suma);
	//Ejercicio 3
	int16_t multiplicacion = MultiplicarSat(Num1Sat, Num2Sat);
	printf("\tLa multiplicacion es: %d\n", multiplicacion);
	//Ejercicio 5
	Num1Sat = 2000; Num2Sat = -10;
	printf("\tLa multiplicacion es: %d\n", MultiplicarSat(Num1Sat, Num2Sat));
	Num1Sat = -1000; Num2Sat = -1000;
	printf("\tLa multiplicacion es: %d\n", MultiplicarSat(Num1Sat, Num2Sat));
	Num1Sat = 2000; Num2Sat = 100;
	printf("\tLa multiplicacion es: %d\n\n", MultiplicarSat(Num1Sat, Num2Sat));


	printf("La cantidad de accesos a la funcion multiplicacion fue de: %u\n", CuentaAccesos() - 1);
	return 0;
}
