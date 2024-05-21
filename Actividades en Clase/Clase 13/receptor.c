/*****************************************************
  Autor: Andrés David Pérez Cely
  Fecha: 23 de Abril de 2024
  Materia: Sistemas Operativos
  Tema: Pipe Nominal
  "Se quiere recibir un mensaje a un proceso, con
  un nombre determinado. Se crea el proceso independiente
  que recibe el mensaje desde la tubería"

  ESTA COSA ES UN PIPE NOMINAL
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <string.h>

int main(int argc, char *argv[]){

  int pipeNM = open("NombreMensaje", O_RDONLY);

  /* Se crea el bus para recibir el mensaje */
  char busCaracteres[100];
  read(pipeNM, busCaracteres, sizeof(busCaracteres));

  printf("El mensaje recibido es:\n\n\t\t %s \n", busCaracteres);

  close(pipeNM);



  return 0;
}