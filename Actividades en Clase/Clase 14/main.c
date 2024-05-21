/********************************
Autor: Andrés Pérez
Co-autor:
Fecha: 30 Abril 2024
Materia: Sistemas Operativos
Pontificia Universidad Javeriana
Tema: Varios
// Hala Madrid
*************************************/

#include "biblio.h"
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>

// Se requiere una estructura para almacenar los datos de entrada
struct DatosEntrada {
  int edad;
  int genero;
  float estatura;
  float peso;
  char *fichero;
};

int main(int argc, char *argv[]) {
  // Se requiere dadas unas banderas, reconocer el valor
  // $./ejecutable -k edad -z genero -d estatura -s peso

  if (argc != 11) {
    printf("\nArgumentos de entrada:\n\t%s -k kvalor -z zvalor\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  struct DatosEntrada *datos =
      (struct DatosEntrada *)malloc(sizeof(struct DatosEntrada));
  float promedio1, promedio2;
  float col1[100], col2[100];
  
  for (int i = 0; i < argc; i++) {
    if (i + 1 != argc) {
      if (strcmp(argv[i], "-k") == 0) {
        char *k = argv[i + 1];
        datos->edad = atoi(k);
        i++;
      }

      if (strcmp(argv[i], "-z") == 0) {
        char *z = argv[i + 1];
        datos->genero = atoi(z);
        i++;
      }

      if (strcmp(argv[i], "-d") == 0) {
        char *d = argv[i + 1];
        datos->estatura = atof(d);
        i++;
      }

      if (strcmp(argv[i], "-s") == 0) {
        char *s = argv[i + 1];
        datos->peso = atof(s);
        i++;
      }
      if (strcmp(argv[i], "-f") == 0) {
        char *f = argv[i + 1];
        datos->fichero = f;
        i++;
      }
    }
  }
  // s s d s d s f s f, 0 1 edad 3 genero 5 estatura 7 peso
  printf("./%s %s %d %s %d %s %f %s %f \n", argv[0], argv[1], datos->edad, argv[3], datos->genero, argv[5], datos->estatura, argv[7], datos->peso);

  FILE *entrada;
  int numero;
  entrada = fopen(datos->fichero, "r");
  if (entrada == NULL) {
    fputs("File error", stderr);
    exit(1);
  }

  printf("\nEl contenido del archivo de prueba es \n\n");
    while((numero = fgetc(entrada)) != EOF)
  {
         printf("%d ",numero);
  }
  
  fclose(entrada);

  printf("\nFin del programa UwU\n");

  return 0;
}

// gcc -o exe main.c biblio.c