/***** Captura de Tiempos ***********
Autor: Andrés Pérez
Fecha: 27 febrero 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Fichero: Interfaz de Biblioteca de Funciones <menú>
*************************************/

#ifndef __BIBLIO__H__
#define __BIBLIO__H__

/*Se reserva un tamaño de memoria gigante */
#define DataSize (1024 * 1024 * 64 * 8)

/*Se crea el espacio de memoria con tipo double*/
static double MEM_CHUNK[DataSize];

/*Funcion de incialización de Matrices*/
void Matriz_Init(int T, double *a, double *b, double *c);
/*Funcion de incialización de Matriz en 0*/
void Matriz_Init0(int T, double *a);
/* Función de multiplicar matrices */
double * multiplicarMatrices(int T, double *a, double *b, double *c) ;
/* Función para imprimir matriz */
void imprimirMatriz(int SZ, double *Ma);

#endif
