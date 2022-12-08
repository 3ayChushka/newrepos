#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calc(double* ptr_array, double* ptr_array2, int size);

int main()
{
	setlocale(LC_ALL, "RUS");

	double* ptr_array, dop, *ptr_array2;
	int size;

	printf("Введите размер массива\n");
	scanf("%d", &size);

	ptr_array = (double*)malloc(size * sizeof(double));  /*Выделение памяти под массив*/
	ptr_array2 = (double*)malloc(size * sizeof(double));  /*Выделение памяти под изменённый массив*/

	for (int i = 0; i < size; i++)  /*Заполнение массива рандомными числами*/
	{
		dop = rand() % 100;  /*Добавление случайной дробной части*/
		*(ptr_array + i) = -100 + rand() % 200;  /*Случайные значения от -100 до 100*/
		*(ptr_array + i) += dop*0.01;
	}
	for (int i = 0; i < size; i++)  /*Вывод неизменённого массива*/
		printf("mas[%d]=%f\n", i, *(ptr_array + i));

	calc(ptr_array, ptr_array2, size);  /*Округление в большую сторону*/

	printf("\n");
	for (int i = 0; i < size; i++)  /*Вывод изменённого массива*/
		printf("mas[%d]=%.0f\n", i, *(ptr_array2 + i));

	free(ptr_array); /* Очищение памяти*/
	ptr_array = NULL;
	free(ptr_array2);
ptr_array2 = NULL;
}

int calc(double *ptr_array, double* ptr_array2, int size)  /*Округление в большую сторону*/
{
	for (int i = 0; i < size; i++)
	{
		if ((int)*(ptr_array+i) != *(ptr_array+i)) *(ptr_array2+i) = (int)*(ptr_array+i) + 1;
		else *(ptr_array+i) = (int)*(ptr_array+i);
	}
	return 0;/}
