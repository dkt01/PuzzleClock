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

    inBoard->emptyIndexX = WIDTH-1;
    inBoard->emptyIndexY = HEIGHT-1;

    return TRUE;
}

uint8_t printBoard(board* inBoard)
{
    if(inBoard == NULL)
        return FALSE;

    printf("\n");
    for(uint8_t y = 0; y < HEIGHT; y++)
    {
        for(uint8_t x = 0; x < WIDTH; x++)
        {
            printf(" %s%c",inBoard->elements[y][x].illumination == ON ? ONCOLOR : OFFCOLOR,
                           x == inBoard->emptyIndexX && y == inBoard->emptyIndexY ? '#' : inBoard->elements[y][x].value);
        }
        printf("\n");
    }
    printf("%s\n",ONCOLOR);
    return TRUE;
}

int32_t distToSolution(board* inBoard, char* solution)
{
    for(uint8_t y = 0; y < HEIGHT; y++)
    {
        for(uint8_t x = 0; x < WIDTH; x++)
        {

        }
    }
    return 0;
}

uint8_t illuminateSolution(board* inBoard, char* solution)
{
    if(inBoard == NULL || solution == NULL)
    {
        return FALSE;
    }
    uint8_t solutionIndex = 0;
    uint8_t inWord = FALSE;
    uint8_t len = 0;
    for(uint8_t y = 0; y < HEIGHT; y++)
    {
        for(uint8_t x = 0; x < WIDTH; x++)
        {
            if(solution[solutionIndex] == '\0')
            {
                deluminateLine(inBoard,y,x);
                break;
            }
            else if(solution[solutionIndex] == ' ')
            {
                inWord = FALSE;
                inBoard->elements[y][x].illumination = OFF;
                solutionIndex++;
                if(x == 0)
                {
                    x--;
                }
                continue;
            }
            else if(inWord == FALSE)
            {
                len = wordLength(&solution[solutionIndex]);
                inWord = TRUE;
            }
            if(len > (WIDTH - x))
            {
                deluminateLine(inBoard,y,x);
                break;
            }
            if(solution[solutionIndex] == inBoard->elements[y][x].value &&
               checkWord(inBoard, &solution[solutionIndex], y, x) == TRUE)
            {
                inBoard->elements[y][x].illumination = ON;
                solutionIndex++;
                len--;
            }
            else
            {
                inBoard->elements[y][x].illumination = OFF;
            }
        }
    }
    return TRUE;
}

uint8_t generateSolution(board* solBoard, char* solution)
{
    if(solBoard == NULL || solution == NULL)
    {
        return FALSE;
    }

    uint8_t solutionIndex = 0;
    uint8_t inWord = FALSE;
    uint8_t len = 0;
    for(uint8_t y = 0; y < HEIGHT; y++)
    {
        for(uint8_t x = 0; x < WIDTH; x++)
        {
            if(solution[solutionIndex] == '\0')
            {
                return TRUE;
            }
            else if(solution[solutionIndex] == ' ')
            {
                inWord = FALSE;
                solutionIndex++;
                if(x == 0)
                {
                    x--;
                }
                continue;
            }
            else if(inWord == FALSE)
            {
                len = wordLength(&solution[solutionIndex]);
                inWord = TRUE;
            }
            if(len > (WIDTH - x))
            {
                break;
            }
            else
            {
                solBoard->elements[y][x].illumination = ON;
                solBoard->elements[y][x].value = solution[solutionIndex];
                solutionIndex++;
                len--;
            }
        }
    }
    return FALSE;
}

uint8_t checkWord(board* inBoard, char* word, uint8_t y, uint8_t x)
{
    if(inBoard == NULL || word == NULL)
    {
        return FALSE;
    }

    uint8_t i = 0;

    while(TRUE)
    {
        if(word[i] == ' ' || word[i] == '\0')
        {
            break;
        }
        if(i + x >= WIDTH)
        {
            return FALSE;
        }
        if(word[i] != inBoard->elements[y][x+i].value)
        {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

uint8_t wordLength(char* string)
{
    if(string == NULL)
    {
        return FALSE;
    }
    uint8_t length = 0;
    while(string[length] != ' ' && string[length] != '\0')
    {
        length++;
    }
    return length;
}

uint8_t deluminateLine(board* inBoard, uint8_t y, uint8_t x)
{
    if(inBoard == NULL || y >= HEIGHT)
    {
        return FALSE;
    }
    for(; x < WIDTH; x++)
    {
        inBoard->elements[y][x].illumination = OFF;
    }
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
