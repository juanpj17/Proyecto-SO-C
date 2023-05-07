#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <time.h>       

int main(int argc, char *argv[]) {
    // Declarar variables para medir el tiempo de ejecución
    clock_t start, end; 
    // Declarar variable para el tiempo de CPU utilizado        
    double cpu_time_used;       

     // Comprobar si hay argumentos de línea de comandos suficientes
    if (argc > 1) {  
        // Declarar una cadena vacía para almacenar el comando          
        char programa[1000] = "";   
        for (int i = 1; i < argc; i++) {  
            // Agregar cada argumento al comando  
            strcat(programa, argv[i]);  
            // Agregar un espacio en blanco después de cada argumento   
            strcat(programa, " ");          
        }

        // Imprimir el comando en la consola
        printf("%s\n", programa);   
        // Registrar el tiempo de inicio
        start = clock();            
        // Ejecutar el comando en la terminal del sistema operativo
        system(programa);           
        // Registrar el tiempo de finalización
        end = clock();              
        // Calcular el tiempo de CPU utilizado
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  
        // Imprimir el tiempo de CPU utilizado en la consola
        printf("%f segundos\n", cpu_time_used);  
    } else {
        // Imprimir un mensaje de error si no hay suficientes argumentos de línea de comandos
        printf("ERROR en los parametros\n");  
    }
    return 0;  
}