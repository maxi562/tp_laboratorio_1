#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

#define NOMBRE 100
#define NUMEROS 50
/*
 * Construye un empleado en memoria
 */

Employee* employee_new()
{
	Employee* bufferAux;
	bufferAux = (Employee*)malloc(sizeof(Employee));
	return bufferAux;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
	Employee* bufferAux;

	bufferAux = employee_new();

	if(bufferAux == NULL || !employee_setIdTexto(bufferAux,idStr) ||
							!employee_setNombre(bufferAux,nombreStr) ||
							!employee_setHorasTrabajadasTexto(bufferAux,horasTrabajadasStr)||
							!employee_setSueldoTexto(bufferAux,sueldo))
	{
		employee_delete(bufferAux);
		bufferAux = NULL;
	}


	return bufferAux;
}

Employee* employee_newParametrosAlta(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldo)
{
	Employee* bufferAux;

	bufferAux = employee_new();

	if(bufferAux == NULL || !employee_setNombre(bufferAux,nombreStr) ||
							!employee_setId(bufferAux,idStr+1) ||
							!employee_setHorasTrabajadas(bufferAux,horasTrabajadasStr)||
							!employee_setSueldo(bufferAux,sueldo))
	{
		employee_delete(bufferAux);
		bufferAux = NULL;
	}


	return bufferAux;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this!= NULL && nombre!= NULL && esNombre(nombre,NOMBRE)!=-1)
	{
		strcpy(this->nombre,nombre);
		retorno = 1;

	}
	return retorno;
}


int employee_setId(Employee* this,int id)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->id = id;
		retorno = 1;
	}

		return retorno;
}
int employee_setIdTexto(Employee* this,char* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL
			&& esNumerica(id,NUMEROS)!=-1)
	{
		this->id = atoi(id);
		retorno = 1;

	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL && horasTrabajadas >=0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

		return retorno;
}
int employee_setHorasTrabajadasTexto(Employee* this,char* horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL && horasTrabajadas != NULL
				&& esNumerica(horasTrabajadas,NUMEROS)!=-1)
	{
		this->horasTrabajadas = atoi(horasTrabajadas);
		retorno = 1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = 0;

	if(this != NULL && sueldo >=0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}

		return retorno;
}

int employee_setSueldoTexto(Employee* this,char* sueldo)
{
	int retorno = 0;

	if(this != NULL && sueldo != NULL
					&& esNumerica(sueldo,NUMEROS)!=-1)
	{
		this->sueldo = atoi(sueldo);
		retorno = 1;

	}

		return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id !=NULL)
	{
		*id = this->id;
		retorno = 1;
	}

		return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this!= NULL && nombre!= NULL && esNombre(nombre,NOMBRE)!=-1)
	{
		strncpy(nombre,this->nombre,NOMBRE);
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = 0;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}

void employee_imprimirEmpleado(Employee* this)
{
	int idAux;
	char nombreAux[200];
	int horasAux;
	int sueldoAux;

	if(this!= NULL)
		{
			employee_getId(this,&idAux);
			employee_getNombre(this,nombreAux);
			employee_getHorasTrabajadas(this,&horasAux);
			employee_getSueldo(this,&sueldoAux);
			printf("%-5d|%-15s|%-5d|%-5d\n",idAux,nombreAux,horasAux,sueldoAux);
		}

}
int employee_buscar(LinkedList* this,char* nombre,int* id)
{
	int retorno = 0;
	int i;
	int j;
	Employee* empleadoAux;
	char nombreAux[200];
	int idAux;
	int horasAux;
	int sueldoAux;
	int idSeleccion=-1;
	int* listaIdEncontrados;
	int contador = 0;

	listaIdEncontrados = (int*)malloc(sizeof(int)*10);

	if(this!=NULL && nombre != NULL)
	{
		printf("%3s %8s %5s %5s\n","ID","NOMBRE","HORAS","SUELDO");
		printf("----------------------------------------------\n");
		for(i=0;i<ll_len(this);i++)
		{
			empleadoAux = ll_get(this,i);
			employee_getNombre(empleadoAux,nombreAux);
			if(strcmp(nombre,nombreAux)==0)
			{
				employee_getId(empleadoAux,&idAux);
				employee_getSueldo(empleadoAux,&sueldoAux);
				employee_getHorasTrabajadas(empleadoAux,&horasAux);
				if(listaIdEncontrados !=NULL)
				{
					*(listaIdEncontrados+contador) = idAux;
					contador++;
					employee_imprimirEmpleado(empleadoAux);
				}

			}

		}
		if(contador>0)
			{
				utn_getNumero(&idSeleccion,"De la lista, indique el ID del empleado\n","Error, ID incorrecto",1,10000,2);
				for(j=0;j<contador;j++)
				{
					if(idSeleccion == *(listaIdEncontrados+j))
					{
						*id = idSeleccion;
						retorno = 1;
					}
				}
			}


	}

	return retorno;
}

int employee_compareById(Employee* primero,Employee* segundo)
{
	int retorno = 0;
	int idPrimero;
	int idSegundo;

	if(primero != NULL && segundo != NULL)
	{
		employee_getId(primero,&idPrimero);
		employee_getId(segundo,&idSegundo);
		if(idPrimero > idSegundo)
		{
			retorno = -1;
		}
		else if(idPrimero < idSegundo)
		{
			retorno= 1;
		}
	}
	return retorno;
}

int employee_compareByName(Employee* primero,Employee* segundo)
{
	int retorno = 0;
	char nombrePrimero[NOMBRE];
	char nombreSegundo [NOMBRE];
	if(primero != NULL && segundo != NULL)
	{
		employee_getNombre(primero,nombrePrimero);
		employee_getNombre(segundo,nombreSegundo);
		if(strcmp(nombrePrimero,nombreSegundo)<0)
		{
			retorno = -1;
		}
		else if(strcmp(nombrePrimero,nombreSegundo)>0)
		{
			retorno= 1;
		}
	}
	return retorno;
}

int employee_compareByHoras(Employee* primero,Employee* segundo)
{
	int retorno = 0;
	int horasPrimero;
	int horasSegundo;

	if(primero != NULL && segundo != NULL)
	{
		employee_getHorasTrabajadas(primero,&horasPrimero);
		employee_getHorasTrabajadas(segundo,&horasSegundo);
		if(horasPrimero > horasSegundo)
		{
			retorno = -1;
		}
		else if(horasPrimero < horasSegundo)
		{
			retorno= 1;
		}
	}
	return retorno;
}

int employee_compareBySueldo(Employee* primero,Employee* segundo)
{
	int retorno = 0;
	int sueldoPrimero;
	int sueldoSegundo;

	if(primero != NULL && segundo != NULL)
	{
		employee_getSueldo(primero,&sueldoPrimero);
		employee_getSueldo(segundo,&sueldoSegundo);
		if(sueldoPrimero > sueldoSegundo)
		{
			retorno = -1;
		}
		else if(sueldoPrimero < sueldoSegundo)
		{
			retorno= 1;
		}
	}
	return retorno;
}

int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 0;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}

		}

	}
	return retorno;
}

int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
