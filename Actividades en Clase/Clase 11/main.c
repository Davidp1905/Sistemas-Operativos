#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define RESERVA (1024 * 128 * 64 * 8)

static double MEM_CHUNK[RESERVA];

struct Datos_MM {
  int N;
  int Th;
  int IDHilo;
  double *mA;
  double *mB;
  double *mC;
};

void init_matrices(int n, double *m1, double *m2, double *m3) {
  for (int i = 0; i < n * n; i++) {
    m1[i] = i * 1.1;
    m2[i] = i * 2.2;
    m3[i] = i;
  }
}

void impr_matrices(int n, double *matriz) {
  if (n < 10) {
    for (int i = 0; i < n * n; i++) {
      if (i % n == 0)
        printf("\n");
      printf(" %10.2f ", matriz[i]);
    }
    printf("\n----------------------------------------------\n");
  } else {
    printf("\n----------------------------------------------\n");
  }
}

void *multi_matrices(void *argMM) {
  struct Datos_MM *val = (struct Datos_MM *)argMM;
  int n = val->N;
  int hilo = val->IDHilo;
  int NumH = val->Th;
  double *m1 = val->mA;
  double *m2 = val->mB;
  double *m3 = val->mC;

  for (int i = hilo * n / NumH; i < (hilo + 1) * n / NumH; i++) {
    for (int j = 0; j < n; j++) {
      double SumTemp, *pA, *pB;
      SumTemp = 0.0;
      pA = m1 + i * n;
      pB = m2 + j;
      for (int k = 0; k < n; k++, pA++, pB += n) {
        SumTemp += *pA * *pB;
      }
      m3[i * n + j] = SumTemp;
    }
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  printf("Hola que tal (^ - ^ ), este es un programa para multiplicar matrices\n");

  if (argc <= 2) {
    printf("\nArgumentos de entrada:\n");
    printf("\n\t $./exe Dim Hilos\n");
    return -1;
  }

  int N = atoi(argv[1]);
  int Th = atoi(argv[2]);

  if (N < 1) {
    printf("\nDimensión matriz incorrecta:\n");
    printf("Debe ser mayor que cero\n");
    return -1;
  }

  double *mA, *mB, *mC;
  pthread_t vectorHilo[Th];

  mA = MEM_CHUNK;
  mB = mA + N * N;
  mC = mB + N * N;

  init_matrices(N, mA, mB, mC);

  printf("\nMatriz A:\n");
  impr_matrices(N, mA);
  printf("Matriz B:\n");
  impr_matrices(N, mB);

  struct Datos_MM datosHilos[Th];

  for (int i = 0; i < Th; i++) {
    datosHilos[i].N = N;
    datosHilos[i].Th = Th;
    datosHilos[i].IDHilo = i;
    datosHilos[i].mA = mA;
    datosHilos[i].mB = mB;
    datosHilos[i].mC = mC;
    pthread_create(&vectorHilo[i], NULL, multi_matrices, (void *)&datosHilos[i]);
  }

  for (int i = 0; i < Th; i++) {
    pthread_join(vectorHilo[i], NULL);
  }

  printf("\n----------------------------------------------\n");
  printf("Matriz Resultado:\n");
  impr_matrices(N, mC);

  printf("\n\n\nFin del programa\n");
  return 0;
}
