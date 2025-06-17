#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <string.h>
#include <stdlib.h>

#define TODO_OK 1
#define ERROR 0
typedef struct sNodo
{
    void * dato;
    unsigned tamDato;
    struct sNodo * izq, *der;
}tNodo;

typedef tNodo * tArbol;

void crearArbol(tArbol * arbol);
int insertarArbolBinBusq(tArbol *arbol,  void *dato, unsigned tamDato, int (*cmp)( void *,  void *));
void recorrerInOrden(tArbol * arbol, void (*acc)(void *));
void recorrerPreOrden(tArbol * arbol, void (*acc)(void *));
void recorrerPosOrden(tArbol * arbol, void (*acc)(void *));
#endif // ARBOL_H_INCLUDED

