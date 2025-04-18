#include "cola.h"

void crearCola(tCola * cola)
{
    cola->pri = 0;
    cola->ult = 0;
    cola->tamDisp = TAM_COLA;
}

int colaVacia(const tCola * cola)
{
    return cola->tamDisp == TAM_COLA;
}

int colaLlena(const tCola * cola, unsigned tamDato)
{
    return cola->tamDisp < tamDato;
}

void vaciarCola(tCola * cola)
{
    cola->pri = cola->ult;
    cola->tamDisp = TAM_COLA;
}

int ponerEnCola(tCola * cola, const void * dato, unsigned tamDato)
{
    if(cola->tamDisp < tamDato + sizeof(unsigned)) return 0;

    //Acutalizo el tamaño de la cola:
    cola->tamDisp -= tamDato + sizeof(unsigned);

    /// COPIAR TAMDATO
    //valido si el dato entra entero o partido
    ini = MIN(sizeof(unsigned), TAM_COLA - cola->ult); /// quiero saber la cant de bytes que entra al final del vector.

    //si ini es != 0 -> tengo que copiar algo.

    if(ini != 0){
        memcpy(cola->cola + cola->ult, &tamDato, ini); //Guardo el tam del dato.
    }
    fin = sizeof(unsigned) - ini;  // si fin da cero, es que se copio todod

    if(fin != 0){
        memcpy(cola->cola, (char*)&tamDato + ini, fin);
    }

    cola->ult = (fin != 0) ?  fin : cola->ult + ini;

    ///COPIAR EL DATO:
    ini = MIN(tamDato, TAM_COLA-cola->ult);
    if(ini != 0){
        memcpy(cola->cola + cola->ult, dato, ini);
    }
    fin = tamDato - ini;

    if(fin != 0){
        memcpy(cola->cola, (char*)dato + ini, fin);
    }

    cola->ult = fin ? fin : cola->ult + ini;
}
