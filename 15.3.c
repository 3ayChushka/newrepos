#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "RUS");

	int class[6][12];

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 12; j++)
			class[i][j] = 20 + rand() % 15;

	for (int q = 0; q < 12; q++)
		printf("%dП\t", q+1);
	printf("\n");

	for (int i = 1; i < 6; i++)
	{
		for (int j = 0; j < 12; j++)
			printf("%d      ", class[i][j]);
		printf("\n");
	}


	int v=10, chel;
	while (v != 0)
	{
		chel = 0;
		printf("Введите номер параллели, 0-Выход\n");
		scanf("%d", &v);
		if (v == 0)break;

		int j = v - 1;

		for (int i = 1; i < 6; i++)
			chel += class[i][j];

		printf("В %d параллели %d человек\n", v, chel);
	}
}
