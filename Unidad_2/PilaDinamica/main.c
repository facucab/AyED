#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
typedef struct
{
    int dni;
    char nombre[30];
}tAlumno;

int main()
{
    tPila p1;
    crearPila(&p1);

    /// TEST PILA VACIA:

    if(pilaVacia(&p1)) printf("PILA VACIA\n");
    else printf("PILA NO VACIA\n");

    /// TEST 3:
    char letra = 'a';
    ponerEnPila(&p1, &letra, sizeof(letra));
    char letra2 = 'b';
    ponerEnPila(&p1, &letra2, sizeof(letra2));

    if(pilaVacia(&p1)) printf("PILA VACIA\n");
    else printf("PILA NO VACIA\n");

    /// TEST 4:

    char valorObtener;
    if(sacarPila(&p1, &valorObtener, sizeof(valorObtener)))
    {
        printf("El valor obtenido es: %c\n", valorObtener);
    }
    else printf("No se pudo obtener el valor de la pila\n");


    /// TEST 5: Ver tope (el tope no remueve nada de la pila)
    char valorTope;
    if(verTope(&p1, &valorTope, sizeof(valorTope)))
    {
        printf("El valor del tope es: %c\n",valorTope);
    }

    /// TEST 6: Vaciar pila
    tPila p2;
    crearPila(&p2);
    tAlumno alumnos[] = {
        {1, "Facundo"},
        {2, "Lionel"},
        {3, "Messi"}
    };

    for(int i = 0; i < (sizeof(alumnos)/sizeof(alumnos[0])); i++)
    {
        if(!ponerEnPila(&p2, &alumnos[i], sizeof(alumnos[i]))) break;
    }

    /*
    tAlumno aux;
    while(sacarPila(&p2,&aux, sizeof(aux)))
    {
        printf("%d\t%s\n", aux.dni, aux.nombre);
    }
    */
    vaciarPila(&p2);
    if(pilaVacia(&p2)) printf("La pila esta vacia");


    return 0;
}
