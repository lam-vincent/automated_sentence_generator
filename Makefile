$(CC) = gcc

final: main.o tree.o node.o file_management.o
		$(CC) main.o tree.o node.o file_management.o -o final

main.o: main.c tree.h node.h
		$(CC) -c main.c

tree.o: tree.c tree.h
		$(CC) -c tree.c

node.o: node.c node.h
		$(CC) -c node.c

file_management.o: file_management.c file_management.h
		$(CC) -c file_management.c
