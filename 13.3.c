#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 100

float func_11_2(float x)  /*Функция для функции из 11.1.2*/
{
	if (x <= 2.5) return x * x + 2.f * M_PI * cos(M_PI * x);
	else return 0;
}

double* full_array(double* ptr_array, int n)   /*Заполнение массива числами из func_11_2*/
{
	int i = 0;
	float x = 0.1;

	for (int i = 0; i < n; i++)    
	{
		ptr_array[i] = func_11_2(x);
		x += 0.024;
	}
}

double* put_array(double* ptr_array, int n)   /*Вывод заполненного массива*/
{
	for (int i = 0; i < n; i++)
		printf("a[%d] = %.6f\n", i, ptr_array[i]);
	return 0;
}

float maxim_che(double* ptr_array, int n)  /*Поиск наибольших значений четных индексов*/
{
	float max1 = ptr_array[0];
	for (int i = 0; i < n; i+=2)  
	{
		float g = ptr_array[i];
		if (max1 < g) max1 = g;
	}
	return max1;
}
float maxim_neche(double* ptr_array, int n)  /*Поиск наибольших значений нечётных индексов*/
{
	float max2 = ptr_array[1];
	for (int i = 1; i < n; i += 2)  
	{
		float g = ptr_array[i];
		if (max2 < g) max2 = g;
	}
	return max2;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	float array[N];
	int n;

	printf("Введите размер массива > \n");
	scanf("%d", &n);

	full_array(array, n);  /*Заполнение массива, 14 строчка*/
	put_array(array, n);  /*Вывод массива*/
	maxim_che(array, n);  /*Определение максимального значения элемента находящегося на четных позициях*/
	maxim_neche(array, n);  /*Определение максимального значения элемента находящегося на нечетных позициях*/

	printf("Наибольшее значение чётных индексов = %f\nНаибольшее значение нечётных индексов = %f\n", maxim_che(array, n), maxim_neche(array, n));  /*Вывод результата */
}
