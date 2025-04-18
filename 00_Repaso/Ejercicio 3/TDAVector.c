#include "TDAVector.h"


int cargarTDAconArch(Vector * v, char * name){
    // Apertura de archivo:
    FILE * arch = fopen(name, "rt");
    if(arch == NULL){
        printf("ERROR EN LA APERTURA DEL ARCHIVO");
        return -1;
    }

    // Leer primera linea;
    char linea[100];
    fgets(linea, sizeof(linea), arch);
    int tam = atoi(linea);

    if(tam > v->capacity){
        printf("\nREALOCO MEMORIA\n");
        int * aux = v->data;
        v->data = (int *)realloc(v->data, sizeof(int) * (v->capacity + 1));
        if(v->data == NULL){
            v->data = aux;
            printf("\nNO SE PUEDO ASIGNAR MAS MEMORIA\n");
            return -1;
        }
    }

    int * ptr = v->data;
    while(fgets(linea, sizeof(linea), arch)){
        *ptr = atoi(linea);
        ptr++;
        v->size+=1;
    }

}


/**
*Funciones genericas de TDA Vector
*/
*
*/
void createVector(Vector * v, size_t capacity){
    v->data = (int *)malloc(sizeof(int)* capacity);
    v->capacity = capacity;
    v->size = 0;
}
*
*/
void destroyVector(Vector * v){
    if(v->data != NULL){
        free(v->data);
        v->data = NULL;
    }
    v->size = 0;
    v->capacity = 0;
}
*
*/
void printVector(Vector * v){
    int * ptr = v->data;

    for(int i = 0; i < v->size; i++){
        printf("\n%d", *ptr);
        ptr += 1;
    }
}
