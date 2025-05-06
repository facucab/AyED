#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main()
{
    tLista lista;

    crearLista(&lista);
    if(listaVacia(&lista)) printf("La lista esta vacia\n");
    else printf("La lista NO esta vacia\n");


    /// Agregar elementos:

    tPersona personas[] =
    {
        {343,"aNA"},
        {5,"juan"},
        {5,"pEdRo"}
    };

    for(int i = 0; i < sizeof(personas) / sizeof(personas[0]); i++)
    {
        agregarPrimeroLista(&lista, &personas[i], sizeof(personas[i]));
    }
    if(listaVacia(&lista)) printf("La lista no se cargo\n");
    else printf("La lista se cargo correctamente!\n");

    ///Normalizar nombre
    mapLista(&lista, normPersona);

    /// Mostrar lista:

    mapLista(&lista, mostraAlumno);

    return 0;
}
