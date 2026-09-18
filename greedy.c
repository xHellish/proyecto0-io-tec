#include "greedy.h"

Respuesta empezar_knapsack_greedy_basico(const Knapsack *problema) {
    int capacidad_restante = problema->capacidad;
    int seleccionados[MAX_ITEMS] = {0};
    Respuesta resultado = {
        .tiempo_ns = 0,
        .cantidad_elementos = problema->num_items,
        .capacidad = problema->capacidad,
        .valor_total = 0,
        .variables = {0}
    };

    while (1) {
        int mejor_indice = -1;
        int mejor_valor = -1;

        for (int i = 0; i < problema->num_items; i++) {
            if (!seleccionados[i] && problema->pesos[i] <= capacidad_restante &&
                problema->valores[i] > mejor_valor) {
                mejor_valor = problema->valores[i];
                mejor_indice = i;
            }
        }

        if (mejor_indice == -1) {
            break;
        }

        seleccionados[mejor_indice] = 1;
        capacidad_restante -= problema->pesos[mejor_indice];
        resultado.valor_total += problema->valores[mejor_indice];
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        resultado.variables[i] = seleccionados[i];
    }

    return resultado;
}

Respuesta empezar_knapsack_greedy_proporcional(const Knapsack *problema) {
    int capacidad_restante = problema->capacidad;
    int seleccionados[MAX_ITEMS] = {0};
    Respuesta resultado = {
        .tiempo_ns = 0,
        .cantidad_elementos = problema->num_items,
        .capacidad = problema->capacidad,
        .valor_total = 0,
        .variables = {0}
    };

    while (1) {
        int mejor_indice = -1;
        double mejor_rendimiento = -1.0;

        for (int i = 0; i < problema->num_items; i++) {
            if (!seleccionados[i] && problema->pesos[i] <= capacidad_restante) {
                double rendimiento = (double) problema->valores[i] / problema->pesos[i];
                if (rendimiento > mejor_rendimiento) {
                    mejor_rendimiento = rendimiento;
                    mejor_indice = i;
                }
            }
        }

        if (mejor_indice == -1) {
            break;
        }

        seleccionados[mejor_indice] = 1;
        capacidad_restante -= problema->pesos[mejor_indice];
        resultado.valor_total += problema->valores[mejor_indice];
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        resultado.variables[i] = seleccionados[i];
    }

    return resultado;
}
