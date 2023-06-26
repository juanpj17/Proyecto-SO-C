#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int i;
    char programa[1000];
    struct timeval start, end;

    // Verifica si se proporcionó al menos un argumento al programa
    if (argc > 1) {
        // Recorre los argumentos del programa a partir del segundo
        for (i = 2; i < argc; i++) {
            // Agrega el argumento actual al nombre del programa
            strcat(programa, argv[i]);
            // Agrega un espacio después del argumento
            strcat(programa, " ");
        }

        // Imprime el nombre completo del programa
        printf("%s\n", programa);

        // Obtiene el tiempo de inicio
        gettimeofday(&start, NULL);

        // Construye un comando para ejecutar el programa con c-es-horrible
        char command[1000] = "c-es-horrible";
        // Agrega el nombre del programa al comando
        strcat(command, programa);
        // Ejecuta el comando para ejecutar el programa
        system(command);

        // Obtiene el tiempo de finalización
        gettimeofday(&end, NULL);

        // Calcula el tiempo de ejecución en segundos
        double execution_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        // Imprime el tiempo de ejecución del programa
        printf("%f segundos\n", execution_time);
    } else {
        // Indica que no se proporcionaron suficientes argumentos al programa
        printf("ERROR en los parametros\n");
    }

    return 0;
}
