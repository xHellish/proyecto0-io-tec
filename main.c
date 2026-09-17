#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "aux_funcs.h"
#include "dynamic.h"
#include "greedy.h"

// Función auxiliar para calcular la diferencia de tiempo en nanosegundos
static long long calcular_tiempo_ns(struct timespec inicio, struct timespec fin) {
    return (fin.tv_sec - inicio.tv_sec) * 1000000000LL + (fin.tv_nsec - inicio.tv_nsec);
}

static void ejecutar_experimentos(int cantidad, int es_ejemplo) {
    Knapsack problema;
    struct timespec inicio, fin;

    for (int i = 0; i < cantidad; i++) {
        if (es_ejemplo) {
            generar_problema_knapsack_ejemplo(&problema);
        } else {
            // Nota: Para el modo experimento (-E) ajustaremos esto luego según la Tabla 1
            generar_problema_knapsack(&problema, 5 + rand() % 6);
        }

        // --- 1. PROGRAMACIÓN DINÁMICA ---
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        empezar_knapsack_dynamic(&problema);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        long long tiempo_dinamico = calcular_tiempo_ns(inicio, fin);

        RespuestaGreedy1 res_basico;
        RespuestaGreedy2 res_proporcional;

        // --- GREEDY BÁSICO ---
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        empezar_knapsack_greedy_basico(&problema, &res_basico);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_basico.tiempo_ns = calcular_tiempo_ns(inicio, fin); // Guardar tiempo en el struct

        // --- 3. GREEDY PROPORCIONAL ---
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        empezar_knapsack_greedy_proporcional(&problema, &res_proporcional);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_proporcional.tiempo_ns = calcular_tiempo_ns(inicio, fin); // Guardar tiempo en el struct

        // Imprimir los tiempos si estamos en modo ejemplo
        if (es_ejemplo) {
            printf("\n--- TIEMPOS DE EJECUCIÓN ---\n");
            printf("Prog. Dinámica:      %lld ns\n", tiempo_dinamico);
            printf("Greedy Básico:       %lld ns\n", res_basico.tiempo_ns);
            printf("Greedy Proporcional: %lld ns\n\n", res_proporcional.tiempo_ns);
        }
    }
}

int main(int argc, char *argv[]) {
    char *fin_numero;
    long numero_experimentos;

    srand((unsigned int) time(NULL));

    if (argc != 2) {
        printf("Error, uso: -X o -E=n\n");

    } else if (strcmp(argv[1], "-X") == 0) {
        printf("Modo de ejemplo activado.\n");
        ejecutar_experimentos(1, 1);

    } else if (strncmp(argv[1], "-E=", 3) == 0) {
        errno = 0;
        numero_experimentos = strtol(argv[1] + 3, &fin_numero, 10);

        if (argv[1][3] != '\0' && *fin_numero == '\0' && errno == 0 &&
            numero_experimentos > 0 && numero_experimentos <= INT_MAX) {
            
            // Para el modo experimento ejecutaremos la recolección de estadísticas
            printf("Modo experimento con n = %ld (En construcción...)\n", numero_experimentos);
            // ejecutar_experimentos((int) numero_experimentos, 0); 
            
        } else {
            printf("Error, n debe ser un entero. Uso: -X o -E=n\n");
        }
        
    } else {
        printf("Error, uso: -X o -E=n\n");
    }

    return 0;
}