#ifndef __MOVES__
#define __MOVES__

void right(int* board, int size, int* score, int* count);
void left(int* board, int size, int* score, int* count);
void up(int* board, int size, int* score, int* count);
void down(int* board, int size, int* score, int* count);
int checkRight(int* board, int size);
int checkLeft(int* board, int size);
int checkDown(int* board, int size);
int checkUp(int* board, int size);

#endif
