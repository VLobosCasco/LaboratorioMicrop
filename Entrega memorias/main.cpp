#include "Header.h"

extern char edata,etext,end; 

int32_t VarGlobal1 = 1;
int32_t VarGlobal2;

int main()
{
    int32_t N;
    int32_t n = 0;
    int32_t *ptr = &N;
    int32_t (*ptrFunc)(int32_t,int32_t);
    ptrFunc = Suma;
    printf("Direccion de memoria:\n");
    printf("\tMain:                           %p\n", &main);
    //printf("\tPuntero a funcion:              %x\n", &ptrFunc);
    printf("\tFuncion:                        %p\n", &Suma);
    printf("\tEtext:                          %p - Comienzo del segmento text\n", &etext);
    printf("\tVariable global inicializada:   %p\n", &VarGlobal1);
    printf("\tEdata:                          %p - Comienzo del segmento data\n", &edata);
    printf("\tVariable global not:            %p\n", &VarGlobal2);
    printf("\tEnd:                            %p - Final del HEAP\n", &end);
    printf("\tVariable local sin inicializar: %p\n", N);
    //printf("\tptr:                            %p\n", &ptr);
    printf("\tVariable local inicializada:    %p\n", &n);
    
    return 0;
}
