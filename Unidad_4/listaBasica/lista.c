#include "lista.h"

void crearLista(tLista * lista)
{
    *lista = NULL;
}

/**
*
*/
int listaVacia(const tLista * lista)
{
    return *lista == NULL;
}


/**
*
*/
int listaLlena(const tLista * lista, unsigned tamDato)
{
    return 0;
}


/**
* Algoritmo:
*
* 1. Creo el nuevo nodo a agregar y le copio la información.
* SI LA LISTA TIENE ELEMENTOS:
* 1. siguiente del nuevo nodo debe ser igual a lista.
* 2. la lista ahora deber ser nuevoNodo.
* SI LA LISTA NO TIENE ELEMENTOS:
* 1. La lista ahora debe ser nuevoNodo.
*
*
*/
int agregarPrimeroLista(tLista * lista, const void * dato, unsigned tamDato)
{
    tNodo * nue = (tNodo *)malloc(sizeof(tNodo));

    if(nue == NULL || (nue->dato = malloc(tamDato)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato, dato, tamDato);
    nue->tamDato = tamDato;
    nue->sig = NULL;

    //Lista tiene elementos.
    if(*lista != NULL)
    {
        nue->sig = *lista;
    }

    *lista = nue;
    return 1;

}


/**
*
*/
void mapLista(tLista * lista, void(*accion)(void*dato))
{
    tNodo * aux = *lista;

    while(aux != NULL)
    {
        accion(aux->dato);

        aux = aux->sig;
    }
}

void mostraAlumno(void * dato)
{
    tPersona *per = (tPersona *) dato;


    printf("%d\t%s\n", per->dni, per->nombre);

}

void normPersona(void * dato)
{
    tPersona *per = (tPersona *) dato;
    normalizarNombre(per->nombre);
}




/// YO NO LA DESARROLLE, ES DE PRUEBA

void normalizarNombre(char *nombre) {
    int i = 0;
    int capitalizar = 1;

    while (nombre[i]) {
        if (isspace(nombre[i])) {
            capitalizar = 1;
        } else {
            nombre[i] = capitalizar ? toupper(nombre[i]) : tolower(nombre[i]);
            capitalizar = 0;
        }
        i++;
    }
}
