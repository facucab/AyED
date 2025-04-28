#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) ((a)>(b))?(b):(a)
typedef struct sNodo
{
    void * info;
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
int colaLlena(const tCola * cola, unsigned tamDato);
int ponerEnCola(tCola * cola, void * dato, unsigned tamDato);
int sacarDeCola(tCola * cola, void * dato, unsigned tamDato);
void vaciarCola(tCola * cola);
int verPrimero(const tCola * cola, void * dato, unsigned tamDato);


#endif // COLA_H_INCLUDED
