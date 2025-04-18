#include "TDAVector.h"

/**
* Esta función inicializa el TDA Vector, asignando memoria dinámica e inicializando la capacidad y el tamaño.
* @param v es un puntero al TDA Vector que se va a inicializar.
* @param capacity es la capacidad inicial que tendrá el TDA Vector.
*/
void createVector(Vector * v, size_t capacity){
    v->data = (int *)malloc(sizeof(int)* capacity);
    v->capacity = capacity;
    v->size = 0;
}

/**
* Esta función inserta el elemento 'elem' en el TDA Vector, manteniendo el orden ascendente.
* Si el vector no tiene la capacidad de almacenar el elemento, se redimensiona con realloc.
* @param v es un puntero al TDA Vector donde se va a insertar el elemento.
* @param elem es el entero que se va a insertar.
* @return int retorna -1 si algo falló y 0 si se ejecutó con éxito.
*/
int insertInOrder(Vector * v, int elem){

    int * ptr_end = v->data + v->size;
    int * ptr_start = v->data;
    int pos = 0;

    //Valido la capacidad:
    if(isFullVector(v) == 1){
        int * aux = v->data;
        v->data = (int *)realloc(v->data, sizeof(int) * (v->capacity + 1));
        if(v->data == NULL){
            printf("No fue posible ingresar el elemento a falta de memoria");
            v->data = aux;
            return -1;
        }
        v->capacity+=1;
    }

    //Desplazo el puntero hasta la posicion de insercion
    while(*ptr_start < elem && pos < v->size){
        ptr_start++;
    }

    // desplazo los elementos a la derecha
    while(ptr_end > ptr_start){
        *ptr_end = *(ptr_end - 1);
        ptr_end-=1;
    }

    //Inserto y aumento el tamaño
    * ptr_start = elem;
    v->size+=1;

    return 0;
}

/**
* Esta funcion valida si el TDA Vector esta vacio.
* @param v es un puntero al TDA Vector se va a validar.
* @return 1 si el vector es vacio y 0 si tiene elementos.
*/
int isEmptyVector(Vector * v){
    return (v->size == 0) ? 1: 0;
}

/**
* Esta función valida si el TDA Vector esta lleno, es decir si el tamaño es igual a la capacidad.
* @param v es un puntero al TDA Vector se va a validar.
* @return 1 si el vector es lleno y 0 si tiene el vector no esta lleno.
*/
int isFullVector(Vector * v){
    return (v->size == v->capacity) ? 1 : 0;
}

/**
* Esta función devuelve la direccion de memoria del elemento que se encuentra en la posicion index.
* @param v es el TDA Vector donde se va a buscar el elemento.
* @param index es la psoicion del elemento a obtener.
* @return devuelve la direccion de memoria del elemento o devuelve NULL si el index es incorrecto.
*/
int * getElement(Vector * v, int index){
    if(index < 0 || index > v->size){
        return NULL;
    }

    int * ptr_v = v->data;
    ptr_v += index;

    return ptr_v;
}

/**
* Esta función se encarga de eliminar el elemento que se encuentra en la posicion indicada.
* @param v es el TDA Vector donde se va a eliminar el elemento.
* @param index es la posicion del elemento que se va a eliminar.
* @return 1 si el elemento fue elimnado 0 si el elemento a eliminar no fue encontrado.
*/
int removeElement(Vector * v, int index){

    if(index < 0 || index > v->size){
        return 0;
    }

    int * ptr = v->data + index;
    int * ptr_end = v->data + v->size;

    while(ptr < ptr_end){
        *ptr = *(ptr + 1);
        ptr++;
    }

    v->size -= 1;
    return 1;

}


/**
* Esta función se encarga de imprimir todos los elementos del TDA Vector.
* @param v es el TDA Vector que se va a mostrar.
*/
void printVector(Vector * v){
    int * ptr = v->data;

    for(int i = 0; i < v->size; i++){
        printf("\n%d", *ptr);
        ptr += 1;
    }
}

/**
* Esta función se encarga de destruir el TDA Vector. (Libera memoria dinamica)
* @param v es el TDA Vector que se va a destruir.
*/
void destroyVector(Vector * v){
    if(v->data != NULL){
        free(v->data);
        v->data = NULL;
    }
    v->size = 0;
    v->capacity = 0;
}


