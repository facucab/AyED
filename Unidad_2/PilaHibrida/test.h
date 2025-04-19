#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

typedef struct
{
    int dni;
    char nombre[30];
}tAlumno;

int crearArchivoPrueba(const char * nombre);
int cargaDeDatosPila_TEST(tPila * pila, const char * nombreArch);
#endif // TEST_H_INCLUDED
