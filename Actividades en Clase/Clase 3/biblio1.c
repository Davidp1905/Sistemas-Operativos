/***** Captura de Tiempos ***********
Autor: Andrés Pérez
Fecha: 6 febrero 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Captura de tiempo de algoritmos
        - Multiplicación de Matrices
        - Creación de Makefile (compilación automatizada)
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "biblio1.h"

#define SZ 6
// Estructuras de datos de tipo timeval
struct timeval start, stop;
// Función que asigna el tiempo a start
void inicio_tiempo() { gettimeofday(&start, NULL); }
// Función que asigna el tiempo a stop, calcula el tiempo transcurrido y lo imprime
void fin_tiempo() {
  gettimeofday(&stop, NULL);
  stop.tv_sec -= start.tv_sec;
  printf("%9.0f µs\n", (double)(stop.tv_sec * 1000000 + stop.tv_usec)); //9 espacios
}
// Función para imprimir la matriz
void impresionMatriz(int M[SZ][SZ]) {
  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      printf(" %d ", M[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}
//Función de inicialización de matriz
void crearMatriz(int matriz01[SZ][SZ]){
  srand(time(NULL)); //Semilla para generar números aleatorios con la aleatoriedad más grande posible
  //int matriz01[SZ][SZ];

  for (int i = 0; i < SZ; i++) {
    for (int j = 0; j < SZ; j++) {
      matriz01[i][j] = 1 + rand() % 7;
    }
  }
}

//Función para multiplicar matrices
void multiplicarMatrices(int matriz1[SZ][SZ], int matriz2[SZ][SZ]){
  int matriz3[SZ][SZ] = {0};
  
  for(int i = 0; i < SZ; i++){
    for(int j = 0 ; j < SZ; j++){
       for(int k = 0; k < SZ; k++){
          matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }
  printf("Matriz resultado:\n");
  impresionMatriz(matriz3);
}
