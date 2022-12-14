
#include "game.h"
#include <time.h>
#include <stdlib.h>

void InitBoard(char board[ROW][COL]){
	int i=0,j=0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col){
	int i=0,j=0;
	for(i;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(j<col-1)
				printf(" %c |",board[i][j]);
			else
				printf(" %c \n",board[i][j]);
		}
		for(j=0;j<col&&i<row-1;j++)
		{
			if(j<col-1)
				printf("---|");
			else
				printf("---\n");
		}
	}
}

char CheckOver(char board[ROW][COL])
{
	int i = 0,j=0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL-1;j++)
		{
			if(board[i][j] != board[i][j+1])
			{
				break;
			}
		}
		if(j == COL - 1 && board[i][j-1] == board[i][j] && board[i][j] != ' ')
		{
			return board[i][j];
		}
	}

	for(i=0;i<COL;i++)
	{
		for(j=0;j<ROW-1;j++)
		{
			if(board[j][i] != board[j+1][i])
			{
				break;
			}
		}
		if(j == COL - 1 && board[j][i] == board[j-1][i] && board[j][i] != ' ')
		{
			return board[j][i];
		}
	}

	for(i=0;i<ROW-1;i++)
	{
		if(board[i][i] != board[i+1][i+1])
		{
			break;
		}
		if(i == ROW - 2 && board[i][i] == board[i+1][i+1] && board[i+1][i+1] != ' ')
		{
			return board[i][i];
		}
	}


	for(i=0,j=COL-1;i<ROW-1;i++,j--)
	{
		if(board[i][j] != board[i+1][j-1])
		{
			break;
		}
		if(i == ROW - 2 && board[i][j] == board[i+1][j-1] && board[i][j] != ' ')
		{
			return board[i][j];
		}
	}

	if(isFull(board))
	{
		return 'z';
	}
	return '1';
}

int isFull(char board[ROW][COL]){
	int i=0,j=0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

void PlayerMove(char board[ROW][COL]){
	int row = 0, col = 0;
	do{
		printf("玩家下：\n");
		printf("请输入位置：> ");
		scanf("%d %d",&row,&col);
		printf("\n");
		if(' ' == board[row-1][col-1]){
			board[row-1][col-1] = '*';
			break;
		}else if(row < 1 || row > ROW || col < 1 || col > COL){
			printf("输入位置不合法，请重新输入！\n");
		}else{
			printf("位置已有棋子，请重新输入！\n");
		}
	}while(1);
}

void AiMove(char board[ROW][COL]){
	int row = 0,col = 0;
	srand((unsigned)time(NULL));
	printf("电脑下：\n");
	while(1){
		row = rand()%ROW;
		col = rand()%COL;
		if(' ' == board[row][col]){
			board[row][col] = '#';
			return;
		}
	}
}