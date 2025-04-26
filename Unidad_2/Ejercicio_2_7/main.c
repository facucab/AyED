#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "sum.h"
#define ARCH_NUM1 "nro1.txt"
#define ARCH_NUM2 "nro2.txt"

int main()
{
    crearArchNum(ARCH_NUM1, "987654321987654321987654321");
    crearArchNum(ARCH_NUM2, "123456789123456789123456789");

    char num1 [1000];
    char num2 [1000];

    if(!leerNumeroArch(ARCH_NUM1, num1, sizeof(num1)))
    {
        printf("No se puede leer el numero 1\n");
        return 0;
    }

    if(!leerNumeroArch(ARCH_NUM2, num2, sizeof(num2)))
    {
        printf("No se puede leer el numero 2\n");
        return  0;
    }

    sumarNum(num1, num2);// RESULTADO ESPERADO: 1111111111111111111111111110



    /*
    /// TEST 1:

    char num1 [] = {"987654321987654321987654321"};
    char num2 [] = {"123456789123456789123456789"};
    sumarNum(num1, num2); // RESULTADO ESPERADO: 1111111111111111111111111110

    printf("\n");

    /// TEST 2:
    char num3 [] = {"999999999999999999999999999999"};
    char num4 [] = {"1"};
    sumarNum(num3, num4); // RESULTADO ESPERADO: 1000000000000000000000000000000

     printf("\n");

    /// TEST 2:
    char num5 [] = {"4934"};
    char num6 [] = {"7"};
    sumarNum(num5, num6); // RESULTADO ESPERADO: 1000000000000000000000000000000

    */
    return 0;
}
