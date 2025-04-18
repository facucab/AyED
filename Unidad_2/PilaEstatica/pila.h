#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TAM_PILA 30
#include <string.h>
#include <stdio.h>
#define MIN(a,b) ((a)>(b))?(b):(a)
typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
} tpila;

void crearPila(tpila * pila);
int pilaLlena(const tpila* pila, unsigned cantBytes);
int ponerEnPila(tpila * pila, void * dato, unsigned tamDato);
int verTope(const tpila * pila, void * dato, unsigned tamDato);
int pilaVacia(const tpila * pila);
int sacarDePila(tpila *pila, void * dato, unsigned tamDato);
void vaciarPila(tpila * pila);
#endif // PILA_H_INCLUDED
