#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "RUS");

	float array[50][50];
	int h, w;

	printf("Введите количество строк\n");
	scanf("%d", &h);
	getchar();

	printf("Введите количество столбцов\n");
	scanf("%d", &w);
	getchar();

	for (int i = 0; i < h; i++)   /*Заполнение массива*/
	{
		for (int j = 0; j < w; j++)
		{
			if (i == 0) /*Номера строк*/
			{
				array[0][j] = j;
				printf("%.0f      ", array[0][j]);
				continue;
			}

			else if (j == 0) /* Номера столбцов*/
			{
				array[i][0] = i;
				printf("%.0f   ", array[i][0]);
				continue;
			}
			array[i][j] = (float)i / (float)j;  /*Заполнение остальных элементов*/
			printf("%.2f   ", array[i][j]);
		}
		printf("\n");
	}

	printf("Элемент в левом верхнем углу массивы - %.2f\n", array[1][1]);

	int stroka_min;
	printf("Введите номер строки, среди которой будет найден минимальный элемент\n");
	scanf("%d", &stroka_min);

	float min = array[stroka_min][1];

	for (int j = 2; j < w; j++)
	{
		if (min >= array[stroka_min][j]) min = array[stroka_min][j];
	}

	printf("Минимальный элемент %d строки = %.2f\n", stroka_min, min);
}
