OBJ = build/main.o build/generator.o build/analisator.o
CC = gcc
CFLAGS = -g3 -O0 -Wall

.PHONY: clean open gdb

chainMarkov: $(OBJ)
	$(CC) $(CFLAGS) -o chainMarkov $(OBJ)

build/generator.o: src/generator.c build
	$(CC) $(CFLAGS) -o build/generator.o -c src/generator.c

build/analisator.o: src/analisator.c build
	$(CC) $(CFLAGS) -o build/analisator.o -c src/analisator.c

build/main.o: src/main.c build
	$(CC) $(CFLAGS) -o build/main.o -c src/main.c

build:
	mkdir build


clean :
	rm -rf build
open :
	./chainMarkov
gdb :
	gdb ./chainMarkov

