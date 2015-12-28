# PuzzleClock
#####Word clock that moves letters around instead of merely illuminating the appropriate characters.

The idea behind this project is to combine a word clock with a sliding tile puzzle.  The letter tiles slide around the board to form time
words in five-minute intervals.  For example, "12:10" would be "IT IS TEN MINUTES PAST TWELVE PM" and "18:45" would be "IT IS QUARTER TO
SEVEN PM".

The project is written in C because I want it to be a lightweight, portable backend for a physical device at some point.  The physical
version will likely run off a simple microcontroller (probably Arduino because they're cheap and easy to find) that does not have much
memory or processing ability.
