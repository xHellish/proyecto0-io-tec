#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "aux_funcs.h"

static void ejecutar_experimentos(int cantidad) {
    Knapsack problema;

    for (int i = 0; i < cantidad; i++) {
        generar_problema_knapsack(&problema, 5 + rand() % 6);
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
        ejecutar_experimentos(1);

    } else if (strncmp(argv[1], "-E=", 3) == 0) {
        errno = 0;
        numero_experimentos = strtol(argv[1] + 3, &fin_numero, 10);

        if (argv[1][3] != '\0' && *fin_numero == '\0' && errno == 0 &&
            numero_experimentos > 0 && numero_experimentos <= INT_MAX) {
            ejecutar_experimentos((int) numero_experimentos);
            
        } else {
            printf("Error, n debe ser un entero. Uso: -X o -E=n\n");
        }
    } else {
        printf("Error, uso: -X o -E=n\n");
    }

    return 0;
}