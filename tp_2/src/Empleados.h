/*
 * Empleados.h
 *
 *  Created on: 27 sep. 2020
 *      Author: maximiliano
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

#define NOMBRE_LEN 51
#define APELLIDO_LEN 51
#define SALARIO_MAXIMO 150000.99
#define SALARIO_MINIMO 30000.99
#define SECTOR_MINIMO 1
#define SECTOR_MAXIMO 100

typedef struct
{
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	float salario;
	int sector;
	int isEmpty;
	int id;
}Empleado;

int emp_print(Empleado* auxProducto);
int emp_initEmployees(Empleado* array,int limite);
int emp_addEmployees(Empleado* array,int limite, int indice, int* id);
int emp_getEmptyIndex(Empleado* array,int limite);
int emp_printEmployees(Empleado* array,int limite);
int emp_findEmployeeById(Empleado array[], int limite, int valorBuscado);
int emp_modificarEmployee(Empleado* array,int limite, int indice);
int emp_removeEmployee(Empleado* array,int limite, int indice);
int emp_sortEmployees(Empleado* array,int limite);
int emp_addEmployeeForzado(Empleado* array,int limite, int indice, int* id,char* nombre,char* apellido,float salario,int sector);
int emp_informEmployees(Empleado* array,int limite);


#endif /* EMPLEADOS_H_ */
