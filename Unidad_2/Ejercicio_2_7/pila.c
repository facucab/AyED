#include "pila.h"

/**
* Esta función crea la pila.
* @param pila - puntero a la pila a crear
*/
void crearPila(tPila * pila)
{
    pila->tope = CANT_MAX;
}

/**
* Esta función verifica si la pila esta llena o no.
* @param pila - puntero a la pila que se va a validar.
* @return int - 1 si esta llena. 0 si no esta llena.
*/
int pilaLlena(const tPila * pila)
{
    return pila->tope == 0;
}

/**
* Esta función agrega un nuevo elemento a la pila.
* @param pila - puntero de la pila donde se va agregar el elemento.
* @param dato - dirección del dato que se va agregar.
* @param tamDato - cantidad de bytes del dato que se va agregar.
* @return int - 1 si se pudo agregar el elemento. 0 si el elemento no fue posible agregarse.
*/
int ponerEnPila(tPila * pila, const void * dato, unsigned tamDato)
{
    if(pila->tope == 0)
    {
        return 0;
    }

    void * nuevo = malloc(tamDato);
    if(!nuevo)
    {
        puts("No hay memoria");
        return 0;
    }
    memcpy(nuevo, dato, tamDato);

    pila->tope -= 1;
    *(pila->datos + pila->tope) = nuevo;
    return 1;
}

/**
* Esta función devuelve el tope de una pila (NO REMUEVE)
* @param pila - puntero a la pila donde se busca el tope.
* @param dato - Dirección de memoria donde se va a copiar el tope.
* @param tamDato - tamaño del dato a recuperar.
* @return int - 1 si se recupero el tope y 0 si no se pudo recuperar el tope.
*/
int verTope(const tPila * pila, void * dato, unsigned tamDato)
{
    if(pila->tope == CANT_MAX)
    {
        puts("Pila vacia");
        return 0;
    }

    void * ptrTope = *(pila->datos + pila->tope);

    memcpy(dato, ptrTope, tamDato);
    return 1;
}


/**
* Esta función saca el tope de la pila.
* @param pila - puntero a la pila donde se va a obtener el topper.
* @param dato - dirección donde se va a copiar el tope.
* @param tamDato - tamaño del dato.
* @return int - 1 si se saco el tope de la pila. 0 si no fue posible.
*/
int sacarDePila(tPila * pila, void * dato, unsigned tamDato)
{
    if(pila->tope == CANT_MAX)
    {
        return 0;
    }

    void **ptrTope = pila->datos+ pila->tope;
    void * datoPila = *ptrTope ;

    memcpy(dato, datoPila, tamDato);

    free(datoPila);
    pila->tope+=1;
    return 1;
}

/**
* Esta función valida si la pila esta vacia.
* @param pila - puntero a la pila que se va a validar si esta vacia.
* @return int - 1 si la pila esta vacia. 0 si la pila NO esta vacia.
*/
int pilaVacia(const tPila * pila)
{
    return pila->tope == CANT_MAX;
}

/**
* Esta funcíon se encarga de vaciar la pila.
* Libera la memoria dinamica de cada elemento.
* @param pila - puntero a la pila que se va a vaciar.
*/
void vaciarPila(tPila * pila)
{
    void **ptr = pila->datos + pila->tope;

    while(ptr < pila->datos + CANT_MAX)
    {
        free(*ptr);
        ptr++;
    }

    pila->tope = CANT_MAX;
}
