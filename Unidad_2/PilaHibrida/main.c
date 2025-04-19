#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "test.h"
#define ARCH_PRUEBA "datos.dat"


int main()
{
    if(!crearArchivoPrueba(ARCH_PRUEBA))
    {
        printf("ERROR AL CREAR ARCHIVO\n");
        return 0;
    }

    /// 1. CREACION DE PILA:
    tPila pila;
    crearPila(&pila);

    /// 2. Pila vacia:
    if(pilaVacia(&pila))
    {
        printf("TEST 2: La pila esta vacia [EXITO]\n");

    }
    else
    {
        printf("TEST 2: La pila no esta vacia [FALLO TEST]\n");
        return 0;
    }

    /// 3 Carga de datos en la pila desde archivo.
    if(!cargaDeDatosPila_TEST(&pila, ARCH_PRUEBA))
    {
        printf("TEST 3: Error al cargar la pila [FALLO TEST]");
        return 0;
    }

    /// 4 Pila llena: la pila esta llena(5 elementos)
    if(pilaLlena(&pila))
    {
        printf("TEST 4: La pila esta llena [EXITO]\n");
    }
    else
    {
        printf("TEST 4: La pila NO esta llena [FALLO TEST]");
    }



    /// 5 Sacar de la pila: sacamos dos elementos y mostramos el tope.
    tAlumno aux;
    for(int i = 0; i < 2; i++)
    {
        sacarDePila(&pila, &aux, sizeof(aux));
        printf("TEST 5: El tope %d es: %d\t%s\n", i + 1, aux.dni, aux.nombre); // resultado esperado es: 1-> 500 Juan | 2 -> 400 Ana
    }

    /// 6 Ver Tope de pila.
    verTope(&pila, &aux, sizeof(aux));
    printf("TEST 6: El ultimo tope es: %d\t%s\n", aux.dni, aux.nombre); // Resultado esperado: 300 Zoe

    /// 7 Vaciar pila y pila vacia:
    vaciarPila(&pila);
    if(pilaVacia(&pila))
    {
        printf("TEST 7: La pila esta vacia [EXITO]\n");
    }
    else
    {
        printf("TEST 7: La pila no esta vacia [FALLO TEST]\n");
    }


    return 0;
}

