/* boardFunctions.c
 * David Turner 2015
 *
 * Purpose: This file contains helper functions for board manipulation.
 */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "comstructs.h"
#include "boardFunctions.h"

 uint8_t moveCell(board* inBoard, uint8_t dir)
{
    uint8_t oldX;
    uint8_t oldY;
    if(inBoard == NULL)
    {
        return FALSE;
    }

    oldX = inBoard->emptyIndexX;
    oldY = inBoard->emptyIndexY;

    switch(dir)
    {
        case UP:
            if(oldY == 0)
                return FALSE;
            inBoard->emptyIndexY -= 1;
        case RIGHT:
            if(oldX == WIDTH-1)
                return FALSE;
            inBoard->emptyIndexX += 1;
        case DOWN:
            if(oldY == HEIGHT-1)
                return FALSE;
            inBoard->emptyIndexY += 1;
        case LEFT:
            if(oldX == 0)
                return FALSE;
            inBoard->emptyIndexX -= 1;
        default:
            return FALSE;
    }
    return swap(&inBoard->elements[oldY][oldX],
                &inBoard->elements[inBoard->emptyIndexY][inBoard->emptyIndexX]);
}

uint8_t initBoard(board* inBoard, char* letterString)
{
    if(inBoard == NULL || letterString == NULL)
        return FALSE;

    uint8_t stopIndex = WIDTH * HEIGHT;

    char defaultChar = ' ';
    char curChar = ' ';

    for(uint8_t index = 0; index < stopIndex; index++)
    {
        if(curChar != '\0')
        {
            curChar = letterString[index];
        }
        if(curChar == '\0')
        {
            inBoard->elements[index/WIDTH][index%WIDTH].value = defaultChar;
        }
        else
        {
            inBoard->elements[index/WIDTH][index%WIDTH].value = curChar;
        }
        inBoard->elements[index/WIDTH][index%WIDTH].illumination = OFF;
    }

    return TRUE;
}

uint8_t printBoard(board* inBoard)
{
    if(inBoard == NULL)
        return FALSE;

    for(uint8_t y = 0; y < HEIGHT; y++)
    {
        for(uint8_t x = 0; x < WIDTH; x++)
        {
            printf(" %s%c",inBoard->elements[y][x].illumination == ON ? ONCOLOR : OFFCOLOR,
                           inBoard->elements[y][x].value);
        }
        printf("\n");
    }
    printf("%s",ONCOLOR);
    return TRUE;
}

uint8_t swap(letter* first, letter* second)
{
    if(first == NULL || second == NULL)
    {
        return FALSE;
    }
    letter temp = *first;
    *first = *second;
    *second = temp;
    return TRUE;
}
