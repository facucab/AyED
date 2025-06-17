#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) ((a)>(b))?(b):(a)

#define SIN_MEMORIA 0
#define TODO_OK 1
#define LISTA_VACIA 0
#define CLAVE_NO_ENCONTRADA 0
typedef struct sNodo
{
    void * dato;
    unsigned tamDato;
    struct sNodo * ant;
    struct sNodo * sig;
}tNodo;
typedef tNodo * tLista;
void crearLista(tLista * lista);
int insertarOrdenado(tLista * lista, void * dato, unsigned tamDato, int (*cmp)(void *, void *));
int eliminarPorClave(tLista * lista, void * clave, int (*cmp)(void *, void *));
void mostraListaDesdeInicio(tLista * lista, void (*acc)(void *));
void mostraListaDesdeFin(tLista * lista, void (*acc)(void *));
void vaciarLista(tLista * lista);

#endif // LISTA_H_INCLUDED
