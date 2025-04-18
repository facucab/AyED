#ifndef ARCHPRUEBA_H_INCLUDED
#define ARCHPRUEBA_H_INCLUDED
typedef struct {
    int id;
    char[50] nombre;
}Alumno;
typedef struct{
    int legajo;
    float sueldo;
    char[70] observacion;
}Empleado;

int lotePruebaAlu(char * name);
int lotePruebaEmp(char * name);

#endif // ARCHPRUEBA_H_INCLUDED
