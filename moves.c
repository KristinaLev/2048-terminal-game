#include "moves.h"



void right(int* board, int size, int* score, int* count) {
    for (int i = 0; i < size; i++) {
        int zero = 0;
        int colide = 0; //checks if two tiles united 
        for (int j = size - 1; j >= 0; j--) {
            if (*(board + size * i + j) == 0)zero++;
            else {
                if (zero != 0) {
                    *(board + size * i + j + zero) = *(board + size * i + j);
                    *(board + size * i + j) = 0;
                }
                if (j != size-1 && colide==0)
                    if (*(board + size * i + j + zero) == *(board + size * i + j + zero + 1) && j + zero != size - 1) {
                        *(board + size * i + j + zero + 1) = *(board + size * i + j + zero) * 2;
                        *score += *(board + size * i + j + zero + 1);
                        *(board + size * i + j + zero) = 0;
                        (*count)++;
                        colide++;
                        zero++;
                }
            }
        }
    }
}






void left(int* board, int size, int* score, int* count) {
    for (int i = 0; i < size; i++) {
        int zero = 0;
        int colide = 0;
        for (int j = 0; j < size; j++) {
            if (*(board + size * i + j) == 0)zero++;
            else {
                if (zero != 0) {
                    *(board + size * i + j - zero) = *(board + size * i + j);
                    *(board + size * i + j) = 0;
                }
                if (j != 0 && colide == 0)

                if (*(board + size * i + j - zero) == *(board + size * i + j - zero - 1) && j - zero != 0) {
                    *(board + size * i + j - zero - 1) = *(board + size * i + j - zero) * 2;
                    *score += *(board + size * i + j - zero -1);
                    *(board + size * i + j - zero ) = 0;
                    (*count)++;
                    colide++;
                    zero++;
                }
            }
        }
    }

}
void up(int* board, int size, int* score, int* count) {
    for (int j = 0; j < size; j++) {
        int colide = 0;
        int zero = 0;
        for (int i = 0; i < size; i++) {
            if (*(board + size * i + j) == 0)zero = zero + 1 * size;

            else {
                
                if (zero != 0) {
                    *(board + size * i + j - zero) = *(board + size * i + j);
                    *(board + size * i + j) = 0;
                }
               if (i != 0 && colide ==0)
                   if (*(board + size * i + j - zero) == *(board + size * i + j - zero - size) && board + size * i + j - zero > board + size - 1) {
                            *(board + size * i + j - zero - size) = *(board + size * i + j - zero) * 2;
                            *score += *(board + size * i + j - zero - size);
                            *(board + size * i + j - zero) = 0;
                            (*count)++;
                            zero = zero + 1 * size;
                            colide++;
                            
                     }
                }
            }
        }
    }





void down(int* board, int size, int* score, int* count) {
    for (int j = 0; j < size; j++) {
        int colide = 0;
        int zero = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (*(board + size * i + j) == 0)zero = zero + 1 * size;
            else {
                if (zero != 0) {
                    *(board + size * i + j + zero) = *(board + size * i + j);
                    *(board + size * i + j) = 0;
                }
                if (i != size-1 && colide==0)
                    if (*(board + size * i + j + zero) == *(board + size * i + j + zero + size) && board + size * i + j + zero < board + size*(size-1)) {
                            int mergedValue = *(board + size * i + j + zero) * 2;
                            *(board + size * i + j + zero + size) = mergedValue;
                            *score += mergedValue;
                            *(board + size * i + j + zero) = 0; 
                            (*count)++;
                            zero = zero + 1 * size;
                            colide++;
                        }
                }
            }
        }
    }
int checkRight(int* board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (*(board + size * i + j) == *(board + size * i + j + 1) && *(board + size * i + j) != 0)
                return 1;
            if (*(board + size * i + j) != 0 && *(board + size * i + j + 1) == 0)
                return 1;

        }
    }
    return 0;
}


int checkLeft(int* board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > 0; j--) {
            if (*(board + size * i + j) == *(board + size * i + j - 1) && *(board + size * i + j) != 0)
                return 1;

            if (*(board + size * i + j) != 0 && *(board + size * i + j - 1) == 0)
                return 1;




        }
    }
    return 0;
}

int checkDown(int* board, int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size-1; i++) {
            if (*(board + size * i + j) == *(board + size * i + j +size) && *(board + size * i + j) != 0)
                return 1;
            if (*(board + size * i + j) != 0 && *(board + size * i + j + size) == 0)
                return 1;



        }
    }
    return 0;



}

int checkUp(int* board, int size) {
    for (int j = 0; j < size; j++) {
        for (int i = size - 1; i > 0; i--) {
            if (*(board + size * i + j) == *(board + size * i + j - size) && *(board + size * i + j) != 0)
                return 1;
            if (*(board + size * i + j) != 0 && *(board + size * i + j - size) == 0)
                return 1;



        }
    }
    return 0;
}
