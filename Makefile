$(CC) = gcc

final: main.o tree.o node.o
		$(CC) main.o tree.o node.o -o final

main.o: main.c Fonctions.h
		$(CC) -c main.c

Fonctions.o: Fonctions.c Fonctions.h
		$(CC) -c Fonctions.c

