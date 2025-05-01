#ifndef __GAME__
#define __GAME__
void playGame(int* board , int size , int scoreToWin);
void showMenu();
void checkInput(int* board, int size, int scoreToWin, char ch, int* ngf, int* best, int* score);
void handleMove(int* board, int size,int scoreToWin, char ch, int* ngf, int* best, int* score);
void newGame(int* board, int size, int scoreToWin, int* best, int* score);
int moveRight(int* board, int size, int* best, int* score);
int moveLeft(int* board, int size, int* best, int* score);
int moveUp(int* board, int size, int* best, int* score);
int moveDown(int* board, int size, int* best, int* score);
int moveVertical(int *board, int size, int direction, int* best, int* score);
int slideVertical(int* board, int size, int col, int start, int end, int step);
int mergeVertical(int* board, int size, int col, int start, int end, int step, int* best, int* score);
int moveHorizontal(int* board, int size, int direction, int* best, int* score);
int slideHorizontal(int* board, int size, int row, int start, int end, int step);
int mergeHorizontal(int* board, int size, int row, int start, int end, int step, int* best, int* score);
void updateBestScore(int* best, int* score);
int checkGameEnd(const int* board, int size, int scoreToWin);
#endif