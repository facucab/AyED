#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    /// FACTORIAL:
    int n = 5;
    printf("\nPUNTO 1)\n");
    printf("El factorial de %d es: %d", n, factorial(n));

    /// Mostrar cadena:
    char cadena[] = {"Hola"};
    printf("\nPUNTO 2)");
    mostrarCadena(cadena);

    printf("\nPUNTO 3)\n");
    mostrarCadenaInvertido(cadena);

    printf("\nPUNTO 4)");
    mostrarCadenaLetraAletra(cadena);

    printf("\nPUNTO 5)");
    mostrarCadenaLetraAletraInverso(cadena);

    printf("\nPUNTO 6)");
    descomponerEntero(12345);

    printf("\nPUNTO 7)");
    descomponerEnteroInverso(12345);

    return 0;
}
