#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int dobavleniye(ptr_array, size, k, ptr_array2);

int main()
{
	setlocale(LC_ALL, "RUS");

	double* ptr_array, dop, * ptr_array2;
	int size, k;

	printf("Введите размер массива\n");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));  /*Выделение памяти под массив*/
	ptr_array2 = (double*)(malloc(size * sizeof(double)));

	for (int i = 0; i < size; i++)  /*Заполнение массива рандомными числами*/
	{
		dop = -99 + rand() % 198;  /*Добавление случайной дробной части*/
		*(ptr_array + i) = dop * 0.01;
	}

	for (int i = 0; i < size; i++)
		*(ptr_array2 + i) = *(ptr_array + i);

	for (int i = 0; i < size; i++)  /*Вывод неизменённого массива*/
		printf("mas[%d]=%.2f\n", i, *(ptr_array + i));


	/*for (int i = 0; i < 100; i++)
	{*/
	printf("Введите номер элемента, после которого будет выводиться -999\n");
	scanf("%d", &k);

	int new_chislo = dobavleniye(ptr_array, size, k, ptr_array2);

	for (int i = 0; i < new_chislo; i++)  /*Вывод изменённого массива*/
		printf("mas[%d]=%.2f\n", i, *(ptr_array2 + i));
	//}
}

//int dobavleniye(double* ptr_array, int size, int k, double* ptr_array2)   /*Вписывает после каждого к-ого элемента -999*/
//{
//	int h=0, dop=0;
//
//	for (int i = 0; i < size; i++)
//	{
//		dop++;
//		if (dop % (k + 1) == 0)
//		{
//			h++;
//			ptr_array2 = (double*)realloc(ptr_array2, (size + h) * sizeof(double));
//
//			for (int o = size + h; o > i; o--)
//			{
//				*(ptr_array2 + o) = *(ptr_array2 + o - 1);
//			}
//		}
//	}
//
//	//for(int i=0;i<size;i++)
//}

int dobavleniye(double* ptr_array, int size, int k, double* ptr_array2)   /*Вписывает после каждого к-ого элемента -999*/
{
	int o = 0, h = 0, pr = 0;

	for (int i = 1; i < size; i++)  /*Подсчёт числа для добавления новой памяти*/
	{
		if (i % k == 0)
			h++;
		if (h % k == 0) pr++;
	}

	ptr_array2 = (double*)realloc(ptr_array2, (size + h) * sizeof(double));


	for (int i = 0; i < size; i++)  /*Перезапись сторого массива в новый массив*/
	{
		*(ptr_array2 + i) = *(ptr_array + i);
	}

	int dop = 1;
	for (int i = 0; i <= size + h; i++)
	{
		dop++;
		if (dop % (k + 1) == 0)
		{
			for (int o = size + h+1; o > i; o--)
			{
				*(ptr_array2 + o) = *(ptr_array2 + o - 1);    /*Перезапись с конца*/
			}
			*(ptr_array2 + i + 1) = -999;
		}
	}
	
	if (size % k == 0)return size + h + 1;
	return size + h;
}
