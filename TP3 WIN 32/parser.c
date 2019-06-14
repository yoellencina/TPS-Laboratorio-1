#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#define OK 1
#define ERROR 0
#define T_BUFFER 500


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int esCorrecto=ERROR;
    int cant;
    char nombre[T_BUFFER];
    char id[T_BUFFER];
    char sueldo[T_BUFFER];
    char horasTrabajadas[T_BUFFER];


    if(pFile !=NULL && pArrayListEmployee !=NULL )
    {


        Employee* this;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        do
            {
                cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

                if (cant == 4)
                {
                    this = (Employee*)malloc(sizeof(Employee));
                    this->id = atoi(id);
                    strcpy(this->nombre, nombre);
                    this->horasTrabajadas= atoi(horasTrabajadas);
                    this->sueldo= atoi(sueldo);
                    ll_add(pArrayListEmployee, this);

                }else{

                    printf("Error! No se puede cargar el archivo csv");
                    break;

                }
        }while(!feof(pFile));
        fclose(pFile);
        esCorrecto=OK;


    }
    return esCorrecto;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int esCorrecto=0;

    if (pFile !=NULL && pArrayListEmployee !=NULL)
    {
        Employee* this;
        while(!feof(pFile))
        {
            this=(Employee*)malloc(sizeof(Employee));
            if ( fread(this, sizeof(Employee),1,pFile) == 1 ){
                ll_add(pArrayListEmployee, this);
                }else{
                break;}
        }
       // fclose(pFile);
        esCorrecto = 1;
    }
    return esCorrecto;
}
