#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int del(double* ptr_array, int size, int k);

int main()
{
	setlocale(LC_ALL, "RUS");

	double* ptr_array, dop, *ptr_array2;
	int size, k, n = -999;;

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

	printf("Введите номер элемента, после которого будет выводиться -999\n");
	scanf("%d", &k);

	ptr_array2 = (double*)malloc((size+size/k) * sizeof(double));  /*Выделение памяти для нового массива*/

	dobavleniye(ptr_array, size, n, k, ptr_array2);

	for (int i = 0; i < size+size/k; i++)  /*Вывод изменённого массива*/
		printf("mas[%d]=%.2f\n", i, *(ptr_array2 + i));
}

int dobavleniye(double* ptr_array, int size, int n, int k, double* ptr_array2)   /*Вписывает после каждого к-ого элемента -999*/
{
	int o = 0;
	*ptr_array2 = *ptr_array;
	for (int i = 1; i < size+size/k; i++)
	{
		if (*(ptr_array2 + i)==-999)continue;
		if (i % k == 0) 
		{ 
			*(ptr_array2+i) = *(ptr_array + i-o);
			*(ptr_array2 + i + 2)= *(ptr_array + i + 1);
			*(ptr_array2 + i + 1) = n;
			o++;
		} else *(ptr_array2 + i) = *(ptr_array + i-o);
	}
}
