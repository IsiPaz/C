
run: programa
	./programa

CC=gcc
CFLAGS=-I.
DEPS = funciones.h lista.h
OBJ = funciones.o lista.o main.o

%.o: %.c $(DEPS)
		$(CC) -Wall -c -o $@ $< $(CFLAGS)

programa: $(OBJ)
	gcc -Wall -o $@ $^ $(CFLAGS)
