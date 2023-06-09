#include "Header.h"

int cant_roots(int a, int b, int c)
{
    int Cant;
    float Discriminante = (b * b) - (4 * a * c);

    if (Discriminante == 0) {
        Cant = 1;
    }
    else if (Discriminante < 0) {
        Cant = 0;
    }
    else {
        Cant = 2;
    }

    return Cant;
}

void value_roots(int a, int b, int c, int cant_roots, float* root1, float* root2) {

    float discriminante = b * b - 4 * a * c;

    if (cant_roots == 0) {
        return;
    }
    else if (cant_roots == 1) {
        *root1 = -b / (2.0 * a);
        return;
    }
    else {
        *root1 = (-b + sqrt(discriminante)) / (2.0 * a);
        *root2 = (-b - sqrt(discriminante)) / (2.0 * a);
    }

}

void imaginary_value_roots(int a, int b, int c, float* real_p, float* img_p) {

    float discriminante = b * b - 4 * a * c;
    *real_p = -b / (2.0 * a);
    *img_p = sqrt(-discriminante) / (2.0 * a);
}

float value_depend(int a, int b, int c, int x) {
    float y = a*pow(x,2) + b * x + c;
    return y;
}

float value_independ(int a, int b, int c, int y) {
   
    int CantRoots = cant_roots(a, b, (c-y));
    float Raiz1, Raiz2;
   // float real_p, float img_p;
    if(CantRoots == 1 || CantRoots == 2)
        value_roots(a, b, (c - y), CantRoots, &Raiz1, &Raiz2);

    switch (CantRoots)
    {
    case 0:
        return -1;
    case 1: 
        return Raiz1;
    case 2: 
        printf("Hay m�s de una soluci�n.\n");
        return Raiz1;
    default:
        break;
    }

}