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

// Se hace una reserva de memoria de tamaño definido
#define RESERVA (1024 * 128 * 64 * 8)

// Se asigna esa reserva de memoria para las variables de tipo double
static double MEM_CHUNK[RESERVA];

// Estructura de datos que encapsula los datos de las matrices a multiplicar
struct Datos_MM{
// Tamaño de las matrices 
  int N;
// Número de threads
  int Th;
// Id del hilo
  int IDHilo;
// Matriz A
  double *mA;
// Matriz B
  double *mB;
// Matriz C que almacena el resultado de la multiplicación entre matrices A y B
  double *mC;
};

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

// main del programa
int main(int argc, char *argv[]) { 
  printf("Hola que tal (^ - ^ ), este es un programa para multiplicar matrices  \n"); 

  //  Se valida que los argumentos de entrada sean suficientes 
  if (argc <= 2) {
    printf("\nArgumentos de entrada:\n");
    printf("\n\t $./exe Dim Hilos\n");
    return -1;
  }
  // Se crea una variable N para el tamaño de las matrices 
  int N = (int)atof(argv[1]);

  // Se crea una variable Th para el número de threads
  int Th = (int)atof(argv[2]);

  // Se valida las dimensiones de la matriz que sean mayores que cero
  if (N < 1) {
    printf("\nDimensión matriz incorrecta:\n");
    printf("Debe ser mayor que cero\n");
    return -1;
  }
  // Se valida que el número de hilos sea válido
  if (Th < 1 || Th > 4) {
    printf("\nNúmero de hilos incorrecto:\n");
    printf("Debe ser mayor que cero y menor que el número de cores que usted tenga en su maquina.\nEn este ejemplo el maximo es 4\n");
    return -1;
  }
  // Se crean punteros para las matrices
  double *mA, *mB, *mC;

  // Se apunta a la reserva de memoria las matrices NxN, es decir, se les asigna un tamaño a cada matriz y su respectivo apuntador apunta a donde comienza la matriz
  mA = MEM_CHUNK;
  mB = mA + N*N;
  mC = mB + N*N;

  // Se crea el vector de hilos
  pthread_t vectorHilo[Th];

  // Se llama a la función que inicialice las matrices
  init_matrices(N, mA, mB, mC);

  // Se imprimen las matrices a multiplicar 
  printf("\nMatriz A:\n");
  impr_matrices(N, mA);
  printf("Matriz B:\n");
  impr_matrices(N, mB);

  // Se inicializa una estructura de datos que almacena la información de las matrices a multiplicar y se llama encValores
  struct Datos_MM *encValores = (struct Datos_MM *)malloc(sizeof(struct Datos_MM));

  // Se asignan la información de las matrices a la estructura creada encValores
  encValores->N = N;
  encValores->mA = mA;
  encValores->mB = mB;
  encValores->mC = mC;
  encValores->Th = Th; 

// For que inicializa y crea varios hilos, cada uno con su propia estructura de datos que contiene punteros a las matrices y otra información relevante.
  for (int i = 0; i < Th; i++) {
    encValores[i].N = N;
    encValores[i].Th = Th;
    encValores[i].IDHilo = i;
    encValores[i].mA = mA;
    encValores[i].mB = mB;
    encValores[i].mC = mC;
    pthread_create(&vectorHilo[i], NULL, multi_matrices, (void *)&encValores[i]);
  }


  // Para cada identificador del hilo
  for(int iDh = 0; iDh< Th; iDh++){
    //Join para esperar a que un hilo termine su ejecución
    pthread_join(vectorHilo[iDh], NULL);
  }


  // Se llama a la función de multiplicar matrices enviándole encValores
 // multi_matrices(encValores);

  // Se imprime el resultado de la multiplicación de matrices
  printf("\n----------------------------------------------\n");
  printf("Matriz Resultado:\n");
  impr_matrices(N, encValores->mC);

  //Finalización de hilo
  pthread_exit(NULL);

  printf("\n\n\nFin del programa\n\n");
  // Se acaba el programa
return 0;
}

// Comando para compilar:
// gcc -o exe mm_v6.c
