#ifndef TDAPRODUCTO_H_INCLUDED
#define TDAPRODUCTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    char nombre[50];
    int stock;
}Producto;

typedef struct {
    Producto prod;
    struct Nodo * nodoSig;
}Nodo;

Nodo * insertarProducto(Nodo * lista, Producto prod);
void mostrarProductos(Nodo * lista);
#endif // TDAPRODUCTO_H_INCLUDED
