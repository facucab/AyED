#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
int main()
{
    /// TEST 1: Crear cola
    tCola cola_prueba;
    crearCola(&cola_prueba);

    /// TEST 2: Cola vacia
    if(colaVacia(&cola_prueba))
    {
        printf("Cola vacia");
    }
    else
    {
        printf("Cola con elementos");
    }

    /// TEST 3: Cola llena
    int num = 1;
    while(num > 0) {
        printf("\nIngresar tamaño: ");
        scanf("%d", &num);
        if(colaLlena(&cola_prueba, num)){
            printf("El valor no entra\n");
        }
        else{
            printf("El valor entra\n");
        }
    };



/// agregas los test de vacias colar y llenar cola.
    return 0;
}
