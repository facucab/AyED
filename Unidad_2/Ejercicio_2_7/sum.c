#include "sum.h"

/**
*
*/
int sumarNum(const char * num1, const char * num2)
{

    tPila numPila1;
    tPila numPila2;

    if(!strlen(num1)|| !strlen(num2)) return NUM_VACIO;

    // CREO DOS PILAS PARA CADA NUMERO:
    crearPila(&numPila1);
    crearPila(&numPila2);
    cargarNumEnPila(&numPila1, num1);
    cargarNumEnPila(&numPila2, num2);

    // SUMO ambas pilas:
    tPila resultado;
    crearPila(&resultado);

    if(!sumarPilas(&numPila1, &numPila2, &resultado)) return ERR_PILA_RES;

    // muestro resultado:
    mostrarResultado(&resultado);
    return 1;
}

/**
* Esta fución suma los valores de dos pilas en una tercera pila.
* @param num1 - puntero a la primer pila a sumar.
* @param num2 - puntero a la segunda pila a sumar.
* @param res  - puntero a la pila donde se almacena el resultado.
* @return int - 1 si se sumaron las pilas. 0 si fallo
*/
int sumarPilas(tPila * num1, tPila * num2, tPila * res)
{
    short num_1 = 0;
    short num_2 = 0;
    short acarreo = 0;

    while(!pilaVacia(num1) || !pilaVacia(num2) || acarreo != 0)
    {
        if( !sacarDePila(num1, &num_1, sizeof(num_1)) ) num_1 = 0;

        if( !sacarDePila(num2, &num_2, sizeof(num_2)) ) num_2 = 0;

        short num_res = (num_1 + num_2 + acarreo) % 10;
        acarreo = (num_1 + num_2 + acarreo) / 10;


        if( !ponerEnPila(res, &num_res, sizeof(num_res)) ) return 0;

    }

    return 1;
}

/**
* Esta función recursiva agregar un cadena de digitos numericos a una pila.
* @param pila - puntero a la pila donde se vana guardar los numeros.
* @param numeros - cadena de digitos que se van a almacenar.
*/
void cargarNumEnPila(tPila * pila, const char * numeros)
{
    if(*numeros == '\0') return;

    short digito = *numeros - '0';
    ponerEnPila(pila, &digito, sizeof(digito));

    cargarNumEnPila(pila, numeros+ 1);
}

/**
* Función recursiva que muestra los elementos de una pila (es destructiva)
*  @param num1 - puntero a la pila que se va a mostrar.
*/
void mostrarResultado(tPila * num1)
{
    short v;

    if(pilaVacia(num1)) return;

    if(sacarDePila(num1, &v, sizeof(v)))
    {
        printf("%hd", v);
    }
    mostrarResultado(num1);
}
