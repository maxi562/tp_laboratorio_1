#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int contador=0;
	int i=0;
	char id [100];
	char nombre[200];
	char horas [50];
	char sueldo [100];
	Employee* empleadoAux;
				  //id,nombre,horas,sueldo
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horas,sueldo);
	if(pFile!=NULL && pArrayListEmployee != NULL)
	{
		do{
			contador = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
			if(contador == 4)
			{
				empleadoAux = employee_newParametros(id,nombre,horas,sueldo);
				ll_add(pArrayListEmployee,empleadoAux);
				i++;
			}
		}while(!feof(pFile));


	}
    return i;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
		int contador=0;
		int i=0;
		Employee auxiliar;
		Employee* ptrEmp;

		if(pFile!=NULL && pArrayListEmployee != NULL)
		{
			do{
				contador = fread(&auxiliar,sizeof(Employee),1,pFile);
				if(contador == 1)
				{
					ptrEmp = employee_newParametrosAlta(auxiliar.id,auxiliar.nombre,auxiliar.horasTrabajadas,auxiliar.sueldo);
					ll_add(pArrayListEmployee,ptrEmp);
					i++;
				}
			}while(!feof(pFile));


		}
	    return i;
}
