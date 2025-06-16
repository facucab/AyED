#ifndef PILADIN_H_INCLUDED
#define PILADIN_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#define MIN(a,b) ((a)>(b))?(b):(a)

#define SIN_MEMORIA 0
#define TODO_OK 1
#define PILA_VACIA_DIN 0

typedef struct sNodo {
    void * dato;
    unsigned tamDato;
    struct sNodo * sig;
}tNodo;

typedef tNodo * tPilaDin;


void crearPila_Din(tPilaDin * pila);
int pilaLlena_Din(const tPilaDin * pila, unsigned tamDato);
int pilaVacia_Din(const tPilaDin * pila);
int apilar_Din(tPilaDin * pila, const void * dato, unsigned tamDato);
int desapilar_Din(tPilaDin * pila, void * dato, unsigned tamDato);
int verTope_Din(const tPilaDin * pila, void * dato, unsigned tamDato);
int vaciarPila_Din(tPilaDin * pila);

#endif // PILADIN_H_INCLUDED
