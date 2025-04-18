#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#define TAM_COLA 30
#define MIN(a,b) ((a)>(b))?(b):(a)
#include <string.h>
typedef struct {
    char cola[TAM_COLA];
    unsigned pri;
    unsigned ult;
    unsigned tamDisp;
}tCola;
void crearCola(tCola * cola);
int colaVacia(const tCola * cola);
int colaLlena(const tCola * cola, unsigned tamDato);
int ponerEnCola(tCola * cola, const void * dato, unsigned tamDato);
int sacarDeCola(tCola * cola, void * dato, unsigned tamDato);
int verPrimero(const tCola * cola, void * dato, unsigned tamDato);
void vaciarCola(tCola * cola);
#endif // COLA_H_INCLUDED
