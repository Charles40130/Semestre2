exe: fonctions.o projet.o
	gcc fonctions.o projet.o -o test

fonctions.o: fonctions.c fonctions.h
	gcc -c fonctions.c -o fonctions.o -Wall

projet.o: projet.c fonctions.h
	gcc -c projet.c -o projet.o -Wall
