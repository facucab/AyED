#ifndef SUM_H_INCLUDED
#define SUM_H_INCLUDED
#define NUM_VACIO -2
#define ERR_PILA_RES -3
#include "pila.h"

void cargarNumEnPila(tPila * pila, const char * numeros);
int sumarNum(const char * num1, const char * num2);
int sumarPilas(tPila * num1, tPila * num2, tPila * res);
void mostrarResultado(tPila * num1);
#endif // SUM_H_INCLUDED
