
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
	//��ʼ������
	InitBoard(board);
	//��ӡ����
	PrintBoard(board,ROW,COL);
	//����
	do{
		//�������
		PlayerMove(board);
		PrintBoard(board,ROW,COL);
		//�ж��Ƿ����
		result = CheckOver(board);
		if('z' != result){
			break;
		}
		//��������
		AiMove(board);
		PrintBoard(board,ROW,COL);
		result = CheckOver(board);
		if('*' == result){
			printf("���ʤ��������\n");
			break;
		}else if('#' == result){
			printf("����ʤ��������\n");
			break;
		}else if('z' == result){
			printf("ƽ�֡�\n");
			break;
		}
	}while(1);
	if('*' == result){
		printf("���ʤ��������\n");
	}else if('#' == result){
		printf("����ʤ��������\n");
	}else if('z' == result){
		printf("ƽ�֡�\n");
	}
}

void menu()
{
	int input = 0;
	printf("************************************************\n");
	printf("*************** 1.start game 0.exit ************\n");
	printf("�����룺> ");
	scanf("%d",&input);
	printf("\n");
	switch(input)
	{
	case 1:
		printf("***************** ��Ϸ��ʼ *****************\n");
		startGame();
		break;
	case 0:
		printf("******************* �˳� *******************\n");
		break;
	default:
		printf("**************** �������*****************\n");
		break;
	}
}

int main()
{
	menu();
	return 0;
}