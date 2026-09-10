#ifndef AUX_H
#define AUX_H

#include <stdio.h>

#define MAX_VARS 20 // Límite de variables por enunciado

// --------------------------------- //
// Structs

typedef struct {
    int coeficiente;
    int id_var; // x1 , x2, x3, ...
} Variable;

// --------------------------------- //
// Funciones
void pedir_datos(void);

int extraer_coeficientes(const char *cadena, Variable variables[], int *num_vars);

#endif