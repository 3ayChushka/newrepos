#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "RUS");

	int array[8][8];

	for (int i = 0; i < 8; i++)   /*Заполнение массива*/
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 0) /*Номера строк*/
			{
				array[0][j] = j;
				continue;
			}

			else if (j == 0) /* Номера столбцов*/
			{
				array[i][0] = i;
				continue;
			}
			array[i][j] = -10 + rand() % 21;  /*Заполнение остальных элементов*/
		}
	}

	for (int i = 0; i < 8; i++)    /*Вывод массива*/
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	} 
	
	printf("\n\nТранспонированный массив\n");
	
	for (int i = 0; i < 8; i++)    /*Вывод транспонированного массива*/
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d\t", array[j][i]);
		}
		printf("\n");
	}

	int m0=0;

	for (int i = 1; i < 8; i++)  /*Подсчёт элементов второго столбца, меньших 0*/
	{
		if (array[i][2] < 0)m0++;
	}
	printf("Во втором столбце %d элементов меньше 0\n\n", m0);

	int odinak=0;
	for (int y = 1; y < 8; y++)   /* Подсчёт одинаковых элементов в каждой строке*/
	{
		odinak = 0;
		for (int x = 2; x < 8; x++)
		{
			if (array[y][x] == array[y][x-1])odinak++;
		}
		printf("В %d строке %d одинаковых элементов\n", y, odinak);
	}

	int max = array[1][1], xmx=1, ymx=1;
	for (int i = 1; i < 8; i++)       /*Поиск координат максимального элемента*/
	{
		for (int j = 1; j < 8; j++)
		{
			if (max <= array[i][j])
			{
				max = array[i][j];
				xmx = i;
				ymx = j;
			}
		}
	}
	printf("Максимaльный элемент находится по координатам array[%d][%d]\n",xmx, ymx);
}
