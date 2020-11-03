#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"

#define NOMBRES 200

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int idMaximo;

	if(path!=NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"r");
		idMaximo = parser_EmployeeFromText(pFile,pArrayListEmployee);
	}
	fclose(pFile);
	return idMaximo;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int idMaximo;

	if(path!=NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"rb");
		idMaximo = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
		printf("id maximo: %d\n",idMaximo);
	}
	fclose(pFile);
	return idMaximo;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int id,int* idSiguiente)
{

	char nombreAux[NOMBRES];
	int sueldoAux;
	int horasAux;
	Employee* empleadoAux;
	int retorno = 0;


	if(pArrayListEmployee!=NULL && id >= 0 &&
	   tomarDatos(nombreAux,200,"Indique el nombre del nuevo Empleado\n")!=-1 &&
	   utn_getNumero(&horasAux,"Indique la cantidad de horas trabajadas","\nCantidad de horas incorrecta",0,400,2)!=-1 &&
	   utn_getNumero(&sueldoAux,"Indique el sueldo del Empleado","\nSueldo Incorrecto",0,1000000,2)!=-1)
	{
		empleadoAux = employee_newParametrosAlta(id,nombreAux,horasAux,sueldoAux);
		ll_add(pArrayListEmployee,empleadoAux);
		retorno = 1;
		*idSiguiente = id+1;


	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char nombreAux[NOMBRES];
    int id;
    int auxiliar;
    int horas;
    int sueldo;
    int retorno = 0;
    Employee* empAux;
    tomarDatos(nombreAux,NOMBRES,"Indique el nombre del Empleado\n");
    if(employee_buscar(pArrayListEmployee,nombreAux,&id))
    {
    	empAux = ll_get(pArrayListEmployee,id-1);
    	do{
    		if(controller_modifMenu(&auxiliar))
    		{
    			switch(auxiliar)
    			{
    				case 1:
    					tomarDatos(nombreAux,NOMBRES,"Indique el nuevo nombre");
    					employee_setNombre(empAux,nombreAux);
    					ll_set(pArrayListEmployee,id-1,empAux);
    					break;

    				case 2:
    					if(utn_getNumero(&horas,"\nIndique la nueva cantidad de horas","\nCantidad incorrecta",0,480,2)==0)
    					{
    						employee_setHorasTrabajadas(empAux,horas);
    						ll_set(pArrayListEmployee,id-1,empAux);
    					}
    					break;

    				case 3:
    					if(utn_getNumero(&sueldo,"\nIndique el nuevo sueldo","\nSueldo incorrecto",0,1000000,2)==0)
    					{
    					    employee_setSueldo(empAux,sueldo);
    					    ll_set(pArrayListEmployee,id-1,empAux);
    					}
    					break;
    			}
    		}
    	}while(auxiliar!=4);

    	retorno = 1;
    }


	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int idAux;
    char nombreAux[NOMBRES];
    Employee* empleadoAux;
    int retorno = 0;

    tomarDatos(nombreAux,200,"Indique el nombre del Empleado\n");
    if(employee_buscar(pArrayListEmployee,nombreAux,&idAux))
    {
    	empleadoAux = ll_get(pArrayListEmployee,idAux);
    	employee_imprimirEmpleado(empleadoAux);
    	if(!controller_validadoraSioNo("\n¿Esta seguro que desea dar de baja?\n1.SI\n2.NO"))
    	{
    		ll_remove(pArrayListEmployee,idAux);
    		retorno = 1;
    	}
    }
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int i;
	Employee* aux;
	if(pArrayListEmployee != NULL)
	{
	       retorno = 1;
	       printf("%-5s|%-15s|%-5s|%-5s\n","ID","NOMBRE","HORAS","SUELDO");
	       printf("==================================\n");
		for(i =0; i<ll_len(pArrayListEmployee);i++)
	    {
	       aux = ll_get(pArrayListEmployee,i);
	       employee_imprimirEmpleado(aux);
	    }
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcionCriterio;
    int opcionOrden;
    int retorno = 0;
	if(pArrayListEmployee != NULL)
	{
		if(controller_sortCriterioMenu(&opcionCriterio)&& opcionCriterio!=5)
		{
			controller_sortOrdenMenu(&opcionOrden);
			retorno = 1;
		}


			if(opcionCriterio == 1 && opcionOrden == 1)
			{
				ll_sort(pArrayListEmployee,employee_compareById,0);
			}
			else if(opcionCriterio == 1 && opcionOrden == 2)
			{
				ll_sort(pArrayListEmployee,employee_compareById,1);
			}

			if(opcionCriterio == 2 && opcionOrden == 1)
			{
				ll_sort(pArrayListEmployee,employee_compareByName,1);
			}
			else if(opcionCriterio == 2 && opcionOrden == 2)
			{
				ll_sort(pArrayListEmployee,employee_compareByName,0);
			}
			if(opcionCriterio == 3 && opcionOrden == 1)
			{
				ll_sort(pArrayListEmployee,employee_compareByHoras,0);
			}
			else if(opcionCriterio == 3 && opcionOrden == 2)
			{
				ll_sort(pArrayListEmployee,employee_compareByHoras,1);
			}
			if(opcionCriterio == 4 && opcionOrden == 1)
			{
				ll_sort(pArrayListEmployee,employee_compareBySueldo,0);
			}
			else if(opcionCriterio == 4 && opcionOrden == 2)
			{
				ll_sort(pArrayListEmployee,employee_compareBySueldo,1);
			}


	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = 0;
    int i;
    Employee* empleadoAux;
    int idAux;
    char nombreAux[NOMBRES];
    int horasAux;
    int sueldoAux;
    if(path!=NULL && pArrayListEmployee != NULL)
    {
    	pArchivo = fopen(path,"w");

    	if(pArchivo != NULL)
    	{
    		rewind(pArchivo);
    		for(i=0;i<ll_len(pArrayListEmployee);i++)
    		{
    			empleadoAux = ll_get(pArrayListEmployee,i);
    			if(empleadoAux != NULL)
    			{
    				employee_getId(empleadoAux,&idAux);
    				employee_getNombre(empleadoAux,nombreAux);
    				employee_getHorasTrabajadas(empleadoAux,&horasAux);
    				employee_getSueldo(empleadoAux,&sueldoAux);
    				fprintf(pArchivo,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
    			}
    		}
    		retorno = 1;
    	}
    	fclose(pArchivo);
    }
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	    int retorno = 0;
	    int i;
	    Employee* empleadoAux;
	    Employee auxiliar;
	    if(path!=NULL && pArrayListEmployee != NULL)
	    {
	    	pArchivo = fopen(path,"wb");

	    	if(pArchivo != NULL)
	    	{
	    		rewind(pArchivo);
	    		for(i=0;i<ll_len(pArrayListEmployee);i++)
	    		{
	    			empleadoAux = ll_get(pArrayListEmployee,i);
	    			if(empleadoAux != NULL)
	    			{
	    				employee_getId(empleadoAux,&auxiliar.id);
	    				employee_getNombre(empleadoAux,auxiliar.nombre);
	    				employee_getHorasTrabajadas(empleadoAux,&auxiliar.horasTrabajadas);
	    				employee_getSueldo(empleadoAux,&auxiliar.sueldo);
	    				fwrite(&auxiliar,sizeof(Employee),1,pArchivo);
	    			}
	    		}
	    		retorno = 1;
	    	}
	    	fclose(pArchivo);
	    }

	return retorno;
}

int controller_optionMenu(int* option)
{
	int retorno = 0;
	int auxiliar;

	printf("\n=================== Menu Principal ===================\n");
	  printf("------------------------------------------------------");
	if(utn_getNumero(&auxiliar,"\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)"
							   "\n2.Cargar los datos de los empleados desde el archivo data.dat (modo binario)"
							   "\n3.Alta de empleado"
							   "\n4.Modificar datos de empleado"
							   "\n5.Baja de empleado"
							   "\n6.Listar empleados"
							   "\n7.Ordenar empleados"
							   "\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto)"
							   "\n9.Guardar los datos de los empleados en el archivo data.dat (modo binario)"
							   "\n10.Salir","\nError, Opción inválida",1,10,2)==0)
	{
		*option = auxiliar;
		retorno = 1;
	}
	return retorno;
}

int controller_modifMenu(int* option)
{
	int retorno = 0;
	int auxiliar;


		printf("\n========== Menu de Modificacion ==========\n");
		if( utn_getNumero(&auxiliar,"\n1.Modificar nombre"
							        "\n2.Modificar horas"
							        "\n3.Modificar sueldo"
							        "\n4.Volver a Menu Principal","\nOpcion incorrecta",1,4,2)==0)
	  {
		  *option = auxiliar;
		  retorno = 1;
	  }


	return retorno;
}

int controller_sortCriterioMenu(int* option)
{
	int retorno = 0;
	int auxiliar;


		printf("\n========== Menu de Criterio de Ordenamiento ==========\n");
		if( utn_getNumero(&auxiliar,"\n1.Ordenar por ID"
									"\n2.Ordenar por Nombre"
							        "\n3.Ordenar por Horas"
							        "\n4.Ordenar por Sueldo"
							        "\n5.Volver a Menu Principal","\nOpcion incorrecta",1,5,2)==0)
	  {
		  *option = auxiliar;
		  retorno = 1;
	  }


	return retorno;
}

int controller_sortOrdenMenu(int* option)
{
	int retorno = 0;
	int auxiliar;


		printf("\n========== Menu de Orden  ==========\n");
		if( utn_getNumero(&auxiliar,"\n1.Orden Ascendente"
							        "\n2.Orden Descendente"
							        "\n3.Salir","\nOpcion incorrecta",1,3,2)==0)
	  {
		  *option = auxiliar;
		  retorno = 1;
	  }


	return retorno;
}
int controller_validadoraSioNo(char* mensaje)
{
	int retorno = -1;
	int validador;
	int verificador;

	do
	{
		verificador = 1;
		puts(mensaje);
		scanf("%d",&validador);

		if(validador == 1)
		{
			verificador = 0;
			retorno = 0;

		}
		else if (validador == 2)
		{
			verificador = 0;
		}


	}while(verificador!=0);


	return retorno;
}

/*int controller_saveLastId(int* lastId,LinkedList* pArrayEmployee, char*path)
{
	int retorno = 0;
	Employee* auxiliar;
	int i;
	int maximo;
	int idAuxiliar;
	FILE* pArchivo;

	if(lastId != NULL && pArrayEmployee != NULL)
	{
		for(i=0;i<ll_len(pArrayEmployee);i++)
		{
			auxiliar = ll_get(pArrayEmployee,i);
			employee_getId(auxiliar,&idAuxiliar);
			if(i==0 || idAuxiliar > maximo)
			{
				maximo = idAuxiliar;
			}
		}
	}
	if(maximo > 0)
	{
		*lastId = maximo;
		pArchivo = fopen(path,"wb");
		if(pArchivo != NULL)
		{
			fwrite(&maximo,sizeof(int),1,pArchivo);
		}
		fclose(pArchivo);
		retorno = 1;
	}
	return retorno;
}*/


