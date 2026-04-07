#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float suma, promedio;
    int i, j;

    for (i = 0; i < ESTUDIANTES; i++) {
        for (j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Ingrese la nota del estudiante %d en asignatura %d: ", i+1, j+1);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("Nota inválida. Debe estar entre 0 y 10.\n");
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    printf("\nPromedio por estudiante:\n");
    for (i = 0; i < ESTUDIANTES; i++) {
        suma = 0;
        for (j = 0; j < ASIGNATURAS; j++) {
            suma += calificaciones[i][j];
        }
        promedio = suma / ASIGNATURAS;
        printf("Estudiante %d: %.2f\n", i+1, promedio);
    }

    printf("\nPromedio por asignatura:\n");
    for (j = 0; j < ASIGNATURAS; j++) {
        suma = 0;
        for (i = 0; i < ESTUDIANTES; i++) {
            suma += calificaciones[i][j];
        }
        promedio = suma / ESTUDIANTES;
        printf("Asignatura %d: %.2f\n", j+1, promedio);
    }

    printf("\nMáxima y mínima por estudiante:\n");
    for (i = 0; i < ESTUDIANTES; i++) {
        float max = calificaciones[i][0], min = calificaciones[i][0];
        for (j = 1; j < ASIGNATURAS; j++) {
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
        }
        printf("Estudiante %d - Máx: %.2f, Mín: %.2f\n", i+1, max, min);
    }

    printf("\nMáxima y mínima por asignatura:\n");
    for (j = 0; j < ASIGNATURAS; j++) {
        float max = calificaciones[0][j], min = calificaciones[0][j];
        for (i = 1; i < ESTUDIANTES; i++) {
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
        }
        printf("Asignatura %d - Máx: %.2f, Mín: %.2f\n", j+1, max, min);
    }

    printf("\nAprobados y reprobados por asignatura:\n");
    for (j = 0; j < ASIGNATURAS; j++) {
        int aprobados = 0, reprobados = 0;
        for (i = 0; i < ESTUDIANTES; i++) {
            if (calificaciones[i][j] >= 6) aprobados++;
            else reprobados++;
        }
        printf("Asignatura %d - Aprobados: %d, Reprobados: %d\n", j+1, aprobados, reprobados);
    }

    return 0;
}
