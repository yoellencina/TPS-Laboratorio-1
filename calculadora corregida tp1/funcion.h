//#ifndef FUNCION_H_INCLUDED
//#define FUNCION_H_INCLUDED

/** \brief Funcion para pedir opciones
 *
 * \param variable tipo letra.
 * \param
 * \return retornar la opcion que fue elegida.
 *
 */

int pedirOpcion(char texto[]);

/** \brief suma dos variables decimal.
 *
 * \param numero de tipo decimal
 * \param numero de tipo decimal
 * \return retorna el valor de la suma de enteros
 *
 */

float sumar (float num1, float num2);
/** \brief resta de dos variables decimales, respetando el signo.
 *
 * \param numero variable decimal
 * \param numero variable decimal
 * \return retorna la diferencia final entre dos numeros enteros
 *
 */
float restar (float num1, float num2);
/** \brief realiza el producto en dos numeros decimales
 *
 * \param numero variable decimal
 * \param numero variable decimal
 * \return el resultado del producto de dos numeros decimales.
 *
 */

float multiplicar (float num1 , float num2);
/** \brief realiza la division de dos numeros decimales
  *
  * \param dividendo variable tipo decimal
  * \param divisor variable tipo decimal
  * \return resultado de la division entre dos numeros decimales
  *
  */
float dividir (float num1, float num2);
/** \brief Realiza el producto de todos los números enteros positivos desde 1 hasta el numero ingresado.
 *
 * \param Numero a factoriar.
 * \return El resultado de la multiplicacion de dicho numero con sus enteros predecesores hasta llegar a 1.
 *
 */
float factorizar (float num1);


//#endif // FUNCION_H_INCLUDED
