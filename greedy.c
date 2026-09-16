#include "greedy.h"
#include <stdio.h>

int empezar_knapsack_greedy_basico(const Knapsack *problema) {
    int capacidad_restante = problema->capacidad;
    int valor_total = 0;
    int seleccionados[MAX_ITEMS] = {0}; // Para rastrear qué objetos ya metimos
    
    while (1) {
        int mejor_indice = -1;
        int mejor_valor = -1;
        
        // Buscar el objeto más valioso que quepa y no haya sido seleccionado
        for (int i = 0; i < problema->num_items; i++) {
            if (!seleccionados[i] && problema->pesos[i] <= capacidad_restante) {
                if (problema->valores[i] > mejor_valor) {
                    mejor_valor = problema->valores[i];
                    mejor_indice = i;
                }
            }
        }
        
        // Si no encontramos ningún objeto que quepa, terminamos
        if (mejor_indice == -1) {
            break;
        }
        
        // Agregar el objeto a la mochila
        seleccionados[mejor_indice] = 1;
        capacidad_restante -= problema->pesos[mejor_indice];
        valor_total += problema->valores[mejor_indice];
    }
    
    printf("Valor (Greedy Básico): %d\n", valor_total);
    printf("Objetos seleccionados (Básico): ");
    
    int hay_objetos = 0;
    for (int i = 0; i < problema->num_items; i++) {
        if (seleccionados[i]) {
            printf("x%d ", i + 1);
            hay_objetos = 1;
        }
    }
    if (!hay_objetos) {
        printf("ninguno");
    }
    printf("\n");
    
    return valor_total;
}

int empezar_knapsack_greedy_proporcional(const Knapsack *problema) {
    int capacidad_restante = problema->capacidad;
    int valor_total = 0;
    int seleccionados[MAX_ITEMS] = {0};
    
    while (1) {
        int mejor_indice = -1;
        double mejor_rendimiento = -1.0;
        
        // Buscar el objeto con mejor rendimiento (valor/peso) que quepa y no esté seleccionado
        for (int i = 0; i < problema->num_items; i++) {
            if (!seleccionados[i] && problema->pesos[i] <= capacidad_restante) {
                double rendimiento = (double)problema->valores[i] / problema->pesos[i];
                if (rendimiento > mejor_rendimiento) {
                    mejor_rendimiento = rendimiento;
                    mejor_indice = i;
                }
            }
        }
        
        // Si no encontramos ninguno, terminamos
        if (mejor_indice == -1) {
            break;
        }
        
        // Agregar el objeto a la mochila
        seleccionados[mejor_indice] = 1;
        capacidad_restante -= problema->pesos[mejor_indice];
        valor_total += problema->valores[mejor_indice];
    }
    
    printf("Valor (Greedy Proporcional): %d\n", valor_total);
    printf("Objetos seleccionados (Proporcional): ");
    
    int hay_objetos = 0;
    for (int i = 0; i < problema->num_items; i++) {
        if (seleccionados[i]) {
            printf("x%d ", i + 1);
            hay_objetos = 1;
        }
    }
    if (!hay_objetos) {
        printf("ninguno");
    }
    printf("\n");
    
    return valor_total;
}