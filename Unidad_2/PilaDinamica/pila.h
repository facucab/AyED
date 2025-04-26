#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "stdlib.h"
#include "string.h"
#define MIN(a,b) ((a)>(b))?(b):(a)
typedef struct sNodo
{
    void * info;
    unsigned tamDato;
    struct sNodo * sig;
} tNodo;

typedef tNodo * tPila;

void crearPila(tPila * pila);
int pilaLlena(const tPila * pila, unsigned tamBytes);
int ponerEnPila(tPila * pila, void * dato, unsigned tamDato);
int pilaVacia(const tPila * pila);
int verTope(const tPila * pila, void * dato, unsigned tamDato);
int sacarPila(tPila * pila, void * dato, unsigned tamDato);
void vaciarPila(tPila * pila);



#endif // PILA_H_INCLUDED
