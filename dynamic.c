#include "dynamic.h"

int empezar_knapsack(const Knapsack *problema) {
	int tabla[MAX_CAPACIDAD + 1][MAX_ITEMS + 1] = {{0}};

	for (int capacidad = 0; capacidad <= problema->capacidad; capacidad++) {
		for (int item = 1; item <= problema->num_items; item++) {
			tabla[capacidad][item] = tabla[capacidad][item - 1];

			if (problema->pesos[item - 1] <= capacidad) {
				int valor = problema->valores[item - 1] +
					tabla[capacidad - problema->pesos[item - 1]][item - 1];
				if (valor > tabla[capacidad][item]) {
					tabla[capacidad][item] = valor;
				}
			}
		}
	}

	return tabla[problema->capacidad][problema->num_items];
}
