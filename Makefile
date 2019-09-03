all: Final Test

Final: fonctions.o main.o
	gcc -lm -Wall -g -std=c99 fonctions.o main.o -o Final

Test: fonctions.o tests.o
	gcc -lm -Wall -g -std=c99 fonctions.o tests.o -o Test

fonctions.o: fonctions.c header.h
	gcc -lm -Wall -g -std=c99 -c fonctions.c -o fonctions.o

main.o: main.c fonctions.c header.h
	gcc -lm -Wall -g -std=c99 -c main.c -o main.o

exec:
	rm -rf *.o
	rm -rf *.psh

purge:
	rm -rf *.o
	rm -rf *.psh
	rm -rf Final Test
