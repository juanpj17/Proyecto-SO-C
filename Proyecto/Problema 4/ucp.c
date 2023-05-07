#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    // Comprobamos si se pasaron los 3 argumentos necesarios
    if (argc == 4) {
        int bufsize = atoi(argv[1]);
        // Verificamos que bufsize esté dentro del rango permitido
        if (bufsize > 0 && bufsize < 16385) {
            // Obtenemos los nombres de los archivos de entrada y salida
            char* psource = argv[2];
            char* ptarget = argv[3];
            // Abrimos el archivo de entrada
            FILE* fsource = fopen(psource, "r");
            if (fsource == NULL) {
                printf("ERROR al abrir el archivo de entrada");
                return 1;
            }
            // Abrimos el archivo de salida
            FILE* ftarget = fopen(ptarget, "w");
            if (ftarget == NULL) {
                printf("ERROR al abrir el archivo de salida");
                fclose(fsource);
                return 1;
            }
            // Establecemos el tamaño del buffer de entrada y salida
            setvbuf(fsource, NULL, _IOFBF, bufsize);
            setvbuf(ftarget, NULL, _IOFBF, bufsize);
            // Creamos el buffer de tamaño bufsize
            char* buffer = malloc(bufsize);
            size_t bytes_read;
            // Leemos del archivo de entrada y escribimos en el de salida en bloques del tamaño del buffer
            while ((bytes_read = fread(buffer, 1, bufsize, fsource)) > 0) {
                fwrite(buffer, 1, bytes_read, ftarget);
            }
            // Liberamos la memoria del buffer
            free(buffer);
            // Cerramos los archivos
            fclose(fsource);
            fclose(ftarget);
        } else {
            printf("ERROR el valor bufsize debe estar dentro del rango 1 a 16384");
            return 1;
        }
    } else {
        printf("ERROR faltan argumentos");
        return 1;
    }
    return 0;
}