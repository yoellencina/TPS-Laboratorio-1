#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArraysEmployes.h"
#define TAM 1000

int main()
{
    int opcion;
    //opcion= menu("\nHOLA\n");


    eEmpleado unEmpleado [TAM];

    char continuar='s';
    int ordenar=0;
    int id=0;

    inicializarEmpleado(unEmpleado, TAM);

    do
    {
        opcion=menu("\n  Bienvenidos al menu de opciones \n\n"
                    "1. Altas \n"
                    "2. Modificar\n"
                    "3. Bajas \n"
                    "4. Informar\n"
                    "5. Salir\n\nElija una opcion: ");

        switch (opcion)
        {
       case 1:
           agregarEmpleado(unEmpleado, TAM);
           break;

       case 2:

           if (yaHayEmpleado(unEmpleado, TAM))
           {
               modificarEmpleado(unEmpleado, TAM);
               break;
           }else{

           printf("Error debe cargar por lo menos un empleado. ");
           system("pause");
           break;
           }
       case 3:
        if (yaHayEmpleado(unEmpleado, TAM))
        {
            borrarEmpleado(unEmpleado, TAM, id);
            break;
        }else
        {
            printf("Error debe cargar por lo menos un empleado. ");
            system("pause");
            break;
        }
       case 4:

         if(yaHayEmpleado(unEmpleado,TAM))
            {
                ordenarEmpleados(unEmpleado,TAM,ordenar) ;
                mostrarEmpleados(unEmpleado,TAM);
                mostrarInformes(unEmpleado, TAM);
                break;
            }else{
                printf("\nError debe cargar por lo menos un empleado.\n");
                system("pause");
                break;
            }
        case 5:
            printf(" Salir \n\n");
            continuar = 'n';
            system("pause");
            break;
        default:
            printf("Error.Debe ingresar un numero del 1 al 5\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 5
            system("pause");
            break;
        }
    }
    while(continuar == 's') ;


        }
