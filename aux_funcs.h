#ifndef AUX_H
#define AUX_H

#include <stdio.h>

#define MAX_VARS 20 // Límite de variables por enunciado
#define MAX_RESTRICCIONES 20 // Límite de restricciones

// --------------------------------- //
// Structs

typedef struct {
    int coeficiente;
    int id_var; // x1 , x2, x3, ...
} Variable;

typedef struct {
    Variable variables[MAX_VARS];
    int num_vars;
    char tipo_restriccion[5];  // "<=", ">=", "="
    int termino_independiente;  // Lo que está a la derecha del operador de restricción
} Restriccion;

// --------------------------------- //
// Funciones
void pedir_datos(void);

int extraer_funcion_z(const char *cadena, Variable variables[], int *num_vars);

int extraer_restriccion(const char *cadena, Restriccion *restriccion);

#endif