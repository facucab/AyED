#include "Cola.h"

void crearCola(tCola * cola)
{
    cola->pri = NULL;
}

int colaLLena(const tCola * cola, unsigned tamDato)
{
    return 0;
}
int colaVacia(const tCola * cola)
{
    return cola->pri == NULL;
}

int encolar(tCola * cola, const void * dato, unsigned tamDato)
{
    tNodo * nue = (tNodo *)malloc(sizeof(tNodo));
    if(!nue) return SIN_MEMORIA;

    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->dato, dato, tamDato);
    nue->sig = NULL;
    nue->tamDato = tamDato;


    if(cola->pri == NULL) cola->pri = nue;
    else cola->ult->sig = nue;

    cola->ult = nue;

    return TODO_OK;
}

int desencolar(tCola * cola, void * dato, unsigned tamDato)
{
    tNodo * elim = cola->pri;

    if(cola->pri == NULL) return COLA_VACIA;

    memcpy(dato, elim->dato, MIN(tamDato, elim->tamDato));

    // Eliminar nodo:
    cola->pri = elim->sig;

    //Liberamos memoria:
    free(elim->dato);
    free(elim);

    return TODO_OK;
}

int verPrimeroCola(const tCola * cola, void * dato, unsigned tamDato)
{
    if(cola->pri == NULL) return COLA_VACIA;

    memcpy(dato, cola->pri->dato, MIN(tamDato, cola->pri->tamDato));

    return TODO_OK;
}

void vaciarCola(tCola * cola)
{
    tNodo * elim;
    while(cola->pri != NULL)
    {
        elim = cola->pri;
        cola->pri = elim->sig;

        free(elim->dato);
        free(elim);
    }
}

