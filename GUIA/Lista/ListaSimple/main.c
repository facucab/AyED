#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
void mostrarInt(void * dato);
int cmpInt(void * a, void * b);

int main()
{
    tLista lista;
    tLista lista_2;
    tLista lista_3;

    int datos[] = {1,67,3,1,32};
    int i;

    /// ################### TEST LISTA SIMPLEMENTE ENLAZADA ###################
    printf("################### TEST LISTA SIMPLEMENTE ENLAZADA ###################\n\n");
    crearLista(&lista);
    crearLista(&lista_2);
    crearLista(&lista_3);

    // TEST 1:
    if(listaVacia(&lista)) printf("[EXITO] TEST 1: La lista esta vacia\n");
    else printf("[ERROR] TEST 1: La lista NO esta vacia\n");

    // PRE-TEST 2, 3 y 4:
    for(i = 0; i < sizeof(datos) / sizeof(datos[0]); i++)
    {
        insertarInicio(&lista, &datos[i], sizeof(datos[0]));
        insertarFin(&lista_2, &datos[i], sizeof(datos[0]));
        insertarOrden(&lista_3, &datos[i], sizeof(datos[0]), cmpInt);
    }

    // TEST 2: Insertar inicio
    printf("[-----] TEST 2 - Resultado esperado: 32 1 3 67 1\n");
    mapLista(&lista, mostrarInt);
    printf("\n");

    // TEST 3: Insertar fin
    printf("[-----] TEST 3 - Resultado esperado: 1 67 3 1 32\n");
    mapLista(&lista_2, mostrarInt);
    printf("\n");

    // TEST 4: Insertar ordenado
    printf("[-----] TEST 3 - Resultado esperado: 1 1 3 32 67 \n");
    mapLista(&lista_3, mostrarInt);
    printf("\n");

    return 0;
}

void mostrarInt(void * dato)
{
    int valor = *((int *)dato);
    printf("%d ", valor);
}

int cmpInt(void * a, void * b)
{
    int valor_a = *((int *)a);
    int valor_b = *((int *)b);

    return valor_a - valor_b;
}
