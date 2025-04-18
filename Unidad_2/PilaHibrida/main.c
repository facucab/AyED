#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/// TEST:

int main()
{
    tPila pila;
    crearPila(&pila);

    int numeros[] = {1,2};

    for(int i = 0; i < sizeof(numeros) / sizeof(numeros[0]); i++)
    {
        ponerEnPila(&pila, &numeros[i], sizeof(numeros[i]));
    }

    int numTope;
    verTope(&pila, &numTope, sizeof(numTope));
    printf("\nEl tome es: %d", numTope);

    return 0;
}

