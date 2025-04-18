#include "pila.h"

/**
* Esta función crear la pila.
* @param pila - puntero a la pila a crear.
*/
void crearPila(tpila * pila)
{
    pila->tope = TAM_PILA;
}

/**
* Valida si hay espacio en la pila para ingresar un nuevo elemento.
* si el tope es menor a la cantidad de bytes + el tamaño, significa que la pila esta llena.
* @param pila - puntero a la pila que se va a validar.
* @param cantBytes - cantidad de bytes que se quieren validar si entra en la pila.
* @return 1 si la pila esta llena. 0 si la pila no esta llena.
*/
int pilaLlena(const tpila* pila, unsigned cantBytes)
{
    return pila->tope < cantBytes + sizeof(unsigned);
}

/**
* Esta función se encarga de poner un elemento dentro de una pila.
* Si la pila esta llena, no ingresa el elemento.
* @param pila - Puntero a la pila que se ingresa el elemento.
* @param dato - dirección del dato a ingresar.
* @param tamDato - cantidad de bytes que pesa el dato a ingresar.
* @return 1 si el elemento se agrego a la pila. 0 si el elemento no se pudo agregar.
*/
int ponerEnPila(tpila * pila, void * dato, unsigned tamDato)
{
    if(pila->tope < tamDato + sizeof(unsigned))
    {
        puts("Pila Llena");  // deberia ser un logger.
        return 0;
    }

    pila->tope -= tamDato;
    memcpy(pila->pila + pila->tope, dato, tamDato);

    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila + pila->tope, &tamDato, sizeof(unsigned));

    return 1;
}

/**
* Esta función devuelve el tope de una pila.
* La macro MIN es por cuestiones de seguridad, dado que recuperar el minimo entre el
* tamDato que envia el usuario y el tam que se recupera.
* Si la pila esta vacia, no se puede ver ningun tope.
* @param pila - puntero a la pila donde se busca el tope.
* @param dato - Dirección de memoria donde se va a copiar el tope.
* @param tamDato - tamaño del dato a recuperar.
* @return int - 1 si se recupero el tope y 0 si no se pudo recuperar el tope.
*/
int verTope(const tpila * pila, void * dato, unsigned tamDato)
{
    unsigned tamInfo;

    if(pila->tope == TAM_PILA)
    {
        puts("Pila vacia");
        return 0;
    }

    memcpy(&tamInfo, pila->pila + pila->tope, sizeof(unsigned)); //Recupero el tamInfo

    memcpy(dato, pila->pila + pila->tope + sizeof(unsigned), MIN(tamInfo,tamDato));
    return 1;

}

/**
* Esta función valida si la pila esta vacia.
* @param pila- puntero a la pila donde vamos a validar si la pila esta vacia.
* @return int - 1 si la pila esta vacia y 0 si la pila NO esta vacia.
*/
int pilaVacia(const tpila * pila)
{
    return pila->tope == TAM_PILA;
}

/**
* Esta función saca el dato que esta en el tope de la pila.
* @param pila - puntero a pila que se va a sacar elemento.
* @param dato - dirección de memoria donde se va a copiar el elemento, que se saca.
* @param tamDato - cantidad de bytes que se quiero obtener.
* @return int - 1 si se pudo obtener/remover el elemento y 0 si la pila estaba vacia.
*/
int sacarDePila(tpila *pila, void * dato, unsigned tamDato)
{
    unsigned tamInfo;

    if(pila->tope == TAM_PILA)
    {
        puts("Pila vacia");
        return 0;
    }

    memcpy(&tamInfo, pila->pila + pila->tope, sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    memcpy(dato, pila->pila + pila->tope, MIN(tamInfo, tamDato));

    pila->tope += tamDato;

    return 1;
}

/**
* Esta función se encarga de vaciar la pila.
* Reinicia el tope al tamaño maximo.
* @param pila - puntero a la pila a vaciar.
*/
void vaciarPila(tpila * pila)
{
    pila->tope = TAM_PILA;
}
