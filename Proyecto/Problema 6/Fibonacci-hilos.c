#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Función que genera un número aleatorio entre 0 y 19.
int nInicial() {
    return rand() % 20;
}

// Función que calcula el n-ésimo término de la serie de Fibonacci,
// comenzando por los números a y a+1.
long fibonacci(long a, int n) {
    long b = a + 1, c = 0;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Estructura que representa un hilo de ejecución.
typedef struct miHilo {
    long sum;    // Suma de los términos calculados por el hilo.
    int n;       // Cantidad de términos a calcular.
    int inicio;  // Primer término de la serie de Fibonacci.
} miHilo;

// Función que ejecuta cada hilo.
void *run(void *arg) {
    miHilo *hilo = (miHilo *) arg;
    hilo->sum = fibonacci(hilo->inicio, hilo->n);
    return NULL;
}

int main() {
    pthread_t hilos[20];
    miHilo *hilo;
    long resultado = 0;
    srand(time(NULL));
    int inicial = nInicial();  // Número inicial para cada hilo.

    // Se crean los 20 hilos y se les asignan los parámetros correspondientes.
    for (int i = 0; i < 20; i++) {
        hilo = (miHilo *) malloc(sizeof(miHilo));
        hilo->inicio = inicial;
        hilo->n = 50000;

        pthread_create(&hilos[i], NULL, run, hilo);
    }

    // Se espera a que todos los hilos terminen su ejecución.
    for (int i = 0; i < 20; i++) {
        pthread_join(hilos[i], NULL);
    }
  
    // Se suman los términos calculados por cada hilo.
    for (int i = 0; i < 20; i++) {
        resultado += hilo[i].sum;
    }
    printf("%ld\n", resultado);  // Se imprime el resultado final.
    return 0;
}