exe: main.o main.o
	gcc main.o main.o -o exe
fonctions.o: fonctions.c fonctions.h
	gcc -c -Wall fonctions.c -o fonctions.o
main.o: main.c fonctions.h
	gcc -c -Wall main.c -o main.o
clean:
	rm -f *.o
