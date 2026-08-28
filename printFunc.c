#include <stdio.h>
#include "printFunc.h"



void printMax_Curr_Score(int score, int *best) {
	printf("Score %d Best %d\n", score, *best);


}
void printBoard(int* board, int size) {
	int i, j;
	for (j = 0; j < size; j++)
	{
		for (int line = size - 1; line < 7 * size; line++)
		{
			printf("-");
		}
		printf("\n");

		for (i = 0; i < size; i++)
		{
			char s = ' ';
			if (i == 0)
				printf("|");

			if (*board != 0)
			{
				printf("%4d |", *board);
				board++;
			}

			else if (*board == 0)
			{
				printf("%4c |", s);
				board++;
			}

		}
		printf("\n");
	}

	for (int line = size - 1; line < 7 * size; line++)
	{
		printf("-");
	}
	printf("\n");
	
}

void printMenu() {

	printf("N/n - New Game\n");
	printf("R/r - Move Right\n");
	printf("L/l - Move Left\n");
	printf("U/u - Move up\n");
	printf("D/d - Move Down\n");
	printf("E/e - Exit\n");

}

int checkIfGameEnd(int* board, int size, int* count, int score, int *best) {


	int check = checkForNeighbors(board, size);
	if (!check) {
		if(score>*best)
			*best=score;
		printMax_Curr_Score(score, best);
		printBoard(board, size);
		printf("Game over your score is %d\n", score);
		return 1;

	}
	return 0;
}

int checkForNeighbors(int* board, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if(j!=size-1)
			{
				if (*(board + size * i + j) == *(board + size * i + j + 1))
					return 1;
			}
			
			if (i != size - 1) 
			{
				if (*(board + size * i + j) == *(board + size * i + j + size))
					return 1;
			}
		}
	}
	return 0;
}


int checkForTileWithMaxScore(int *board, int size,int maxScore)
{
	int len = size * size;
	for(int i=0;i<len;i++)
	{
		if (*(board + i) == maxScore)	
			return 1;
	
	}			
	return 0;		
}








