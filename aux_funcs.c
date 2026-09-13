#include "aux_funcs.h"
#include <stdio.h>
#include <stdlib.h>

void generar_problema_knapsack(Knapsack *problema, int num_items) {
	int peso_total = 0;

	problema->num_items = num_items;

	for (int i = 0; i < num_items; i++) {
		problema->valores[i] = 1 + rand() % 50;
		problema->pesos[i] = 1 + rand() % 10;
		peso_total += problema->pesos[i];
	}

	problema->capacidad = peso_total / 2;
	if (problema->capacidad == 0) {
		problema->capacidad = 1;
	}

	printf("Generado problema de mochila con %d items y capacidad %d\n",
		problema->num_items, problema->capacidad);
	imprimir_knapsack(problema);
}

void imprimir_knapsack(const Knapsack *problema) {
	printf("Z = ");
	for (int i = 0; i < problema->num_items; i++) {
		printf("%s%dx%d", i == 0 ? "" : " + ", problema->valores[i], i + 1);
	}
	printf("\nVariables: x_i in {0,1}\nRestriccion: ");
	for (int i = 0; i < problema->num_items; i++) {
		printf("%s%dx%d", i == 0 ? "" : " + ", problema->pesos[i], i + 1);
	}
	printf(" <= %d\n", problema->capacidad);
}
