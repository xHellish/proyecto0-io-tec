#include <stdio.h>
#include <stdlib.h>

int main() {

    // --------------------------------- //
    // Crear el archivo de .tex
    FILE *tex = fopen("salida.tex", "w");
    if (tex == NULL) {
        perror("Error al crear el archivo .tex");
        return 1;
    }

    // --------------------------------- //
    // Líneas
    fprintf(tex, "\\documentclass{article}\n");
    fprintf(tex, "\\usepackage[utf8]{inputenc}\n");
    fprintf(tex, "\\usepackage[spanish]{babel}\n");
    fprintf(tex, "\\title{Reporte de Salida}\n");
    fprintf(tex, "\\author{Proyecto C}\n");
    fprintf(tex, "\\begin{document}\n");
    fprintf(tex, "\\maketitle\n");
    fprintf(tex, "\\section{Resultados}\n");
    fprintf(tex, "Documento generado correctamente desde el programa en C.\n");
    fprintf(tex, "\\end{document}\n");
    fclose(tex);

    return 0;
}