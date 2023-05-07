#include <stdlib.h> 
#include <string.h>  
#include <stdio.h>   

int main() {
    // Imprimir un mensaje en la consola
    printf("El número de procesos del usuario es:\n");  
    // Ejecutar el comando "logname" en la terminal del sistema operativo
    system("logname");  
    // Ejecutar el comando "ulimit -a | grep process" en la terminal del sistema operativo
    system("ulimit -a | grep process");  
    // Devolver un valor de salida de 0 para indicar que el programa ha finalizado correctamente
    return 0;   
}