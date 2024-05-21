/***** Multiples procesos ***********
Autor: Andrés Pérez
Fecha: 27 febrero 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: -Trabajo con múltiples procesos 
Fichero: principal
*************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
   
 /* int x;
  for(x = 0; x < 3; x++){
    fork();
    printf("The process ID (PID): %d \n", getpid());
  }*/


  int processID = fork();
  if(processID > 0){
    printf("fork() devuelve un valor +ve. Este es el 'proceso padre' con ID: %d \n", getpid());
  }
  else if(processID == 0){
    printf("fork() devuelve un valor 0. Este es el 'proceso hijo' recien creado con ID: %d \n", getpid());
    printf("El 'proceso padre' de este 'proceso hijo' tiene el ID: %d \n\n", getppid());
  } else {
    printf("fork() devuelve un valor de -ve. Por lo que la llamada al sistema fork() falló\n");
  }
  printf("\nEsta es una única impresión. Si la llamada al sistema fork() ha tenido exito\n");
  printf("tanto el 'proceso padre' como el 'proceso hijo' se ejecutarán simultáneamente\n");
  printf("y esta impresión aparecerá 2 veces\n\n");
  return 0;
}
