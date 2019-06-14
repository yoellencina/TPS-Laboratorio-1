#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Constructor por defecto de empleado. Crea un empleado en memoria dinamica
 *
 * \return Employee* Devuelve el puntero al empleado creado
 *
 */
Employee* employee_new();
/** \brief Constructor parametrizado de empleado. Crea un empleado en memoria dinamica
           con los datos recibidos como parametros
 *
 * \param id int El id del empleado
 * \param nombre char* El nombre del empleado
 * \param horasTrabajadas int Las horas trabajadas del empleado
 * \param sueldo int El sueldo del empleado
 * \return Employee* Devuelve el puntero al empleado creado
 *
 */
Employee* employee_newParametros(int idEmpleado,char* nombreEmpleado,int horasTrabajadas, int sueldoEmpleado);
void employee_delete();
/** \brief Función que setea el id de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int El id a setear
 * \return int Devuelve 1 si se pudo setear, o 0 si no se pudo
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Función que obtiene el id de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int* El id obtenido
 * \return int Devuelve 1 si se pudo obtener, o 0 si no se pudo
 *
 */
int employee_getId(Employee* this,int* id);
/** \brief Función que setea el nombre de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int El id a setear
 * \return int Devuelve 1 si se pudo setear, o 0 si no se pudo
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Función que obtiene el nombre de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int* El id obtenido
 * \return int Devuelve 1 si se pudo obtener, o 0 si no se pudo
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Función que setea las horas trabajadas de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int El id a setear
 * \return int Devuelve 1 si se pudo setear, o 0 si no se pudo
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Función que obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int* El id obtenido
 * \return int Devuelve 1 si se pudo obtener, o 0 si no se pudo
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Función que setea el sueldo de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int El id a setear
 * \return int Devuelve 1 si se pudo setear, o 0 si no se pudo
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Función que obtiene el sueldo de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int* El id obtenido
 * \return int Devuelve 1 si se pudo obtener, o 0 si no se pudo
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Sirve para comparar y asi poder ordenar los id de los empleados
 *
 * \param puntero que apunta a un empleado
 * \param puntero que apunta al segundo empleado
 * \return devuelve 0, 1 , -1 segun el orden
 *
 */

int Employee_CompareById(void* empleado1, void*empleado2);

/** \brief sirve para comparar y asi poder ordenar los nombres de los empleados
 *
 * \param empleado1 void*
 * \param void*empleado2
 * \return devuelve 0, 1 , -1 segun el orden
 *
 */
int Employee_CompareByNombre(void* empleado1, void*empleado2);
/** \brief sirve para comparar y asi poder ordenar las horas trabajadas de los empleados
 *
 * \param empleado1 void*
 * \param void*empleado2
 * \return devuelve 0, 1 , -1 segun el orden
 *
 */

int Employee_CompareByHorasTrabajadas(void* empleado1, void*empleado2);
/** \brief sirve para comparar y asi poder ordenar los sueldos de los empleados
 *
 * \param empleado1 void*
 * \param void*empleado2
 * \return devuelve 0, 1 , -1 segun el orden
 *
 */
 int Employee_CompareBySueldo(void* empleado1, void*empleado2);
 /** \brief muestra un empleado de la lista
  *
  * \param puntero a un empleado
  * \param
  * \return void
  *
  */

 void mostrar_UnEmpleado(Employee* this);

/** \brief muestra el encabezado de la funcon mostrar empleado
 *
 * \param puntero empleado
 * \param
 * \return void
 *
 */

 void mostrar_Columnas();
#endif // employee_H_INCLUDED
