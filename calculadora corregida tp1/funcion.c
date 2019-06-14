//#ifndef FUNCION_C_INCLUDED
//#define FUNCION_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

//pedir opcion de menu
int pedirOpcion(char texto[])
{
    int opcion;

    printf("%s", texto);
    scanf("%d", &opcion);

    return opcion;
}
// calculo para sumer los numeros ingresados

float sumar (float num1, float num2)
{
    float suma=num1+num2;

    return suma;
}
// calculo para restar los numeros ingresados

float restar (float num1, float num2)
{
    float resta=num1-num2;

    return resta;
}
// calculo para multiplicar los numeros ingresados
 float multiplicar (float num1 , float num2)
 {
     float multiplicion= num1*num2;

     return multiplicion;
 }
 //calculo para dividir los numeros infresados
  float dividir (float num1, float num2)
  {


      return num1/num2;
  }
  //calculo para sacar factorial
float factorizar (float num1)
{
    int i = 1, j = 1, z = 0;
    float w = 0;


    z = (int) num1;
    w = (float) z;

    if (num1==0)
    {
        j=1;
    }else if (num1>= 1 && num1==w)
    {
        while(i <= num1)
        {
            j=j*i;
            i++;
        }
    }else{
    j=0;}


    return j;
   }



//#endif // FUNCION_C_INCLUDED
