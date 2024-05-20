/* Fecha: 30 enero 2024
 * Autor: Andres Perez
 * Tema: Introducción al Lenguaje de Programación C
 * Topico: Compilación por separado   
 * Materia: Sistemas Operativos
 *Fichero: fichero principal que llama a la biblioteca artesanal construida
 */

#include <stdio.h>
#include "biblio01.h"

int main(void) {
  int columnas = 5;
  int filas = 5;
  int res1 = sumaEnteros(2,3);
  double res2 = exponente(7,4);
  double res3 = areaRectangulo(8,11);
  double res4 = areaCirculo(5);

  funcionImprimir(columnas, filas);
  printf("La suma de 2 + 3 = %i", res1);
  printf("\nEl resultado de 7 elevado a la 4 es: %f", res2);
  printf("\nEl area de unn rectángulo de base 8 y altura 11 es: %f", res3);
  printf("\nEl area de un círculo de radio 5 es: %f", res4);
  
  return 0;
}