#ifndef AUX_H
#define AUX_H

#include <time.h>

#define MAX_ITEMS 100
#define MAX_CAPACIDAD 1000

typedef struct {
	int num_items;
	int capacidad;
	int pesos[MAX_ITEMS];
	int valores[MAX_ITEMS];
} Knapsack;

typedef struct {
    long long tiempo_ns;
    int cantidad_elementos;
    int capacidad;
    int valor_total;
    int variables[MAX_ITEMS];
    int tabla[MAX_CAPACIDAD + 1][MAX_ITEMS + 1];
} Respuesta;

void generar_problema_knapsack(Knapsack *problema, int num_items);

void generar_problema_knapsack_ejemplo(Knapsack *problema);

void imprimir_knapsack(const Knapsack *problema);

long long calcular_tiempo_ns(struct timespec inicio, struct timespec fin);

int soluciones_iguales(const Respuesta *respuesta_a, const Respuesta *respuesta_b);

#endif