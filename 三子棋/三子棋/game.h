#define ROW 3
#define COL 3

#include <stdio.h>

void InitBoard(char board[ROW][COL]);

void PrintBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL]);

void AiMove(char board[ROW][COL]);

char CheckOver(char board[ROW][COL]);