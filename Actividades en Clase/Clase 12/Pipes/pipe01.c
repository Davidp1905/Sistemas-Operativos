 /****************************************
Autor: Andrés Pérez
Fecha: 16 de Abril 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Pipes "Tuberías para comunicar o enviar información entre procesos"

A continuación se presentan las diferentes etapas:
  -Se crea el main para ingreso de argumentos de entrada
  -


  Que carajo es un pipe nominal :V
  
*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
  pid_t pID;
  int tuberia[2];

  //Crear la tubería "pipe"
  if(pipe(tuberia)){
    printf("Error creando la tuberia\n");
    return -1;
  }

  pID = fork();

  if(pID == 0){ // Proceso Hijo
    // Se cierra primero el otro extremo de la tuberia
    close(tuberia[0]);
    char *mensaje = "Mensaje enviado desde el proceso HIJO...\n";
    write(tuberia[1], mensaje, strlen(mensaje) +1);
    close(tuberia[1]);
    return EXIT_SUCCESS;
  } else if (pID > 0){ // Proceso Padre
    // Se cierra primero el otro extremo de la tuberia
    close(tuberia[1]);
    char busMensaje[69];
    read(tuberia[0], busMensaje, sizeof(busMensaje));
    printf("Mensaje desde el HIJO: \n\n\t %s \n" , busMensaje);
    close(tuberia[0]);
    return EXIT_SUCCESS;
  } else {
    printf("Error en la creación del PIPE\n"); 
    return EXIT_FAILURE;
  }

  return 0;
}
//gcc -o exe pipe01.c