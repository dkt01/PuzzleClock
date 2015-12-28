/* puzzleclock.c
 * David Turner 2015
 *
 * Purpose: This file is the main program for PuzzleClock.
 */

#include <stdio.h>
#include <stdint.h>
#include "comstructs.h"
#include "boardFunctions.h"
#include "gui.h"

int main()
{
    board myBoard;
    board solBoard;
    char emptyString[] = "\0";
    char testTime[] = "IT IS TWENTY FIVE MINUTES PAST EIGHT AM\0";
    char testString[] = "AAAAACCCEEEEEEEEFFGHHIIIIIIIKLLMMNNNNNOOOOOPPQRRRRSSSSSTTTTTTTUUUVVWWXY\0";
    char testSolution[] = "NOOOO\0";
    initBoard(&solBoard,emptyString);
    initBoard(&myBoard,testString);

    uint8_t illumination = ON;

    for(uint8_t y = 0; y < HEIGHT; y++)
    {
        for(uint8_t x = 0; x < WIDTH; x++)
        {
            myBoard.elements[y][x].illumination = illumination;
            illumination = (illumination == ON ? OFF : ON);
        }
    }

    printBoard(&myBoard);

    illuminateSolution(&myBoard,testSolution);

    printBoard(&myBoard);

    generateSolution(&solBoard,testTime);

    printBoard(&solBoard);

    return 0;
}
