#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new()
{
    Employee* this;
    this=(Employee*) malloc(sizeof(Employee));
    return this;
}
Employee* employee_newParametros(int id, char* nombre,int horasTrabajadas, int sueldo)
{
    Employee* this;
    this=employee_new();
    if(this!= NULL)

    {
        this->id= id;
        strcpy(this->nombre, nombre);
        this->horasTrabajadas= horasTrabajadas;
        this->sueldo= sueldo;
    }
    return this;
}

int employee_setId(Employee* this,int id)
{
    int esCorrecto=0;
    if (this!=NULL )
    {
        this->id=id;
        esCorrecto=1;}

    return esCorrecto;
}
int employee_getId(Employee* this,int* id)
{
     int retorno = 0;

    if(this != NULL){
        *id = this->id ;
        retorno = 1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int estado= 0;
    if(this != NULL && nombre != NULL)
        {
            strcpy(this->nombre,nombre);
            estado= 1;
        }
    return estado;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int estado= 0;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        estado= 1;
    }
    return estado;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int esCorrecto=0;
    if (this!=NULL )
    {
        this->horasTrabajadas=horasTrabajadas;
        esCorrecto=1;}

    return esCorrecto;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno= 0;
    if(this != NULL && horasTrabajadas != NULL) {
        *horasTrabajadas= this->horasTrabajadas;
        retorno= 1;
    }
    return retorno;

}
int employee_setSueldo(Employee* this,int sueldo)
{
    int esCorrecto=0;
    if (this!=NULL )
    {
        this->sueldo=sueldo;
        esCorrecto=1;}

    return esCorrecto;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno= 0;
    if(this != NULL && sueldo != NULL){
        *sueldo= this->sueldo;
        retorno= 1;
    }
    return retorno;

}

int Employee_CompareById(void* empleado1, void*empleado2)
{
    int retorno;
    if(((Employee*)empleado1)->id > ((Employee*)empleado2)->id)
    {
        retorno=1;
    }else if(((Employee*)empleado1)->id < ((Employee*)empleado2)->id)
    {
        retorno=-1;
    }else{
    retorno =0;}

    return retorno;
}


int Employee_CompareByNombre(void* empleado1, void*empleado2)
{
    Employee* empleadoA = (Employee*) empleado1;
    Employee* empleadoB = (Employee*) empleado2;
    return stricmp(empleadoA->nombre,empleadoB->nombre);
}
int Employee_CompareByHorasTrabajadas(void* empleado1, void*empleado2)
{
    int retorno;
    if(((Employee*)empleado1)->horasTrabajadas > ((Employee*)empleado2)->horasTrabajadas)
    {
        retorno=1;
    }else if(((Employee*)empleado1)->horasTrabajadas < ((Employee*)empleado2)->horasTrabajadas)
    {
        retorno=-1;
    }else{
    retorno =0;}

    return retorno;
}
int Employee_CompareBySueldo(void* empleado1, void*empleado2)
{
    int retorno;
    if(((Employee*)empleado1)->sueldo > ((Employee*)empleado2)->sueldo)
    {
        retorno=1;
    }else if(((Employee*)empleado1)->sueldo < ((Employee*)empleado2)->sueldo)
    {
        retorno=-1;
    }else{
    retorno =0;}

    return retorno;
}
void mostrar_UnEmpleado(Employee* this)
{
    if(this != NULL){


        printf("\t%2d \t%22s \t\t%d \t\t\t%d\n", this->id, this->nombre,this->horasTrabajadas, this->sueldo);

    }
}

void mostrar_Columnas(){
    printf("\n\tID\t\t\tNOMBRE \t\tHORAS TRABAJADAS \tSUELDO \n\n");
}
