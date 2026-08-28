#ifndef __GAME__
#define __GAME__


void playGame(int* board, int size, int scoreToWin);
void init(int* board, int size, int* count, int * maxScore);
void userChoice(int* board, int size, int scoreToWin);
void addRandomTile(int* board, int size, int* count);
void restart(int* board, int size);

#endif
