/*****************************************************
  Autor: Andrés David Pérez Cely
  Fecha: 23 de Abril de 2024
  Materia: Sistemas Operativos
  Tema: Pipe Nominal
  "Se quiere enviar un mensaje a un proceso, con
  un nombre determinado. El proceso independiente
  que recibe el mensaje tendrá el nombre de la tubería"

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
  mkfifo("NombreMensaje", 0666);

  int pipeNM = open("NombreMensaje", O_WRONLY);

  /* Se escribe el mensaje en la tubería */
  char cadCaracteres[] = "Hola como te va...!";
  write(pipeNM, cadCaracteres, strlen(cadCaracteres) + 1);

  close(pipeNM);



  return 0;
}

/*

// Receptor
$ ls
pipe_nom.c  pipe_receptor.c
~$ gcc pipe_receptor.c -o pipe_receptor
~$ ls
pipe_envio  pipe_envio.c  pipe_receptor  pipe_receptor.c
~$ ./pipe_receptor
El mensaje recibido es:

// Desde el que se envia :
~$ ./pipe_envio &
[1] 1498
~$ 



*/