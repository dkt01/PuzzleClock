/* comstructs.h
 * David Turner 2015
 *
 * Purpose: This file contains structure definitions used amongst
 *          many files.  Requisite constants are also defined here.
 */

#ifndef _COMSTRUCTS_H
#define _COMSTRUCTS_H

#include <stdint.h>

/* Board is defined as an 11x5 grid.  This is not
 * modifiable to simplify future processes
 */

#define WIDTH  11
#define HEIGHT 5
#define ON  1
#define OFF 0
#define TRUE 1
#define FALSE 0

typedef struct letter
{
    char value;
    uint8_t illumination;
} letter;

typedef struct board
{
    letter elements[HEIGHT][WIDTH];
    unsigned emptyIndexX;
    unsigned emptyIndexY;
} board;

#endif