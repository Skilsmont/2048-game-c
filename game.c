#include <stdio.h>
#include <ctype.h>
#include "game.h"
#include "board.h"

void playGame(int* board, int size, int scoreToWin)
{
    int ngf = 0, best = 0, score = 0; // ngf - New Game Flag
    showBoard(board, size, &best, &score);
    showMenu();
    char ch;
    do
    {   
        do
        {
            ch = getchar();
        } while(isspace(ch));
        checkInput(board, size, scoreToWin, ch, &ngf, &best, &score);

    } while(ch != 'e' && ch != 'E');
    clearBoard(board, size);
    printf("Bye bye\n");
    
}

void showMenu()
{
    printf("Please choose one of the following options:\n");
    printf("N/n - New Game\n");
    printf("R/r - Move Right\n");
    printf("L/l - Move Left\n");
    printf("U/u - Move Up\n");
    printf("D/d - Move Down\n");
    printf("E/e - Exit\n");
}

void checkInput(int* board, int size, int scoreToWin, char ch, int* ngf, int* best, int* score) 
{
    if (ch == 'n' || ch == 'N') {
        *ngf = 1;
        newGame(board, size, scoreToWin, best, score);
    } else if (ch == 'e' || ch == 'E') {
        *ngf = 0;
        printf("Ending previous game - your score %d best score %d.\n\n", *score, *best);
    } else if (*ngf == 1) {
        handleMove(board, size, scoreToWin, ch, ngf, best, score);
    } else {
        printf("Need to start a game first!\n");
    }
}
    
void handleMove(int* board, int size, int scoreToWin, char ch, int* ngf, int* best, int* score) 
{
    int canMove = 0;
    int status;

    if (ch == 'r' || ch == 'R')
        canMove = moveRight(board, size, best, score);        
    else if (ch == 'l' || ch == 'L') 
        canMove = moveLeft(board, size, best, score);        

    else if (ch == 'u' || ch == 'U') 
        canMove = moveUp(board, size, best, score);        

    else if (ch == 'd' || ch == 'D') 
        canMove = moveDown(board, size, best, score);        

    else
    {
        printf("Wrong Input, please enter another char according to the menu.\n");
        return;
    }
        
    if (!canMove) {
        printf("Nothing to move in this direction, choose another option.\n\n");
        showMenu();
        return;
    }


    status = checkGameEnd(board, size, scoreToWin);
    if(status == 1)
    {
        printf("You won %d! - Ending Game.\n", scoreToWin);
        *ngf = 0;
    }
    else if(status == -1)
    {
        printf("Game over Your score is %d.\n", *score);
        *ngf = 0;
    }
    
}

void newGame(int* board, int size, int scoreToWin, int* best, int* score)
{
    if (!checkEmptyBoard(board, size))
        clearBoard(board, size);
    *score = 0;
    printf("--------------  STARTING A GAME  --------------\n");
	printf("           Higest tile for a win %d            \n", scoreToWin);
	printf("-----------------------------------------------\n");
    initBoard(board, size);
    showBoard(board, size, best, score);
    showMenu();
}

int moveRight(int* board, int size, int* best, int* score)
{
    if (moveHorizontal(board, size, -1, best, score) == 0)
        return 0; //Nothing to move in this direction
    setNewVal(board, size);
    showBoard(board, size, best, score);
    showMenu();
    return 1;

}

int moveLeft(int *board, int size, int* best, int* score)
{   
    if (moveHorizontal(board, size, 1, best, score) == 0)
        return 0; //Nothing to move in this direction
    setNewVal(board, size);
    showBoard(board, size, best, score);
    showMenu();
    return 1;
}

int moveUp(int *board, int size, int* best, int* score)
{
    if (moveVertical(board, size, 1, best, score) == 0)
        return 0; //Nothing to move in this direction
    setNewVal(board, size);
    showBoard(board, size, best, score);
    showMenu();
    return 1;
}

int moveDown(int *board, int size, int* best, int* score)
{
    if (moveVertical(board, size, -1, best, score) == 0)
        return 0; //Nothing to move in this direction
    setNewVal(board, size);
    showBoard(board, size, best, score);
    showMenu();
    return 1;
}

int moveVertical(int *board, int size, int direction, int* best, int* score)
// direction to determine rather to move up (1) or down (-1).
{
    int start = (direction == 1) ? 0 : size - 1;
    int end = (direction == 1) ? size : -1;
    int step = direction;
    int movementFlag = 0;
    int mergeFlag = 0;
    int generalMoveFlag = 0;
    

    for (int col = 0; col < size; col++)
    {
        movementFlag = slideVertical(board, size, col, start, end, step);
        mergeFlag = mergeVertical(board, size, col, start, end, step, best, score);
        if (movementFlag == 1 || mergeFlag == 1)
            generalMoveFlag = 1;
    }
    return generalMoveFlag;
}

int slideVertical(int* board, int size, int col, int start, int end, int step)
// move all the tiles to the desire direction
{
    int movementFlag = 0;
    for (int i = start; i != end; i += step)
    {
        if (*(board + i * size + col) == 0)
        {
            for (int k = i + step; k != end; k += step)
            {
                if (*(board + k * size + col) != 0)
                {
                    *(board + i * size + col) = *(board + k * size + col);
                    *(board + k * size + col) = 0;
                    movementFlag = 1;
                    break;
                }
            }
        }
    }
    return movementFlag;
}

int mergeVertical(int *board, int size, int col, int start, int end, int step, int* best, int* score)
// merge equals tiles
{
    int mergeFlag = 0;
    for (int i = start; i != end - step; i += step)
    {
        if (*(board + i * size + col) != 0 &&
            *(board + i * size + col) == *(board + (i + step) * size + col))
        {
            *(board + i * size + col) *= 2;
            *score += *(board + i * size + col);
            updateBestScore(best, score);
            *(board + (i + step) * size + col) = 0;
            mergeFlag = 1;

            for (int k = i + step; k != end - step; k += step)
            {
                *(board + k * size + col) = *(board + (k + step) * size + col);
                *(board + (k + step) * size + col) = 0;
            }
            break;
        }
    }
    return mergeFlag;
}

int moveHorizontal(int* board, int size, int direction, int* best, int* score)
// direction to determine rather to move left (1) or right (-1).
{
    int start = (direction == 1) ? 0 : size - 1;
    int end = (direction ==  1) ? size : -1;
    int step = direction;
    int movementFlag = 0;
    int mergeFlag = 0;
    int generalMoveFlag = 0;

    for(int row = 0; row < size; row++)
    {
        movementFlag = slideHorizontal(board, size, row, start, end, step);
        mergeFlag = mergeHorizontal(board, size, row, start, end, step, best, score);
        if (movementFlag == 1 || mergeFlag == 1)
                generalMoveFlag = 1;
    }
    return generalMoveFlag;
}

int slideHorizontal(int* board, int size, int row, int start, int end, int step)
// move all the tiles to the desire direction
{   
    int movementFlag = 0;
    for(int i = start; i != end; i += step)
    {
        if(*(board + i + size * row) == 0)
        {
            for(int k =  i + step; k != end; k += step)
            {
                if(*(board + k + row * size) != 0)
                {
                    *(board + i + size * row) = *(board + k + row * size);
                    *(board + k + row * size) = 0;
                    movementFlag = 1;
                    break;
                } 
            }
        }
    }
    return movementFlag;
}

int mergeHorizontal(int* board, int size, int row, int start, int end, int step, int* best, int* score)
// merge equals tiles
{
    int mergeFlag = 0;
    for(int i = start; i != end - step; i += step)
    {
        if (*(board + i + size * row) != 0 &&
            *(board + i + size * row) == *(board + i + size * row + step))
        {
            *(board + i + size * row) *= 2;
            *score += *(board + i + size * row);
            updateBestScore(best, score);
            *(board + i + size * row + step) = 0;
            mergeFlag = 1;

            for (int k = i + step; k != end - step; k += step)
            {
                *(board + k + size * row) = *(board + k + size * row + step);
                *(board + k + size * row + step) = 0;
            }
            break;
        }
    }
    return mergeFlag;
}

void updateBestScore(int* best, int* score)
{
    if(*score > *best)
        *best = *score;
}

int checkGameEnd(const int* board, int size, int scoreToWin) 
{
    int flag = -1; // set the flag to 'game over' state
    for (int i = 0; i < size * size; i++) 
    {
        if (*(board + i) == scoreToWin)
            {
                flag = 1; // tile equals to the maximum possible tile
                return flag; // exit and return 'win' state
            }

        if (*(board + i) == 0)
            flag = 0; // tile value is '0' - continue game

        if ((i + 1) % size != 0 && *(board + i) == *(board + i + 1))
            flag = 0; // current tile and the next right tile are equales - continue game
    
        if (i + size < size * size && *(board + i) == *(board + i + size))
            flag = 0; // current tile and the next tile below are equales - continue game
            
    }
    return flag; // return game over (-1) or continue game (0)
}