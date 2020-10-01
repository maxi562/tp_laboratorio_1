/*
 ============================================================================
 Name        : TP2_Labo1_Maxi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <stdio_ext.h>
#include <string.h>
#include "Empleados.h"

#define CANT_EMPLEADOS 1000

int main(void) {


	int opcion;
	int indice = 0;
	int idEmpleado = 0;
	int buscarID;
	Empleado arrayEmp[CANT_EMPLEADOS];

	emp_initEmployees(arrayEmp,CANT_EMPLEADOS);

	emp_addEmployeeForzado(arrayEmp,CANT_EMPLEADOS,0,&idEmpleado,"Juan","Gomez",34500.99,1);
	emp_addEmployeeForzado(arrayEmp,CANT_EMPLEADOS,1,&idEmpleado,"Juan","Gomez",34500.99,2);//Para prueba Informe ordenar, mismo nombre distinto sector
	emp_addEmployeeForzado(arrayEmp,CANT_EMPLEADOS,2,&idEmpleado,"Vanesa","Gonzalez",98564.87,1);
	emp_addEmployeeForzado(arrayEmp,CANT_EMPLEADOS,3,&idEmpleado,"Milton","Perez",31234.56,2);
	emp_addEmployeeForzado(arrayEmp,CANT_EMPLEADOS,4,&idEmpleado,"Lorena","Ramos",45676.90,3);


			do
			{
				printf("\n============================================================================\n");
				printf("%45s\n","Menu de Empleados");
				printf("============================================================================\n");
				if(!utn_getNumero(&opcion,"\n1.Alta de Empleado"
									 	  "\n2.Modificar Empleado"
									 	  "\n3.Baja de Empleado"
									 	  "\n4.Informe de empleados ordenados por Nombre y Sector"
									 	  "\n5.Informes Salarios"
									 	  "\n6.Salir","Error, opcion inexistente",1,6,2))
				{

				switch(opcion)
				{

				case 1:
					indice = emp_getEmptyIndex(arrayEmp,CANT_EMPLEADOS);
					if((indice >=0) && (!emp_addEmployees(arrayEmp,CANT_EMPLEADOS,indice,&idEmpleado)))
					{
						printf("\nAlta de empleado realizada con exito\n\n El nuevo id es :%d",arrayEmp[indice].id);
					}
					else
					{
						printf("No queda espacio para mas empleados");
					}

					break;

				case 2:
					emp_printEmployees(arrayEmp,CANT_EMPLEADOS);
					if(!utn_getNumero(&buscarID,"\n\nIndique el numero de ID del empleado a modificar\n","Error, ID inexistente",
									  0,idEmpleado-1,2))
					{
						indice = emp_findEmployeeById(arrayEmp,CANT_EMPLEADOS,buscarID);
						if(indice>=0 &&
								!emp_modificarEmployee(arrayEmp,CANT_EMPLEADOS,indice))
						{
							printf("\nModificación realizada con éxito");
						}

					}

					break;

				case 3:
					emp_printEmployees(arrayEmp,CANT_EMPLEADOS);
						if(!utn_getNumero(&buscarID,"\n\nIndique el numero de ID del empleado a eliminar\n","Error, ID inexistente",
										  0,idEmpleado-1,2))
					{
						indice = emp_findEmployeeById(arrayEmp,CANT_EMPLEADOS,buscarID);
						if(indice >=0 &&
								!emp_removeEmployee(arrayEmp,CANT_EMPLEADOS,indice))
						{
							printf("Baja realizada con éxito");
						}

					}
					break;

				case 4:
					printf("\n##########================================##########\n");
					printf("%30s","Desordenados");
					printf("\n====================================================\n");
					emp_printEmployees(arrayEmp,CANT_EMPLEADOS);
					emp_sortEmployees(arrayEmp,CANT_EMPLEADOS);
					printf("\n====================================================\n");
					printf("%30s","Ordenados");
					printf("\n====================================================\n");
					emp_printEmployees(arrayEmp,CANT_EMPLEADOS);

					break;

				case 5:
					printf("\n##########================================##########\n");
					printf("%35s","Informe Salarios");
					printf("\n====================================================\n");
					emp_informEmployees(arrayEmp,CANT_EMPLEADOS);


					break;
				}
			}




			}while(opcion<6);

		return EXIT_SUCCESS;
}
