#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#define MESSAGE_SIZE 50

void handler(int signum){
    printf("Mensaje enviado\n");
}

int main() {
    // Se define el manejador para la señal SIGALRM
    signal(SIGALRM, handler);
    
    // Se crea el pipe para la comunicación entre procesos
    int pipefd[2];
    pid_t c1, c2;
    char message[MESSAGE_SIZE];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Se crea el proceso hijo c2
    c2 = fork();

    if (c2 == 0) {
        // Código del proceso hijo c2
        close(pipefd[1]);
        for (int i = 0; i < 10; i++) {
            // Se lee el mensaje del proceso c1
            read(pipefd[0], message, MESSAGE_SIZE);
            printf("%s\n", message);
            // printf("Soy pid, c %d he recibido mensaje %s\n", i, message);
        }
    } else {
        // Se crea el proceso hijo c1
        c1 = fork();

        if (c1 == 0) {
            // Código del proceso hijo c1
            close(pipefd[0]);
            for (int i = 0; i < 10; i++) {
                // Se envía una señal SIGALRM al proceso c1
                alarm(2);
                pause();
                strcpy(message, "Mensaje recibido");
                // Se escribe el mensaje en el pipe para que el proceso c2 lo lea
                write(pipefd[1], message, strlen(message) + 1);
                // printf("Soy pid2, c %d he mandado mensaje y debe haber sido leido\n", i);
            }
        } else {
            // Código del proceso padre
            wait(NULL);
        }
    }

    return 0;
}