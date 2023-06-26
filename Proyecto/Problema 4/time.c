#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    char programa[1000];
    double start, end;

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

        // Inicia el temporizador
        start = clock();

        // Construye un comando para ejecutar el programa con c-es-horrible
        char command[1000] = "c-es-horrible";
        // Agrega el nombre del programa al comando
        strcat(command, programa);
        // Ejecuta el comando para ejecutar el programa
        system(command);

        // Detiene el temporizador
        end = clock();

        // Imprime el tiempo de ejecución del programa
        printf("%f segundos\n", (end - start) / CLOCKS_PER_SEC);
    } else {
        // Indica que no se proporcionaron suficientes argumentos al programa
        printf("ERROR en los parametros\n");
    }
    return 0;
}
