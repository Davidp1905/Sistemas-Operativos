/***** Captura de Tiempos ***********
Autor: Andrés Pérez
Fecha: 5 marzo de 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Retos clase 6
      -Memoria dinámica
      -Punteros
Fichero: fichero principal que llama a la biblioteca artesanal construida
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "biblio.h"
#include <string.h>


int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Ingreso de parametros erroneo: \nSe necesita escribir de la siguiente manera:\n");
    printf("$./eje  rows cols\n\nPara el reto puntero 6 se necesita los tamaños de rows y cols para las matrices\n");
    return -1;
  }
  
  reto1();
  reto2();
  reto3();
  reto4();
  reto5();

  printf("\nFunción de bonus 1 memoria dinámica: \n\n");
  char *a = NULL;
  char *b = NULL;
  a = reto6("Hi, It's fun to learn");
  b = reto6("systems engineer");
  printf("From main: %s %s\n", a, b);
  printf("\nFin bonus 1 memoria dinámica\n");
    
  retoPuntero1();
  retoPuntero2();
  retoPuntero3();
  retoPuntero4();
  retoPuntero5();
  retoPuntero6(argv);  
  
  return 0;
}

//gcc -o exe main.c biblio.c