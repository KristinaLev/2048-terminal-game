#ifndef __PRINTFUNC__
#define __PRINTFUNC__


void printMax_Curr_Score(int score,int *best);
void printBoard(int* board, int size);
void printMenu();
int checkIfGameEnd(int* board, int size, int* count, int score, int* best);
int checkForNeighbors(int* board, int size);
int checkForTileWithMaxScore(int *board, int size,int maxScore);







#endif
