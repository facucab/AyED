#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define SIN_MEMORIA 0
#define TODO_OK 1
#define COLA_VACIA 0
#define MIN(a,b) ((a)>(b))?(b):(a)
typedef struct sNodo
{
    void * dato;
    unsigned tamDato;
    struct sNodo * sig;
}tNodo;
typedef struct
{
    tNodo * pri;
    tNodo * ult;
}tCola;

void crearCola(tCola * cola);
int colaVacia(const tCola * cola);
int colaLLena(const tCola * cola, unsigned tamDato);
int ponerEnCola(tCola * cola, const void * dato, unsigned tamDato);
int sacarDeCola(tCola * cola, void * dato, unsigned tamDato);
void vaciarCola(tCola * cola);
int verPrimero(const tCola * cola, void * dato, unsigned tamDato);

#endif // COLA_H_INCLUDED
