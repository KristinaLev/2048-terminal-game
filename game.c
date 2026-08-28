#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "game.h"
#include "moves.h"
#include "printFunc.h"
#define MAX 100
#define MIN 1


void playGame(int* board, int size, int scoreToWin)
{


	userChoice(board, size,scoreToWin);


}

void addRandomTile(int* board, int size, int* count) {
	if (*count <= 0)
		return;
	
	int randnum, num;
	randnum = MIN + (rand() % (MAX - MIN + 1));
	if (randnum > 30) {
		num = 2;
	}
	else {
		num = 4;
	}
	int blank = 0 + (rand() % (*(count)));
	int size1 = size * size;
	for (int i = 0; i < size1; i++) {
		if (*(board + i) == 0) {
			if (blank == 0) {
				*(board + i) = num;
				(*count)--;
				break;

			}

			blank--;
		}

	}
}


void restart(int* board, int size) {
	int size1 = size * size;
	for (int i = 0; i < size1; i++)
		*(board + i) = 0;


}


void init(int* board, int size, int* count, int *maxScore)
{
	printf("----------- STARTING A GAME -----------\n");
	printf("        Highest tile for a win %d      \n", *maxScore);
	printf("---------------------------------------\n");
	printf("\n");
	
	restart(board, size);
	addRandomTile(board, size, count);
	addRandomTile(board, size, count);
	
	
}



void userChoice(int* board, int size, int scoreToWin)
{
	int gameOver = 0;
	int check = 0; //checks if you can make a certain move
	char userChoice;
	int count = size * size; //checks the amount of empty cells can be used to check if the game ended if used correctly 
	int best = 0;
	int start = 0; //checks if you started the game
	int score = 0;
	
	restart(board, size);//cleans the board after ending one game
	printBoard(board,size);
	int firstBoardPrinted=1; 
	do {	
		
		if(score>best)//check if you can update the best score 
			best=score;
			
		int res = checkForTileWithMaxScore(board, size, scoreToWin);
		if (res == 1)//check for tile with max score
		{
			gameOver=1;
			printMax_Curr_Score(score, &best);
			printBoard(board, size);
			printf("You won %d! - Ending Game\n", scoreToWin);
			
			check=0;
			start=0;
			restart(board,size);
		}
			
			
		if (count == 0) {
			int res = checkIfGameEnd(board, size, &count, score, &best);
			if (res ) {
				start = 0;
				score = 0;
				count = size * size;
				gameOver = 1;
			}
		}
		
		
		if(start && check)
		{
			printMax_Curr_Score(score, &best);
			printBoard( board,  size);	
		}
		else if(!start && !firstBoardPrinted)
		{
			if(!gameOver)
			{
				printBoard(board,size);
				firstBoardPrinted=1;	
			}	
		}		
		
		printf("\n\n");
		printf("please choose one of the following options:\n");
		printMenu();
		do {
			scanf("%c", &userChoice);
		} while (isspace(userChoice));

		switch (userChoice)
		{

		case 'N':
		case 'n':
			count = size * size;
			init(board, size, &count, &scoreToWin);
			score = 0;
			start = 1;
			check = 1;
			firstBoardPrinted=0;
			gameOver = 0;

			break;

		case 'R':
		case 'r':
			if (start == 0)
			{
				printf("need to start game first \n");
				
			}
			else {
				check = checkRight(board, size);
				if (check) {
					right(board, size, &score, &count);
					addRandomTile(board, size, &count);
				}
				else {
					printf("Nothing to move in this direction, choose another option \n");

				}
			}
			break;

		case 'L':
		case 'l':
			if (start == 0)
			{
				printf("need to start game first \n");
				printf("\n\n");

			}
			else {
				check = checkLeft(board, size);
				if (check) {
					left(board, size, &score, &count);
					addRandomTile(board, size, &count);
				}
				else printf("Nothing to move in this direction, choose another option \n");
			}

			break;

		case 'U':
		case 'u':
			if (start == 0)
			{
				printf("need to start game first \n");
				printf("\n\n");

			}
			else {
				check = checkUp(board, size);
				if (check) {

					up(board, size, &score, &count);
			
					addRandomTile(board, size, &count);
				}
				else printf("Nothing to move in this direction, choose another option \n");

			}
			break;

		case 'D':
		case 'd':
			if (start == 0)
			{
				printf("need to start game first \n");
				printf("\n\n");

			}
			else {
				check = checkDown(board, size);
				if (check) {
					down(board, size, &score, &count);
					addRandomTile(board, size, &count);
				}
				else printf("Nothing to move in this direction, choose another option \n");
			}
			break;
		case 'E':
		case 'e':
			if(best==0)
				best=score;
			printf("Ending previous game - your score %d best score %d \n\n", score, best);
			printf("bye bye\n");
			break;

		default:
			printf("Invalid choice, please try again.\n");
		}
	} while (userChoice != 'E' && userChoice != 'e');

}

