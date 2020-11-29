CC = gcc
AR = ar
OBJECTS_MAIN = main.o
FLAGS = -Wall -g

all: myBanks mains

mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a

functions: myBanks.c
	$(CC) $(FLAGS) -c myBank.c

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBanks: myBank.o
	$(AR) -rcs libmyBank.a myBank.o

.PHONY: clean all          

clean:
	rm -f *.o all
