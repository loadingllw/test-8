#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10

//��ʼ������
void Initboard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void Displayboard(char board[ROWS][COLS], int row, int col);


void Setmine(char mine[ROWS][COLS], int row, int col, int count);

//�Ų���
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);