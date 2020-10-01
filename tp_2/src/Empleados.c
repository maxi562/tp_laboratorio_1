/*
 * Empleados.c
 *
 *  Created on: 27 sep. 2020
 *      Author: maximiliano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "Empleados.h"
#include "utn.h"

/**
 * \brief Imprime los datos de un empleado
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_print(Empleado* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %.2f - %d",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->salario,pElemento->sector);
	}
	return retorno;
}

/**
 * \brief Imprime el array de empleados
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_printEmployees(Empleado* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			emp_print(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_initEmployees(Empleado* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
		printf("Array inicializado OK");
	}

	return respuesta;
}

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_addEmployees(Empleado* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Empleado bufferEmp;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferEmp.nombre,NOMBRE_LEN,"\nIndique nombre\n","\nNombre Incorrecto\n",2) == 0 &&
			utn_getNombre(bufferEmp.apellido,APELLIDO_LEN,"\nIndique apellido\n","\nApellido Incorrecto\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmp.salario,"\nIndique Salario\n","\nError, no esta dentro del rango permitido\n",SALARIO_MINIMO,SALARIO_MAXIMO,2) == 0 &&
			utn_getNumero(&bufferEmp.sector,"\nIndique numero de sector\n","Sector inexistente",SECTOR_MINIMO,SECTOR_MAXIMO,2) == 0)
		{
			respuesta = 0;
			bufferEmp.id = *id;
			bufferEmp.isEmpty = 0;
			array[indice] = bufferEmp;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_modificarEmployee(Empleado* array,int limite, int indice)
{
	int respuesta = -1;
	Empleado bufferEmp;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferEmp.nombre,NOMBRE_LEN,"\nIndique nombre\n","\nERROR\n",2) == 0 &&
				utn_getNombre(bufferEmp.apellido,APELLIDO_LEN,"\nIndique apellido\n","\nERROR\n",2) == 0 &&
				utn_getNumeroFlotante(&bufferEmp.salario,"\nIndique Salario\n","\nERROR\n",SALARIO_MINIMO,SALARIO_MAXIMO,2) == 0 &&
				utn_getNumero(&bufferEmp.sector,"\nIndique numero de sector\n","Sector inexistente",SECTOR_MINIMO,SECTOR_MAXIMO,2) == 0)
		{
			respuesta = 0;
			bufferEmp.id = array[indice].id;
			bufferEmp.isEmpty = 0;
			array[indice] = bufferEmp;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_removeEmployee(Empleado* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array empleado Array de empleado
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int emp_findEmployeeById(Empleado array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_getEmptyIndex(Empleado* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/*Brief Da de alta empleados de modo forzado para TEST
 * param array es el array de empleados donde se genera el alta
 * param limite es el limite del array
 * param indice es el indice donde se va a dar de alta el empleado
 * param id es el id ùnico del empleado
 * param nombre es el nombre ficticio del empleado
 * param apellido es el apellido ficticio del empleado
 * param salario es el salario del empleado
 * param sector es el sector del empleaod
 * return Retorna 0 (EXITO) y -1 (ERROR)
 */

int emp_addEmployeeForzado(Empleado* array,int limite, int indice, int* id,char* nombre,char* apellido,float salario,int sector)
{
	int respuesta = -1;
	Empleado auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{

			strncpy(auxiliar.nombre,nombre,NOMBRE_LEN);
			strncpy(auxiliar.apellido,apellido,APELLIDO_LEN);
			auxiliar.salario = salario;
			auxiliar.sector = sector;


			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
			array[indice].id = *id;
			*id = *id + 1;

	}
	return respuesta;
}

/**
 * \brief Ordenar el array de empleados por nombre y sector
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_sortEmployees(Empleado* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Empleado buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}

				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
				else if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) == 0)
				{
					if(array[i].sector > array[i+1].sector)
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1]=buffer;
					}
				}
			}
				limite--;
			}while(flagSwap);
	}
	return respuesta;
	}

/**
 * \brief Elabora 3 informes: salario total, salario promedio, empleados con salario mayor al promedio
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_informEmployees(Empleado* array,int limite)
{
	int i;
	int retorno = -1;
	float acumulador = 0;
	int contador = 0;
	float sueldoPromedio;
	int contadorSueldoSuperiorPromedio = 0;


	if(array != NULL && limite > 0)
	{

	for(i=0;i<limite;i++)
	{
		if(!array[i].isEmpty)
		{
			contador++;
			acumulador = acumulador + array[i].salario;
		}
	}

		sueldoPromedio = acumulador / (float)contador;

	for(i=0;i<limite;i++)
	{
		if(!array[i].isEmpty)
		{
			if(array[i].salario > sueldoPromedio)
			{
				contadorSueldoSuperiorPromedio++;
			}
		}
	}
	retorno = 0;
	printf("\nEl total de salarios es: %.2f",acumulador);
	printf("\n- - - - - - - - - - - - - - - - - - - -");
	printf("\nEl promedio de salarios es: %.2f",sueldoPromedio);
	printf("\n- - - - - - - - - - - - - - - - - - - -");
	printf("\nLa cantidad de empleados con sueldo mayor al promedio es: %d",contadorSueldoSuperiorPromedio);

	}



	return retorno;
}
















