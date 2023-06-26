#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int signum) {
    printf("Mensaje enviado\n");
}

int main() {
    pid_t c1, c2;
    int pipefd[2];

    // Se define el manejador cuando se recibe la señal de alarma
    signal(SIGALRM, handler);

    // Se crea el pipe
    if (pipe(pipefd) == -1) {
        perror("Error al crear el pipe");
        exit(EXIT_FAILURE);
    }

    // Se crea el proceso hijo c2
    c2 = fork();

    if (c2 == 0) {
        // Proceso hijo c2
        // En c2 se cierra el extremo de escritura del pipe
        close(pipefd[1]);

        for (int i = 0; i < 10; i++) {
            // Se lee el mensaje del proceso c1
            char text[50];
            read(pipefd[0], text, 50);
            printf("%s\n", text);
            // printf("Soy pid, c%d, he recibido mensaje %s\n", i, text);
        }
    } else {
        // Se crea el proceso hijo c1
        c1 = fork();

        if (c1 == 0) {
            // Proceso hijo c1
            // En c1 se cierra el extremo de lectura del pipe
            close(pipefd[0]);

            for (int i = 0; i < 10; i++) {
                // La alarma es enviada cada 2 segundos
                alarm(2);
                // El proceso se retiene hasta que se reciba una señal
                pause();
                // C1 envía al extremo de escritura del pipe
                char text[] = "Mensaje recibido";
                write(pipefd[1], text, sizeof(text));
                // printf("Soy pid2, c%d, he mandado mensaje y debe haber sido leído\n", i);
            }
        } else {
            // El proceso se retiene hasta que todos sus procesos hijos terminen
            wait(NULL);
        }
    }

    return 0;
}
