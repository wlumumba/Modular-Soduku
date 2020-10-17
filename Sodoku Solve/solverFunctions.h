#ifndef _solverFunctions_h
#define _solverFunctions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 9 //Length of one row

void printSodoku(int grid[N][N]);
bool solvePuzzle(int grid[N][N]);
bool checkForZero(int grid[N][N], int *row, int *col);
bool checkIfPossible(int row, int col, int grid[N][N], int value);
void delay(int milliseconds);


#endif