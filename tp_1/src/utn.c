/*
 * utn.c
 *
 *  Created on: 30 ago. 2020
 *      Author: maximiliano
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define MN -2147483600
#define MX	 2147483600

/**
	 * \brief La función toma un número indicado por el usuario y lo guarda en el puntero resultado. Además muestra los
	 	 	  dos operandos en pantalla.
	 * \param pResultado: en este puntero la función guarda el número que indica el usuario
	 * \param minimo: es el numero minimo posible que puede indicar el usuario
	 * \param maximo: es el numero maximo posible que puede indicar el usuario
	 * \param reintentos: es el numero maximo posible de reintentos que tiene el usuario si indica un numero fuera del rango mínimo - máximo
	 * \param bufferInt: es la variable auxiliar que se utiliza para interactuar con el usuario
	 * \return esta función retorna -1 si la función no se concreta y devuelve un 0 si todo se ejecuta correctamente
	 */
int utn_getNumero(int* pResultado,double primerOperando,double segundoOperando,int minimo,int maximo,int reintentos)
{
		int retorno = -1;
		int bufferInt;

		if(pResultado != NULL && minimo <= maximo && reintentos >=0)
		{
			do{
				printf("\n1.Ingresar primer operando\t%.2f"
					   "\n2.Ingresar segundo operando\t%.2f"
					   "\n3.Calcular la suma"
					   "\n4.Calcular la resta"
					   "\n5.Calcular la division"
					   "\n6.Calcular la multiplicacion"
					   "\n7.Calcular factorial"
					   "\n8.Calcular todas las operaciones"
					   "\n9.Salir",primerOperando,segundoOperando);
				__fpurge(stdin);
				scanf("%d",&bufferInt);

				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;

				}
				else {
					printf("\nOpcion incorrecta");
					reintentos--;
				}

			}while(reintentos>= 0);


		}
		else
		{
			printf("\nReintentos agotados. vuelva a iniciar");
		}

		return retorno;

}
/**
	 * \brief La función toma un número indicado por el usuario y lo guarda en el puntero resultado
	 * \param pResultado: en este puntero la función guarda el número que indica el usuario
	 * \param mensaje: es el mensaje que se muestra por pantalla al usuario
	 * \param mensajeError: en el caso de que el usuario elija una opcion incorrecta, se muestra este mensaje
	 * \param minimo: es el numero minimo posible que puede indicar el usuario
	 * \param maximo: es el numero maximo posible que puede indicar el usuario
	 * \param reintentos: es el numero maximo posible de reintentos que tiene el usuario si indica un numero fuera del rango mínimo - máximo
	 * \param bufferInt: es la variable auxiliar que se utiliza para interactuar con el usuario
	 * \return esta función retorna -1 si la función no se concreta y devuelve un 0 si todo se ejecuta correctamente
	 */
int utn_getNumeroDouble(double * pResultado,char* mensaje,char* mensajeError,double  minimo,double  maximo,double  reintentos)
{
	int retorno = -1;
	double  bufferInt;

			if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
			{
				printf("%s",mensaje);
				__fpurge(stdin);
				scanf("%lf",&bufferInt);

				do{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;

				}
				else {
					printf("%s",mensajeError);
					reintentos--;
				}

				}while(reintentos>= 0);


			}

			return retorno;

}
/**
 * brief\ La Funcion suma dos numeros del tipo double y devuelve el resultado a traves del puntero
 * param\ primerNumero: es un numero pasado por valor a la funcion
 * param\ segundoNumero: es un numero pasado por valor a la funcion
 * param\ resultado: es el puntero donde se guardará el resultado de la operación
 * return esta función retorna -1 si la función no se concreta y devuelve un 0 si todo se ejecuta correctamente
 */
int sumar (double  primerNumero,double  segundoNumero, double * resultado)
{
	int retorno = -1;

	if(primerNumero>= MN && primerNumero <= MX && segundoNumero>= MN && segundoNumero <= MX )
	{
		*resultado = primerNumero + segundoNumero;
	}
	if(*resultado>= MN && *resultado <= MX )
	{
		retorno=0;
	}

	return retorno;
}
/**
 * brief\ La Funcion resta dos numeros del tipo double y devuelve el resultado a traves del puntero
 * param\ primerNumero: es un numero pasado por valor a la funcion
 * param\ segundoNumero: es un numero pasado por valor a la funcion
 * param\ resultado: es el puntero donde se guardará el resultado de la operación
 * return esta función retorna -1 si la función no se concreta y devuelve un 0 si todo se ejecuta correctamente
 */
int restar (double  primerNumero,double  segundoNumero, double * resultado)
{
	int retorno = -1;

	if(primerNumero>= MN && primerNumero <= MX && segundoNumero>= MN && segundoNumero <= MX )
	{
		*resultado = primerNumero - segundoNumero;
	}
	if(*resultado>= MN && *resultado <= MX )
	{
		retorno=0;
	}

	return retorno;
}
/**
 * brief\ La Funcion divide dos numeros del tipo double y devuelve el resultado a traves del puntero
 * param\ primerNumero: es un numero pasado por valor a la funcion
 * param\ segundoNumero: es un numero pasado por valor a la funcion
 * param\ resultado: es el puntero donde se guardará el resultado de la operación
 * return esta función retorna -1 si la función no se concreta y devuelve un 0 si todo se ejecuta correctamente
 */
int dividir (double  primerNumero,double  segundoNumero, double* resultado)
{
	int retorno = -1;

	if(primerNumero>= MN && primerNumero <= MX && segundoNumero>= MN && segundoNumero <= MX && segundoNumero!=0)
	{
		*resultado = (double)primerNumero / segundoNumero;
	}
	else if(segundoNumero == 0)
	{
		printf("\nLa divisiòn por Cero (0) no es posible");
	}
	if(*resultado>= MN && *resultado <= MX )
	{
		retorno=0;
	}

	return retorno;
}
/**
 * brief\ La Funcion multiplica dos numeros del tipo double y devuelve el resultado a traves del puntero
 * param\ primerNumero: es un numero pasado por valor a la funcion
 * param\ segundoNumero: es un numero pasado por valor a la funcion
 * param\ resultado: es el puntero donde se guardará el resultado de la operación
 * return esta función retorna -1 si la función no se concreta y devuelve un 0 si todo se ejecuta correctamente
 */
int multiplicar (double  primerNumero,double  segundoNumero, double * resultado)
{
	int retorno = -1;

	if(primerNumero>= MN && primerNumero <= MX && segundoNumero>= MN && segundoNumero <= MX )
	{
		*resultado = primerNumero * segundoNumero;
	}
	if(*resultado>= MN && *resultado <= MX )
	{
		retorno=0;
	}

	return retorno;
}
/**
 * brief\ La Funcion ejecuta las operaciones de sumar, restar, dividir, multiplicar y factorial de 2 numeros distintos
 * 		  devolviendo los resultados de cada operacion a traves de un puntero
 * param\ primerNumero: es un numero pasado por valor a la funcion
 * param\ segundoNumero: es un numero pasado por valor a la funcion
 * param\ resultadoMultiplicacion: es el puntero donde se guardará el resultado de la multiplicacion
 * param\ resultadoSuma: es el puntero donde se guardará el resultado de la suma
 * param\ resultadoResta: es el puntero donde se guardará el resultado de la resta
 * param\ resultadoDivision: es el puntero donde se guardará el resultado de la division
 * param\ resultadoPrimerFactorial: es el puntero donde se guardará el resultado del factorial de primerNumero
 * param\ resultadoSegundoFactorial: es el puntero donde se guardará el resultado del factorial de segundoNumero
 * param\ resultado: es el puntero donde se guardará el resultado de la operación
 * param\ buffers: se utilizan para interactuar con las funciones, una vez verificado que cumplen con las condiciones
 * 			       se pasan como vàlidos a los punteros resultado de cada operación
 * return esta función retorna -1 si la función no se concreta y devuelve un 0 si todo se ejecuta correctamente
 */
int todasOperacionesJuntas(double primerNumero,double segundoNumero,double* resultadoMultiplicacion,
						   double* resultadoSuma,double*resultadoResta,double* resultadoDivision,
						   double* resultadoPrimerFactorial, double* resultadoSegundoFactorial)
{
	int retorno = -1;
	double bufferSuma;
	double bufferResta;
	double bufferMulti;
	double bufferDiv;
	double bufferFactorial1;
	double bufferFactorial2;
	if(primerNumero>= MN && primerNumero <= MX && segundoNumero>= MN && segundoNumero <= MX )
	{
		multiplicar(primerNumero,segundoNumero,&bufferMulti);
		sumar(primerNumero,segundoNumero,&bufferSuma);
		restar(primerNumero,segundoNumero,&bufferResta);
		dividir(primerNumero,segundoNumero,&bufferDiv);
		factorial(primerNumero,&bufferFactorial1);
		factorial(segundoNumero,&bufferFactorial2);
	}
	if(bufferDiv>=MN && bufferDiv <= MX && bufferMulti >= MN && bufferMulti <= MX && bufferResta >= MN && bufferResta <= MX &&
		bufferSuma>= MN && bufferSuma<= MX && bufferFactorial1 >= MN && bufferFactorial1 <= MX && bufferFactorial2 >=MN
		&& bufferFactorial2 <= MX)
	{
		retorno = 0;
		*resultadoDivision = bufferDiv;
		*resultadoMultiplicacion = bufferMulti;
		*resultadoResta = bufferResta;
		*resultadoSuma = bufferSuma;
		*resultadoPrimerFactorial = bufferFactorial1;
		*resultadoSegundoFactorial = bufferFactorial2;
	}

	return retorno;
}
/**
 * brief\ La Funcion realiza el factorial de un numero del tipo double y devuelve el resultado a traves del puntero
 * param\ numero: es un numero pasado por valor a la funcion
 * param\ resultado: es el puntero donde se guardará el resultado de la operación
 * param\ i: es la variable que inicializa el for
 * param\ factorial: variable auxiliar que se utiliza para calcular el factorial
 * return esta función retorna -1 si la función no se concreta y devuelve un 0 si todo se ejecuta correctamente
 */
int factorial (double numero,double* resultado)
{
	double i;
	double factorial;
	int retorno = -1;
	factorial = 1;

	if(numero==0)
	{
		*resultado = 1;
		retorno = 0;
	}
	else
	{
		for(i=1;i<=numero;i++)
		{
			factorial*=i;
		}

	}
	if(factorial>= MN && factorial <= MX )
	{
		*resultado = factorial;
		retorno=0;
	}

	return retorno;

}
