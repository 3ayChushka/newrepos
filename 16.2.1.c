#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int del(double* ptr_array, int size, int k);

int main()
{
	setlocale(LC_ALL, "RUS");

	double* ptr_array, dop;
	int size, k, n;

	printf("Введите размер массива\n");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));  /*Выделение памяти под массив*/

	for (int i = 0; i < size; i++)  /*Заполнение массива рандомными числами*/
	{
		dop = -99 + rand() % 198;  /*Добавление случайной дробной части*/
		*(ptr_array + i) = dop * 0.01;
	}


	for (int i = 0; i < size; i++)  /*Вывод неизменённого массива*/
		printf("mas[%d]=%.2f\n", i, *(ptr_array + i));


	printf("Введите индекс массива, который хотите удалить\n");
	scanf("%d", &k);
	n = del(ptr_array, size, k);  /*Удаление выбранного индекса*/


	for (int i = 0; i < n; i++)  /*Вывод изменённого массива*/
	{
		printf("mas[%d]=%.2f\n", i, *(ptr_array + i));
	}
}

int del(double* ptr_array, int size, int k)  /*Удаляет каждый к-ый элемент массива и возвращает размер изменённого массива*/
{
	int n = size - (int)size / k, q=0;

	for (int i = 0; i < size; i++)
	{
		if (i == 0)continue;
		if (i % k == 0)
			{
				for(int o=i-q; o< size;o++)
				*(ptr_array + o) = *(ptr_array + o + 1);
				q++;
			}
	}
	return n;
}
