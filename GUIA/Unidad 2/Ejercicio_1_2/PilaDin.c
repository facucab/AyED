#include "PilaDin.h"

void crearPila_Din(tPilaDin * pila){
    *pila = NULL;
}

int pilaLlena_Din(const tPilaDin * pila, unsigned tamDato)
{
    return 0;
}

int pilaVacia_Din(const tPilaDin * pila)
{
    return *pila == NULL;
}

int apilar_Din(tPilaDin * pila, const void * dato, unsigned tamDato)
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
    nue->sig = *pila;

    *pila = nue;

    return TODO_OK;
}

int desapilar_Din(tPilaDin * pila, void * dato, unsigned tamDato)
{
    tNodo * elim = *pila;

    if(*pila == NULL) return PILA_VACIA_DIN;

    *pila = elim->sig;

    //copio el dato
    memcpy(dato, elim->dato, MIN(tamDato, elim->tamDato));

    // libero memoria
    free(elim->dato);
    free(elim);

    return TODO_OK;
}

int verTope_Din(const tPilaDin * pila, void * dato, unsigned tamDato){

    if(*pila == NULL) return PILA_VACIA_DIN;

    memcpy(dato, (*pila)->dato, MIN((*pila)->tamDato,tamDato));

    return TODO_OK;
}

int vaciarPila_Din(tPilaDin * pila)
{
    tNodo * elim;

    while(*pila){
        elim = *pila;
        *pila = elim->sig;

        free(elim->dato);
        free(elim);
    }

    return TODO_OK;
}
