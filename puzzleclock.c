/* puzzleclock.c
 * David Turner 2014
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
    char testString[] = "This Is A Test of Everything...ish but It's not perfect";
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
    return 0;
}
