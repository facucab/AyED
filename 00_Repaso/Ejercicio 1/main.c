/**
Implemente un TDA Vector. Debe desarrollar una versión con memoria estática y otra con memoria
dinámica. Debe implementar las primitivas:
- crear vector *
- vector lleno *
- vector vacío *
- insertar elemento en orden *
- ver elemento de una posición dada *
- eliminar elemento *
- destruir vector *
Tenga en cuenta que la primitiva ‘destruir’ debe, según sea el caso, liberar la memoria reservada, o
poner la cantidad de elementos en cero.
Contemple los casos frontera.
Defina y prepare el entorno para que se puedan probar las funcionalidades solicitadas.

*/

#include <stdio.h>
#include <stdlib.h>
#include "TDAVector.h"
int main() {
    Vector vec;

    printf("===== TEST 1: Crear vector =====\n");
    createVector(&vec, 5);
    if (vec.data == NULL) {
        printf("ERROR EN LA ASIGNACION DE MEMORIA\n");
        return -1;
    }

    printf("\n===== TEST 2: Verificar si el vector esta vacio =====\n");
    if (isEmptyVector(&vec) == 1) {
        printf("El vector esta vacio\n");
    }

    printf("\n===== TEST 3: Insertar elementos ordenados =====\n");
    insertInOrder(&vec, 5);
    insertInOrder(&vec, 1);
    insertInOrder(&vec, 5);
    insertInOrder(&vec, 5);
    insertInOrder(&vec, 1);
    insertInOrder(&vec, 3);
    insertInOrder(&vec, -1);
    insertInOrder(&vec, 0);
    printVector(&vec);

    printf("\n===== TEST 4: Obtener elemento en la posicion 1 =====\n");
    int *result = getElement(&vec, 1);
    if (result != NULL) {
        printf("Elemento en la posicion 1: %d\n", *result);
    } else {
        printf("El elemento no fue encontrado\n");
    }

    printf("\n===== TEST 5: Eliminar elemento en la posicion 7 =====\n");
    removeElement(&vec, 7);
    printVector(&vec);

    printf("\n===== TEST 6: Destruir vector =====\n");
    destroyVector(&vec);
    if (vec.data == NULL) {
        printf("El vector fue destruido correctamente\n");
    }

    return 0;
}
