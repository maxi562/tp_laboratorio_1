/*
 * utn.h
 *
 *  Created on: 30 ago. 2020
 *      Author: maximiliano
 */

#ifndef UTN_H_
#define UTN_H_
#define MIN -2147483648
#define MAX	 2147483647
int utn_getNumero(int* pResultado,double primerOperando,double segundoOperando,int minimo,int maximo,int reintentos);
int utn_getNumeroDouble(double * pResultado,char* mensaje,char* mensajeError,double  minimo,double  maximo,double  reintentos);
int sumar (double  primerNumero,double  segundoNumero, double * resultado);
int restar (double  primerNumero,double  segundoNumero, double * resultado);
int dividir (double  primerNumero,double  segundoNumero, double* resultado);
int multiplicar (double  primerNumero,double  segundoNumero, double * resultado);
int factorial (double numero,double* resultado);
int todasOperacionesJuntas(double primerNumero,double segundoNumero,double* resultadoMultiplicacion,
						   double* resultadoSuma,double*resultadoResta,double* resultadoDivision,
						   double* resultadoPrimerFactorial, double* resultadoSegundoFactorial);

#endif /* UTN_H_ */
