#include "Calcular.h"

void calcular(void * num1, void * num2, void (*op)(void *, void*, void*), void * resultado)
{
    op(num1, num2, resultado);
}

void sumarInt(void * num1, void * num2, void * resultado)
{
    int value_1 = * ((int*) num1);
    int value_2 = * ((int*) num2);

    *((int *)resultado) = value_1 + value_2;
}

void multFloat(void * num1, void * num2, void*resultado)
{
    *(float *)resultado = (*(float *)num1) * (*(float *)num2);
}

void divInt(void * num1, void * num2, void*resultado)
{
    int value_1 = *(int*)num1;
    int value_2 = *(int*)num2;

    if(value_2 != 0)
    {
        *(float *)resultado = value_1 / (float)value_2;

    }
    else
    {
        printf("\nNo se puede dividir por cero\n");
    }


}
