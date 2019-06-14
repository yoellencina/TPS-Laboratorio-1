#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


/** \brief funcion que valida si es numero
 *
 * \param  letra
 * \param
 * \return 1 cuando son numeros 0 cuando no lo som
 *
 */

int funcionEsNum(char letra[]);
/** \brief funcion que valida si son numeros
 *
 * \param  char mensaje
 * \param input
 * \return 0 si realizo la funcion
 *
 */

int funcionGetStringNumeros(char mensaje[],char input[]);
/** \brief funcion que valida que sean letras y no numeros
 *
 * \param char letra
 * \param
 * \return 0 si lo son 1 si no lo son
 *
 */

int funcionSoloLetras(char letra[]);
/** \brief funcion que valida que sean letras y no numeros
 *
 * \param char letra
 * \param
 * \return 1 si lo son 0 si no lo son
 *
 */
int funcionGetStringLetras(char msj[],char input[]);
/** \brief funcion que valida si desea continuar o no
 *
 * \param mensaje char
 * \param char input
 * \return ninguna
 *
 */

void funcionContinuarSiONo(char mensaje[],char input[]);










#endif // EMPLEADO_H_INCLUDED
