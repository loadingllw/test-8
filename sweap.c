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
	//����������Ӧ������
	char mine[ROWS][COLS];//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS];//��ŵ����Ų�����׵���Ϣ

	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//������
	Setmine(mine,ROW,COL,COUNT);
	//Displayboard(mine, ROW, COL); 

	//�Ų���
	Findmine(mine, show, ROW, COL);
}

int main()
{
	int n = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();//ɨ����Ϸ��ʵ��
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (n);

	return 0;
}