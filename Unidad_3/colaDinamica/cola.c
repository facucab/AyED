#include "cola.h"

/**
* Esta función crea la cola.
* @param cola - puntero a la cola.
*/
void crearCola(tCola * cola)
{
    cola->pri = NULL;
    cola->ult = NULL;
}

/**
* Esta funcion valida si la cola esta vacia.
* @param cola - puntero a la cola que se valida.
* @return int - 1 si la cola esta vacia. 0 Si la cola no esta vacia.
*/
int colaVacia(const tCola * cola)
{
    return cola->pri == NULL && cola->ult == NULL;
}

/**
* Esta función valida si la cola esta llena.
*/
int colaLlena(const tCola * cola, unsigned tamDato)
{
    return 0;
}

/**
* Esta función agrega un elemento a la cola.
* Algoritmo:
* 1.Creo un nuevo tNodo asignadole memoria y luego le asigno memoria al dato de ese tNodo.
* 2.en el nuevo Nodo copio la informacion de dato.
* 3.1 Si el primer elemento de la cola es nulo:
*   3.1.1 el primer elemento va a ser el nuevo nodo.
* 3.2 Si el primer elemento de la cola es NO nulo:
*   3.2.1 el ultimo tNodo de la cola, va apuntar al nuevo nodo.
* 4.Asignamos que el nuevo tNodo sea el ultimo elemento de la cola.
*
* @param cola - puntero a la cola donde se va agregar el elemento.
* @param dato - dato que se va agregar a la cola.
* @param tamDato - cantidad de bytes que se van a guardar en la cola.
* @return int - 1 si el elemento se agrego a la cola. 0 si el elemento no se agrego a la cola.
*/
int ponerEnCola(tCola * cola, void * dato, unsigned tamDato)
{
    tNodo * nuevoNodo = (tNodo *)malloc(sizeof(tNodo));
    if(!nuevoNodo) return 0;

    nuevoNodo->info = malloc(tamDato);
    if(!nuevoNodo->info)
    {
        free(nuevoNodo);
        return 0;
    }

    memcpy(nuevoNodo->info, dato, tamDato);
    nuevoNodo->tamDato = tamDato;
    nuevoNodo->sig = NULL;

    if(cola->pri == NULL) cola->pri = nuevoNodo;
    else cola->ult->sig = nuevoNodo;

    cola->ult = nuevoNodo;

    return 1;
}

/**
* Esta función obtiene el primer elemento de una cola.
* Algoritmo:
* 1. valido si la cola no esta vacia.
* 2. copio la info del primer tNodo en el buffer Dato.
*
* @param cola - puntero a la cola donde se va obtener el primer elemento.
* @param dato - buffer donde se va a copiar el dato.
* @param tamDato - tamaño del buffer.
* @return int - 1 si el primer elemento fue cargado. 0 si la cola no tiene elementos.
*/
int verPrimero(const tCola * cola, void * dato, unsigned tamDato)
{
    if(cola->pri == NULL && cola->ult == NULL) return 0;

    memcpy(dato, cola->pri->info, MIN(cola->pri->tamDato, tamDato));

    return 1;
}

/**
* Esta función saca el primer elemento de una cola.
* Algoritmo:
* 1. Validar que la cola no este vacia.
* 2. creo un auxiliar de tNodo que contenga la direccion del primer nodo.
* 3. Copio la información del auxiliar en el buffer.
* 4. el primer elemento de la cola, apunta al siguiente elemento del auxiliar.
* 5. Si ahora el primer elemento de la cola es NULL (la cola quedo vacia)
* el ultimo elemento debe ser nulo
* 6. libero memoria del auxiliar.
*
* @param cola - puntero a la cola que se va a scar el elemento.
* @param dato - buffer donde se va a copiar el elemento.
* @param tamDato - tamaño del buffer
*@return int - 1 si el elemento fue sacado de la cola. 0 si no se saco nada
*/
int sacarDeCola(tCola * cola, void * dato, unsigned tamDato)
{
    if(cola->pri == NULL && cola->ult == NULL) return 0;

    tNodo * elim = cola->pri;

    memcpy(dato, elim->info, MIN(tamDato, elim->tamDato));

    cola->pri = elim->sig;

    if(cola->pri == NULL) cola->ult = NULL;

    free(elim->info);
    free(elim);

    return 1;
}

/**
* Etsa función vacia una cola.
* Algoritmo: Mientras que la cola no este vacia:
* 1. Creo una variable auxiliar para almacenar el primer elemento de la cola.
* 2. El primer elemento de la pila apunta al siguiente elemento de auxiliar.
* 3. Si ahora el primer elemento de la pila es NULL, el ultima tambien debe ser NULL.
* 4. Liberar memoria
*
* @param cola - puntero a la cola que se vaciar
*/
void vaciarCola(tCola * cola)
{
    while(cola->pri && cola->ult)
    {
        tNodo * elim = cola->pri;
        cola->pri = elim->sig;

        if(!cola->pri) cola->ult = NULL;

        free(elim->info);
        free(elim);
    }
}

