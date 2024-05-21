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
 -Funciones (programación modular)
    -Inicializar
    -Imprimir (solo si N < 10)
*************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define RESERVA (1024 * 128 * 64 * 8)

static double MEM_CHUNK[RESERVA];

//Función parar inicializar las matrices
void init_matrices(int n, double *m1, double *m2, double *m3){
  for(int i = 0; i < n*n; i++){
    m1[i] = i*1.1;
    m2[i] = i*2.2;
    m3[i] = i;
  }
}

//Función para imprimir matrices
void impr_matrices(int n, double *matriz){
  if(n < 10){
    for(int i = 0; i < n*n; i++){
    if(i%n == 0) printf("\n");
    printf(" %f ", matriz[i]);
    }
    printf("\n----------------------------------------------\n");
  } else  {
    printf("\n----------------------------------------------\n");
  } 

}

int main(int argc, char *argv[]) { 
  printf("Hola que tal (^ - ^ ) \n"); 
  if (argc < 1) {
    printf("\nArgumentos de entrada:\n");
    printf("\n\t $./exe Dim Hilos\n");
    return -1;
  }

  int N = (int)atof(argv[1]);
  int Th = (int)atof(argv[2]);

  if (N < 1) {
    printf("\nDimensión matriz incorrecta:\n");
    printf("Debe ser mayor que cero\n");
    return -1;
  }

  double *mA, *mB, *mC;
  mA = MEM_CHUNK;
  mB = mA + N*N;
  mC = mB + N*N;

  init_matrices(N, mA, mB, mC);
  
  impr_matrices(N, mA);
  impr_matrices(N, mB);
  impr_matrices(N, mC);

  printf("\n\n\nFin del programa\n");
return 0;
}

// gcc -o exe mm_v2.c