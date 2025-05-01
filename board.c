#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void showBoard(const int *board, int size,const int* best, const int* score)
{
    int i, j, n;
    int rowLen = size + 1 + size * 6;
    printf("Score %d Best %d\n", *score, *best);
    for (i = 0; i < size; i++)
    {
        for (n = rowLen; n > 0; n--)
        {
            printf("-");
        }
        printf("\n");
        for(j = 0; j < size; j++, board++)
        {
            *board > 0 ? printf("| %4d ", *board) : printf("|      "); 
        }
        printf("|\n");  
    }
    for (n = rowLen; n > 0; n--)
    {
        printf("-");
    } 
    printf("\n");
}

int checkEmptyBoard(const int *board, int size)
{   
    int i;
    for(i = 0; i < size * size; i++, board++)
    {
        if(*board != 0)
        return 0;
    }
    return 1;
}

void initBoard(int *board, int size)
{
    setNewVal(board, size);
    setNewVal(board, size);
}

int getRandomIndex(const int *board, int size)
{
    int index;
    int max = size * size - 1;
   
    do {
        index = MIN + (rand() % (max - MIN + 1));
    } while (*(board + index) != 0);

    return index;
}

void setNewVal(int *board, int size)
{
    int index = getRandomIndex(board, size);
    int value = getRandomVal();
    *(board + index) = value;
}

int getRandomVal()
{
    double probability = (double)rand() / RAND_MAX;

    if (probability < PROB)
        return VAL_A;
    else
        return VAL_B;
}

void clearBoard(int *board, int size)
{
    int i;
    for(i = 0; i < size * size; i++, board++)
    {
        *board = 0;
    }
}
