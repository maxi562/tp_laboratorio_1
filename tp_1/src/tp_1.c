/*
 ============================================================================
 Name        : tp_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define MINIMO -2147483600
#define MAXIMO	2147483600

int main(void) {
	int option;
	double primerOperando;
	double segundoOperando;
	double resultadoSuma;
	double resultadoResta;
	double resultadoDivision;
	double resultadoMultiplicacion;
	double resultadoFactorial1;
	double resultadoFactorial2;

	do{
		printf("\n----------Menu de opciones----------\n");
		if(utn_getNumero(&option,primerOperando,segundoOperando,1,9,2) == 0)
		{

			switch(option)
			{
				case 1:
						if(utn_getNumeroDouble(&primerOperando,"Indique el primer operando","Fuera de rango permitido",MINIMO,MAXIMO,3)==0)
						{
							printf("\nCarga Exitosa de primer operando");
						}
						else
						{
							printf("\nError en la carga de primer operando");
						}

					break;

				case 2:
						if(utn_getNumeroDouble(&segundoOperando,"Indique el segundo operando","Fuera de rango permitido",MINIMO,MAXIMO,3)==0)
						{
							printf("\nCarga Exitosa de segundo operando");
						}
						else
						{
							printf("\nError en la carga de segundo operando");
						}

					break;

				case 3:
						if(sumar(primerOperando,segundoOperando,&resultadoSuma)==0)
						{
							printf("\nEl resultado de la suma es: %.2f",resultadoSuma);
						}
						else
						{
							printf("\nError en la suma");
						}

					break;

				case 4:
						if(restar(primerOperando,segundoOperando,&resultadoResta)==0)
						{
							printf("\nEl resultado de la resta es: %.2f",resultadoResta);
						}
						else
						{
							printf("\nError en la resta");
						}

					break;

				case 5:
						if(dividir(primerOperando,segundoOperando,&resultadoDivision)==0 && segundoOperando !=0)
						{
							printf("\nEl resultado de la division es: %.6f",resultadoDivision);
						}
						else if (segundoOperando != 0)
						{
							printf("\nError en la division");
						}

					break;

				case 6:
						if(multiplicar(primerOperando,segundoOperando,&resultadoMultiplicacion)==0)
						{
							printf("\nEl resultado de la multiplicacion es: %.2f",resultadoMultiplicacion);
						}
						else
						{
							printf("\nError en la multiplicacion");
						}

					break;

				case 7:
						if(factorial(primerOperando,&resultadoFactorial1)==0 &&
								factorial(segundoOperando,&resultadoFactorial2)==0)
						{
							printf("\nEl factorial del primer operando es: %.2f",resultadoFactorial1);
							printf("\nEl factorial del segundo operando es: %.2f",resultadoFactorial2);
						}
						else
						{
							printf("\nError en factorial");
						}

					break;

				case 8:
						if(todasOperacionesJuntas(primerOperando,segundoOperando,&resultadoMultiplicacion,&resultadoSuma,&resultadoResta,
								&resultadoDivision,&resultadoFactorial1,&resultadoFactorial2)==0)
						{
							printf("\nEl resultado de la suma es: %.2f",resultadoSuma);
							printf("\nEl resultado de la resta es: %.2f",resultadoResta);
							printf("\nEl resultado de la multiplicacion es: %.2f",resultadoMultiplicacion);
							if(segundoOperando !=0)
							{
								printf("\nEl resultado de la division es: %.6f",resultadoDivision);
							}
							printf("\nEl factorial del primer operando es: %.2f",resultadoFactorial1);
							printf("\nEl factorial del segundo operando es: %.2f",resultadoFactorial2);

						}
						else
						{
							printf("\nError al realizar las operaciones");
						}

					break;
			}

		}



	}while(option!=9);

	return EXIT_SUCCESS;
}
