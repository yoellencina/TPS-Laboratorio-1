#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validaciones.h"

#define NUEVO_ID 1000
//#define PATH_TXT "data.csv"
//#define PATH_BIN "data.bin"



/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main(){


    LinkedList* listaEmpleados= ll_newLinkedList();
    int siguienteId= NUEVO_ID;
    int opcion;


    int flagTxt = 0;
    int flagBin = 0;
    int cant;


    do{

       printf("-->BIENVENIDO AL MENU DE EMPLEADOS.!<--\n\n");

        opcion = menu();
        switch(opcion){
            case 1:
                if(listaEmpleados == NULL){
                    printf("No existe el archivo destino.\n");
                }
                else{
                    if(controller_loadFromText("data.csv",listaEmpleados) == 1){
                        empleado_SiguienteId(listaEmpleados, &siguienteId);
                        printf("\nDatos cargados con exito.\n\n");
                        flagTxt = 0;
                    }
                    else{
                        printf("\nError! No se han podido cargaar los datod .\n\n");
                    }
                }
                break;
            case 2:
                if(listaEmpleados == NULL){
                    printf("No existe el archivo destino.\n");
                }
                else{
                    if(controller_loadFromBinary("data.bin", listaEmpleados)){
                        empleado_SiguienteId(listaEmpleados, &siguienteId);
                        printf("\nDatos cargados con exito.\n\n");
                        flagBin = 0;
                    }
                    else{
                        printf("\nError! No se han podido cargaar los datos.\n\n");
                    }
                }
                break;
            case 3:
                if(flagTxt == 1 && flagBin == 1){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{

                    if(controller_addEmployee(listaEmpleados , &siguienteId)){
                        printf("\nAlta exitosa!\n\n");
                    }
                    else{
                        printf("\nError! No se han podido cargaar los datos .\n\n");
                    }
                }
                break;
            case 4:
                if(flagTxt == 1 && flagBin == 1){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_editEmployee(listaEmpleados)){
                        printf("\nModificacion exitosa!\n\n");
                    }
                    else{
                        printf("\nNo se pudo modificar los datos.\n\n");
                    }
                }
                break;
            case 5:
                if(flagTxt == 1 && flagBin == 1){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_removeEmployee(listaEmpleados)){
                        printf("\nBaja exitosa!\n\n");
                    }
                    else{
                        printf("\nBaja cancelada.\n\n");
                    }
                }
                break;
            case 6:
                if(flagTxt == 1 && flagBin == 1){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    cant = controller_ListEmployee(listaEmpleados);
                    if(cant == 0){
                        printf("\nNo se pudo listar los empleados.\n\n");
                    }
                    else{
                        printf("\nSe han listado con exito empleados.\n\n");
                    }
                }
                break;
            case 7:
                if(flagTxt == 1 && flagBin == 1){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_sortEmployee(listaEmpleados) == -1){
                        printf("\nSe ha producido problemas con el ordenamiento\n\n");
                    }
                    else{
                        printf("\nOrdenamiento exitoso!\n\n");
                    }
                }
                break;
            case 8:
                if(flagTxt == 1 && flagBin == 1){
                    printf("\nNo se  han cargado los datos en el sistema.\n\n");
                }
                else{
                    if(controller_saveAsText("data.csv", listaEmpleados)){
                        printf("\nDatos guardados con exito!\n\n");
                    }
                    else{
                        printf("\n\nError! No se han podido cargaar los datos .\n\n");
                    }
                }
                break;
            case 9:
                if(flagTxt == 1 && flagBin == 1){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_saveAsBinary("data.bin", listaEmpleados)){
                        printf("\nDatos guardados con exito!\n\n");
                    }
                    else{
                        printf("\nError! No se han podido cargaar los datos .\n\n");
                    }
                }
                break;
            case 10:
                ll_deleteLinkedList(listaEmpleados);
                exit(0);
                break;
            default:
                break;
        }
        if(opcion != 10){
            system("pause");
        }
    }while((opcion) != 10);


    return 0;

}
