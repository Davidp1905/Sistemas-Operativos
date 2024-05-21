#ifndef __MODULO_H__
#define __MODULO_H__

// Estructura de datos que encapsula los datos de las matrices a multiplicar
struct Datos_MM{
  int N; // Tamaño de las matrices 
  int Th; // Número de threads
  int IDHilo; // Id del hilo
  double *mA; // Matriz A
  double *mB; // Matriz B
  double *mC; // Matriz C que almacena el resultado de la multiplicación entre matrices A y B
};

// Función parar inicializar las matrices
void init_matrices(int n, double *m1, double *m2, double *m3);

// Función para imprimir matrices solo si el tamaño N es menor a 10
void impr_matrices(int n, double *matriz);

// Función para multiplicar matrices con algoritmo clásico de multiplicación de matrices
void * multi_matrices(void *argMM);

#endif
