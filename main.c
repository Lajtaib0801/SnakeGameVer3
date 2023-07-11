#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>

#define ROWS 20
#define COLS 20


void go(char* map, char dir, int* row, int* col);
void draw(char* map, int row, int col);
void fill(char* map);

int main(void)
{
	HWND wh = GetConsoleWindow();
	MoveWindow(wh, 100, 100, 700, 700, TRUE);

	char* map = malloc((ROWS * COLS) * sizeof(char));

	fill(map);

	
	int curr_r = 10;
	int curr_c = 10;
	char direction = '\0';
	do 
	{
		draw(map, curr_r, curr_c);
		direction = _getch();
		go(map, direction, &curr_r, &curr_c);

	} while (direction != 'q');


	free(map);
	return 0;
}


void fill(char* map)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
				map[i * COLS + j] = '1';
			else
				map[i * COLS + j] = ' ';
		}
	}
}
void go(char* map, char dir, int* row, int* col)
{
	if (dir == 'w')
	{
		map[(*row) * COLS + (*col)] = ' ';
		(*row)--;
	}
	else if (dir == 'a')
	{
		map[(*row) * COLS + (*col)] = ' ';
		(*col)--;
	}
	else if (dir == 's')
	{
		map[(*row) * COLS + (*col)] = ' ';
		(*row)++;
	}
	else if (dir == 'd')
	{
		map[(*row) * COLS + (*col)] = ' ';
		(*col)++;
	}
}
void draw(char* map, int row, int col)
{
	system("cls");
	map[row * COLS + col] = '#';
	for (int i = 0; i < ROWS; i++)
	{
		printf("\t\t");
		for (int j = 0; j < COLS; j++)
		{
			printf("%c", map[i * COLS + j]);

		}
		printf("\n");
	}
}