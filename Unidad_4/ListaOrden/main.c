#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
typedef struct
{
    int legajo;
    char nombre[30];
} tEmpleado;

void mostrarTEmpleado(void * dato);
int compararTEmpleado(void * , void *);
int main()
{
    tLista lista;
    crearLista(&lista);

    /// Lotes de prueba:
    tEmpleado empleados[] =
    {
        {14,"F"},
        {44,"C"},
        {1,"D"},
        {10,"AB"},
        {4,"A"}
    };

    for(int i = 0; i < sizeof(empleados) / sizeof(empleados[0]); i++)
    {
        insertarInicio(&lista, &empleados[i], sizeof(empleados[i]));
    }

    ///
    printf("------------- Lista desordenada -------------\n");
    mapLista(&lista, mostrarTEmpleado);

    ordenarLista(&lista, compararTEmpleado, mostrarTEmpleado);


    printf("------------- Lista ordenada -------------\n");
    mapLista(&lista, mostrarTEmpleado);

    return 0;
}


void mostrarTEmpleado(void * dato)
{
    tEmpleado * valor = (tEmpleado *)dato;
    printf("%d\t%s\n", valor->legajo, valor->nombre);
}


int compararTEmpleado(void *a , void *b){
    tEmpleado * valor_a = (tEmpleado *)a;
    tEmpleado * valor_b = (tEmpleado *)b;

    return valor_a->legajo - valor_b->legajo;
}
