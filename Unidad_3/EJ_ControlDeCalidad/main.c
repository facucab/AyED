#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "Funciones.h"
#define CREAR_LOTE 1
#define ENTRADA "entradas.txt"
int main(int argc, char * argv[])
{
    /// CREAR LOTE DE PRUEBA:
    if(CREAR_LOTE) crearLote(ENTRADA);


    menu(ENTRADA);



    return 0;
}
