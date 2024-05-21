/*******************************************************
Autor: Andrés Pérez
Fecha: Abril 2 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Procesamiento paralelo
Objetivo: Crear una aplicación que use el algoritmo de multiplicación de matrices clásica (filas por columnas). 
La aplicación presentará diversos pasos como metodología para la implementación de un algoritmo. 
La implementación se hará para matrices cuadradas, es decir, el número de filas es igual al número de columnas

A continuación se presentan las diferentes etapas:
 -Reserva de memoria
 -Se crea el main para ingreso de argumentos de entrada
     -Arg1 dimensión matriz (NxN)
     -Arg2 cantidad de hilos.
 -Validar los argumentos de entrada 
 -Crear punteros para matrices
 -Apuntar a la reserva de memoria las matrices NxN
 -Inicialzar las matrices
 -Impresión de matrices
 -Funciones (programación modular)
    -Inicializar
    -Imprimir (solo si N < 10)
  -Algoritmo Clásico Multiplicación Matrices con Hilos
  -Estructura de datos que encapsule datos
      -N, Th y las matrices
      -Se crea una variable de tipo struct creado
      -Se asigna valores
  -Se crean los hilos para realizar la multiplicación
  -Se espera a que los hilos terminen su ejecución 
********************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "modulo.h"


// Función parar inicializar las matrices
void init_matrices(int n, double *m1, double *m2, double *m3){
  for(int i = 0; i < n*n; i++){
    m1[i] = i*1.1;
    m2[i] = i*2.2;
    m3[i] = i;
  }
}

// Función para imprimir matrices solo si el tamaño N es menor a 10
void impr_matrices(int n, double *matriz){
  if(n < 10){
    for(int i = 0; i < n*n; i++){
    //Hace un salto de línea cada vez que se llega a una nueva fila
    if(i%n == 0) printf("\n");
    printf(" %10.2f ", matriz[i]);
    }
    printf("\n----------------------------------------------\n");
  } else  {
    printf("\n----------------------------------------------\n");
  } 
}

// Función para multiplicar matrices con algoritmo clásico de multiplicación de matrices
void * multi_matrices(void *argMM){
  // Se convierte el argumento genérico a un puntero de tipo struct Datos_MM
  struct Datos_MM *val = (struct Datos_MM *)argMM;
  // ID del hilo
  int hilo = val->IDHilo; 
  // Se extrae la dimensión de la matriz
  int n = val->N;
  // Cantidad de hilos
  int NumH = val->Th; 
  // Se obtienen punteros a las matrices de entrada y salida
  double *m1 = val->mA; // Matriz A
  double *m2 = val->mB; // Matriz B
  double *m3 = val->mC; // Matriz resultante
  int init = hilo * n / NumH; // Se calcula donde debe iniciar cada hilo
  int fin = (hilo + 1) * n / NumH; // Se calcula donde debe terminar cada hilo

  // Bucle para recorrer las filas de la matriz resultante
  for(int i = init; i < fin; i++){
    // Bucle para recorrer las columnas de la matriz resultante
    for(int j = 0; j < n; j++){
      double SumTemp, *pA, *pB;
      SumTemp = 0.0;
      // Se obtiene un puntero a la fila i de la matriz A
      pA = m1 + i*n;
      // Se obtiene un puntero a la columna j de la matriz B
      pB = m2 + j;
      // Bucle para calcular el valor de la celda (i, j) de la matriz resultante
      for(int k = 0; k < n; k++, pA++, pB+=n){
        // Se calcula el producto acumulativo de los elementos de la fila i de A y la columna j de B
        SumTemp += *pA * *pB;
      }
      // Se asigna el valor calculado a la celda (i, j) de la matriz resultante
      m3[i*n+j] = SumTemp;
    }
  }
  pthread_exit(NULL);
}

// Comando para compilar:
// gcc -o exe mm_v6.c
