#include "Pila.h"

void crearPila(tPila * pila){
    pila->tope = TAM_PILA;
}

int pilaLlena(const tPila * pila, unsigned tamDato){
    return pila->tope < (tamDato + sizeof(unsigned));
}

int pilaVacia(const tPila * pila){
    return pila->tope == TAM_PILA;
}

int apilar(tPila * pila, const void * dato, unsigned tamDato){

    if(pila->tope < (tamDato + sizeof(unsigned))) return PILA_LLENA;

    //Copio el dato
    pila->tope -= tamDato;
    memcpy(pila->pila + pila->tope, dato, tamDato);

    //Copio el tamDato
    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila + pila->tope, &tamDato, sizeof(unsigned));

    return DATO_APILADO;
}

int desapilar(tPila * pila, void * dato, unsigned tamDato)
{
    unsigned tamDatoPila;

    if(pila->tope == TAM_PILA) return PILA_VACIA;

    //Obtenemos el tamDato
    memcpy(&tamDatoPila, pila->pila +  pila->tope, sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    //obtenemos el dato
    memcpy(dato, pila->pila + pila->tope, MIN(tamDato,tamDatoPila ));
    pila->tope += tamDato;

    return DATO_DESAPILADO;
}

int verTope(const tPila * pila, void * dato, unsigned tamDato)
{
    unsigned tamDatoPila;

    if(pila->tope == TAM_PILA) return PILA_VACIA;

    // OBTENGO EL TAMDATO:
    memcpy(&tamDatoPila, pila->pila + pila->tope, sizeof(unsigned));

    // obtengo el dato
    memcpy(dato, pila->pila + pila->tope + sizeof(unsigned), MIN(tamDatoPila, tamDato));

    return EXITO;
}

