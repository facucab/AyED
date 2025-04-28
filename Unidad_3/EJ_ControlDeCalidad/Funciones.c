#include "Funciones.h"


/**
* Esta función es la encarga de procesar el archivo de entrada, separando los lotes en observados o aprobados.
* Algoritmo:
* 1. Abrir archivos e inicializar una cola.
* 2. Leer el archivo linea a linea (trozar).
* 3. Evaluamos si se puede obtener el primer valor de la cola:
* 3.1 Si se puede, signfica que no es el primer elemento y se debe:
*   3.1.1 Se debe evaluar si el registro del tope tiene el mis codLote que el registro que se esta leyendo.
*   3.1.2 Si es igual debe agregarlo a la cola, dado que partenecen al mismo Lote.
*   3.1.3 Si NO es igual, se debe grabar la cola en el archivo correspondiente (esto vacia la cola) y agregar el nuevo elemento a la cola (es de lote diferente).
* 3.2 Si no se puede acceder al primer elemento, significa que la cola esta vacia y se debe agregar el registro actual.
* 4. Leer el ultimo lote que quedo registrado en la cola.
* 5. Cerrar archivos.
*
* Aclaracion: Por cada vez que se agrega un elemento a la cola, se debe validar si esta Ok o fallado, cambiar la flag (loteFallado)
* @param nombre - nombre del archivo de entrada.
* @return int - 1 si el archivo fue procesado exitosamente. 0 Si fallo.
* Se puede refactorizar bastante
*/
int controlLotes(const char * nombre)
{

    tCola cola;
    crearCola(&cola);
    char buffer[100];
    tRegistro reg;
    int loteFallado = 0;

    FILE * archivo = fopen(nombre, "rt");
    FILE * apro_arch = fopen("lotesAprobados.txt", "wt");
    FILE * obs_arch = fopen("lotesObservados.txt", "wt");

    if(!archivo) return ERROR_ARCHIVO;
    if(!apro_arch)
    {
        fclose(archivo);
        return ERROR_ARCHIVO;
    }
    if(!obs_arch)
    {
        fclose(archivo);
        fclose(apro_arch);
        return ERROR_ARCHIVO;
    }

    while(fgets(buffer, sizeof(buffer), archivo))
    {

        trozarLinea(buffer, &reg);
        tRegistro primerRegistro;

        if(verPrimero(&cola, &primerRegistro, sizeof(primerRegistro)))
        {

            if(strcmp(primerRegistro.codLote, reg.codLote) == 0)
            {
                if(strcmp(reg.resultadoControl, FALLA) == 0) loteFallado = 1;
                ponerEnCola(&cola, &reg, sizeof(reg));
            }
            else
            {
                if(loteFallado == 1) grabarColaEnArchivo(&cola, obs_arch);
                else grabarColaEnArchivo(&cola, apro_arch);

                // Agrego nuevo Lote a la cola, reinicio flags
                loteFallado = 0;
                if(strcmp(reg.resultadoControl, FALLA) == 0) loteFallado = 1;
                ponerEnCola(&cola, &reg, sizeof(reg));
            }

        }
        else
        {
            if(strcmp(reg.resultadoControl, FALLA) == 0) loteFallado = 1;
            ponerEnCola(&cola, &reg, sizeof(reg));
        }

    }

    if(loteFallado == 1) grabarColaEnArchivo(&cola, obs_arch);
    else grabarColaEnArchivo(&cola, apro_arch);


    fclose(archivo);
    fclose(apro_arch);
    fclose(obs_arch);
    return TODO_OK;
}

/**
* Esta función graba el contenido de una cola, en un archivo.
* @param cola - puntero a la cola que se va a grabar.
* @param archivo - puntero archivo que se va a grabar.
* Aclaracion: No se que tan seguro es compartir punteros FILE. (Consultar)
*/
void grabarColaEnArchivo(tCola * cola, FILE * archivo)
{
    tRegistro tmp;
    while(sacarDeCola(cola, &tmp, sizeof(tmp)))
    {
        fprintf(archivo, "%s,%d,%s\n", tmp.codLote, tmp.idProducto, tmp.resultadoControl);
    }
}


/**
* Esta funcion se encarga de recibir una linea, trozarla y carga la informacion en una estructura de tipo tRegistro
* @param linea - linea que va a ser trozada.
* @param reg - puntero a la estructura donde se almacena la informacion.
*/
void trozarLinea(char * linea, tRegistro * reg)
{
    char * aux = strchr(linea, '\n');
    *aux = '\0';

    aux = strrchr(linea, ',');
    strcpy(reg->resultadoControl, aux+1);
    *aux='\0';

    aux = strrchr(linea,',');
    sscanf(aux+1, "%d", &reg->idProducto);
    *aux = '\0';
    strcpy(reg->codLote, linea);
}

/**
*
*/
void menu(const char * nombre)
{
    int opcion;
    printf("------------------- MENU DE OPCIONES ---------------\n");
    printf("- 1) Procesar archivo de entrada.\n");
    printf("- 2) Mostrar archivo de entrada.\n");
    printf("- 3) Mostrar el contenido de los archivos de salida con un encabezado apropiado para cada uno.\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    if(opcion == 1)
    {
        system("cls");
        if(controlLotes(nombre))
            printf("------------------- El archivo de entrada fue procesado con exito! ---------------\n");
        else
            printf("------------------- Error al procesar archivo de entrada. ---------------\n");

    }
    else if(opcion == 2)
    {
        system("cls");
        printf("------------------- Mostrar archivo de entrada ---------------\n");
        mostrarArchivo(nombre);
    }
    else if(opcion == 3)
    {
        system("cls");
        printf("--------- Lotes Aprobados -------- \n");
        mostrarArchivo("lotesAprobados.txt");
        printf("\n\n--------- Lotes Observados --------\n");
        mostrarArchivo("lotesObservados.txt");
    }
    else
    {
        system("cls");
        printf("------------------- Error al ingresar en menu ---------------\n");
    }
}

/**
*
*/
int mostrarArchivo(const char * nombre)
{
    FILE * archivo = fopen(nombre, "rt");
    if(!archivo) return ERROR_ARCHIVO;

    char buffer[100];

    while(fgets(buffer, sizeof(buffer), archivo))
    {
        tRegistro reg;
        trozarLinea(buffer, &reg);
        printf("%s %d %s\n", reg.codLote, reg.idProducto, reg.resultadoControl);
    }

    fclose(archivo);
    return TODO_OK;
}

/**
* Esta función crear un lote de pruebas.
* @param nombre - nombre del archivo donde se va a crear el lote.
* @return int
*/
int crearLote(const char * nombre)
{
    FILE * archivo = fopen(nombre, "wt");
    if(!archivo) return ERROR_ARCHIVO;

    tRegistro registros[] =
    {
        {"LOT01",1,"OK"},
        {"LOT01",10,"OK"},
        {"LOT01",18,"FALLA"},
        {"LOT02",5,"OK"},
        {"LOT03",100,"FALLA"},
        {"LOT03",500,"OK"},
        {"LOT04",5,"OK"},
        {"LOT04",6,"OK"},
        {"LOT04",7,"OK"},
        {"LOT05",15,"FALLA"}
    };

    for(int i = 0; i < sizeof(registros) / sizeof(registros[0]); i++)
    {
        fprintf(archivo, "%s,%d,%s\n", registros[i].codLote, registros[i].idProducto, registros[i].resultadoControl);
    }

    fclose(archivo);
    return ARCHIVO_CREADO;
}

