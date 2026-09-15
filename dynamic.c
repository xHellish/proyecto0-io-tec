#include "dynamic.h"
#include <stdio.h>
#include <time.h>

struct respuesta_dynamic empezar_knapsack_dynamic(const Knapsack *problema) {
	
	// Inicializar la estructura de respuesta
	struct respuesta_dynamic respuesta = {
		.tiempo = 0.0,
		.cantidad_elementos = problema->num_items,
		.capacidad = problema->capacidad,
		.valor_z = 0,
		.solucion = {0}
	};
	
	clock_t inicio = clock();  // Iniciar el tiempo desde el comienzo del algoritmo

	int tabla[MAX_CAPACIDAD + 1][MAX_ITEMS + 1] = {{0}};

	for (int capacidad_disponible = 0; capacidad_disponible <= problema->capacidad; capacidad_disponible++) {
		
		for (int cantidad_objetos = 1; cantidad_objetos <= problema->num_items; cantidad_objetos++) {
			int indice_objeto = cantidad_objetos - 1;
			int mejor_valor_sin_objeto = tabla[capacidad_disponible][cantidad_objetos - 1];

			// Primera opción: no incluir el objeto actual.
			tabla[capacidad_disponible][cantidad_objetos] = mejor_valor_sin_objeto;

			// Segunda opción: incluirlo si cabe en la capacidad disponible.
			if (problema->pesos[indice_objeto] <= capacidad_disponible) {
				int valor_al_incluir_objeto = problema->valores[indice_objeto] + 
				tabla[capacidad_disponible - problema->pesos[indice_objeto]][cantidad_objetos - 1];

				if (valor_al_incluir_objeto > tabla[capacidad_disponible][cantidad_objetos]) {
					tabla[capacidad_disponible][cantidad_objetos] = valor_al_incluir_objeto;
				}
			}
		}
	}

	printf("Valor optimo: %d\n", tabla[problema->capacidad][problema->num_items]);
	printf("Objetos seleccionados para la solución óptima: ");

	int capacidad_restante = problema->capacidad;
	int hay_objetos_seleccionados = 0;

	// Recorrer la tabla desde la solución final hacia atrás
	for (int cantidad_objetos = problema->num_items; cantidad_objetos > 0; cantidad_objetos--) {
		
		int indice_objeto = cantidad_objetos - 1;
		
		// Si el valor cambia al quitar el objeto, ese objeto forma parte de la solución óptima
		if (tabla[capacidad_restante][cantidad_objetos] != tabla[capacidad_restante][cantidad_objetos - 1]) {
			respuesta.solucion[indice_objeto] = 1;
			
			printf("x%d ", indice_objeto + 1);  // debug: imprimir el objeto seleccionado en la solución óptima
			
			hay_objetos_seleccionados = 1;
			capacidad_restante -= problema->pesos[indice_objeto];
		}
	}

	if (!hay_objetos_seleccionados) {
		printf("ninguno");
	}
	
	printf("\n");

	respuesta.valor_z = tabla[problema->capacidad][problema->num_items];
	respuesta.tiempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

	return respuesta;
}
