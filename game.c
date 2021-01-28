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
			//x,y��û����
			mine[x][y] = '1';
			count--;
		}
	}
}
//�ú���������ͳ�ƣ�x,y��������Χ�м�����
int Getminecont(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}


//�Ų��ף��漰��������
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win<=row*col-COUNT)
	{
		printf("%������Ҫ�Ų������:>");
		int  x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		//����ĺϷ���
		//�ô������ǲ����ף����ǣ����жϸ�������Χ���׵ĸ���
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�ܿ�ϧ���㱻ը����\n");
				Displayboard(mine, row, col);
				break;
			}
			else
			{
				int count = Getminecont(mine, x, y);
				show[x][y] = count + '0';//��ŵ��������ַ�
				Displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if (win == row*col - COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		Displayboard(mine, row, col);
	}
}





