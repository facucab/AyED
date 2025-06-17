#include "arbol.h"

void crearArbol(tArbol * arbol)
{
    *arbol = NULL;
}

int insertarArbolBinBusq(tArbol *arbol,  void *dato, unsigned tamDato, int (*cmp)( void *,  void *))
{
    int resultado;
    tNodo * nue;

    while(*arbol)
    {
        resultado = cmp((*arbol)->dato, dato);

        if(resultado > 0 ) arbol = &(*arbol)->der;
        else if(resultado < 0) arbol = &(*arbol)->izq;
        else return ERROR;

    }

    // reservo memoria:
    nue = (tNodo *)malloc(sizeof(tNodo));
    if(!nue) return ERROR;

    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return ERROR;
    }

    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;
    nue->der = NULL;
    nue->izq = NULL;


    *arbol = nue;

    return TODO_OK;
}

/**
* IN-ORDEN IRD - Izquierda - Ráiz - Derecha
*/
void recorrerInOrden(tArbol * arbol, void (*acc)(void *))
{
    if(!*arbol) return;

    recorrerInOrden(&(*arbol)->izq, acc);
    acc((*arbol)->dato);
    recorrerInOrden(&(*arbol)->der, acc);
}

/**
* PRE-ORDEN RID - Ráiz - Izquierda - Derecha
*/
void recorrerPreOrden(tArbol * arbol, void (*acc)(void *))
{
    if(!*arbol) return;

    acc((*arbol)->dato);

    recorrerPreOrden(&(*arbol)->izq, acc);
    recorrerPreOrden(&(*arbol)->der, acc);

}

/**
* POS-ORDEN IDR: Izquierda - Derecha - Raiz
*/

void recorrerPosOrden(tArbol * arbol, void (*acc)(void *))
{
    if(!*arbol) return;

    recorrerPosOrden(&(*arbol)->izq, acc);
    recorrerPosOrden(&(*arbol)->der, acc);
    acc((*arbol)->dato);
}
