/***** Captura de Tiempos ***********
Autor: Andrés Pérez
Fecha: 6 febrero 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Captura de tiempo de algoritmos
        - Multiplicación de Matrices
        - Creación de Makefile (compilación automatizada)
Fichero: fichero principal que llama a la biblioteca artesanal construida
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "biblio1.h"

#define SZ 6

int main() {
  int matriz01[SZ][SZ];
  int matriz02[SZ][SZ];
  crearMatriz(matriz01);
  crearMatriz(matriz02);
  
  printf("Matriz 1: \n");
  impresionMatriz(matriz01);

  printf("Matriz 2: \n");
  impresionMatriz(matriz02);
  
  multiplicarMatrices(matriz01, matriz02);

  return 0;
}
