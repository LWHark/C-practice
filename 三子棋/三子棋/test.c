
#include <stdio.h>
#include "game.h"
#include <stdlib.h>
#include <time.h>

void startGame()
{
	char board[ROW][COL] = {0};
	int row = 0,col = 0;
	char result = ' ';
	srand((unsigned)time(NULL));
	//初始化棋盘
	InitBoard(board);
	//打印棋盘
	PrintBoard(board,ROW,COL);
	//下棋
	do{
		//玩家下棋
		PlayerMove(board);
		PrintBoard(board,ROW,COL);
		//判断是否结束
		result = CheckOver(board);
		if('z' != result){
			break;
		}
		//电脑下棋
		AiMove(board);
		PrintBoard(board,ROW,COL);
		result = CheckOver(board);
		if('*' == result){
			printf("玩家胜利！！！\n");
			break;
		}else if('#' == result){
			printf("电脑胜利！！！\n");
			break;
		}else if('z' == result){
			printf("平局。\n");
			break;
		}
	}while(1);
	if('*' == result){
		printf("玩家胜利！！！\n");
	}else if('#' == result){
		printf("电脑胜利！！！\n");
	}else if('z' == result){
		printf("平局。\n");
	}
}

void menu()
{
	int input = 0;
	printf("************************************************\n");
	printf("*************** 1.start game 0.exit ************\n");
	printf("请输入：> ");
	scanf("%d",&input);
	printf("\n");
	switch(input)
	{
	case 1:
		printf("***************** 游戏开始 *****************\n");
		startGame();
		break;
	case 0:
		printf("******************* 退出 *******************\n");
		break;
	default:
		printf("**************** 输入错误！*****************\n");
		break;
	}
}

int main()
{
	menu();
	return 0;
}