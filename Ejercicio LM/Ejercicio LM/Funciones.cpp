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