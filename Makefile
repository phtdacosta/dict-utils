CC = gcc

LINK_TARGET = main.exe

OBJS = \
dictutils.o

MAIN = main.c	

build:
	$(CC) -c dictutils.c -o $(OBJS)
	ar rcs libdictutils.a $(OBJS)
	$(CC) -c $(MAIN) -o main.o
	$(CC) -shared -o libdictutils.so $(OBJS)
	$(CC) -o main.exe main.c libdictutils.so