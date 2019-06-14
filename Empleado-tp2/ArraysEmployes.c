#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArraysEmployes.h"
#include "Empleado.h"

int menu(char texto[])
{
    int opcion;

    printf("%s", texto);
    scanf("%d", &opcion);

    return opcion;
}
int inicializarEmpleado(eEmpleado lista[], int tam)
{
     int retorno = 0;
     int i;

    if(lista != NULL && tam > 0)
    {

        for( i=0; i < tam; i++)
        {

            lista[i].estado = 1;
        }
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}

int agregarEmpleado(eEmpleado lista[], int tam)
{
    char auxNombre [20];
    char auxApellido [20];
    char auxSalario[10];
    char auxSector[10];
    int retorno;
    eEmpleado nuevoEmpleado;
    int indice;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        fflush(stdin);
        indice=dameLugar(lista, tam);
        printf(" --> ALTA EMPLEADO <--\n\n");

        if (indice==-1)
        {
            printf("No hay lugar en el sistema.");
            retorno=-1;
            system("pause");
        }else {

            printf("\n Nuevo empleado, ID numero %d \n",indice) ;
            nuevoEmpleado.id = indice ;
            if(!funcionGetStringLetras("Ingrese nombre: ",auxNombre))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");
            }
            else if(!funcionGetStringLetras("Ingrese apellido: ",auxApellido))
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!funcionGetStringNumeros("Ingrese el salario: ",auxSalario) && auxSalario > 0)
            {
                printf("Error. ingrese nuevamente el salario. solo deben ir numeros \n\n");
                system("pause");
                system("cls");

            }
            else if(!funcionGetStringNumeros("Ingrese el sector: ", auxSector))
            {
                printf("Error el sector debe tener solo numeros.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                strcpy(nuevoEmpleado.nombre,auxNombre) ;
                strcpy(nuevoEmpleado.apellido,auxApellido) ;
                nuevoEmpleado.salario =atoi(auxSalario) ;
                nuevoEmpleado.sector =atoi(auxSector) ;
                nuevoEmpleado.estado = 0;
                lista[indice] = nuevoEmpleado ;
                system("pause");
                system("cls");
                printf("\n\nEMPLEADO DADO DE ALTA CON EXITO:\n\n");
                mostrarEmpleado(lista[indice]);
                printf("\n\n\n");
                system("pause");
                retorno = 0 ;
             }

        }
    }else{
    retorno=-1;}

    return retorno;


}
int encontrarEmpleadoPorId (eEmpleado lista[],int tam, int id)
{
    int aux=1;
    int i;
    for (i=0; i<tam; i++)
    {
        if (lista[i].id== id && lista[i].estado==0)
        {
            aux=i;
            break;
        }
    }
    return aux;

}
int borrarEmpleado (eEmpleado lista[], int tam, int id)
{
    int indice;
    int retorno;
    char auxID[10];
    char seguir[1];

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("\n--> BAJA DE EMPLEADO <--\n\n");

        if (!funcionGetStringNumeros("Ingrese Id\n",auxID))
        {
            printf("Error el id solo debe tener numeros..");
            system("pause");
            system("cls");
        }else{
        id=atoi(auxID);
        indice=encontrarEmpleadoPorId(lista, tam, id);
        if (indice==-1)
        {
            printf("\n No hay ningun empleado con ese ID..");
        }else{
        retorno=0;
        mostrarEmpleado(lista[indice]);
        funcionContinuarSiONo("\nDesea Eliminarlo s/n: ",seguir);
                if(seguir[0] == 'n' || seguir[0] == 'N')
        {
            printf("Baja cancelada\n\n");
        }else{
            lista[indice].estado = 1;
            printf("Borrado exitoso\n\n");}

        system("pause");}

      }

    }
    return retorno;

    }
int dameLugar (eEmpleado lista[], int tam)
{
   int indice = -1;
   int i;
    for(i=0; i< tam ; i++)
    {
        if( lista[i].estado == 1)
        {
            indice = i ;
            break;
        }
    }
    return indice ;
}
void modificarEmpleado(eEmpleado lista[], int tam)
{
    int id;
    int indice;
    char auxId[5];
    char seguir[1];
    char nuevoSalario[5];
    char nuevoSector[5];
    char nuevoNombre[51];
    char nuevoApellido[51];

    system("cls");
    printf("-->MODIFICAR EMPLEADO<-- \n\n");

    if (!funcionGetStringNumeros("Ingrese el numero id: ",auxId))
    {
        printf("Error, el id solo debe contener numeros..");
    }

    id= atoi(auxId);
    indice= encontrarEmpleadoPorId(lista , tam, id);

    if(indice== -1)
    {
        printf("No hay ningun empleado con ese numero id.. %d \n\n", id);
        system("pause");

    }else{
    mostrarEmpleado(lista[indice]);

    funcionContinuarSiONo("Desea modificar el nombre: s/n",seguir);
    if(seguir[0] == 'n'|| seguir[0] == 'N')
        {
            printf("\n  No modifico el nombre. \n\n");
            system("cls") ;

        } else if(!funcionGetStringLetras("Ingrese nuevo nombre: ",nuevoNombre))
            {
                printf("\n Error. El nombre debe tener solo letras.");
            }else
            {
            strcpy(lista[indice].nombre,nuevoNombre);
            printf("\n\n  Usted a modificado el nombre. \n\n");
            }
    //MODIFICAR APELLIDO

    mostrarEmpleado(lista[indice]);

    funcionContinuarSiONo("Desea modificar el Apellido: s/n",seguir);
    if(seguir[0] == 'n'|| seguir[0] == 'N')
        {
            printf("\n  No modifico el apellido. \n\n");
            system("cls") ;

        } else if(!funcionGetStringLetras("Ingrese nuevo apellido: ",nuevoApellido))
            {
                printf("\n Error. El Apellido debe tener solo letras.");
            }else{
            strcpy(lista[indice].apellido,nuevoApellido);
            printf("\n\n  Usted a modificado el Apellido. \n\n");
            }
    //MODIFICAR SALARIO
    mostrarEmpleado(lista[indice]);

   funcionContinuarSiONo("Desea modificar el Salario: s/n",seguir);
    if(seguir[0] == 'n'|| seguir[0] == 'N')
        {
            printf("\n  No modifico el Salario. \n\n");
            system("cls") ;

        } else if(!funcionGetStringNumeros("Ingrese el nuevo Salario: ",nuevoSalario))
            {
                printf("\n Error. El salario debe tener solo numeros..");
            }else{
            lista[indice].salario= atoi(nuevoSalario);
            printf("\n\n  Usted a modificado el Salario. \n\n");
            }

    mostrarEmpleado(lista[indice]);

    funcionContinuarSiONo("Desea modificar el Sector: s/n",seguir);
    if(seguir[0] == 'n'|| seguir[0] == 'N')
        {
            printf("\n  No modifico el Sector. \n\n");
            system("cls") ;

        } else if(!funcionGetStringNumeros("Ingrese el nuevo Sector: ",nuevoSector))
            {
                printf("\n Error. El sector debe tener solo numeros..");
            }else{
            lista[indice].sector= atoi(nuevoSector);
            printf("\n\n  Usted a modificado el Sector. \n\n");
             system("pause");
            system("cls") ;
            }

    }

}
void mostrarEmpleado(eEmpleado lista)
{
    printf("%2d %15s %16s %16.2f %15d\n",lista.id , lista.nombre, lista.apellido, lista.salario, lista.sector);
}
void mostrarEmpleados(eEmpleado lista[], int tam)
{
    system("cls");
    printf("\n\nID\t\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n");

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado == 0)
        {
            mostrarEmpleado(lista[i]) ;
        }
    }
}
int ordenarEmpleados (eEmpleado lista[], int tam, int ordenar)
{
    eEmpleado auxEmpleado;
    char auxOrdenar[1] ;
    int i;
    int j;
    if(!funcionGetStringNumeros("\n Ingrese 1 para ordenar de manera ascendente o ingrese 2 para ordenar de manera descendente: ",auxOrdenar))
    {
        printf("Error debe ingresar un numero..");

    }

    ordenar = atoi(auxOrdenar);

     switch(ordenar)
    {
    case 1:
        for(i = 0; i < tam - 1; i++)
        {
            for(j = i + 1; j < tam; j++)
            {
                if(strcmp(lista[j].apellido, lista[i].apellido) < 0  && lista[j].estado == 0 && lista[i].estado == 0)
                {
                    auxEmpleado = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxEmpleado;
                }
                else if(strcmp(lista[j].apellido, lista[i].apellido) == 0 && lista[j].sector < lista[i].sector  && lista[j].estado == 0 && lista[i].estado == 0)
                {
                    auxEmpleado = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxEmpleado;
                }
            }
        }
        printf("\n\nEl ordenado ascendente se ha realizado con exito.\n");
        system("pause") ;
        system("cls") ;
        break;
    case 2:
        for( int i = 0; i < tam-1; i++)
        {
            for( int j = i+1; j < tam; j++)
            {
                if(strcmp(lista[j].apellido, lista[i].apellido) > 0 && lista[j].estado == 0 && lista[i].estado == 0)
                {
                    auxEmpleado = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxEmpleado;
                }
                else if(strcmp(lista[j].apellido, lista[i].apellido) == 0 && lista[j].sector > lista[i].sector  && lista[j].estado == 0 && lista[i].estado == 0)
                {
                    auxEmpleado = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxEmpleado;
                }
            }
        }

        system("pause") ;
        system("cls") ;
        break;
    default:
        printf("No ingreso 1 o 2");
    }
    return 0;
}
int yaHayEmpleado(eEmpleado lista[],int tam)
{
    int retorno = 0;
    int i;
    for( i = 0; i<tam ; i++)
    {
        if(lista[i].estado == 0)
        {
            retorno = 1 ;
            break;
        }
    }

    return retorno;
    }


float obtenerSalarioTotal(eEmpleado lista[], int tam)
{
    float acumSalario= 0;
    int i;
    for(i=0;i<tam;i++){
        if(lista[i].estado==0){
            acumSalario= acumSalario + lista[i].salario;
        }
    }
    return acumSalario;
}

float obtenerSalarioPromedio(eEmpleado lista[], int tam)
{
    float acumSalario = 0;
    int contSalario= 0;
    float promedio ;
    for(int i = 0; i < tam; i++ )
    {

        if(lista[i].estado == 0)
        {
            acumSalario = acumSalario + lista[i].salario ;
            contSalario++;

        }
    }

    promedio = (acumSalario / contSalario);

    return promedio;
}

int contarSalariosMayores(eEmpleado lista[], int tam)
{
    int contador = 0;

    for(int i = 0; i < tam ; i++)
    {
        if(lista[i].estado == 0 && lista[i].salario > obtenerSalarioPromedio(lista,tam))
        {
            contador++;
        }
    }
    return contador;
}
void mostrarInformes (eEmpleado lista[], int tam)
{
    char continuar= 's';
    do
    {

    int opcion= menu("\n\nIngrese las siguientes opciones:\n 1.Total de salario.\n 2.Promedio de salario.\n"
                     "3.Empleados que superan el promedio de salario.\n 4.Volver al menu principal.\n\nElija una opcion:  ");

                     switch (opcion)

                     {
                    case 1:
                        printf("\n\n\nEl total de los salarios es de: %.2f \n", obtenerSalarioTotal(lista, tam));
                        break;
                    case 2:
                        printf("\n\nEl promedio de los salarios es de: %.2f\n",obtenerSalarioPromedio(lista, tam));
                        break;
                    case 3:
                        printf("\n\nLa cantidad de empleados que superan el salario promedio son: %d\n",contarSalariosMayores(lista, tam));
                        break;
                    case 4:
                        printf(" Salir \n\n");
                        continuar = 'n';
                        system("pause");
                        break;
                     }
    }while(continuar=='s');
}

