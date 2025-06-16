#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TAM_PILA 30
#include <string.h>
#define MIN(a,b) ((a)>(b))?(b):(a)

///CODIGO DE ESTADOS:
#define EXITO 1
#define DATO_APILADO 100
#define DATO_DESAPILADO 101
#define PILA_LLENA -100
#define PILA_VACIA -101

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
}tPila;

void crearPila(tPila * pila);
int pilaLlena(const tPila * pila, unsigned tamDato);
int pilaVacia(const tPila * pila);
int apilar(tPila * pila, const void * dato, unsigned tamDato);
int desapilar(tPila * pila, void * dato, unsigned tamDato);
int verTope(const tPila * pila, void * dato, unsigned tamDato);
int vaciarPila(tPila * pila);



#endif // PILA_H_INCLUDED
