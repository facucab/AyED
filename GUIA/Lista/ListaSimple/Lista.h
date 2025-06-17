#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#define MIN(a,b) ((a)>(b))?(b):(a)

/// CODIGO DE ERRORES:
#define SIN_MEMORIA 0
#define TODO_OK 1


typedef struct sNodo{
    void * dato;
    unsigned tamDato;
    struct sNodo * sig;
}tNodo;

typedef tNodo * tLista;

void crearLista(tLista * lista);
int listaVacia(const tLista * lista);
int listaLLena(const tLista * lista, unsigned tamDato);
int insertarInicio(tLista * lista, const void * dato, unsigned tamDato);
int insertarFin(tLista * lista, const void * dato, unsigned tamDato);
int insertarOrden(tLista * lista, void *dato, unsigned tamDato, int (*cmp)(void *, void *));
void mapLista(tLista * lista, void (*acc)(void *));



#endif // LISTA_H_INCLUDED
