#include <stdio.h>

#include "latex_generator.h"

static const int capacidades[10] = {100, 200, 300, 400, 500,
                                     600, 700, 800, 900, 1000};
static const int cantidades[10] = {10, 20, 30, 40, 50,
                                   60, 70, 80, 90, 100};

static double promedio_global(double data_matrix[5][2][10][10], int tipo) {
    double total = 0.0;
    double cantidad = 0.0;

    for (int capacidad = 0; capacidad < 10; capacidad++) {
        for (int elementos = 0; elementos < 10; elementos++) {
            double repeticiones = data_matrix[tipo][1][capacidad][elementos];
            total += data_matrix[tipo][0][capacidad][elementos] * repeticiones;
            cantidad += repeticiones;
        }
    }

    return cantidad == 0.0 ? 0.0 : total / cantidad;
}

static void escribir_tabla_tiempos(FILE *tex,
                                   double data_matrix[5][2][10][10],
                                   int tipo) {
    fprintf(tex, "\\begin{table}[htbp]\n");
    fprintf(tex, "\\centering\n");
    fprintf(tex, "\\small\n");
    fprintf(tex, "\\resizebox{\\textwidth}{!}{%%\n");
    fprintf(tex, "\\begin{tabular}{c|cccccccccc}\n");
    fprintf(tex, "\\hline\n");
    fprintf(tex, "Capacidad / objetos");

    for (int elementos = 0; elementos < 10; elementos++) {
        fprintf(tex, " & %d", cantidades[elementos]);
    }
    fprintf(tex, " \\\\\n\\hline\n");

    for (int capacidad = 0; capacidad < 10; capacidad++) {
        fprintf(tex, "%d", capacidades[capacidad]);
        for (int elementos = 0; elementos < 10; elementos++) {
            fprintf(tex, " & %.3f",
                    data_matrix[tipo][0][capacidad][elementos]);
        }
        fprintf(tex, " \\\\\n");
    }

    fprintf(tex, "\\hline\n");
    fprintf(tex, "\\end{tabular}\n");
    fprintf(tex, "}\n");
    fprintf(tex, "\\caption{Tiempo promedio en microsegundos.}\n");
    fprintf(tex, "\\end{table}\n\n");
}

static void escribir_seccion(FILE *tex,
                             double data_matrix[5][2][10][10],
                             int tipo,
                             const char *titulo) {
    fprintf(tex, "\\section{%s}\n\n", titulo);
    fprintf(tex, "Tiempo promedio global: %.3f microsegundos.\n\n",
            promedio_global(data_matrix, tipo));
    escribir_tabla_tiempos(tex, data_matrix, tipo);
}

void generate_latex_experiment_mode(double data_matrix[5][2][10][10]) {
    FILE *tex = fopen("salida.tex", "w");
    if (tex == NULL) {
        perror("Error al crear el archivo .tex");
        return;
    }

    fprintf(tex, "\\documentclass[11pt]{article}\n");
    fprintf(tex, "\\usepackage[utf8]{inputenc}\n");
    fprintf(tex, "\\usepackage[T1]{fontenc}\n");
    fprintf(tex, "\\usepackage[spanish,es-nodecimaldot]{babel}\n");
    fprintf(tex, "\\usepackage[left=2cm,right=2cm,top=2cm,bottom=2cm]{geometry}\n");
    fprintf(tex, "\\usepackage{graphicx}\n");
    fprintf(tex, "\\begin{document}\n\n");
    fprintf(tex, "\\title{Experimento de algoritmos para la mochila 0/1}\n");
    fprintf(tex, "\\author{Anthony Camacho Palma \\\\ "
                 "Ben Farzamipour Alfaro \\\\ Jose Joel Jara Alvarez}\n");
    fprintf(tex, "\\date{\\today}\n");
    fprintf(tex, "\\maketitle\n\n");
    fprintf(tex, "Los tiempos se expresan en microsegundos. Cada celda "
                 "corresponde a una capacidad y una cantidad de objetos.\n\n");

    escribir_seccion(tex, data_matrix, 0, "Programacion dinamica");
    escribir_seccion(tex, data_matrix, 1, "Greedy basico");
    escribir_seccion(tex, data_matrix, 3, "Greedy proporcional");

    fprintf(tex, "\\end{document}\n");
    fclose(tex);
}

void generate_latex_example_mode(void) {
    FILE *tex = fopen("salida.tex", "w");
    if (tex == NULL) {
        perror("Error al crear el archivo .tex");
        return;
    }

    fprintf(tex, "\\documentclass[11pt]{article}\n");
    fprintf(tex, "\\usepackage[utf8]{inputenc}\n");
    fprintf(tex, "\\usepackage[T1]{fontenc}\n");
    fprintf(tex, "\\usepackage[spanish]{babel}\n");
    fprintf(tex, "\\usepackage[left=2.5cm,right=2.5cm]{geometry}\n");
    fprintf(tex, "\\begin{document}\n");
    fprintf(tex, "\\section*{Modo de ejemplo}\n");
    fprintf(tex, "El documento de ejemplo aun no ha sido generado.\n");
    fprintf(tex, "\\end{document}\n");
    fclose(tex);
}