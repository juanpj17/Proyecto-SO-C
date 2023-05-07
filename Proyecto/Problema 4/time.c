#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    char programa[1000];
    double start, end;
    // verifica si se proporcionó al menos un argumento al programa
    if (argc > 1) { 
        // recorre los argumentos del programa a partir del segundo
        for (i = 2; i < argc; i++) { 
            // agrega el argumento actual al nombre del programa
            strcat(programa, argv[i]); 
            // agrega un espacio después del argumento
            strcat(programa, " "); 
        }
        // imprime el nombre completo del programa
        printf("%s\n", programa); 
        // inicia el temporizador
        start = clock(); 
        // construye un comando para ejecutar el programa con Python 3
        char command[1000] = "python3 "; 
        // agrega el nombre del programa al comando
        strcat(command, programa); 
        // ejecuta el comando para ejecutar el programa
        system(command); 
         // detiene el temporizador
        end = clock();
        // imprime el tiempo de ejecución del programa
        printf("%f segundos\n", (end - start) / CLOCKS_PER_SEC); 
    }
    else {
        // indica que no se proporcionaron suficientes argumentos al programa
        printf("ERROR en los parametros\n"); 
    }
    return 0;
}