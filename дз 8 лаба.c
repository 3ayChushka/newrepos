#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "RUS");

	int x, c=1, z=1;

	printf("Введите x\n");
	scanf("%d", &x);

	for (int a = 1; a < 64; a = a * 2 + 1)
	{
		c *= (x - a);
	}

	for (int b = 2; b < 65; b = b * 2)
	{
		z *= (x - b);
	}

	printf("Ответ: %lf\n\n", (float)c / (float)z);
	
}