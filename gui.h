/* gui.h
 * David Turner 2015
 *
 * Purpose: This file contains constants and function prototypes
 *          for the graphical user interface.
 */

#ifndef _GUI_H
#define _GUI_H

#include <curses.h>

void initscreen(WINDOW* inWindow, board* inBoard);

void updatescreen(WINDOW* inWindow, board* inBoard);

void dispLetter(WINDOW* inWindow, int x, int y, letter inLetter);

#endif