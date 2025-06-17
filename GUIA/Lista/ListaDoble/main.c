#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int compararInt(void * a, void * b);
void mostrarInt(void * a);

int main()
{
    tLista lista;
    crearLista(&lista);

    int datos [] = {10,3,5,12,6};

    for(int i = 0; i < sizeof(datos) / sizeof(datos[0]); i++)
    {
        insertarOrdenado(&lista, &datos[i], sizeof(datos[0]), compararInt);
    }

    printf("LISTA DESDE EL INICIO: \n");
    mostraListaDesdeInicio(&lista, mostrarInt);

    int clave = 5;
    eliminarPorClave(&lista, &clave, compararInt);

    printf("LISTA DESDE EL FIN: \n");
    mostraListaDesdeFin(&lista, mostrarInt);


    return 0;
}

int compararInt(void * a, void * b)
{
    int valor_a = *((int *)a);
    int valor_b = *((int *)b);

    return valor_a - valor_b;
}

void mostrarInt(void * a)
{
    int valor = *((int*)a);
    printf("%d\n", valor);
}
