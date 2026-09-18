#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aux_funcs.h"

char* generate_table(int width, int height, int** data_matrix){
    char* result = malloc (sizeof (char) * 700);
    return result;
}



void generate_latex_experiment_mode(double data_matrix[5][2][10][10]){
    FILE *tex = fopen("salida.tex", "w");
    if (tex == NULL) {
        perror("Error al crear el archivo .tex");
        return;
    }
    fprintf(tex, "\\documentclass[11pt]{article}\n");
    fprintf(tex, "\\usepackage[left=2.5cm, right=2.5cm]{geometry}\n");
    fprintf(tex, "\\usepackage{xcolor}\n");
    fprintf(tex, "\\begin{document}\n");
    fprintf(tex, "\\title{Algorithms to solve the 0/1 Knapsack Problem - Experiment Mode}\n");
    fprintf(tex, "\\author{");
    fprintf(tex, "Anthony Camacho Palma, Ben Farzamipour Alfaro, Jose Joel Jara Álvarez");
    fprintf(tex, "}\n");
    fprintf(tex, "\\markboth{\n");
    fprintf(tex, "ITCR - Operations Research\n");
    fprintf(tex, "}{}\n");
    fprintf(tex, "\\maketitle\n");
    fprintf(tex, "blahblahblah\n");

    // Dynamic Section

	fprintf(tex, "\n\\section{Dynamic programming approach}\n\nAverage execution time:\n");
    fprintf(tex, "\\[%.3f ms\\]\n\n", 1.0); //VALOR!!!
    fprintf(tex, "Average execution time per number of elements and capacity:\n\n");

    // Begin table
    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    for (int i = 0; i < 10; i++){
        fprintf(tex, "\\multicolumn{1}{|c|}{%d00} ", i + 1);
        for (int j = 0; j < 9; j++){
            fprintf(tex, "& \\multicolumn{1}{c|}{%.3f} ", data_matrix[0][0][i][j]);
        }
        fprintf(tex, " & %.3f \\\\ \\hline\n", data_matrix[0][0][i][9]);

    }
    fprintf(tex, "\\end{tabular}\n\\end{table}\n");
    // End of table

    fprintf(tex, "\n\\newpage\n");

    // Greedy Section

    fprintf(tex, "\\section{Greedy algorithm}\n\n");
    fprintf(tex, "Average execution time:\n\\[%.3f ms\\]\n\n", 1.0); // VALOR!!!
    fprintf(tex, "Average execution time per number of elements and capacity:\n\n");

    // Begin table
    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    for (int i = 0; i < 10; i++){
        fprintf(tex, "\\multicolumn{1}{|c|}{%d00} ", i + 1);
        for (int j = 0; j < 9; j++){
            fprintf(tex, "& \\multicolumn{1}{c|}{%.3f} ", data_matrix[1][0][i][j]);
        }
        fprintf(tex, " & %.3f \\\\ \\hline\n", data_matrix[1][0][i][9]);

    }
    fprintf(tex, "\\end{tabular}\n\\end{table}\n");
    // End of table
    fprintf(tex, "Success ratio per number of elements and capacity:\n\n");

    // Begin table
    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    for (int i = 0; i < 10; i++){
        fprintf(tex, "\\multicolumn{1}{|c|}{%d00} ", i + 1);
        for (int j = 0; j < 9; j++){
            fprintf(tex, "& \\multicolumn{1}{c|}{%.3f} ", data_matrix[2][0][i][j]);
        }
        fprintf(tex, " & %.3f \\\\ \\hline\n", data_matrix[2][0][i][9]);

    }
    fprintf(tex, "\\end{tabular}\n\\end{table}\n");
    // End of table

    fprintf(tex, "\n\\newpage\n\n");

    //Proportional Greedy Section

    fprintf(tex, "\\section{Proportional Greedy Algorithm}\n\n");
    fprintf(tex, "Average execution time:\n\\[%.3f ms\\]\n\n", 1.0); // VALOR!!!
    fprintf(tex, "Average execution time per number of elements and capacity:\n\n");

    // Begin table
    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    for (int i = 0; i < 10; i++){
        fprintf(tex, "\\multicolumn{1}{|c|}{%d00} ", i + 1);
        for (int j = 0; j < 9; j++){
            fprintf(tex, "& \\multicolumn{1}{c|}{%.3f} ", data_matrix[3][0][i][j]);
        }
        fprintf(tex, " & %.3f \\\\ \\hline\n", data_matrix[3][0][i][9]);

    }
    fprintf(tex, "\\end{tabular}\n\\end{table}\n");
    // End of table

    fprintf(tex, "Success ratio per number of elements and capacity:\n\n");

    // Begin table
    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    for (int i = 0; i < 10; i++){
        fprintf(tex, "\\multicolumn{1}{|c|}{%d00} ", i + 1);
        for (int j = 0; j < 9; j++){
            fprintf(tex, "& \\multicolumn{1}{c|}{%.3f} ", data_matrix[4][0][i][j]);
        }
        fprintf(tex, " & %.3f \\\\ \\hline\n", data_matrix[4][0][i][9]);

    }
    fprintf(tex, "\\end{tabular}\n\\end{table}\n");
    // End of table
    //ETC

    // End of doc section

    fprintf(tex, "\n\\end{document}");
}

void generate_latex_example_mode(double data_matrix[5][2][10][10]){
    FILE *tex = fopen("salida.tex", "w");
    if (tex == NULL) {
        perror("Error al crear el archivo .tex");
        return;
    }
    fprintf(tex, "\\documentclass[11pt]{article}\n");
    fprintf(tex, "\\usepackage[left=2.5cm, right=2.5cm]{geometry}\n");
    fprintf(tex, "\\usepackage{xcolor}\n");
    fprintf(tex, "\\begin{document}\n");
    fprintf(tex, "\\title{Algorithms to solve the 0/1 Knapsack Problem - Example Mode}\n");
    fprintf(tex, "\\author{");
    fprintf(tex, "Anthony Camacho Palma, Ben Farzamipour Alfaro, Jose Joel Jara Álvarez");
    fprintf(tex, "}\n");
    fprintf(tex, "\\markboth{\n");
    fprintf(tex, "ITCR - Operations Research\n");
    fprintf(tex, "}{}\n");
    fprintf(tex, "\\maketitle\n");


    fprintf(tex, "Problem to solve:\n\nMaximise:\n\n");
    // Math expression here 0mfg

    fprintf(tex, "Subject to:\n\n");

    // A whole bunch of inequalities 0mg

    // Dynamic Section

    fprintf(tex, "\n\\newpage\n");


	fprintf(tex, "\n\\section{Dynamic programming approach}\n\nExecution time:\n");
    fprintf(tex, "\\[%.3f ms\\]\n\n", 1.0); //VALOR!!!
    fprintf(tex, "Solution:\n\n");

    // Solution here :33

    fprintf(tex, "Table used with sub-optimal results:\n\n");

    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccc|}\n\\cline{2-7}\n& \\multicolumn{6}{c|}{Element}\n\\\\ \\hline\n\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{$v_1$} & \\multicolumn{1}{c|}{$v_2$} & \\multicolumn{1}{c|}{$v_3$} & \\multicolumn{1}{c|}{$v_4$} & \\multicolumn{1}{c|}{$v_5$} & $v_6$ \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{0}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{1}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{2}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{3}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{4}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{5}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{6}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{7}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{8}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{9}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{10}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{11}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{12}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{13}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{14}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{15}        & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      & \\multicolumn{1}{c|}{%.3f}      &  %.3f     \\\\ \\hline\n");
    fprintf(tex, "\\end{tabular}\\end{table}\n");


    fprintf(tex, "\n\\newpage\n");

    // Greedy Section

    fprintf(tex, "\\section{Greedy algorithm}\n\n");
    fprintf(tex, "Average execution time:\n\\[%.3f ms\\]\n\n", 1.0); // VALOR!!!
    fprintf(tex, "Average execution time per number of elements and capacity:\n\n");

    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{100}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{200}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{300}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{400}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{500}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{600}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{700}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{800}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{900}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{1000}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\end{tabular}\n\\end{table}\n\n");

    fprintf(tex, "Success ratio per number of elements and capacity:\n\n");

    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{100}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{200}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{300}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{400}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{500}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{600}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{700}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{800}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{900}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{1000}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\end{tabular}\n\\end{table}\n\n");

    fprintf(tex, "\n\\newpage\n\n");

    //Proportional Greedy Section

    fprintf(tex, "\\section{Proportional Greedy Algorithm}\n\n");
    fprintf(tex, "Average execution time:\n\\[%.3f ms\\]\n\n", 1.0); // VALOR!!!
    fprintf(tex, "Average execution time per number of elements and capacity:\n\n");

    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{100}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{200}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{300}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{400}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{500}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{600}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{700}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{800}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{900}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{1000}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\end{tabular}\n\\end{table}\n\n");

    fprintf(tex, "Success ratio per number of elements and capacity:\n\n");

    fprintf(tex, "\\begin{table}[h!]\n\\centering\n\\begin{tabular}{c|cccccccccc|}\n\\cline{2-11}\n");
    fprintf(tex, "& \\multicolumn{10}{c|}{Number of elements}\\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{Capacity} & \\multicolumn{1}{c|}{10} & \\multicolumn{1}{c|}{20} & \\multicolumn{1}{c|}{30} & \\multicolumn{1}{c|}{40} & \\multicolumn{1}{c|}{50} & \\multicolumn{1}{c|}{60} & \\multicolumn{1}{l|}{70} & \\multicolumn{1}{l|}{80} & \\multicolumn{1}{l|}{90} & 100 \\\\ \\hline\n");
    fprintf(tex, "\\multicolumn{1}{|c|}{100}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{200}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{300}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{400}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{500}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{600}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{700}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{800}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{900}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\multicolumn{1}{|c|}{1000}      & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{c|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & \\multicolumn{1}{l|}{%.3f}   & %.3f \\\\ \\hline\n", data_matrix[0][0][3][0], data_matrix[0][0][3][1], data_matrix[0][0][3][2], data_matrix[0][0][3][3], data_matrix[0][0][3][4], data_matrix[0][0][3][5], data_matrix[0][0][3][6], data_matrix[0][0][3][7], data_matrix[0][0][3][8], data_matrix[0][0][3][9]);
    fprintf(tex, "\\end{tabular}\n\\end{table}\n\n");

    // End of doc section

    fprintf(tex, "\n\\end{document}");
}