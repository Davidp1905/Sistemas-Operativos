/***** Captura de Tiempos ***********
Autor: Andrés Pérez
Fecha: 27 febrero 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Captura de tiempo de algoritmos
        - Multiplicación de Matrices
        - Creación de Makefile (compilación automatizada)
Fichero: Interfaz de Biblioteca de Funciones <menú>
*************************************/
#ifndef __BIBLIO1__H__
#define __BIBLIO1__H__
#define SZ 6

// Función que asigna el tiempo a start
void inicio_tiempo();

// Función que asigna el tiempo a stop, calcula el tiempo transcurrido y lo imprime
void fin_tiempo();

// Función para imprimir la matriz
void impresionMatriz(int M[SZ][SZ]);

//Función de inicialización de matriz
void crearMatriz(int matriz01[SZ][SZ]);

//Función para multiplicar matrices
void multiplicarMatrices(int matriz1[SZ][SZ], int matriz2[SZ][SZ]);


#endif