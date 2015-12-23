/* boardFunctions.h
 * David Turner 2015
 *
 * Purpose: This file contains definitions for board manipulation functions.
 */

#ifndef _BOARDFUNCTIONS_H
#define _BOARDFUNCTIONS_H

#include <stdint.h>
#include "comstructs.h"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define ONCOLOR "\x1B[0m"
#define OFFCOLOR "\x1B[34m"

uint8_t moveCell(board* inBoard, uint8_t dir);

uint8_t initBoard(board* inBoard, char* letterString);

uint8_t printBoard(board* inBoard);

int32_t distToSolution(board* inBoard, char* solution);

uint8_t illuminateSolution(board* inBoard, char* solution);

uint8_t wordLength(char* string);

uint8_t deluminateLine(board* inBoard, uint8_t y, uint8_t x);

uint8_t swap(letter* first, letter* second);

#endif
