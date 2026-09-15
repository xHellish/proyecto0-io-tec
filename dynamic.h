#ifndef DYNAMIC_H
#define DYNAMIC_H

#include "aux_funcs.h"

struct respuesta_dynamic {
    double tiempo;
    int cantidad_elementos;
    int capacidad;
    int valor_z;
    int solucion[MAX_ITEMS];
};

struct respuesta_dynamic empezar_knapsack_dynamic(const Knapsack *problema);

#endif