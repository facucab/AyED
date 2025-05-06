#include "cola.h"

/*
* ESTA BIEN
*/
void crearCola(tCola * cola)
{
    cola->pri = NULL;
    //cola->ult = NULL; /// No es necesario.
}
/*
* ESTA BIEN
*/
int colaVacia(const tCola * cola)
{
    return cola->pri == NULL;
}

/*
* ESTA BIEN
*/
int ponerEnCola(tCola * cola, const void * dato, unsigned tamDato)
{
    /// Reservamos memoria para nodo e info.
    tNodo * nue = (tNodo *) malloc(sizeof(tNodo));
    if(!nue) return SIN_MEMORIA;

    nue->dato = malloc(tamDato);
    if(!nue->dato)
    {
        free(nue);
        return SIN_MEMORIA;
    }

    /// Copiamos del buffer al nuevo nodo:
    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;
    nue->sig = NULL;

    ///
    if(cola->pri == NULL)
        cola->pri = nue;
    else
        cola->ult->sig = nue;

    cola->ult = nue;

    return TODO_OK;
}

/*
* ESTA BIEN
*/
int sacarDeCola(tCola * cola, void * dato, unsigned tamDato)
{
    tNodo * elim = cola->pri;

    /// validar si la cola no esta vacia:
    if(cola->pri == NULL) return COLA_VACIA; // PODRIA SER ELIM, EN lugar de cola->pri

    /// Copiamos en el buffer elim
    memcpy(dato, elim->dato, MIN(tamDato, elim->tamDato));

    /// el primero apunta al siguiente
    cola->pri = elim->sig;

    /// liberamos memoria:
    free(elim->dato);
    free(elim);

    return TODO_OK;
}

/*
* ESTA BIEN
*/
int verPrimero(const tCola * cola, void * dato, unsigned tamDato)
{
    /// validar si la cola no esta vacia:
    if(cola->pri == NULL) return COLA_VACIA;

    memcpy(dato, cola->pri->dato, MIN(cola->pri->tamDato, tamDato));

    return TODO_OK;
}

/*
* ESTA BIEN
*/
int colaLLena(const tCola * cola, unsigned tamDato)
{
    return 0;
}

/*
* ESTA BIEN
*/
void vaciarCola(tCola * cola)
{
    tNodo * elim = cola->pri;
    while(cola->pri != NULL)
    {
        cola->pri = elim->sig;
        free(elim->dato);
        free(elim);
        elim = cola->pri;
    }
}



