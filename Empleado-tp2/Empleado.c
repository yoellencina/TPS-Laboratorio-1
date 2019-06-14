#ifndef EMPLEADO_C_INCLUDED
#define EMPLEADO_C_INCLUDED

#endif // EMPLEADO_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"




int funcionSoloLetras(char letra[])
{
    int i=0;
    while(letra[i] != '\0')
    {
        if((letra[i] != ' ') && (letra[i] < 'a' || letra[i] > 'z') && (letra[i] < 'A' || letra[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
void FuncionGetString (char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin) ;
    gets(input) ;
}
int funcionGetStringLetras(char mensaje[],char input[])
{
    char aux[256];
    FuncionGetString(mensaje,aux);
    if(funcionSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}
int funcionEsNum(char letra[])
{
     int i=0;
    while(letra[i] != '\0')
    {
        if(letra[i] < '0' || letra[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int funcionGetStringNumeros(char mensaje[],char input[])
{
   char aux[256];
   FuncionGetString(mensaje,aux);
   if(funcionEsNum(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void funcionContinuarSiONo(char mensaje[],char input[])
{
    do
    {
        if(!funcionGetStringLetras(mensaje,input))
        {
            printf("Error Debe ingresar la letra S o N");
            system("pause");
            system("cls");
        }

    }
    while(!(input[0] == 's' || input[0] == 'n' || input[0] == 'S' || input[0] == 'N'));

}


