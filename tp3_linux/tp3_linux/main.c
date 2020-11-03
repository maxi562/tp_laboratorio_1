#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/



int main()
{
   int option = 0;
   int idSiguiente;
   int idUltimo;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	if(controller_optionMenu(&option))
    	{
    		switch(option)
    		{
            	case 1:
            		idSiguiente = controller_loadFromText("data.csv",listaEmpleados);
            		if(idSiguiente > 0)
            		{
            			printf("Carga exitosa\n");
            		}
            		break;

            	case 2:
            		idSiguiente = controller_loadFromBinary("data.dat",listaEmpleados);
            		if(idSiguiente > 0)
            		{
            		    printf("Carga exitosa\n");
            		}
            		break;

            	case 3:
            		if(controller_addEmployee(listaEmpleados,idSiguiente,&idUltimo))
            		{
            			printf("Alta Exitosa\n");
            			idSiguiente = idUltimo;
            		}
            		break;

            	case 4:
            		if(controller_editEmployee(listaEmpleados)==0)
            		{
            			printf("ID incorrecto\n");
            		}
            		break;

            	case 5:
            		if(controller_removeEmployee(listaEmpleados))
            		{
            			printf("\nBaja Exitosa");
            		}
            		break;

            	case 6:
            		if(controller_ListEmployee(listaEmpleados))
            		{
            			printf(("\nImpresión Ok"));
            		}
            		break;
            	case 7:
            		if(controller_sortEmployee(listaEmpleados))
            		{
            			printf("\nOrdenamiento Exitoso");
            		}
            		break;

            	case 8:
            		if(controller_saveAsText("data.csv",listaEmpleados))
            		{
            		    printf("\nSalvado Exitoso");
            		}
            		break;

            	case 9:
            		if(controller_saveAsBinary("data.dat",listaEmpleados))
            		{
            			printf("\nSalvado exitoso");
            		}
            		break;
            	//case 10:
            		//if(controller_saveLastId(&idUltimo,listaEmpleados))
            		//{
            		//	printf("Ok último ID %d",idUltimo);
            		//}
            		//break;
    		}
    	}
    	else
    	{
    		printf("\nReintentos Agotados");
    		break;
    	}
    }while(option != 10);

    return 0;
}

