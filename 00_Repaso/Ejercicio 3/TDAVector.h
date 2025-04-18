#ifndef TDAVECTOR_H_INCLUDED
#define TDAVECTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int * data;
    size_t capacity;
    size_t size;
}Vector;
void createVector(Vector * v, size_t capacity);
void destroyVector(Vector * v);
void printVector(Vector * v);
int cargarTDAconArch(Vector * v, char * name);
#endif // TDAVECTOR_H_INCLUDED
