/*
Implemente una función que se denomine calcular. Esta función debe recibir al menos tres
argumentos:
- Operando 1.
- Operando 2.
- Puntero a función. Por ahí recibe la función que resuelve la operación (sumar, restar,
multiplicar y dividir).
Contemple los casos frontera.
Determine cómo se hará la devolución del resultado.
Defina y prepare el entorno para que se puedan probar las funcionalidades solicitadas
*/
#include <stdio.h>
#include <stdlib.h>
#include "Calcular.h"

int main()
{
    int a = 235;
    int b = 10;
    int resultado;
    calcular(&a, &b, sumarInt, &resultado);
    printf("EL RESULTADO DE LA SUMA DE INT ES: %d" , resultado);

    float c = 1.5;
    float d = 1.5;
    float resultadoFloat;
    calcular(&c, &d, multFloat, &resultadoFloat);
    printf("\nEL RESULTADO DE LA MULT DE FLOAT ES: %f" , resultadoFloat);


    int e = 3;
    int f = 2;
    calcular(&e, &f, divInt, &resultadoFloat);
    printf("\nEL RESULTADO DE LA divicion DE INT ES: %f" , resultadoFloat);
    return 0;

}
