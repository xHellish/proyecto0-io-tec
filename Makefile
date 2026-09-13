CC = gcc
CFLAGS = -Wall -g

.PHONY: all clean pdf

all: main

main: *.c
	$(CC) $(CFLAGS) *.c -o main

pdf: 
	flatpak-spawn --host pdflatex salida.tex

clean:
	rm -f main salida.pdf salida.tex documento.pdf salida.tex *.aux *.log
