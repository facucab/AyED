#include <stdio.h>
#include <stdlib.h>
#include "TDAProducto.h"
/*
REVISAR PARA APLICAR MEJORAS Y SOLUCIONAR WARNINGS
*/
int main()
{
    Nodo * lista = NULL;

    /// Insertar productos:
    Producto p1 = {1, "Lapicera", 50};
    Producto p2 = {2, "Cuaderno", 30};
    Producto p3 = {3, "Regla", 20};

    lista = insertarProducto(lista, p1);
    lista = insertarProducto(lista, p2);
    lista = insertarProducto(lista, p3);

    mostrarProductos(lista);
    return 0;
}
