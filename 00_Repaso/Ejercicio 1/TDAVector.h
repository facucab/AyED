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
int insertInOrder(Vector * v, int elem);
int isEmptyVector(Vector * v);
int isFullVector(Vector * v);
int * getElement(Vector * v, int index);
int removeElement(Vector * v, int index);
void printVector(Vector * v);
void destroyVector(Vector * v);
#endif // TDAVECTOR_H_INCLUDED
