#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "solverFunctions.h"

int main(int argc, char *argv[])
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
    
    
    //Print statements
    printf("*** WELCOME ***\n\n Sodoku Puzzle Solver\n\n************\n\n");
    delay(1000);

    printSodoku(grid);
    
    char c;
    printf("This is current unsolved puzzle. Do you want to solve? (yes or no)? ");
    scanf("%c", &c);
    if(c != 'y')
        return 1;
    
    printf("\nSolution:\n");
    if(solvePuzzle(grid))
        printSodoku(grid);
    else
        printf(" No possible solutions using soduku rules.\n\n");
    
    
    return 0;
}