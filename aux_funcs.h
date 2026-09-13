#ifndef AUX_H
#define AUX_H

#define MAX_ITEMS 20
#define MAX_CAPACIDAD 100

typedef struct {
	int num_items;
	int capacidad;
	int pesos[MAX_ITEMS];
	int valores[MAX_ITEMS];
} Knapsack;

void generar_problema_knapsack(Knapsack *problema, int num_items);
void imprimir_knapsack(const Knapsack *problema);

#endif