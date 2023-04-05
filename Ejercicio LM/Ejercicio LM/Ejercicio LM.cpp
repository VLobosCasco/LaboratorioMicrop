// Ejercicio LM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    int A, B, C;
    int CantRaices;
    printf("Ingresar los coeficientes de un polinomio de grado 2:\n");
    
    printf("\tIngrese el valor A: ");
    scanf_s(" %d", &A);
    printf("\tIngrese el valor B: ");
    scanf_s(" %d", &B);
    printf("\tIngrese el valor C: ");
    scanf_s("%d", &C);
    
    CantRaices = cant_roots(A, B, C);

    printf("Cantidad de raices distintas: %d", CantRaices);

    return 0;
}

