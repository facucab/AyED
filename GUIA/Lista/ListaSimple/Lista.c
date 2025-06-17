#include "Lista.h"

void crearLista(tLista * lista)
{
    *lista = NULL;
}

int listaVacia(const tLista * lista)
{
    return *lista == NULL;
}

int listaLLena(const tLista * lista, unsigned tamDato)
{
    return 0;
}

int insertarInicio(tLista * lista, const void * dato, unsigned tamDato)
{
    tNodo * nue = (tNodo *)malloc(sizeof(tNodo));
    if(!nue) return SIN_MEMORIA;

    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;

    // Intercambio nodos:
    nue->sig = *lista;
    *lista = nue;

    return TODO_OK;
}

int insertarFin(tLista * lista, const void * dato, unsigned tamDato)
{
    tNodo * nue = (tNodo *)malloc(sizeof(tNodo));
    if(!nue) return SIN_MEMORIA;

    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return SIN_MEMORIA;
    }

    // Copio el dato:
    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;
    nue->sig = NULL;

    // muevo la lista, hasta el siguiente del ultimo
    while(*lista)
    {
        lista = &(*lista)->sig;
    }

    *lista = nue;

    return TODO_OK;

}

int insertarOrden(tLista * lista, void *dato, unsigned tamDato, int (*cmp)(void *, void *))
{
    tNodo * nue = (tNodo *)malloc(sizeof(tNodo));
    if(!nue) return SIN_MEMORIA;

    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return SIN_MEMORIA;
    }

    //Copio el dato en el nuevo NODO
    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;


    while(*lista && cmp(dato, (*lista)->dato) >0 )
    {
        lista = &(*lista)->sig;
    }

    nue->sig = *lista;
    *lista = nue;

    return TODO_OK;
}

void mapLista(tLista * lista, void (*acc)(void *))
{
    while(*lista)
    {
        acc((*lista)->dato);
        lista = &(*lista)->sig;
    }
}


