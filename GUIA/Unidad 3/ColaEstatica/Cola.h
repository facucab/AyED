#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <string.h>
#include <stdlib.h>


#define MIN(a,b) ((a)>(b))?(b):(a)

/// codigo de estados:
#define SIN_MEMORIA 0
#define TODO_OK 1
#define COLA_VACIA 0


typedef struct sNodo {
    void * dato;
    unsigned tamDato;
    struct sNodo * sig;
}tNodo;

typedef struct {
    tNodo * pri;
    tNodo * ult;
}tCola;

void crearCola(tCola * cola);
int colaLLena(const tCola * cola, unsigned tamDato);
int colaVacia(const tCola * cola);
int encolar(tCola * cola, const void * dato, unsigned tamDato);
int desencolar(tCola * cola, void * dato, unsigned tamDato);
void vaciarCola(tCola * cola);
int verPrimeroCola(const tCola * cola, void * dato, unsigned tamDato);

#endif // COLA_H_INCLUDED
