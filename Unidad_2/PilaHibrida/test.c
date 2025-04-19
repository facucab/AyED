#include "test.h"

/**
* Esta función crea el un archivo con un lote de datos, para pruebas.
* @param nombre - nombre del archivo.
* @return int - 1 si el archivo se creo. 0 si el archivo no fue creado
*/
int crearArchivoPrueba(const char * nombre)
{
    FILE * arch = fopen(nombre, "wb");
    if(!arch) return 0;

    tAlumno alumnos[] = {
        {100, "Lionel"},
        {200, "Rodrigo"},
        {300, "Zoe"},
        {400, "Ana"},
        {500, "Juan"}
    };

    fwrite(alumnos, sizeof(alumnos[0]), sizeof(alumnos) / sizeof(alumnos[0]), arch);
    fclose(arch);
    return 1;
}

/**
* Esta funcion carga los datos de un archivo binario y los carga en una pila.
* El archivo usa la estructura tAlumno.
* @param pila - puntero a la pila donde se van a cargar los datos.
* @param nombreArch - nombre del archivo.
* @return int - 1 si la pila pudo ser cargada. 0 si la pila no fue cargada
*/
int cargaDeDatosPila_TEST(tPila * pila, const char * nombreArch)
{
    FILE * arch = fopen(nombreArch, "rb");
    if(!arch) return 0;

    tAlumno tAlumnoAux;

    while(fread(&tAlumnoAux, sizeof(tAlumnoAux), 1, arch))
    {
        ponerEnPila(pila, &tAlumnoAux, sizeof(tAlumnoAux));
    }

    fclose(arch);

    return 1;
}
