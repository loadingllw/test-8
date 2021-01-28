#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------------------------------\n");
	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------\n");
}


void Setmine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		//1-9
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			//x,y处没有雷
			mine[x][y] = '1';
			count--;
		}
	}
}
//该函数是用来统计（x,y）坐标周围有几个雷
int Getminecont(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}


//排查雷，涉及两个数组
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win<=row*col-COUNT)
	{
		printf("%请输入要排查的坐标:>");
		int  x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		//坐标的合法性
		//该处坐标是不是雷？不是，则判断该坐标周围的雷的个数
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很可惜，你被炸死了\n");
				Displayboard(mine, row, col);
				break;
			}
			else
			{
				int count = Getminecont(mine, x, y);
				show[x][y] = count + '0';//存放的是数字字符
				Displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == row*col - COUNT)
	{
		printf("恭喜你，排雷成功\n");
		Displayboard(mine, row, col);
	}
}





