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
    int valor_z;
    int solucion[MAX_ITEMS];
} RespuestaDynamic;

typedef struct {
    long long tiempo_ns;
    int cantidad_elementos;
    int capacidad_mochila;
    int valor_total;
    int variables[MAX_ITEMS];
} RespuestaGreedyBasico;

typedef struct {
    long long tiempo_ns;
    int cantidad_elementos;
    int capacidad_mochila;
    int valor_total;
    int variables[MAX_ITEMS];
} RespuestaGreedyProporcional;

void generar_problema_knapsack(Knapsack *problema, int num_items);

void generar_problema_knapsack_ejemplo(Knapsack *problema);

void imprimir_knapsack(const Knapsack *problema);

long long calcular_tiempo_ns(struct timespec inicio, struct timespec fin);

#endif