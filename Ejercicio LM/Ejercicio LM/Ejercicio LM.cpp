// Ejercicio LM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    int A, B, C;
    int CantRaices;
    float Raiz1, Raiz2;

    printf("Ingresar los coeficientes de un polinomio de grado 2:\n");

    printf("\tIngrese el valor A: ");
    scanf_s(" %d", &A);
    printf("\tIngrese el valor B: ");
    scanf_s(" %d", &B);
    printf("\tIngrese el valor C: ");
    scanf_s("%d", &C);

    CantRaices = cant_roots(A, B, C);
    value_roots(A, B, C, CantRaices, &Raiz1, &Raiz2);


    switch (CantRaices) {
    case 0:
        printf("El polinomio no tiene raices reales\n");
        break;
    case 1:
        printf("El polinomio tiene una raiz real: %f\n", Raiz1);
        break;
    case 2:
        printf("El polinomio tiene dos raices reales: %f y %f\n", Raiz1, Raiz2);
        break;
    }
    return 0;
}

