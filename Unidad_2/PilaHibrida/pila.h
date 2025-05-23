#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define CANT_MAX 5
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void * datos[CANT_MAX];
    unsigned tope;
}tPila;

void crearPila(tPila * pila);
int pilaLlena(const tPila * pila);
int ponerEnPila(tPila * pila, const void * dato,unsigned tamDato);
int verTope(const tPila * pila, void * dato, unsigned tamDato);
int sacarDePila(tPila * pila, void * dato, unsigned tamDato);
int pilaVacia(const tPila * pila);
void vaciarPila(tPila * pila);
#endif // PILA_H_INCLUDED
