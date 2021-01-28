#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"


void menu()
{
	printf("********************************\n");
	printf("*****       1.play        ******\n");
	printf("*****       0.exit        ******\n");
	printf("********************************\n");
}

void game()
{
	//创建棋盘相应的数组
	char mine[ROWS][COLS];//存放布置好的雷的信息
	char show[ROWS][COLS];//存放的是排查出的雷的信息

	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//布置雷
	Setmine(mine,ROW,COL,COUNT);
	//Displayboard(mine, ROW, COL); 

	//排查雷
	Findmine(mine, show, ROW, COL);
}

int main()
{
	int n = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();//扫雷游戏的实现
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (n);

	return 0;
}