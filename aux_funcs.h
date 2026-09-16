#ifndef AUX_H
#define AUX_H

#define MAX_ITEMS 100
#define MAX_CAPACIDAD 1000

typedef struct {
	int num_items;
	int capacidad;
	int pesos[MAX_ITEMS];
	int valores[MAX_ITEMS];
} Knapsack;

typedef struct {
    long long tiempo_ns;           // Tiempo de duración en nanosegundos
    int cantidad_elementos;        // Cantidad de elementos evaluados
    int capacidad_mochila;         // Capacidad de la mochila evaluada
    int valor_total;               // El valor final obtenido en la mochila
    int variables[MAX_ITEMS];      // 1 si el objeto i fue seleccionado
} ResultadoAlgoritmo;

void generar_problema_knapsack(Knapsack *problema, int num_items);

void generar_problema_knapsack_ejemplo(Knapsack *problema);

void imprimir_knapsack(const Knapsack *problema);

#endif