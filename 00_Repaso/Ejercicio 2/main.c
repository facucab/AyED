/*
Implemente una funci�n que se denomine calcular. Esta funci�n debe recibir al menos tres
argumentos:
- Operando 1.
- Operando 2.
- Puntero a funci�n. Por ah� recibe la funci�n que resuelve la operaci�n (sumar, restar,
multiplicar y dividir).
Contemple los casos frontera.
Determine c�mo se har� la devoluci�n del resultado.
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
