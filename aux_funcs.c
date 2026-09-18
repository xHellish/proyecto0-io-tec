#include "aux_funcs.h"
#include <stdio.h>
#include <stdlib.h>

static void generar_problema_knapsack_con_limites(Knapsack *problema, int num_items, int capacidad, int max_peso, int max_valor) {
	
	int peso_total = 0;

	problema->num_items = num_items;

	for (int i = 0; i < num_items; i++) {
		problema->valores[i] = 1 + rand() % max_valor;
		problema->pesos[i] = 1 + rand() % max_peso;
		peso_total += problema->pesos[i];
	}

	if (capacidad > 0) {
		problema->capacidad = capacidad;

	} else {
		problema->capacidad = peso_total / 2;

		if (problema->capacidad == 0) {
			problema->capacidad = 1;
		}
	}

	printf("Generado problema de mochila con %d items y capacidad %d\n", problema->num_items, problema->capacidad);

	imprimir_knapsack(problema);
}

void generar_problema_knapsack(Knapsack *problema, int num_items) {
	generar_problema_knapsack_con_limites(problema, num_items, 0, 10, 50);
}

void generar_problema_knapsack_experimento(Knapsack *problema, int num_items,
                                           int capacidad) {
	problema->num_items = num_items;
	problema->capacidad = capacidad;

	int max_peso = capacidad * 40 / 100;
	for (int i = 0; i < num_items; i++) {
		problema->valores[i] = 1 + rand() % 100;
		problema->pesos[i] = 1 + rand() % max_peso;
	}
}

void generar_problema_knapsack_ejemplo(Knapsack *problema) {
	generar_problema_knapsack_con_limites(problema, 6, 15, 7, 20);
}

void imprimir_knapsack(const Knapsack *problema) {

	printf("Z (valores) = ");
	
	for (int i = 0; i < problema->num_items; i++) {
		printf("%s%dx%d", i == 0 ? "" : " + ", problema->valores[i], i + 1);
	}

	printf("\nVariables: x_i ∈ {0,1}\nRestricción (pesos): ");

	for (int i = 0; i < problema->num_items; i++) {
		printf("%s%dx%d", i == 0 ? "" : " + ", problema->pesos[i], i + 1);
	}

	printf(" <= %d\n", problema->capacidad);
}

// Función auxiliar para calcular la diferencia de tiempo en nanosegundos
long long calcular_tiempo_ns(struct timespec inicio, struct timespec fin) {
    return (fin.tv_sec - inicio.tv_sec) * 1000000000LL + (fin.tv_nsec - inicio.tv_nsec);
}

int soluciones_iguales(const Respuesta *respuesta_a, const Respuesta *respuesta_b) {
	if (respuesta_a->cantidad_elementos != respuesta_b->cantidad_elementos) {
		return 0;
	}

	for (int i = 0; i < respuesta_a->cantidad_elementos; i++) {
		if (respuesta_a->variables[i] != respuesta_b->variables[i]) {
			return 0;
		}
	}

	return 1;
}