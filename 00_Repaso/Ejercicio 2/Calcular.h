#ifndef CALCULAR_H_INCLUDED
#define CALCULAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
void calcular(void * num1, void * num2, void (*op)(void *, void*,void * ), void * resultado);
void sumarInt(void * num1, void * num2, void * resultado);
void multFloat(void * num1, void * num2, void*resultado);
void divInt(void * num1, void * num2, void*resultado);
#endif // CALCULAR_H_INCLUDED
