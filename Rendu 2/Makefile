# Makefile pour TP6 (client/server BMP -> SVG JSON)
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJS = bmp.o couleur.o

all: client serveur

bmp.o: bmp.c bmp.h couleur.h
	$(CC) $(CFLAGS) -c bmp.c

couleur.o: couleur.c couleur.h
	$(CC) $(CFLAGS) -c couleur.c

client: client.c client.h bmp.o couleur.o
	$(CC) $(CFLAGS) -o client client.c bmp.o couleur.o

serveur: serveur.c serveur.h couleur.o
	$(CC) $(CFLAGS) -o serveur serveur.c couleur.o

clean:
	rm -f *.o client serveur output.svg
