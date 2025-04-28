#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "cola.h"

#define ERROR_ARCHIVO 0
#define ARCHIVO_CREADO 1
#define TODO_OK 1
#define ERROR 0
#define FALLA "FALLA"

typedef struct
{
    char codLote[10];
    int idProducto;
    char resultadoControl[6];
}tRegistro;

int crearLote(const char * nombre);
int controlLotes(const char * nombre);
void trozarLinea(char * linea, tRegistro * reg);
void grabarColaEnArchivo(tCola * cola, FILE * archivo);
void menu(const char * nombre);
int mostrarArchivo(const char * nombre);
#endif // FUNCIONES_H_INCLUDED
