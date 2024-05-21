/**********************************
Autor: Andrés Pérez
Fecha: Abril 2 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Procesamiento paralelo
Objetivo: Crear una aplicación que use el algoritmo de multiplicación de
matrices clásica (filas por columnas). La aplicación presentará diversos pasos
como metodología para la implementación de un algoritmo. La implementación se
hará para matrices cuadradas, es decir, el número de filas = columnas

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
*************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define RESERVA (1024 * 128 * 64 * 8)

static double MEM_CHUNK[RESERVA];

int main(int argc, char *argv[]) { 
  printf("Hola que tal (^ - ^ ) \n"); 
  if (argc < 1) {
    printf("\nArgumentos de entrada:\n");
    printf("\n\t $./exe Dim Hilos\n");
    return -1;
  }

  int N = (int)atof(argv[1]);
  int Th = (int)atof(argv[2]);

  if (N <1) {
    printf("\nDimensión matriz incorrecta:\n");
    printf("Debe ser mayor que cero\n");
    return -1;
  }

  double *mA, *mB, *mC;
  mA = MEM_CHUNK;
  mB = mA + N*N;
  mC = mB + N*N;

  for(int i = 0; i < N*N; i++){
    mA[i] = i*1.1;
    mC[i] = i*2.2;
    mA[i] = i;
  }
  for(int i = 0; i < N*N; i++){
    if(i%N == 0)
      printf("\n");
    printf(" %f ", mA[i]);
  }


  printf("\n\n\nFin del programa\n");
return 0;
}

// gcc -o exe mm_v1.c