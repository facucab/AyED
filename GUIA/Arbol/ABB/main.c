#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
int compararInt(void *a, void * b);
void mostrarEntero(void *dato);

int main()
{
    tArbol arbol;
    crearArbol(&arbol);
    int datos[] = {1,4,6,3,7};

    for(int i = 0; i < sizeof(datos) / sizeof(datos[0]); i++)
    {
        insertarArbolBinBusq(&arbol, &datos[i], sizeof(datos[0]), compararInt);
    }

    recorrerInOrden(&arbol, mostrarEntero);
    printf("\n");
    recorrerPreOrden(&arbol, mostrarEntero);
    printf("\n");
    recorrerPosOrden(&arbol, mostrarEntero);
    return 0;
}


int compararInt(void *a, void * b)
{
    int valor_a = *((int*)a);
    int valor_b = *((int*)b);

    return valor_a - valor_b;
}

void mostrarEntero(void *dato)
{
    printf("-%d-", *(int *)dato);
}
