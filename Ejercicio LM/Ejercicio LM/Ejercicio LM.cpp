// Ejercicio LM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    int A, B, C;
    int CantRaices;
    float Raiz1, Raiz2;
    float real_p, img_p;
    float y, x;

    printf("Ingresar los coeficientes de un polinomio de grado 2:\n");

    printf("\tIngrese el valor A: ");
    scanf_s(" %d", &A);
    printf("\tIngrese el valor B: ");
    scanf_s(" %d", &B);
    printf("\tIngrese el valor C: ");
    scanf_s("%d", &C);

    //Inciso 1 a) ----------------------------------------------------------------
    CantRaices = cant_roots(A, B, C);
    //Inciso 1 b) ----------------------------------------------------------------
    value_roots(A, B, C, CantRaices, &Raiz1, &Raiz2);

    //Inciso 1 c) ----------------------------------------------------------------
    if (CantRaices == 0)
    {
        imaginary_value_roots(A, B, C, &real_p, &img_p);
    }

    switch (CantRaices) {
    case 0:
        printf("El polinomio tiene raices imaginarias: %f + j %f\n", real_p,img_p);
        break;
    case 1:
        printf("El polinomio tiene una raiz real: %f\n", Raiz1);
        break;
    case 2:
        printf("El polinomio tiene dos raices reales: %f y %f\n", Raiz1, Raiz2);
        break;
    }

    // Inciso 1 d) ---------------------------------------------------------------
    printf("Ingrese la variable Independiente X para calcular la dependiente Y:\n");
    scanf_s("%f", &x);

    y = value_depend(A, B, C, x);
    printf("El valor de la variable dependiente es y: %f\n", y);

    return 0;
}

