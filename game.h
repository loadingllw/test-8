#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10

//≥ı ºªØ∆Â≈Ã
void Initboard(char board[ROWS][COLS], int rows, int cols, char set);

//¥Ú”°∆Â≈Ã
void Displayboard(char board[ROWS][COLS], int row, int col);


void Setmine(char mine[ROWS][COLS], int row, int col, int count);

//≈≈≤È¿◊
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);