#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int del(double* ptr_array, int size, int k);

int main()
{
	setlocale(LC_ALL, "RUS");

	/*10+(float)rand() / (float)(RAND_MAX)* 40*/

	double* a, * b, * c, *d;
	int size;

	printf("Введите размер массивов\n");
	scanf("%d", &size);

	a = (double*)malloc(size * sizeof(double));
	b = (double*)malloc(size * sizeof(double));
	c = (double*)malloc(size * sizeof(double));

	int pol = 0, otr = 0;
	

	d = (double*)malloc((pol+otr) * sizeof(double));

	for (int i = 0; i <= size; i++)
	{
		*(a + i) = -50 + (float)rand() / (float)(RAND_MAX) * 100;
		*(b + i) = -50 + (float)rand() / (float)(RAND_MAX) * 100;
		*(c + i) = -50 + (float)rand() / (float)(RAND_MAX) * 100;
	}

	for (int i = 0; i < size; i++)
	{
		if (*(a + i) > 0)pol++;
		if (*(b + i) < 0)otr++;
	}

	printf("Массив a\n");
	for(int i=0;i<size;i++)
		printf("a[%d]=%.4f\n",i, *(a+i));

	printf("Массив b\n");
	for (int i = 0; i < size; i++)
		printf("b[%d]=%.4f\n", i, *(b + i));

	printf("Массив c\n");
	for (int i = 0; i < size; i++)
		printf("c[%d]=%.4f\n", i, *(c + i));

	zap_d(a, b, c, d, size, pol, otr);

	printf("Массив d\n");
	for (int i = 0; i < otr+pol; i++)
		printf("d[%d]=%.4f\n", i, *(d + i));
}

int zap_d(double* a, double *b, double *c,double *d, int size, int* pol, int otr)
{
	int o = 0;
	for (int z = 0; z < pol; z++)
	{
		for (int i = 0; i < size; i++)
		{
			if (*(a + i) > 0)
			{
				o = *(a + i);
				*(d + z) = o;
			}
			
		}
	}
}
