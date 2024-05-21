/***** Apuntadores ***********
Autor: Andrés Pérez
Fecha: 20 febrero 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Reserva de memoria y trabajo de punteros
Fichero: principal
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

/*Se reserva un tamaño de memoria gigante */
#define DataSize (1024 * 1024 * 64 * 8)

/*Se crea el espacio de memoria con tipo double*/
static double MEM_CHUNK[DataSize];

/*Funcion de incialización de Matrices*/
void Matriz_Init(int T, double *a, double *b, double *c) {
  for (int i = 0; i < T * T; i++) {
    a[i] = 2.0 + i;
    b[i] = 1.0 + i;
    c[i] = 0.0;
  }
}
/*Funcion de incialización de Matriz en 0*/
void Matriz_Init0(int T, double *a) {
  for (int i = 0; i < T * T; i++) {
    a[i] = 0.0;
  }
}
/* Función de multiplicar matrices */
double * multiplicarMatrices(int T, double *a, double *b, double *c) {
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            for (int k = 0; k < T; k++) {
                c[i + j * T] += a[i + k * T] * b[k + j * T];
            }
        }
    }
  return c;
}
/* Función para imprimir matriz */
void imprimirMatriz(int SZ, double *Ma){
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      printf(" %.0f", Ma[i + j * SZ]);
    }
    printf("\n");
  }
}



// gcc main.c -o exe
