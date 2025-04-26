#include "pila.h"

/**
* Esta función crea una pila.
* @param
*/
void crearPila(tPila * pila)
{
    *pila = NULL;
}

/**
* Esta función valida si una pila esta vacia.
* @param pila - Puntero a la pila que se va a validar.
* @return int - 1 si la pila esta vacia. 0 si la pila NO esta vacia
*/
int pilaVacia(const tPila * pila)
{
    return *pila == NULL;
}

/**
* Esta función agrega elementos a una pila.
* Algoritmo:
* 1. Primero reserva memoria dinámica para el tNodo.
* 2. Reserva memoria dinámica para el dato.
* 3. Copia al nodoNuevo, el dato enviado por parametro y asignar el tamDato al nuevoNodo.
* 4. Cambia a donde a punta cada nodo:
*   4.1 El nuevo nodo debe apuntar a la direccion de la pila.
*   4.2 La pila ahora debe apuntar al nuevo nodo agregado.
*
* @param pila - Puntero a la pila, donde se agrega el dato.
* @param dato - void * del dato que se va almacenar en la pila.
* @param tamDato - tamaño del dato que se va almacenar.
* @return int - 1 si es el dato fue almacenado en la pila. 0 si no fue posible.
*/
int ponerEnPila(tPila *pila, void * dato, unsigned tamDato)
{
    tNodo * nodoNuevo = (tNodo *)malloc(sizeof(tNodo));
    if(!nodoNuevo) return 0; /// NO hay memoria

    nodoNuevo->info = malloc(tamDato);
    if(!nodoNuevo){
        free(nodoNuevo);
        return 0;
    }

    memcpy(nodoNuevo->info, dato, tamDato);
    nodoNuevo->tamDato = tamDato;

    nodoNuevo->sig = *pila;

    *pila = nodoNuevo;

    return 1;

}

/**
* Esta función saca un elemento de una pila dinámica.
* Algoritmo:
* 1. Valido que la pila no este vacia.
* 2. Copia en dato, lo que esta en la pila.
* 3. Hago un auxiliar (elim) que guarde la direccion del elemento a eliminar (pila).
* 4. Cambio a donde apunta cada nodo:
*   4.1 Pila ahora apunta al siguiente tNodo de pila (tpila->sig)
* 5. Libero memoria del elemento "elim". (Liberar memoria del dato y luego de tNodo).
*
* Aclaración: Para que sea mas facil el manejo de punteros, la variable auxiliar (elim), se podria crear arriba.
*
* @param pila - puntero a pila donde se va a sacar el elemento.
* @param dato - buffer de memoria donde se va a copiar el elemento de la pila.
* @param tamDato - tamaño del dato que se va a obtener.
* @return int - 1 si el elemento fue sacado de la pila. 0 si elemento no fue sacado.
*/
int sacarPila(tPila * pila, void * dato, unsigned tamDato)
{

    if(*pila == NULL) return 0;

    memcpy(dato, (*pila)->info, MIN(tamDato, (*pila)->tamDato));

    tNodo * elim = *pila;

    *pila = (*pila)->sig;

    free(elim->info);
    free(elim);

    return 1;
}

/**
* Esta función indica si una pila esta llena.
* Dado que en memoria dinámica la determinacion de si hay memoria, es momentánea.
* Se mantiene la primitiva, para no romper ninguna implementación.
*/
int pilaLlena(const tPila * pila, unsigned tamBytes)
{
    return 0;
}

/**
* Esta función nos copia el tope de la pila en un buffer enviado por parametro.
* Algoritmo:
* 1. Valido si la pila esta vacia.
* 2. Copio la info de pila, en el buffer dato.
*
* @param pila - puntero a la pila donde se va obtener el tope.
* @param dato - buffer de memoria, donde se copia el tope.
* @param tamDato - tamaño del dato que se va a copiar.
* @return int - 1 si el tope fue cargado. 0 Si el tope no fue cargado.
*/
int verTope(const tPila * pila, void * dato, unsigned tamDato)
{
    if(*pila == NULL) return 0;

    memcpy(dato, (*pila)->info, MIN(tamDato, (*pila)->tamDato) );
    return 1;
}

/**
* Esta función vacia una pila.
* Algoritmo: Es una función recursiva, su caso base es cuando la pila esta vacia.
* 1. Validamos el caso base.
* 2. Creamos un auxiliar de *pila.
* 3. Pila ahora es igual al nodo siguiente de auxiliar.
* 4. free al dato del auxiliar y al auxiliar.
* 5. volvemos a llamar a la función.
*
* Aclaracion: Tal vez la recursión no es la mejor solucion, dado que si la pila es muy grande.
* se guarda cada llamada a la funcion vaciarPila y se llena el stack
* se puede modificar por un while.
* @param
*/
void vaciarPila(tPila * pila)
{
   if(*pila == NULL) return;

   tNodo * elim = *pila;

   *pila = elim->sig;

   free(elim->info);
   free(elim);

   vaciarPila(pila);
}
