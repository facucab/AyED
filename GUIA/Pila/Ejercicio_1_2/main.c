#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "PilaDin.h"

int main()
{
    tPila pilaTest_1;
    unsigned tamDato;;
    char datos [] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int i;
    char dato;
    tPilaDin pilaTest_2;


    /// ############### TEST PILA DINAMICA ######################
    printf("############### TEST PILA DINAMICA ######################\n");
    crearPila_Din(&pilaTest_2);

    // TEST 1: Pila vacia
    if(pilaVacia_Din(&pilaTest_2)) printf("EXITO: La pila esta vacia\n");
    else printf("ERROR: La pila no esta vacia\n");

    // TEST 2: Pila llena
    tamDato = 4;
    if(pilaLlena_Din(&pilaTest_2, tamDato)) printf("ERROR: La pila esta llena\n");
    else  printf("EXITO: La pila NO esta llena\n");

    // TEST 3: APILAR

    for(i = 0; i < sizeof(datos) / sizeof(datos[0]); i++)
    {
        if(apilar_Din(&pilaTest_2, &datos[i], sizeof(datos[0])) == TODO_OK) printf("EXITO: EL dato fue almacenado\n");
        else printf("ERROR: El dato no fue almacenado");
    }

    // TEST 4: Desapilar
    i = 0;
    while(i < 2 && desapilar_Din(&pilaTest_2, &dato, sizeof(dato)) == TODO_OK)
    {
        printf("EXITO: %c\n", dato);
        i++;
    }

    // TEST 5:
    for(i = 0; i < 2; i++)
    {
        verTope_Din(&pilaTest_2, &dato, sizeof(dato));
        printf("EXITO %d: %c\n", i + 1, dato);
    }

    // TEST 6:
    vaciarPila_Din(&pilaTest_2);
    if(pilaVacia_Din(&pilaTest_2)) printf("EXITO: La pila se vacio\n");
    else printf("ERROR: La pila no esta vacia\n");

    /// ############### TEST PILA ESTATICA ######################
    printf("\n############### TEST PILA ESTATICA ######################\n");
    crearPila(&pilaTest_1);

    // TEST 1: Pila vacia
    if(pilaVacia(&pilaTest_1)) printf("EXITO: La pila esta vacia\n");
    else printf("ERROR: La pila no esta vacia\n");

    // TEST 2: Pila llena
    tamDato = 4;
    if(pilaLlena(&pilaTest_1, tamDato)) printf("ERROR: La pila esta llena\n");
    else  printf("EXITO: La pila NO esta llena\n");


    // TEST 3: APILAR

    for(i = 0; i < sizeof(datos) / sizeof(datos[0]); i++)
    {
        if(apilar(&pilaTest_1, &datos[i], sizeof(datos[0])) == DATO_APILADO) printf("EXITO: EL dato fue almacenado\n");
        else printf("ERROR: El dato no fue almacenado");
    }

    // TEST 4: Desapilar
    i = 0;
    while(i < 2 && desapilar(&pilaTest_1, &dato, sizeof(dato)) == DATO_DESAPILADO)
    {
        printf("EXITO: %c\n", dato);
        i++;
    }

    // TEST 5:
    for(i = 0; i < 2; i++)
    {
        verTope(&pilaTest_1, &dato, sizeof(dato));
        printf("EXITO %d: %c\n", i + 1, dato);
    }



    return 0;
}
