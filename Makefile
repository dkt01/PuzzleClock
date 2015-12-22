# Makefile
# David Turner 2015
#
# Purpose: Builds PuzzleClock executable

CFLAGS = -Wall -g

all: boardFunctions puzzleclock.c
	$(CC) $(CFLAGS) -o puzzleclock puzzleclock.c boardFunctions.o
boardFunctions: comstructs.h boardFunctions.h boardFunctions.c
	$(CC) $(CFLAGS) -c -o boardFunctions.o boardFunctions.c
clean:
	rm puzzleclock *.o
	rm -rf *.dSYM
