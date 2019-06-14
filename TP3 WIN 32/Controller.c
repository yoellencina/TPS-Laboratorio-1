#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "Validaciones.h"

#define OK 1
#define ERROR 0

int empleado_SiguienteId(LinkedList* pArrayListEmployee, int* siguienteId){
    int estado= ERROR;
    int i;

    if(pArrayListEmployee != NULL && siguienteId != NULL){
        Employee* this;
        for(i=0; i< ll_len(pArrayListEmployee);i++){
            this= ll_get(pArrayListEmployee, i);
            if(this->id >= *siguienteId){
                *siguienteId= this->id;
            }
        }
        estado= OK;
    }
    return estado;
}

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int estado= ERROR;

    FILE* unArchivo= fopen(path, "r");

    if((unArchivo == NULL) && (pArrayListEmployee == NULL))
    {
        printf("\nEl archivo a cargar no existe..");
    }else
    {
        ll_clear(pArrayListEmployee);
        estado= parser_EmployeeFromText(unArchivo, pArrayListEmployee);
        fclose(unArchivo);

    }

    return estado;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int estado= ERROR;

    FILE* unArchivo=fopen(path, "rb");

    if((unArchivo == NULL) && (pArrayListEmployee == NULL))
    {
        printf("\nEl archivo a cargar no existe..");
    }else
    {
        ll_clear(pArrayListEmployee);
        estado= parser_EmployeeFromBinary(unArchivo, pArrayListEmployee);
        fclose(unArchivo);

    }
    return estado;
}


int controller_addEmployee(LinkedList* pArrayListEmployee , int* siguienteId)
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    int estado=ERROR;

    Employee* this;

    if(pArrayListEmployee != NULL && siguienteId != NULL)
    {

        if(pedirCadena("\nIngrese el nombre del empleado",nombre,50))
        {
            printf("\nError al cargar el nombre. El nombre solo debe tener letras.");

        }else if(pedirEnteroPositivo("\nIngrese las horas trabajadas", &horasTrabajadas))
        {
            printf("\nError las horas las debe ingresar en numeros.");
        }else if(pedirEnteroPositivo("\n Ingrese el sueldo del empleado.", &sueldo))
        {
            printf("\nError el sueldo solo debe contener numeros.");
        }


        id= *siguienteId;
        id++;

        this=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
        *siguienteId= id;
        estado=OK;
        ll_add(pArrayListEmployee, this);

        mostrar_Columnas();
        mostrar_UnEmpleado(this);
        printf("\n->EMPLEADO CARGADO..\n");

    }else{

        printf("\nError al cargar el empleado. Intente de nuevo");
    }

    return estado;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int estado=ERROR;
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int indice=-1;
    int i;
    char seguir[1];
    Employee* this;

    if(pArrayListEmployee !=NULL)
    {
        if(pedirEnteroPositivo("\n Ingrese el id del empleado que desea modificar", &id))
        {
            printf("\nError el id solo debe contener numeros.");
        }
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            if( this->id == id ){
                indice= i;
                break;
            }
    }

    if (indice == -1)
    {
        printf("No hay ningun empleado con ese numero id..  \n\n");
        system("pause");
    }else{


        mostrar_UnEmpleado(this);

        funcionContinuarSiONo("\n¿Desea cambiar el Nombre? s/n",seguir);

        if(seguir[0]=='n'|| seguir[0]=='N')
        {
            printf("\nNo ha modificado el nombre.");
        }else if(pedirCadena("\nIngrese el nuevo nombre: ",nombre, 20))
        {
            printf("\n Error. el nombre solo debe contener letras.");
        }else{

            employee_setNombre(this,nombre);
            printf("\nEl nombre ha sido modificado!");
        }
        //MODIFICAR HORAS TRABAJADAS

        mostrar_UnEmpleado(this);

        funcionContinuarSiONo("\n¿Desea cambiar las horas trabajadas? s/n", seguir);

        if(seguir[0]=='n'|| seguir[0]=='N')
        {
            printf("\n No ha modificado las horas.");
        }else if(pedirEnteroPositivo("\n Ingrese la Nueva cantidad de horas de trabajo:",&horasTrabajadas))
        {
            printf("\nError solo debe contener numeros.");
        }else{

            employee_setHorasTrabajadas(this, horasTrabajadas);
            printf("\nLas Horas han sido modificadas!");
        }

        //MODIFICAR SUELDO

        mostrar_UnEmpleado(this);
        funcionContinuarSiONo("\n¿Desea cambiar el sueldo? s/n", seguir);

        if(seguir[0]=='n'|| seguir[0]=='N')
        {
            printf("\n No ha modificado el sueldo.");
        }else if(pedirEnteroPositivo("\n Ingrese el nuevo salario:",&sueldo))
        {
            printf("\nError solo debe contener numeros.");
        }else{

            employee_setSueldo(this, sueldo);
            printf("\nEl sueldo ha sido modificado!");
            }
        estado=OK;
        }
    }
    return estado;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int indice=-1;
    int estado=ERROR;
    int id;
    int i;
    char seguir[1];
    Employee* this;

    if(pArrayListEmployee !=NULL)
    {
         if(pedirEnteroPositivo("\n Ingrese el id del empleado que desea eliminar", &id))
        {
            printf("\nError el id solo debe contener numeros.");
        }
        for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
            this= (Employee*)ll_get(pArrayListEmployee, i);
            if( this->id == id )
                {
                indice= i;
                break;
                }
            }
        if(indice==-1)
        {
            printf("No hay ningun empleado con ese numero id..  \n\n");
            system("pause");
        }else
        {
            mostrar_UnEmpleado(this);

            funcionContinuarSiONo("\n¿Desea dar de baja a este empleado? s/n ",seguir);

            if(seguir[0]=='n' || seguir[0]=='N')
            {
                printf("\n Baja de empleado cancelada..");

            }else
            {
                ll_remove(pArrayListEmployee, indice);
                estado=OK;
            }
        }
    }



    return estado;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int estado=ERROR;
    int i;
    int contador=0;
    Employee* this;

    if (pArrayListEmployee != NULL)
    {
        mostrar_Columnas();
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            this= (Employee*)ll_get(pArrayListEmployee, i);
            mostrar_UnEmpleado(this);
            contador++;
            if(contador== 500){
                system("pause");
                contador= 0;
            }

        }
        estado=OK;
    }
    return estado;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int estado= ERROR;
    int opcion;
    if(pArrayListEmployee != NULL)
        {

        enteroRango("\n1. Ordenar por id"
                         "\n2. Ordenar por nombre"
                         "\n3. Ordenar por sueldo"
                         "\n4. Ordenar por horas trabajadas"
                         "\n5. Cancelar ordenamiento"
                         "\n\nElija una opcion", &opcion, 1, 5);

        if(opcion >= 1 && opcion <=4){
            printf("\nORDENANDO!\n");
        }

         switch(opcion){
                case 1:

                    ll_sort(pArrayListEmployee, Employee_CompareById, 1);
                    printf("\nSe ha ordenado por numero id..");
                    break;
                case 2:

                    ll_sort(pArrayListEmployee, Employee_CompareByNombre, 1);
                    printf("\nSe ha ordenado por nombre..");
                    break;
                case 3:

                    ll_sort(pArrayListEmployee, Employee_CompareBySueldo, 1 );
                    printf("\nSe ha ordenado por sueldo..");
                    break;
                case 4:

                    ll_sort(pArrayListEmployee, Employee_CompareByHorasTrabajadas, 1 );
                    printf("\nSe ha ordenado por cantidad de horas trabajadas..");
                    break;
                case 5:
                    printf("\nSaliendo..");
                    break;
            }
            estado=OK;

        }else{

            printf("Error! no se pudo realizar el ordenamiento.");
        }
    return estado;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int estado=ERROR;
    int i;

    FILE* unArchivo= fopen(path, "w");
    Employee* this;

    if(unArchivo!=NULL  && pArrayListEmployee != NULL)
    {
        fprintf(unArchivo,"id,nombre,horasTrabajadas,sueldo\n");
        for( i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            this= ll_get(pArrayListEmployee, i);
            fprintf(unArchivo, "%d,%s,%d,%d\n",this->id,this->nombre,this->horasTrabajadas, this->sueldo);
        }
        fclose(unArchivo);
        estado=OK;
    }else{
        printf("No hay datos");}

    return estado;

}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int estado=ERROR;
    int i;

    FILE* unArchivo;
    unArchivo = fopen(path, "wb");
    Employee* this;

    if(unArchivo!= NULL && pArrayListEmployee != NULL)
    {
        for(i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            this=ll_get(pArrayListEmployee, i);
            fwrite(this, sizeof(Employee), 1, unArchivo);
        }

        fclose(unArchivo);
        estado= OK;
    }else{
        printf("No hay datos");
    }
    return estado;
}


