#include "Funciones.h"

/**
* Esta función recursiva calcula el factorial de un numero.
* @param n es numero que se va a calcular el factorial.
* @return int que es el factorial calculado.
*/
int factorial(int n){
    //CASOS BASE:
    if(n == 0 || n == 1){
        return 1;
    }

    return n * factorial(n -1);
}

/**
* Esta es una funcion recursiva que muestra por pantalla la cadena original
* y luego cada una de sus versiones sin el primer carácter
* Por ejemplo, para "Hola", imprimirá:
*
* Hola
* ola
* la
* a
* @param cadena Un puntero a la cadena de caracteres que se desea mostrar
*/
void mostrarCadena(char * cadena){
    //Caso base:
    if(*cadena == '\0') return;
    printf("\n%s", cadena);

    mostrarCadena(cadena+1);
}

/**
* Dada una cadena como "Hola", imprime:
* a
* la
* ola
* Hola
* @param cadena Un puntero al primer carácter de la cadena
*/
void mostrarCadenaInvertido(char *cadena) {
    if (*cadena == '\0') return;

    mostrarCadenaInvertido(cadena + 1);
    printf("%s\n", cadena);
}

/**
* Envoltorio de la siguiente funcion
*/
void mostrarCadenaLetraAletra(char * cadena){
   _mostrarCadenaLetraAletra(cadena, 0);
}

/**
* Dada una cadena como "Hola", imprime:
* H
* Ho
* Hol
* Hola
* @param cadena Un puntero al primer carácter de la cadena
*/
void _mostrarCadenaLetraAletra(char * cadena, int n){
     if( *(cadena + n) == '\0'){
        return;
    }
    printf("\n%.*s", n+1, cadena);
    _mostrarCadenaLetraAletra(cadena, n + 1);
}

/**
* Dada una cadena como "Hola", imprime:
* Hola
* Hol
* Ho
* H
* @param cadena Un puntero al primer carácter de la cadena
* Luego de utilizar esta funcion, la cadena ya no sirve.
*/
void mostrarCadenaLetraAletraInverso(char * cadena){
    if(strlen(cadena) == 1){
        printf("\n%s", cadena);
        return;
    }

    printf("\n%s", cadena);
    *(cadena + strlen(cadena) - 1) = '\0';
    mostrarCadenaLetraAletraInverso(cadena);

}


/**
* Descompene un numero, dado el numero 123:
* 3
* 2
* 1
* @param numero int que se va a descomponer
*/
void descomponerEntero(int numero){
    if(numero == 0){
        return;
    }

    printf("\n%d", numero%10);
    numero = numero/10;
    descomponerEntero(numero);
}

/**
* Descompene un numero, dado el numero 123:
* 1
* 2
* 3
* @param numero int que se va a descomponer
*/
void descomponerEnteroInverso(int num) {
    if (num < 10) {
        printf("\n%d", num);
        return;
    }

    descomponerEnteroInverso(num / 10);
    printf("\n%d", num % 10);
}
