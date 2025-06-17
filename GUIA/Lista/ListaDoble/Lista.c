#include "Lista.h"

void crearLista(tLista * lista)
{
    *lista = NULL;
}

int insertarOrdenado(tLista * lista, void * dato, unsigned tamDato, int (*cmp)(void *, void *))
{
    tNodo * ant, *sig, *act, *nue;
    act = *lista;

    if(*lista == NULL)
    {
        ant = NULL;
        sig = NULL;
    }
    else
    {
        while(act->sig && cmp(act->dato, dato) < 0) act = act->sig;
        while(act->ant && cmp(act->dato, dato) > 0) act = act->ant;

        if(cmp(act->dato, dato) >= 0)
        {
            sig = act;
            ant = act->ant;

        }
        else{
            ant = act;
            sig = act->sig;
        }
    }

    ///
    nue = (tNodo *)malloc(sizeof(tNodo));
    if(!nue) return SIN_MEMORIA;

    nue->dato = malloc(tamDato);
    if(!nue->dato){
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;

    nue->sig = sig;
    nue->ant = ant;

    //Enlanzar
    if(ant) ant->sig = nue;
    if(sig) sig->ant = nue;

    *lista = nue;

    return TODO_OK;

}

void mostraListaDesdeInicio(tLista * lista, void (*acc)(void *))
{
    tNodo * aux = *lista;

    ///accedo al primer nodo
    while(aux->ant)
    {
        aux = aux->ant;
    }

    while(aux)
    {
        acc(aux->dato);
        aux = aux->sig;
    }

}

void mostraListaDesdeFin(tLista * lista, void (*acc)(void *))
{
    tNodo * aux = *lista;

    while(aux->sig)
    {
        aux = aux->sig;
    }

    while(aux)
    {
        acc(aux->dato);
        aux = aux->ant;
    }
}

int eliminarPorClave(tLista * lista, void * clave, int (*cmp)(void *, void *))
{
    tNodo * elim, *ant, *sig;
    elim = *lista;

    if(*lista == NULL) return LISTA_VACIA;

    while(elim->ant){
        elim = elim->ant;
    }


    while(elim && cmp(elim->dato, clave) != 0)
    {
        elim = elim->sig;
    }

    if(!elim) return CLAVE_NO_ENCONTRADA;

    ant =  elim->ant;
    sig = elim->sig;

    if(ant) ant->sig = elim->sig;
    if(sig) sig->ant = elim->ant;

    // Si el nodo eliminado apuntaba a lista

    if(elim == *lista)
    {
        if(ant) *lista = ant;
        else *lista = sig;
    }

    free(elim->dato);
    free(elim);


    return TODO_OK;

}

