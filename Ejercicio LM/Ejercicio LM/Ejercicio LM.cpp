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
    char opcion = 'z';

    while (true)
    {
        printf("\n\nMENU\n");
        printf("\t'a' - Cantidad de racies \n\t'b' - Valor de racies(cuales sean)\n\t'c' - Valor del polinomio en x\n\t'd' - Valor del polinomio en y\n\n");

        printf("\tIngrese la opcion: ");
        scanf_s(" %c", &opcion);
        if (opcion == '0') {
            printf("FIN DEL PROGRAMA");
            break;
        }

        printf("\nPOLINOMIO DE GRADO 2\n");

        printf("\tIngrese el valor A: ");
        scanf_s(" %d", &A);
        printf("\tIngrese el valor B: ");
        scanf_s(" %d", &B);
        printf("\tIngrese el valor C: ");
        scanf_s("%d", &C);


        switch (opcion)
        {
        case 'a':
            //Inciso 1 a) ----------------------------------------------------------------
            CantRaices = cant_roots(A, B, C);
            printf("\n\tLa cantidad de raices es de: %d", CantRaices);

            break;

        case 'b':
            //Inciso 1 b) ----------------------------------------------------------------
            CantRaices = cant_roots(A, B, C);
            value_roots(A, B, C, CantRaices, &Raiz1, &Raiz2);

            //Inciso 1 c) ----------------------------------------------------------------
            CantRaices = cant_roots(A, B, C);
            if (CantRaices == 0)
            {
                imaginary_value_roots(A, B, C, &real_p, &img_p);
            }

            switch (CantRaices) {
            case 0:
                printf("\tEl polinomio tiene raices imaginarias: %f + j %f\n", real_p, img_p);
                break;
            case 1:
                printf("\tEl polinomio tiene una raiz real: %f\n", Raiz1);
                break;
            case 2:
                printf("\tEl polinomio tiene dos raices reales: %f y %f\n", Raiz1, Raiz2);
                break;
            }
            break;

        case 'c':
            // Inciso 1 d) ---------------------------------------------------------------
            printf("Ingrese la variable Independiente X para calcular la dependiente Y:\n");
            scanf_s("%f", &x);

            y = value_depend(A, B, C, x);
            printf("El valor de la variable dependiente es y: %f\n", y);

            break;

        case 'd':
            // Inciso 1 e) ----------------------------------------------------------------
            printf("Ingrese la variable Dependiente Y para calcular la Independiente X:\n");
            scanf_s("%f", &y);

            x = value_independ(A, B, C, y);
            if (x != -1)
            {
                printf("El valor de la variable dependiente es y: %f\n", x);
            }

            break;

        default:
            break;
        }
        system("pause"); 
        system("cls"); 
    }

    return 0;
}

