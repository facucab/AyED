#include "sum.h"


/**
* Esta función suma dos numeros con pila y los devuelve en un archivo.
* El algortimo consiste en depositar los dos numeros en dos pilas distintas (quedan en orden inversos) y luego sumar en una tercera pila.
*/
int sumarNum(const char * num1, const char * num2)
{

    tPila numPila1;
    tPila numPila2;

    if(!strlen(num1)|| !strlen(num2)) return NUM_VACIO;

    // CREO DOS PILAS PARA CADA NUMERO:
    crearPila(&numPila1);
    crearPila(&numPila2);
    cargarNumEnPila(&numPila1, num1);
    cargarNumEnPila(&numPila2, num2);

    // SUMO ambas pilas:
    tPila resultado;
    crearPila(&resultado);

    if(!sumarPilas(&numPila1, &numPila2, &resultado)) return ERR_PILA_RES;

    // muestro resultado:

    //mostrarResultado(&resultado);
    cargarResultado(&resultado);
    return 1;
}

/**
* Esta fución suma los valores de dos pilas en una tercera pila.
* @param num1 - puntero a la primer pila a sumar.
* @param num2 - puntero a la segunda pila a sumar.
* @param res  - puntero a la pila donde se almacena el resultado.
* @return int - 1 si se sumaron las pilas. 0 si fallo
*/
int sumarPilas(tPila * num1, tPila * num2, tPila * res)
{
    short num_1 = 0;
    short num_2 = 0;
    short acarreo = 0;

    while(!pilaVacia(num1) || !pilaVacia(num2) || acarreo != 0)
    {
        if( !sacarDePila(num1, &num_1, sizeof(num_1)) ) num_1 = 0;

        if( !sacarDePila(num2, &num_2, sizeof(num_2)) ) num_2 = 0;

        short num_res = (num_1 + num_2 + acarreo) % 10;
        acarreo = (num_1 + num_2 + acarreo) / 10;


        if( !ponerEnPila(res, &num_res, sizeof(num_res)) ) return 0;

    }

    return 1;
}

/**
* Esta función recursiva agregar un cadena de digitos numericos a una pila.
* @param pila - puntero a la pila donde se vana guardar los numeros.
* @param numeros - cadena de digitos que se van a almacenar.
*/
void cargarNumEnPila(tPila * pila, const char * numeros)
{
    if(*numeros == '\0') return;

    short digito = *numeros - '0';
    ponerEnPila(pila, &digito, sizeof(digito));

    cargarNumEnPila(pila, numeros+ 1);
}

/**
* Función recursiva que muestra los elementos de una pila (es destructiva)
*  @param num1 - puntero a la pila que se va a mostrar.
*/
void mostrarResultado(tPila * num1)
{
    short v;

    if(pilaVacia(num1)) return;

    if(sacarDePila(num1, &v, sizeof(v)))
    {
        printf("%hd", v);
    }
    mostrarResultado(num1);
}

/**
* Lee un numero desde un archivo y lo copia en una cadena.
* @param nombre - nombre del archivo.
* @param cadena - cadena donde se va a copiar el numero.
* @param tamCadena - tamaño de la cadena.
* @return int - 1 si el archivo fue creado. 0 si hubo algun error.
*/
int leerNumeroArch(const char * nombre, char * cadena, unsigned tamCadena)
{
    FILE * arch = fopen(nombre, "rt");
    if(!arch)
    {
        printf("ERROR EN LA APERTURA DE ARCHIVO \n");
        return 0;
    }

    if(!fgets(cadena, tamCadena, arch))
    {
        printf("ERROR ARCHIVO");
        return 0;
    }

    fclose(arch);
    return 1;
}


/**
* Crear un archivo de prueba con el numero enviado.
* @param nombre - nombre del archivo.
* @param numero - numero a grabar en el archivo.
* @return int - 1 si el archivo fue creado. 0 si hubo algun error.
*/
int crearArchNum(const char * nombre, char * numero)
{
    FILE * arch = fopen(nombre, "wt");
    if(!arch)
    {
        printf("ERROR EN LA CREACION DE ARCHIVO");
        return 0;
    }

    fprintf(arch, "%s", numero);
    fclose(arch);

    return 1;
}

/**
*
*/
int cargarResultado(tPila * pila)
{
    short valor;
    FILE * arch = fopen("resultado.txt", "wt");
    if(!arch)
    {
        printf("ERROR EN ARCHIVO DE RESPUESTA");
        return 0;
    }


    while(!pilaVacia(pila))
    {
        if(sacarDePila(pila, &valor, sizeof(valor)))
        {
            fprintf(arch, "%hd", valor);
        }
    }

    fclose(arch);
    return 1;
}
