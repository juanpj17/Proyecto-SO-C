#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int bufsize;
    char *psource, *ptarget;
    FILE *fsource, *ftarget;

    // Verificar que se hayan proporcionado los tres argumentos necesarios
    if (argc == 4) {
        // Convertir el tamaño del búfer (el primer argumento) a un entero
        bufsize = atoi(argv[1]);

        // Verificar que el tamaño del búfer esté dentro del rango permitido
        if (0 < bufsize && bufsize < 16385) {
            // Guardar los nombres de archivo de origen y destino en variables separadas
            psource = argv[2];
            ptarget = argv[3];

            // Abrir el archivo de destino en modo de escritura
            if ((ftarget = fopen(ptarget, "w")) == NULL) {
                perror("Error al abrir el archivo de salida");
                exit(1);
            }

            // Abrir el archivo de origen en modo de lectura
            if ((fsource = fopen(psource, "r")) == NULL) {
                perror("Error al abrir el archivo de entrada");
                exit(1);
            }

            char chunk[bufsize];
            size_t bytes_read;
            // Leer y escribir en el archivo de destino en fragmentos del tamaño del búfer
            while ((bytes_read = fread(chunk, 1, bufsize, fsource)) > 0) {
                fwrite(chunk, 1, bytes_read, ftarget);
            }
            
            // Cerrar ambos archivos
            fclose(fsource);
            fclose(ftarget);
        } else {
            printf("ERROR: el valor de bufsize debe estar dentro del rango 1 a 16384\n");
        }
    } else {
        printf("ERROR: faltan argumentos\n");
    }

    return 0;
}