#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
typedef struct
{
    int dni;
    char nombre[35];
} tAlumno;

int main()
{
    tCola cola;
    crearCola(&cola);
    tCola cola_vacia;
    crearCola(&cola_vacia);

    /// TEST 1: COLA VACIA
    if(colaVacia(&cola)) printf("La cola esta vacia\n");
    else printf("La cola NO esta vacia\n");


    /// TEST 2:
    tAlumno alumnos[] =
    {
        {1, "F"},
        {2, "C"},
        {3, "S"},
        {4, "FC"},
        {5, "CF"},
    };

    for(int i = 0; i< (sizeof(alumnos) / sizeof(alumnos[0])); i++)
    {
        if(!ponerEnCola(&cola, &alumnos[i], sizeof(alumnos[i]))) break;
    }

    if(colaVacia(&cola)) printf("La cola esta vacia\n");
    else printf("La cola NO esta vacia\n");


    /// TEST 3: Ver primero
    tAlumno primerAlumno;

    if(verPrimero(&cola, &primerAlumno, sizeof(primerAlumno))){
        printf("El primer alumno es: %d\t%s\n", primerAlumno.dni, primerAlumno.nombre);
    }
    else printf("No se pudo obtener el tope");


    /// TEST 4: Sacar Cola
    tAlumno auxAlu;

    for(int i = 0; i < 2; i++)
    {
        if(sacarDeCola(&cola,&auxAlu, sizeof(auxAlu)))
        {
            printf("El elemento %d es: %d\t%s\n",i+1, auxAlu.dni, auxAlu.nombre);
        }
        else printf("Cola vacia\n");
    }


    /// TEST 5: Vaciar cola
    vaciarCola(&cola);
    if(colaVacia(&cola)) printf("La cola esta vacia");
    else printf("La cola no esta vacia");


    return 0;
}
