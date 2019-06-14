

typedef struct
{
    int id;
    char nombre [51];
    char apellido [51];
    float salario;
    int sector;
    int estado;
}eEmpleado;
/** \brief su funcion es pedir opciones al usuario
 *
 * \param lista de empleados
 * \param  tamaño y cantidad
 * \return opcion
 *
 */

int menu ();
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int hardcodeoDeEmpleados (eEmpleado lista [], int tam, int cant);
/** \brief funcion que inicializa los empleados agregados
 *
 * \param  lista de empleados
 * \param  tamaño del array
 * \return retorna 0 si realiza la funcioj
 *
 */

int inicializarEmpleado(eEmpleado lista[], int tam);
/** \brief funcion que agrega a cada uno de los empleados.
 *
 * \param  lista de empleados
 * \param  tamaño del array
 * \return 0 si realiza la funcion
 *
 */

int agregarEmpleado(eEmpleado lista[], int tam);
/** \brief busca a con su id a los empleados y los reconoce
 *
 * \param  lista de empleados
 * \param  tamaño de array
 * \return  la ubicacion donde se encuentre el empleado
 *
 */

int encontrarEmpleadoPorId (eEmpleado lista[],int tam, int id);
/** \brief borra a un empleado
 *
 * \param lista de empleados
 * \param tamaño de array
 * \return devuelve 0 cuando realiza la funcion
 *
 */

int borrarEmpleado (eEmpleado lista[], int tam, int id);
/** \brief asigna un espacio de memoria para un empleado
 *
 * \param lista de empleado
 * \param tamaño de array y id que lo idntifica
 * \return retorna el indice
 *
 */

int dameLugar (eEmpleado lista[], int tam);
/** \brief modifica a un empleado. segun lo que necesite modificarse
 *
 * \param lista de empleados
 * \param tamaño de array
 * \return void
 *
 */

void modificarEmpleado(eEmpleado lista[], int tam);
/** \brief muestra la lista de empleados dado de alta
 *
 * \param lista de empleados
 * \param array de tamaño
 * \return void
 *
 */

void mostrarEmpleado(eEmpleado lista);
/** \brief muestra un empleado de la lista
 *
 * \param  lista de empleados
 * \param  array de tamaño
 * \return  void
 *
 */

void mostrarEmpleados(eEmpleado lista[], int tam);
/** \brief ordena los empleados descendente y ascendente por apellido y sector
 *
 * \param  lista de empleados
 * \param  tamaño del array
 * \return  retorno 0 si realiza la funcion
 *
 */

int ordenarEmpleados (eEmpleado lista[], int tam, int ordenar);
/** \brief funcion que indica que hay empleados existentes
 *
 * \param lista de empleados
 * \param tamaño del array
 * \return retorna 0 si realiza la funcion
 *
 */

int yaHayEmpleado(eEmpleado lista[],int tam);
/** \brief funcion que cuenta los salarios que estan por encima del promedio
 *
 * \param  lista de empleados
 * \param  tamaño del array
 * \return contador de los empleados que sobrepasan el promedio
 *
 */

int contarSalariosMayores(eEmpleado lista[], int tam);
/** \brief obtiene el promedio del salario total
 *
 * \param lista de empleados
 * \param tamaño del array
 * \return resultado del promedio
 *
 */

float obtenerSalarioPromedio(eEmpleado lista[], int tam);
/** \brief suma total de los salarios de los empleados
 *
 * \param lista de empleados
 * \param tamaño del array
 * \return salario total de los empleados
 *
 */

float obtenerSalarioTotal(eEmpleado lista[], int tam);
/** \brief Muestra los informes del promedio salario, total y el mas alto.
 *
 * \param lista empleados
 * \param tamaño de array
 * \return void
 *
 */

void mostrarInformes (eEmpleado lista[], int tam);
