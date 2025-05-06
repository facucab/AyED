#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct sNodo
{
    void * dato;
    unsigned tamDato;
    struct sNodo * sig;
}tNodo;
typedef struct
{
    int dni;
    char nombre[30];
} tPersona;

typedef tNodo * tLista;

void crearLista(tLista * lista);
int listaVacia(const tLista * lista);
int listaLlena(const tLista * lista, unsigned tamDato);
int agregarPrimeroLista(tLista * lista, const void * dato, unsigned tamDato);
void mostraAlumno(void * dato);
void normPersona(void * dato);
void mapLista(tLista * lista, void(*accion)(void*dato));
void normalizarNombre(char *nombre);
#endif // LISTA_H_INCLUDED
