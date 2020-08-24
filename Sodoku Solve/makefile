# Makefile comments
PROGRAMS = driver
CC = gcc
CFLAGS = -Wall -g
all: $(PROGRAMS)
clean:
	rm -f *.o

# C compilations
solverFunctions.o: solverFunctions.c solverFunctions.h
	$(CC) $(CFLAGS) -c solverFunctions.c
driver.o: driver.c solverFunctions.h
	$(CC) $(CFLAGS) -c driver.c

# Executable programs
driver: driver.o solverFunctions.o
	$(CC) $(CFLAGS) -o driver driver.o solverFunctions.o

