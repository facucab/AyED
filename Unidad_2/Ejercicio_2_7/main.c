#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "sum.h"

int main()
{
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

    return 0;
}
