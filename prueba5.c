#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARRERAS 7
#define NUM_SEMESTRES 2
#define NUM_ANIOS 5

/**
 * Genera datos aleatorios de ingresos de alumnos en las diferentes carreras y años.
 * se ingresa el arreglo tridimensional para almacenar los datos generados.
 */
void generarDatosAleatorios(int ingresos[][NUM_SEMESTRES][NUM_ANIOS]) {
    srand(time(NULL)); // Inicializar la semilla aleatoria con el tiempo actual

    int i, j, k;
    for (i = 0; i < NUM_CARRERAS; i++) {
        for (j = 0; j < NUM_SEMESTRES; j++) {
            for (k = 0; k < NUM_ANIOS; k++) {
                ingresos[i][j][k] = rand() % 100 + 1; // Generar un número aleatorio entre 1 y 100
            }
        }
    }
}

void escribirDatosEnArchivo(int ingresos[][NUM_SEMESTRES][NUM_ANIOS]) {
    FILE *archivo;
    archivo = fopen("datos.txt", "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char *carreras[NUM_CARRERAS] = {
        "Ingeniería de Software",
        "Administración",
        "Economía",
        "Relaciones Internacionales",
        "Matemáticas",
        "Contabilidad",
        "Ingeniería Industrial"
    };

    int i, j, k;
    for (i = 0; i < NUM_CARRERAS; i++) {
        fprintf(archivo, "Carrera: %s\n", carreras[i]);
        for (j = 0; j < NUM_SEMESTRES; j++) {
            fprintf(archivo, "Semestre %d:\n", j + 1);
            for (k = 0; k < NUM_ANIOS; k++) {
                fprintf(archivo, "Año %d: %d\n", k + 1, ingresos[i][j][k]);
            }
            fprintf(archivo, "\n");
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
}

int main() {
    int ingresos[NUM_CARRERAS][NUM_SEMESTRES][NUM_ANIOS];

    generarDatosAleatorios(ingresos);
    escribirDatosEnArchivo(ingresos);
    printf("Los datos aleatorios se han generado y guardado en el archivo datos.txt.\n");

    return 0;
}
