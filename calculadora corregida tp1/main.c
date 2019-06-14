#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
int main()
{

    float numA;
    float numB;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    int factorialUno;
    int factorialDos;
    int opcion;
    int flagA=0, flagB=0;
    char seguir= 's';


    do{
            printf("         CALCULADORA BASICA          \n");
        if(flagA==0)
        {
            printf("1. Ingrese el primer numero operando (A=X)\n");
        }
        else
        {
            printf("1. Ingrese el primer numero operando (A= %.2f)\n", numA);
        }
        if(flagB==0)
        {
            printf("2. Ingresar segundo numero operando (B=Y)\n");
        }
        else
        {
            printf("2. Ingresar segundo numero operando (B= %.2f)\n", numB);
        }



        opcion=pedirOpcion("3. Calcular todas las operaciones:\n"
                           "A. Calcular la suma (A+B)\n"
                           "B. Calcular la resta (A-B)\n"
                           "C. Calcular la multiplicacion (A*B)\n"
                           "D. Calcular la division (A/B)\n"
                           "E. Calcular el factorial (A!)\n"
                           "4. Informar los resultados de las operaciones.\n"
                           "5. Salir.");

        switch(opcion)
        {
            case 1:
                printf("\n Ingrese el primer numero: \n ");
                scanf("%f",& numA);
                flagA=1;
                break;
            case 2:
                printf("\n Ingrese el segundo numero: \n");
                scanf("%f",& numB);
                flagB=1;
                break;
            case 3:
                printf("Se han calculado las operaciones,\n oprima 4 para ver los resultados.\n");
                case 'A':
                    suma= sumar(numA, numB);

                case 'B':
                    resta= restar(numA, numB);

                case 'C':
                    multiplicacion= multiplicar(numA, numB);

                case 'D':
                    if(numB==0){

                    }else{
                    division= dividir(numA, numB);
                    }
                case 'E':
                    factorialUno = factorizar (numA);
                    factorialDos = factorizar (numB);
                    break;

            case 4:
                //SUMA
                printf("\n La suma es: %f", suma);
                //RESTA
                printf("\n La resta es: %f", resta);
                // MULTIPLICACION
                printf("\n La multiplicacion es: %f", multiplicacion);
                //DIVISION
                 if(numB==0){
                    printf("NO SE PUEDE DIVIDIR POR CERO");
                }else{
                    division= dividir(numA, numB);
                    printf("\n La division es: %f", division);
                }
                //FACTORIAL
                if (factorialUno >= 1)
                {
                    printf("\n el factorial de X es %i \n", factorialUno);
                }else{
                printf("\n MathError! no es posible factorizar decimales o numeros negativos.\n");}
                //Factorial Y
                if (factorialDos >= 1)
                {
                    printf(" el factorial de Y es %i \n", factorialDos);
                }else{
                printf(" MathError! no es posible factorizar decimales o numeros negativos.\n");}
                break;

            case 5:
                seguir='n';
                break;

            default:
                printf("opcion incorrecta\n");
                break;
                }
                system("pause");
                system("cls");
    }while(seguir=='s');

    return 0;
}
