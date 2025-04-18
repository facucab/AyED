#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main()
{
    tpila pila;

    /// TEST 1: Crear pila
    crearPila(&pila);

    /// TEST 2: pila llena

    int tam;
    printf("Ingrese un tam que desea ingresar en la pila: \n");
    scanf("%d", &tam);
    while(tam > 0)
    {
        if(pilaLlena(&pila, tam))
        {
            printf("El dato NO entra\n");
        }
        else
        {
            printf("El dato entra\n");
        }

        printf("Ingrese un tam que desea ingresar en la pila: \n");
        scanf("%d", &tam);
    }

    /// TEST 3.1: Poner en pila - intentar agregar un elemento que supere los bytes

    char nombre[] = {"HOLA ESTO ES UN TEST DONDE SUPERO EL MAXIMO VALOR DE LA PILA"};
    ponerEnPila(&pila, nombre, sizeof(nombre));

    /// TEST 3.2: Poner en pila - Agregar un elemento que si entre en la pila

    int num = 1;
    ponerEnPila(&pila, &num, sizeof(num));

    /// TEST 4.1: Ver Tope - La función no debe remover el tope, así que al ejecutarla dos veces o mas seguidas, el tope debe seguir igual.

    for(int i = 1; i<4; i++)
    {
        int numTope;
        verTope(&pila, &numTope, sizeof(numTope));
        printf("\nTope %d: %d", i, numTope);
    }

    /// TEST 4.2: Ver Tope - ingresar un tamDato mayor al del dato.
    int numTope;
    verTope(&pila, &numTope, sizeof(long));
    printf("\nTope 4: %d", numTope);

    /// TEST 5.1: Pila Vacia. Validar con una pila NO vacia

    if(pilaVacia(&pila))
    {
        printf("\nPila esta vacia");
    }
    else
    {
        printf("\nPila NO esta vacia");
    }


    /// TEST 5.2: Pila Vacia. Validar con una pila vacia
    tpila pila_vacia;
    crearPila(&pila_vacia);
    if(pilaVacia(&pila_vacia))
    {
        printf("\npila_vacia esta vacia");
    }
    else
    {
        printf("\npila_vacia NO esta vacia");
    }

    /// TEST 6: Sacar Pila
    tpila pila_nueva;
    crearPila(&pila_nueva);
    int numeros [] = {1,2,3};
    ponerEnPila(&pila_nueva, &numeros[0], sizeof(numeros[0]));
    ponerEnPila(&pila_nueva, &numeros[1], sizeof(numeros[1]));
    ponerEnPila(&pila_nueva, &numeros[2], sizeof(numeros[2]));

    for(int i = 0; i < 3; i++)
    {
        int numRecuperado;
        sacarDePila(&pila_nueva, &numRecuperado, sizeof(int));
        printf("\nElemento %d es: %d", i+1, numRecuperado);
    }

    /// TEST 6.1 valido que la pila este vacia
    if(pilaVacia(&pila_nueva))
    {
        printf("\nLa pila_nueva esta vacia");
    }
    else
    {
        printf("\nLa pila_nueva NO esta vacia");
    }

    /// TEST 7: vaciar pilar
    vaciarPila(&pila);
    if(pilaVacia(&pila))
    {
        printf("\nLa pila esta vacia");
    }
    else
    {
        printf("\nLa pila NO esta vacia");
    }
    return 0;
}
