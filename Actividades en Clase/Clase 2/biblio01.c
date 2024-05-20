/* Fecha: 30 enero 2024
 * Autor: Andres Perez
 * Tema: Introducción al Lenguaje de Programación C
 * Topico: Compilación por separado   
 * Materia: Sistemas Operativos
 */

#include <stdio.h>
#include "biblio01.h"

/* Función para imprimir una matriz*/
void funcionImprimir(int col, int fil){

  printf("**** Impresión de matriz ****\n");
  for(int i = 0; i < col; i++){
    for(int j = 0; j < fil; j++){
      printf(" %i ", i+j);
    }
    printf("\n");
  }
  printf("************************\n");

}
/*Función para sumar 2 números enteros*/
int sumaEnteros(int a, int b){
  return a + b;
}
/*Función para calcular un exponente*/
double exponente(double base, int exp){
  double resultado = 1;
  if(exp == 0){
    return resultado;
  }
  for(int i = 0; i < exp; i++){
    resultado = resultado * base;
  }
  return resultado;
}
/*Función para el área de un rectángulo*/
double areaRectangulo(double a, double b){
  return a * b;
}
/*Función para el área de un círculo*/
double areaCirculo(double radio){
  return 3.1416 * radio * radio;
}
