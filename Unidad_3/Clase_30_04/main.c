#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
typedef struct
{
    int id;
    char nombre[45];
} tEmpleado;


int main()
{
    /// TEST 1:
    tCola cola;
    crearCola(&cola);


    /// TEST 2:
    if(colaVacia(&cola))
        printf("La cola esta vacia\n");
    else
        printf("La cola NO esta vacia\n");

    /// TEST 3:
    tEmpleado empleados[] =
    {
        {1, "Juan"},
        {2, "Ana"},
        {3, "ABC"},
    };

    for(int i = 0; i < sizeof(empleados) / sizeof(empleados[0]); i++ )
    {
        ponerEnCola(&cola, &empleados[i], sizeof(empleados[i]));
    }

    if(colaVacia(&cola))
        printf("La cola esta vacia\n");
    else
        printf("La cola NO esta vacia\n");

    /// TEST 4:

    tEmpleado empTemp;

    sacarDeCola(&cola, &empTemp, sizeof(empTemp));
    printf("%d %s\n", empTemp.id, empTemp.nombre);

    sacarDeCola(&cola, &empTemp, sizeof(empTemp));
    printf("%d %s\n", empTemp.id, empTemp.nombre);

    sacarDeCola(&cola, &empTemp, sizeof(empTemp));
    printf("%d %s\n", empTemp.id, empTemp.nombre);

    if(sacarDeCola(&cola, &empTemp, sizeof(empTemp)) == COLA_VACIA)
    {
        printf("Cola vacia, no se puede obtener elemento\n");
    }


    /// TEST 5:
    ponerEnCola(&cola, &empleados[0], sizeof(empleados[0]));
    ponerEnCola(&cola, &empleados[1], sizeof(empleados[1]));

    if(verPrimero(&cola, &empTemp, sizeof(empTemp)) == TODO_OK)
    {
        printf("%d %s\n", empTemp.id, empTemp.nombre);
    }
    else printf("fallo ver primero \n");


    /// TEST 6:
    vaciarCola(&cola);
        if(colaVacia(&cola))
        printf("La cola se vacio\n");
    else
        printf("La cola NO se vacio\n");


    return 0;
}




