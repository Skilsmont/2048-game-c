#ifndef __BOARD__
#define __BOARD__
#define MIN 0
#define VAL_A 2 // higher probability value
#define VAL_B 4 // lower probability value
#define PROB 0.7
void showBoard(const int* board, int size, const int* best, const int* score);
int checkEmptyBoard(const int* board, int size);
void initBoard(int* board, int size);
int getRandomIndex(const int* board, int size);
void setNewVal(int* board, int size);
int getRandomVal();
void clearBoard(int* board, int size);
#endif