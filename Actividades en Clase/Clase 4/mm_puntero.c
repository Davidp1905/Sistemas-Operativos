/***** Apuntadores ***********
Autor: Andrés Pérez
Fecha: 13 febrero 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Uso de punteros en C
*************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int arreglo[3];
  int *p = arreglo;
  int *ref = &arreglo[2];
  //printf("XD: %d\n", argc);
  if(argc == 4){
    for(int i = 1; i < argc; i++){
      arreglo[i-1] = atoi(argv[i]);
    }
  } else {
    printf("Entrada de argumentos inválidos\n\n");
    printf("$./ejecutable arg1, arg2. arg3\n\n\n");
  }
  for(int i = 0; i < argc -1; i++, p++){
    printf("Valor ingresado es: %d\n", *p);
    printf("%d\n", *ref);
  }

  /*
  int x;
  int suma = 0;
  do{
    scanf("%d", &x);
    suma += x;
  } while (x!=0);
    printf("La suma es: %d \n", suma);*/
  return 0;
}

//gcc main.c -o exe