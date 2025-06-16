#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TODO_OK 1
#define SIN_MEMORIA 0
#define LISTA_VACIA 0
typedef struct sNodo
{
    void * info;
    unsigned tamDato;
    struct sNodo * sig;
}tNodo;
typedef void (*ACCION)(void *);
typedef int(*Comparar)(void *, void *);

typedef tNodo * tLista;

void crearLista(tLista * lista);
int insertarInicio(tLista * lista, const void * dato, unsigned tamDato);
void mapLista(tLista * lista, ACCION acc);
int ordenarLista(tLista *lista, Comparar comp, ACCION acc);

#endif // LISTA_H_INCLUDED
