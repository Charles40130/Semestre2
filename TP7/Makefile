
CC=gcc -Wall
RM=rm -f
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
HEAD=$(wildcard *.h)
PROG=main

all : $(PROG)

$(PROG) : $(OBJ)

	$(CC) $^ -o $@ -lm

%.o : %.c
	$(CC) -c $^ -o $@

clean :
	$(RM) $(OBJ) $(PROG)



