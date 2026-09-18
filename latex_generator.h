#ifndef LATEX_GENERATOR
#define LATEX_GENERATOR

char* generate_table(int width, int height, int** data_matrix);

void generate_latex_experiment_mode(double data_matrix[5][2][10][10]);

void generate_latex_example_mode();

#endif