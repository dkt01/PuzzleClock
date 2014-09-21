/* comstructs.h
 * David Turner 2014
 *
 * Purpose: This file contains structure definitions used amongst
 *          many files.  Requisite constants are also defined here.
 */

#ifndef _COMSTRUCTS_H
#define _COMSTRUCTS_H

/* Board is defined as an 11x5 grid.  This is not
 * modifiable to simplify future processes
 */

#define WIDTH  11
#define HEIGHT 5
#define ON  1
#define OFF 0

typedef struct letter
{
    char value;
    char illumination;
} letter;

typedef struct board
{
    letter[WIDTH][HEIGHT] elements;
} board;

#endif