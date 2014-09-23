/* gui.h
 * David Turner 2014
 *
 * Purpose: This file contains constants and function prototypes
 *          for the graphical user interface.
 */

#ifndef _GUI_H
#define _GUI_H

#include <curses.h>

void initscreen(WINDOW* inwindow, board* inboard);

void updatescreen(WINDOW* inwindow, board* inboard);

void displetter(WINDOW* inwindow, int x, int y, letter inletter);

#endif