#include "lista.h"

/**
*
*/
void crearLista(tLista * lista)
{
    *lista = NULL;
}

/**
*
*/
int insertarInicio(tLista * lista, const void * dato, unsigned tamDato)
{
    tNodo * nuevoNodo = (tNodo *)malloc(sizeof(tNodo));

    if(!nuevoNodo || (nuevoNodo->info = malloc(tamDato)) == NULL )
    {
        free(nuevoNodo);
        return SIN_MEMORIA;
    }

    memcpy(nuevoNodo->info, dato, tamDato);
    nuevoNodo->tamDato = tamDato;

    nuevoNodo->sig = *lista;
    *lista = nuevoNodo;

    return TODO_OK;

}

void mapLista(tLista * lista, ACCION acc)
{
    while(*lista)
    {
        acc((*lista)->info);
        lista = &(*lista)->sig;
    }
}


/**
*´Algoritmo:
* 1. Verifico que la lista no este vacia.
* 2. Bucle do-while, al menos debo validar una vez si esta todo ordenado, este bucle se ejecuta si hubo intercambio.
* Una vez, que intercambio es igual a cero, signfica que se ordeno
* 3. por cada pasada del bucle do-while cambio la flah intercambio a 0
* 4. Mientras que la lista sea no nula y tenga elementos siguiente ejecuto.
* 5. Si el elemento actual es mayor al elemento siguiente debo intercambiar
* 6. Incremento lista.
*
*/
int ordenarLista(tLista * lista, Comparar comp, ACCION acc)
{
    int intercambio;
    if(*lista == NULL) return LISTA_VACIA;

    do
    {
        intercambio = 0;
        tLista * auxLista = lista;
        while(*auxLista && (*auxLista)->sig)
        {

            if( comp((*auxLista)->info, (*auxLista)->sig->info) > 0)
            {
                tNodo * a = *auxLista;
                tNodo * b = (*auxLista)->sig;

                a->sig = b->sig;
                b->sig = a;
                *auxLista = b;

                intercambio = 1;
            }
            auxLista = &((*auxLista)->sig);
        }
    }while(intercambio);

    return TODO_OK;
}



