

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0 si no se pudieron cargar los datos y 1 si se pudo cargar los datos
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);



/** \brief carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArraylistEmployee linkedlist*
 * \return 0 si no se pudieron cargar los datos y 1 si se pudo cargar los datos
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si realizo el alta 0 si no
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* siguinteId);
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si realizo la modificacion 0 si no
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si realizo la baja 0 si no
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si realizo el listado 0 si no
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si realizo el ordenamiento 0 si no
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si guardo los datos 0 si no
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 siguardo los datos  0 si no
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief para identificar el siguiente id y no hayan id iguales
 *
 * \param path char*
 * \param pArray listEmployee linkedList*
 * \return 1 si realiza la funcion 0 si no.
 *
 */

int empleado_SiguienteId(LinkedList* pArrayListEmployee, int* siguienteId);


