/***** Captura de Tiempos ***********
Autor: Andrés Pérez
Fecha: 5 marzo de 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Retos clase 6
      -Memoria dinámica
      -Punteros
*************************************/

#include "biblio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#define size 10;

void reto1() {
  char *p = malloc(100);
  char *q = NULL;
  printf("Función de reto 1 memoria dinámica: \n\n");
  printf("Address of p = %p\n", (void *)p);
  strcpy(p, "Hello, I'm the best in Operating Systems!!!");
  printf("%s\n", p);
  printf("About to copy \"Goodbye\" to q\n");
  q = realloc(q, 100 * sizeof(int));
  strcpy(q, "Goodbye");
  printf("String copied\n");
  printf("%s\n", q);

  printf("\nFin reto 1 memoria dinámica\n\n");
  free(q);
  free(p);
}
void reto2() {
  char *q = NULL;

  printf("\nFunción de reto 2 memoria dinámica: \n\n");
  printf("Requesting space for \"Goodbye\" \n");
  q = (char *)malloc(strlen("Goodbye") + 1);
  if (!q) {
    perror("Failed to allocate space because");
    exit(1);
  }
  printf("About to copy \"Goodbye\" to q at address %s \n", q);
  strcpy(q, "Goodbye");
  printf("String copied\n");
  printf("%s \n", q);
  printf("\nFin reto 2 memoria dinámica\n");
}

void reto3() {
  printf("\nFunción de reto 3 memoria dinámica: \n\n");
  int *ptr;
  ptr = malloc(15 * sizeof(*ptr)); /* a block of 15 integers */

  if (ptr != NULL) {
    *(ptr + 5) = 480; /* assign 480 to sixth integer */
  }
  printf("Value of the 6th integer is %d \n ", *(ptr + 5));
  printf("\nFin reto 3 memoria dinámica\n\n");
}

void reto4() {
  printf("\nFunción de reto 4 memoria dinámica sumar números: \n\n");
  int n, i, j, *ptr, sum = 0;
  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1) {
    printf("Error reading input.\n");
    exit(EXIT_FAILURE);
  }
  ptr = (int *)calloc(n, sizeof(int));
  if (ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }

  for (i = 0; i < n; ++i) {
    printf("Enter elements %d: ", i + 1);
    if (scanf("%d", ptr + j) != 1) {
      printf("Error reading input.\n");
      exit(EXIT_FAILURE);
    }
    sum += *(ptr + j);
  }
  printf("Sum = %d", sum);
  free(ptr);
  printf("\nFin reto 4 memoria dinámica\n\n");
}

void reto5() {
  printf("\nFunción de reto 5 memoria dinámica cambiar tamaño de puntero: \n\n");
  int *ptr, i, n1, n2;
  printf("Enter size: ");
  if (scanf("%d", &n1) != 1) {
    printf("Error reading input.\n");
    exit(EXIT_FAILURE);
  }
  ptr = (int *)malloc(n1 * sizeof(int));
  printf("Addresses of previously allocated memory: ");
  for (i = 0; i < n1; ++i)
    printf("\n\np = %p\n", ptr + i);
  printf("\n Enter the new size: ");
  if (scanf("%d", &n2) != 1) {
    printf("Error reading input.\n");
    exit(EXIT_FAILURE);
  }
  // rellocating the memory
  ptr = realloc(ptr, n2 * sizeof(int));
  printf("Addresses of newly allocated memory: ");
  for (i = 0; i < n2; ++i)
    printf("\n\np = %p\n", ptr + i);
  printf("\nFin reto 5 memoria dinámica\n\n");
  free(ptr);
}

char *reto6(char *p) {

  char *q = malloc(strlen(p) + 1);
  strcpy(q, p);
  printf("From q: the string is %s\n", q);
  return q;
}

void retoPuntero1() {

  printf("Función de reto 1, punteros: \n\n");
  int variable = 123;
  int *ptr = &variable;
  printf("Valor de la Variable %d \n", variable);
  printf("Dirección de memoria de la Variable %p\n", &variable);
  printf("Dirección a la que apunta el puntero %p \n", (void *)ptr);
  printf("Valor de la Variable %i \n", *ptr);
  printf("Fin reto 1, punteros \n\n");
}

void retoPuntero2() {
  printf("Función de reto 2, punteros: \n\n");

  int *vectorPunteros[3];      //--> vector de punteros de tipo int
  int p = 40, q = 80, r = 120; //--> variables tipo entero
  vectorPunteros[0] = &p;      //--> Apuntar a la dirección de p;
  vectorPunteros[1] = &q;      //--> Apuntar a la dirección de q;
  vectorPunteros[2] = &r;      //--> Apuntar a la dirección de r;
  printf("\nForma de acceso al vector de punteros: \n");
  for (int i = 0; i < 3; i++) {
    printf("Para la dirección: %p \t el valor - %d\n", vectorPunteros[i],
           *vectorPunteros[i]);
    printf("Fin reto 2, punteros \n\n");
  }
}

void retoPuntero3() {
  printf("Función de reto 3, punteros: \n\n");
  /******* Suma de dos valores ingresados por pantalla usando punteros *****/
  int valor1, valor2; //--> variables de tipo entero
  int *ptrV1, *ptrV2; //--> punteros de tipo entero
  ptrV1 = &valor1; //-->  apunte a la variable
  ptrV2 = &valor2; //-→> apunte a la variable 
  
  
  printf("\nIngrese dos valores a ser sumados \n");
  if(scanf("%d %d", &valor1, &valor2) != 1)
  printf("AnLa suma es = %d\n", *ptrV1+*ptrV2);

  printf("Fin reto 3, punteros \n\n");
}
void retoPuntero4() {
  printf("Función de reto 4, punteros: \n\n");
  /******** Suma de dos valores, ingresados por pantalla usando punteros *****/ 
  int vector[] = {40, 80, 120, 230};  //--> vector de enteros e inicializado
  int *ptrV1;  //--> puntero de tipo entero
  ptrV1 = vector;   //--> apunte a primera posición del vector
  printf("\n Impresión por Indices \n");
  printf("-------------\n");
  for(int i=0; i<4; i++){
    printf("Por Indices: El valor del vector[%d] = %d\n", i, ptrV1[i]);
  }
  printf("\n Impresión por Sucesor (puntero)\n");
  printf("-------------\n");
  for(int i=0; i<4; i++){
    printf("Por Sucesor: El valor del vector[%d] = %d\n", i, *ptrV1);
    ptrV1++; //--> Apunta a la siguiente posición
  }

  printf("Fin reto 4, punteros \n\n");
}
void retoPuntero5() {
  printf("Función de reto 5, punteros: \n\n");
  int var = 480;
  int *varptr = &var;
  int **doubleptr = &varptr;
  printf("Valor de la Variable \t\t= %d\n", var );
  printf("Valor del puntero \t\t\t= %d\n", *varptr);
  printf( "Valor del puntero doble \t= %d\n", **doubleptr);

  printf("Dirección de la Variable \t= %p\n", &var );

  printf("Dirección del puntero \t\t= %p\n", &varptr );
  printf("Valor en el puntero \t\t= %p\n", varptr );

  printf("Dirección del puntero doble = %p \n", *doubleptr);
  printf("Valor en el puntero doble \t= %p\n", doubleptr);
  printf("Fin reto 5, punteros \n\n");
}

void retoPuntero6(char ** argv){
  printf("Función de reto 6, punteros: \n\n");
  int rows, cols, i, j; 
  int **matrix;

  rows = (int) atof(argv[1]);
  cols = (int) atof(argv[2]);
  // Asignación de Memoria para la Matriz
  matrix = (int **)malloc(rows*sizeof(int *));
  for (i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }
  // Llenado de matriz con valores iniciales
  for (i = 0; i < rows; i++){
    for (j = 0; j < cols; j++){
      matrix[i][j] = i * j;
    }
  }
  // Impresión de Matriz
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++){
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }

  // Liberación o entrega de memoria al SO
  for (i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
  printf("Fin reto 6, punteros \n\n");
}