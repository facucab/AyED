#include "TDAProducto.h"

/**
* Inserta un producto en una lista enlazada.
* @param lista - Es la lista de nodos, donde se va a insertar el producto.
* @param prod - Es el producto a insertar
* @return Nodo *
*/
Nodo * insertarProducto(Nodo * lista, Producto prod){
    // Creo el nuevo nodo
    Nodo * nuevo = (Nodo *)malloc(sizeof(Nodo));
    if(nuevo == NULL) return lista;

    nuevo->prod = prod; /// SOLO SE PUEDE HACER, PORQUE LA ESTRUCTURA TIENE DATOS PRIMITIVOS
    nuevo->nodoSig = NULL;

    // Valido si es el primer elemento:
    if(lista == NULL) return nuevo;

    // Recorro hasta el nodo final:
    Nodo * nodoI = lista;
    while(nodoI->nodoSig != NULL){
        nodoI = nodoI->nodoSig;
    }

    nodoI->nodoSig = nuevo;

    return lista;
}


void mostrarProductos(Nodo * lista){
    if(lista == NULL) return;

    printf("\n%d\t%s\t%d ", lista->prod.id, lista->prod.nombre, lista->prod.stock);

    mostrarProductos(lista->nodoSig);

}
