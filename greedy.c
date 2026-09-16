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
    ResultadoAlgoritmo res_basico;
    ResultadoAlgoritmo res_proporcional;

    for (int i = 0; i < cantidad; i++) {
        if (es_ejemplo) {
            generar_problema_knapsack_ejemplo(&problema);
        } else {
            generar_problema_knapsack(&problema, 5 + rand() % 6);
        }

        // --- 1. PROGRAMACIÓN DINÁMICA ---
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        empezar_knapsack_dynamic(&problema);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        long long tiempo_dinamico = calcular_tiempo_ns(inicio, fin);
        printf("Tiempo de duración (Dinámica): %lld ns\n", tiempo_dinamico);

        // --- 2. GREEDY BÁSICO ---
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        empezar_knapsack_greedy_basico(&problema, &res_basico);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_basico.tiempo_ns = calcular_tiempo_ns(inicio, fin);

        // --- 3. GREEDY PROPORCIONAL ---
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        empezar_knapsack_greedy_proporcional(&problema, &res_proporcional);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_proporcional.tiempo_ns = calcular_tiempo_ns(inicio, fin);

        // Imprimir los resultados de los structs si estamos en modo ejemplo
        if (es_ejemplo) {
            // Resultados Greedy Básico
            printf("\n--- RESULTADOS GREEDY BÁSICO ---\n");
            printf("Tiempo de duración:  %lld ns\n", res_basico.tiempo_ns);
            printf("Cantidad elementos:  %d\n", res_basico.cantidad_elementos);
            printf("Capacidad evaluada:  %d\n", res_basico.capacidad_mochila);
            printf("Valor total (Z):     %d\n", res_basico.valor_total);
            
            printf("Variables seleccionadas: ");
            int hay_objetos = 0;
            for (int j = 0; j < res_basico.cantidad_elementos; j++) {
                if (res_basico.variables[j] == 1) {
                    printf("x%d ", j + 1);
                    hay_objetos = 1;
                }
            }
            if (!hay_objetos) printf("ninguna");
            printf("\n");

            // Resultados Greedy Proporcional
            printf("\n--- RESULTADOS GREEDY PROPORCIONAL ---\n");
            printf("Tiempo de duración:  %lld ns\n", res_proporcional.tiempo_ns);
            printf("Cantidad elementos:  %d\n", res_proporcional.cantidad_elementos);
            printf("Capacidad evaluada:  %d\n", res_proporcional.capacidad_mochila);
            printf("Valor total (Z):     %d\n", res_proporcional.valor_total);
            
            printf("Variables seleccionadas: ");
            hay_objetos = 0;
            for (int j = 0; j < res_proporcional.cantidad_elementos; j++) {
                if (res_proporcional.variables[j] == 1) {
                    printf("x%d ", j + 1);
                    hay_objetos = 1;
                }
            }
            if (!hay_objetos) printf("ninguna");
            printf("\n\n");
        }
    }
}

int main(int argc, char *argv[]) {
    char *fin_numero;
    long numero_experimentos;

    // Inicializar la semilla para que los problemas aleatorios cambien en cada ejecución
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
            
            printf("Modo experimento con n = %ld (En construcción...)\n", numero_experimentos);
            // La llamada a ejecutar_experimentos está comentada aquí hasta 
            // que se programe la lógica de las tablas de la Sección VI del PDF.
            // ejecutar_experimentos((int) numero_experimentos, 0); 
            
        } else {
            printf("Error, n debe ser un entero. Uso: -X o -E=n\n");
        }
        
    } else {
        printf("Error, uso: -X o -E=n\n");
    }

    return 0;
}