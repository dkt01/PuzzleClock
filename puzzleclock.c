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
    char testString[] = "THIS NOT THATHAT IS A SOSOLUTION    HELLA HELLO WURLD?WORLD!\0";
    char testSolution[] = "THIS NOT THAT IS A SOLUTION HELLO WORLD!\0";
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
    return 0;
}
