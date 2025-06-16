#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"
int main()
{
    tCola cola;
    char dato;
    char datos[] = {'A','B','C','D','E','F'};
    int i;


    /// ############ TEST COLA DINAMICA ############
    printf("############ TEST COLA DINAMICA ############\n\n");
    crearCola(&cola);

    // TEST 1: cola vacia
    if(colaVacia(&cola)) printf("[EXITO] TEST 1: La cola esta vacia\n");
    else printf("[ERROR] TEST 1: La cola NO esta vacia\n");


    // TEST 2: Encolar

    for(i = 0; i < sizeof(datos)/sizeof(datos[0]); i++)
    {
        if(encolar(&cola, &datos[i], sizeof(datos[0]))) printf("[EXITO] TEST 2: El dato fue encolado\n");
        else printf("[ERROR] TEST 2: El dato no fue almacenado\n");
    }

    // TEST 3: Desencolar
    i = 0;
    while(i < 2 && desencolar(&cola, &dato, sizeof(dato)))
    {
        printf("[EXITO] TEST 3: El dato desencolado %c\n", dato);
        i++;
    }

    // TEST 4: Ver primero
    if(verPrimeroCola(&cola, &dato, sizeof(dato))) printf("[EXITO] TEST 4: El primer elemento es %c\n", dato);
    else printf("[ERROR] TEST 4\n");

    // TEST 5: Vaciar cola
    vaciarCola(&cola);

    if(colaVacia(&cola)) printf("[EXITO] TEST 5: La cola se vacio\n");
    else printf("[ERROR] TEST 5: La cola NO se vacio\n");

    return 0;
}
