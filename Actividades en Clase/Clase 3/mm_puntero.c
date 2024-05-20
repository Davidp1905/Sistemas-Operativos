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
/** Llenar las matrices **/

int main(int argc, char *argv[]) {
  int SZ, i, j, k;
  if (argc > 1) {
    SZ = (int)atoi(argv[1]);
  } else {
    printf("Ingreso de parametros erroneo: \n");
    printf("$./ejecutable SizeMatriz\n");
    return -1;
  }
  printf("Matriz[%d][%d]  \n", SZ, SZ);

  /** Declarar las matricas (solo los apuntadores)**/
  double *Ma, *Mb, *Mc;

  /** Apuntamos al espacio de memoria de tamaño SZ*SZ **/
  Ma = MEM_CHUNK;
  Mb = Ma + SZ * SZ;
  Mc = Mb + SZ * SZ;

  Matriz_Init(SZ, Ma, Mb, Mc);
  
  /** Se imprime la matriz**/
  for (i = 0; i < SZ; i++) {
    for (j = 0; j < SZ; j++) {
      printf(" %f", Ma[i + j * SZ]);
    }
    printf("\n");
  }

  return 0;
}

// gcc main.c -o exe
