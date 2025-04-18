/*
Diseñe e implemente un programa que cargue un TDA Vector a partir del contenido de un archivo de
texto cuyo formato es el siguiente:
3
23
13
18
En donde la primera línea del archivo contiene un número que corresponde a la cantidad de registros
que contiene el archivo. Para el ejemplo anterior, el archivo va a contener 3 (tres) números; y esos
números van a ser 23, 13 y 18.
Contemple los casos frontera.
Defina y prepare el entorno para que se puedan probar las funcionalidades solicitadas.

*/

#include <stdio.h>
#include <stdlib.h>
#include "TDAVector.h"
int crearArchivo(char * name);
int main(int argc, char * argv[])
{
    //Creo archivo de prueba:
    crearArchivo(argv[1]);

    Vector vec;
    createVector(&vec, 1);

    cargarTDAconArch(&vec, argv[1]);

    printVector(&vec);
    destroyVector(&vec);
}


/**
*
*/
int crearArchivo(char * name)
{
    FILE * f = fopen(name, "wt");
    if(f == NULL)
    {
        printf("ERROR AL CREAR EL ARCHIVO");
        return -1;
    }
    fprintf(f, "3\n");
    fprintf(f, "23\n");
    fprintf(f, "13\n");
    fprintf(f, "18\n");
    fclose(f);
    return 0;
}
