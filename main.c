#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "aux_funcs.h"
#include "dynamic.h"
#include "greedy.h"
#include "latex_generator.h"

#define average_dynamic 0
#define average_greedy 1
#define ratio_greedy 2
#define average_p_greedy 3
#define ratio_p_greedy 4

double master_matrix[5][2][10][10];

void wipe_matrix(double matrix[5][2][10][10]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 10; k++){
                for (int l = 0; l < 10; l++)
                matrix[i][j][k][l] = (double) 0.0;
            }
        }
    }
    return;
}

void print_matrix(double matrix[5][2][10][10]){
    for (int i = 0; i < 5; i++){
        printf("[");
        for (int j = 0; j < 2; j++){
            printf("[");
            for (int k = 0; k < 10; k++){
                printf("[");
                for (int l = 0; l < 10; l++)
                printf("%f, ", matrix[i][j][k][l]);
                printf("],");
            }
            printf("],\n");
        }
        printf("],\n\n");
    }
    return;
}

void master_matrix_store(double matrix[5][2][10][10], int type, double value, int capacity, int num_elements){
    int capacity_position = capacity / 100 - 1;
    int elements_position = num_elements / 10 - 1;

    if (type < 0 || type >= 5 || capacity_position < 0 || capacity_position >= 10 ||
        elements_position < 0 || elements_position >= 10) {
        return;
    }

    // Updates the average value
    matrix[type][0][capacity_position][elements_position] =
                (matrix[type][0][capacity_position][elements_position] * matrix[type][1][capacity_position][elements_position]
                + value) / (matrix[type][1][capacity_position][elements_position] + 1);
    
    // Increase counter of elements
    matrix[type][1][capacity_position][elements_position] ++;
}

static void medir_problema(const Knapsack *problema, int es_ejemplo) {
    struct timespec inicio, fin;
    Respuesta res_basico;
    Respuesta res_proporcional;
    Respuesta res_dinamico;

        clock_gettime(CLOCK_MONOTONIC, &inicio);
        res_dinamico = empezar_knapsack_dynamic(problema);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_dinamico.tiempo_ns = calcular_tiempo_ns(inicio, fin);
        master_matrix_store(master_matrix, average_dynamic, res_dinamico.tiempo_ns / 1000,
                            problema->capacidad, problema->num_items);

        clock_gettime(CLOCK_MONOTONIC, &inicio);
        res_basico = empezar_knapsack_greedy_basico(problema);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_basico.tiempo_ns = calcular_tiempo_ns(inicio, fin);

        master_matrix_store(master_matrix, average_greedy, res_basico.tiempo_ns / 1000,
                            problema->capacidad, problema->num_items);

        clock_gettime(CLOCK_MONOTONIC, &inicio);
        res_proporcional = empezar_knapsack_greedy_proporcional(problema);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_proporcional.tiempo_ns = calcular_tiempo_ns(inicio, fin);

        master_matrix_store(master_matrix, average_p_greedy, res_proporcional.tiempo_ns / 1000,
                            problema->capacidad, problema->num_items);

        if (es_ejemplo) {
            imprimir_tabla_resultados(&res_dinamico, problema);
            printf("\n--- TIEMPOS DE EJECUCIÓN ---\n");
            printf("Prog. Dinámica:      %lld ns\n", res_dinamico.tiempo_ns);
            printf("Greedy Básico:       %lld ns\n", res_basico.tiempo_ns);
            printf("Greedy Proporcional: %lld ns\n\n", res_proporcional.tiempo_ns);
        }
}

static void ejecutar_experimentos(int cantidad, int es_ejemplo) {
    wipe_matrix(master_matrix);

    if (es_ejemplo) {
        Knapsack problema;
        generar_problema_knapsack_ejemplo(&problema);
        medir_problema(&problema, 1);
        return;
    }

    for (int capacidad = 100; capacidad <= 1000; capacidad += 100) {
        for (int num_items = 10; num_items <= 100; num_items += 10) {
            for (int repeticion = 0; repeticion < 100 * cantidad; repeticion++) {
                Knapsack problema;
                generar_problema_knapsack_experimento(&problema, num_items, capacidad);
                medir_problema(&problema, 0);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char *fin_numero;
    long numero_experimentos;

    //ejecutar_experimentos(10,0);

    //generate_latex_experiment_mode(master_matrix);

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
            ejecutar_experimentos((int) numero_experimentos, 0);
            generate_latex_experiment_mode(master_matrix);
            
        } else {
            printf("Error, n debe ser un entero. Uso: -X o -E=n\n");
        }
        
    } else {
        printf("Error, uso: -X o -E=n\n");
    }

    return 0;
}