#include <stdio.h>
#include "aux.h"

// --------------------------------- //
// Extraer coeficientes y variables del string input
int extraer_coeficientes(const char *cadena, Variable variables[], int *num_vars) {

    const char *ptr = cadena;

    int coeficiente, id, bytes_leidos;

    *num_vars = 0;

    int signo = 1;

    // Escanea la forma dígito*variable
    while (sscanf(ptr, " %dx%d%n", &coeficiente, &id, &bytes_leidos) == 2) {

        variables[*num_vars].coeficiente = coeficiente * signo;

        variables[*num_vars].id_var = id;
        
        (*num_vars)++;

        ptr += bytes_leidos; // Avanza el puntero en la cadena
        
        // Salta espacios y cambia el signo si encuentra un '+' o '-'
        while (*ptr == ' ' || *ptr == '+' || *ptr == '-') {

            if (*ptr == '-') {
                signo = -1;
            } 

            if (*ptr == '+') {
                signo = 1;
            }

            ptr++;
        }
    }

    return *num_vars;
}

// --------------------------------- //
void pedir_datos() {
    
    char func_objetivo[100];  // Variable para almacenar la función objetivo

    printf("Ingrese la función objetivo Z a maximizar (ejemplo: 3x1 + 2x2): ");

    fgets(func_objetivo, sizeof(func_objetivo), stdin);  // input

    printf("\nFunción objetivo ingresada: Z = %s\n", func_objetivo);

    Variable variables[MAX_VARS];  // Array para almacenar las variables

    int num_vars = 0;  // Contador de variables

    extraer_coeficientes(func_objetivo, variables, &num_vars);

    // Mostrar los coeficientes y variables extraídas
    printf("\nCoeficientes y variables extraídas:\n");

    for (int i = 0; i < num_vars; i++) {
        printf("Coeficiente: %d, Variable: x%d\n", variables[i].coeficiente, variables[i].id_var);
    }
}