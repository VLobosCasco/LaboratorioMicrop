#include "Header.h"

int cant_roots(int a, int b, int c)
{
    int Cant;
    float raiz = (b * b) - (4 * a * c);

    if (raiz == 0) {
        Cant = 1;
    }
    else if (raiz < 0) {
        Cant = 0;
    }
    else {
        Cant = 2;
    }

    return Cant;
}