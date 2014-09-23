# Makefile
# David Turner 2014
#
# Purpose: Builds PuzzleClock executable

all: comstructs.h gui.h puzzleclock.c
	gcc -Wall -g -o puzzleclock puzzleclock.c
clang: comstructs.h gui.h puzzleclock.c
	clang -Wall -g -o puzzleclock puzzleclock.c
clean:
	rm puzzleclock puzzleclock.dSYM