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
    int capacity_position = capacity / 100;
    int elements_position = num_elements / 10;

    printf("capacidad: %d\nelementos: %d\nCantidad de datos:%f\n\n", capacity_position, elements_position, matrix[type][1][capacity_position][elements_position]);

    // Updates the average value
    matrix[type][0][capacity_position][elements_position] =
                (matrix[type][0][capacity_position][elements_position] * matrix[type][1][capacity_position][elements_position]
                + value) / (matrix[type][1][capacity_position][elements_position] + 1);
    
    printf("Tipo: %d\nPromedio actual: %f\n\n", type, matrix[type][0][capacity_position][elements_position]);
    
    // Increase counter of elements
    matrix[type][1][capacity_position][elements_position] ++;
}

static void ejecutar_experimentos(int cantidad, int es_ejemplo) {
    Knapsack problema;
    struct timespec inicio, fin;

    // Estructuras de datos para resultados
    //double master_matrix[5][2][10][10];

    // [0] average_dynamic
    // [1] average_greedy
    // [2] ratio_greedy
    // [3] average_p_greedy
    // [4] ratio_p_greedy

    // La segunda matrix guarda un conteo de los elementos guardados en cada celda

    // Limpiar la matriz por si acaso
    wipe_matrix(master_matrix);


    for (int i = 0; i < cantidad; i++) {
        if (es_ejemplo) {
            generar_problema_knapsack_ejemplo(&problema);
            // printf("Problema de ejemplo generado.\n");
        } else {
            // Nota: Para el modo experimento (-E) ajustaremos esto luego según la Tabla 1
            generar_problema_knapsack(&problema, 5 + rand() % 6);
        }

        Respuesta res_basico;
        Respuesta res_proporcional;
        Respuesta res_dinamico;

        // PROGRAMACIÓN DINÁMICA
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        res_dinamico = empezar_knapsack_dynamic(&problema);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_dinamico.tiempo_ns = calcular_tiempo_ns(inicio, fin);
        printf("res_dinamico: %lld\ncapacidad: %d\nacntidad de items: %d\n\n", res_basico.tiempo_ns, problema.capacidad, problema.num_items);
        master_matrix_store(master_matrix, average_dynamic, res_dinamico.tiempo_ns/1000, problema.capacidad, problema.num_items);

        // GREEDY BÁSICO
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        res_basico = empezar_knapsack_greedy_basico(&problema);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_basico.tiempo_ns = calcular_tiempo_ns(inicio, fin); // Guardar tiempo en el struct

        master_matrix_store(master_matrix, average_greedy, res_basico.tiempo_ns/1000, problema.capacidad, problema.num_items);

        // GREEDY PROPORCIONAL
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        res_proporcional = empezar_knapsack_greedy_proporcional(&problema);
        clock_gettime(CLOCK_MONOTONIC, &fin);
        res_proporcional.tiempo_ns = calcular_tiempo_ns(inicio, fin); // Guardar tiempo en el struct

        master_matrix_store(master_matrix, average_p_greedy, res_proporcional.tiempo_ns/1000, problema.capacidad, problema.num_items);

        // Imprimir los tiempos si estamos en modo ejemplo
        if (es_ejemplo) {
            imprimir_tabla_resultados(&res_dinamico, &problema);
            printf("\n--- TIEMPOS DE EJECUCIÓN ---\n");
            printf("Prog. Dinámica:      %lld ns\n", res_dinamico.tiempo_ns);
            printf("Greedy Básico:       %lld ns\n", res_basico.tiempo_ns);
            printf("Greedy Proporcional: %lld ns\n\n", res_proporcional.tiempo_ns);
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
            printf("Modo experimento con n = %ld (En construcción...)\n", numero_experimentos);
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