#include <stdio.h>
#include <string.h>
#include "aux.h"

// --------------------------------- //
// Extraer coeficientes y variables del string input
int extraer_funcion_z(const char *cadena, Variable variables[], int *num_vars) {

    const char *ptr = cadena;
    int coeficiente, id, bytes_leidos;
    int signo = 1;

    // Saltar espacios iniciales
    while (*ptr == ' ') ptr++;

    while (*ptr != '\0' && *ptr != '\n') {
        bytes_leidos = 0;

        // Intenta parsear con coeficiente: dígito*variable
        if (sscanf(ptr, "%dx%d%n", &coeficiente, &id, &bytes_leidos) == 2) {
            variables[*num_vars].coeficiente = coeficiente * signo;
            variables[*num_vars].id_var = id;
            (*num_vars)++;
            ptr += bytes_leidos;
        }
        // Intenta parsear sin coeficiente: variable
        else if (sscanf(ptr, "x%d%n", &id, &bytes_leidos) == 1) {
            variables[*num_vars].coeficiente = 1 * signo;
            variables[*num_vars].id_var = id;
            (*num_vars)++;
            ptr += bytes_leidos;
        }
        else {
            break;  // No hay más variables
        }

        // Salta espacios
        while (*ptr == ' ') ptr++;

        // Captura el signo
        if (*ptr == '+') {
            signo = 1;
            ptr++;
        } else if (*ptr == '-') {
            signo = -1;
            ptr++;
        } else {
            break;  // No hay más variables
        }

        // Salta espacios después del signo
        while (*ptr == ' ') ptr++;
    }

    return *num_vars;
}

// --------------------------------- //
// Extraer restricción: coeficientes, tipo de restricción y término independiente
int extraer_restriccion(const char *cadena, Restriccion *restriccion) {

    const char *ptr = cadena;
    int coeficiente, id, bytes_leidos;
    int signo = 1;

    restriccion->num_vars = 0;
    strcpy(restriccion->tipo_restriccion, "");
    restriccion->termino_independiente = 0;

    // Saltar espacios iniciales
    while (*ptr == ' ') ptr++;

    // Parsear variables hasta encontrar el operador
    while (*ptr != '\0' && *ptr != '\n' && *ptr != '<' && *ptr != '>' && *ptr != '=') {
        bytes_leidos = 0;

        // Intenta parsear con coeficiente: dígito*variable
        if (sscanf(ptr, "%dx%d%n", &coeficiente, &id, &bytes_leidos) == 2) {
            restriccion->variables[restriccion->num_vars].coeficiente = coeficiente * signo;
            restriccion->variables[restriccion->num_vars].id_var = id;
            (restriccion->num_vars)++;
            ptr += bytes_leidos;
        }
        // Intenta parsear sin coeficiente: variable
        else if (sscanf(ptr, "x%d%n", &id, &bytes_leidos) == 1) {
            restriccion->variables[restriccion->num_vars].coeficiente = 1 * signo;
            restriccion->variables[restriccion->num_vars].id_var = id;
            (restriccion->num_vars)++;
            ptr += bytes_leidos;
        }
        else {
            break;  // No hay más variables
        }

        // Salta espacios
        while (*ptr == ' ') ptr++;

        // Captura el signo o detiene si encuentra operador
        if (*ptr == '+') {
            signo = 1;
            ptr++;
        } else if (*ptr == '-' && (*(ptr+1) < '0' || *(ptr+1) > '9')) {
            // Es un signo, no un número negativo
            signo = -1;
            ptr++;
        } else {
            break;  // No hay más variables
        }

        // Salta espacios después del signo
        while (*ptr == ' ') ptr++;
    }

    // Busca el operador de restricción (<=, >=, =)
    while (*ptr == ' ') ptr++;  // Salta espacios finales

    int termino_indep = 0;

    // Asignar el operador correspondiente y el valor independiente
    if (sscanf(ptr, "<=%d%n", &termino_indep, &bytes_leidos) == 1) {
        strcpy(restriccion->tipo_restriccion, "<=");
        restriccion->termino_independiente = termino_indep;

    } else if (sscanf(ptr, ">=%d%n", &termino_indep, &bytes_leidos) == 1) {
        strcpy(restriccion->tipo_restriccion, ">=");
        restriccion->termino_independiente = termino_indep;

    } else if (sscanf(ptr, "=%d%n", &termino_indep, &bytes_leidos) == 1) {
        strcpy(restriccion->tipo_restriccion, "=");
        restriccion->termino_independiente = termino_indep;
    }

    return restriccion->num_vars;
}

// --------------------------------- //
void pedir_datos() {
    
    char func_objetivo[100];  // Variable para almacenar la función objetivo (sólo los caracteres)

    printf("Ingrese la función objetivo Z a maximizar (ejemplo: 3x1 + 2x2): ");

    fgets(func_objetivo, sizeof(func_objetivo), stdin);  // input

    printf("\nFunción objetivo ingresada: Z = %s\n", func_objetivo);

    // --------------------------------- //
    // Array para almacenar las variables y coheficientes de la función objetivo
    Variable variables_funcion_objetivo[MAX_VARS];  
    // ---------------------------------- //
    int num_vars = 0;

    extraer_funcion_z(func_objetivo, variables_funcion_objetivo, &num_vars);

    /*
    // Mostrar los coeficientes y variables extraídas (debug)
    printf("Coeficientes y variables extraídas:\n");

    for (int i = 0; i < num_vars; i++) {
        printf("Coeficiente: %d, Variable: x%d\n", variables_funcion_objetivo[i].coeficiente, variables_funcion_objetivo[i].id_var);
    }
    */

    printf("Ingrese nueva restricción (ejemplo: 2x1 + 3x2 <= 10) [Dejar en blanco para terminar]: ");

    Restriccion restricciones_arr[MAX_RESTRICCIONES];  // Array para almacenar las restricciones
    int num_restricciones = 0;

    char linea_restriccion[100];  // Variable temporal para cada restricción

    while (1) {
        printf("Restricción %d: ", num_restricciones + 1);
        
        fgets(linea_restriccion, sizeof(linea_restriccion), stdin);
        
        // Si la línea está vacía (solo '\n'), terminar
        if (linea_restriccion[0] == '\n' || linea_restriccion[0] == '\0') {
            break;
        }
        
        // Procesar y guardar la restricción
        extraer_restriccion(linea_restriccion, &restricciones_arr[num_restricciones]);
        
        printf("[debug] Guardada: %d variable(s), operador: %s, término: %d\n",
            restricciones_arr[num_restricciones].num_vars,
            restricciones_arr[num_restricciones].tipo_restriccion,
            restricciones_arr[num_restricciones].termino_independiente);
        
        num_restricciones++;
        
        if (num_restricciones >= MAX_RESTRICCIONES) {
            printf("Límite máximo de restricciones alcanzado.\n");
            break;
        }
    }

    printf("\nTotal de restricciones ingresadas: %d\n", num_restricciones);
}