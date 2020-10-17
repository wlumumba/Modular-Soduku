#include "solverFunctions.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>


//Prints grid
void printSodoku(int grid[N][N])
{
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

bool solvePuzzle(int grid[N][N])
{
    int row = 0, col = 0, num = 0;
    
    if(!checkForZero(grid, &row, &col)) //Base case: find spot with a zero
        return true;

    for (num = 1; num <= N; num++)  //check all possibilities
    {  
        if(checkIfPossible(row, col, grid, num))
        {
            grid[row][col] = num;
            if(solvePuzzle(grid))
                return true;
            
            grid[row][col] = 0; //on backtrack
        }
    }
    
    return false;
}
bool checkForZero(int grid[N][N], int *row, int *col)
{
    int rowLoop, colLoop;

    for (rowLoop = 0; rowLoop < N; rowLoop++)
    {
        for(colLoop = 0; colLoop < N; colLoop++)
        {
            if(grid[rowLoop][colLoop] == 0)
            {
                *row = rowLoop;
                *col = colLoop;
                return true;
            }
        }
        
    }
    return false;
}

bool checkIfPossible(int row, int col, int grid[N][N], int value)
{
    int i = 0, j = 0, tempX = 0, tempY = 0;
    for(i = 0; i < N; i++)
    {
        if(grid[row][i] == value)
            return false;
        if(grid[i][col] == value)
            return false;
    }
    
    tempX = row - row%3;
    tempY = col - col%3;
    for(i = tempX; i < tempX + 3; i++)
    {
        for(j = tempY; j < tempY + 3; j++)
        {
            if(grid[i][j] == value)
                return false;
        }
    }
    return true;
}

//Delay function
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}