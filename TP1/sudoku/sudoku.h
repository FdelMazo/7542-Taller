#ifndef TP1_SUDOKU_H
#define TP1_SUDOKU_H

#include <stdlib.h>
#include "board.h"

#define SUDOKU_RANGE 9
#define SUDOKU_DIVISION 3

typedef struct {
    board_t board;
} sudoku_t;

// Initializes sudoku structure
// Returns false if any of the heap allocations fail, otherwise, returns true
bool sudoku_init(sudoku_t *self);

// Loads the original cells to play, from a given file
// The file must be formatted as 9 lines of numbers,
//   separated by spaces, with a 0 when a cell is to be left empty
// Returns false if fopen or any allocation fails, otherwise, returns true
bool sudoku_load(sudoku_t *self, char *filename);

// Responds whether a put is valid or not
// Returns:
//   0 if the put is valid
//   1 if (row,col) isn't in the supported range
//   2 if the number isn't in the supported range
int sudoku_put_valid(size_t n, size_t row, size_t col);

// Writes n in the position (row,col)
// (row,col) are indexes from 1 to SUDOKU_RANGE
// n is a number from 1 to SUDOKU_RANGE
// Returns:
//   -1 if the cell is an original (unmodifiable) one
//   0 if the number was written
//   1 or 2 if there was an error (specified in sudoku_put_valid)
int sudoku_put(sudoku_t *self, size_t n, size_t row, size_t col);

// Verifies the status of the board
// A board is valid if it doesn't have any repeated numbers in
//   the rows, columns, or sections
//   (which isn't to say it is mistake-free)
// A board isn't valid otherwise
// Returns true if the board is valid, false if it isn't
bool sudoku_verify(sudoku_t *self);

// Stores in the buf a printable representation of the board
void sudoku_get(sudoku_t *self, char *buf);

// Restores the board to the original one, without the user-modified cells
void sudoku_reset(sudoku_t *self);

// Releases the allocated memory inside the structure
void sudoku_release(sudoku_t *self);

#endif
