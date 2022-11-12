#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <string.h>
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
	for (int i=0; i<n;i++)    /*Вычисление функции от х минимального до х минимального и запись результата в массив*/
	{
		ptr_array[i] = func_11_2(x);
		x += 0.024;
	}
	return 0;
}

double* put_array(double* ptr_array, int n)   /*Вывод заполненного массива*/
{
	for (int i = 0; i < n; i++)
		printf("a[%d] = %g\n", i, ptr_array[i]);
	return 0;
}

double* calc_array(double* ptr_array, int n) /*Вычисление для изменённого массива*/
{
	for (int i = 0; i < n; i++)
	{
		int g = ptr_array[i];
		if (ptr_array[i] == g) ptr_array[i] = g;
		else if (ptr_array[i] < 0) ptr_array[i] = -(g + 1);
		else ptr_array[i] = g + 1;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int n;
	double array[N];
	double* ptr_array;

	printf("Введите размер массива\n");
	scanf("%d", &n);

	full_array(array, n);  /*Заполнение массива(15 строчка)*/
	put_array(array, n);  /*Вывод неизменённого массива массива(26 строчка)*/
	printf("\n");
	calc_array(array, n);  /*Вычисление для изменённого массива(32 строчка)*/
	put_array(array, n);  /*Вывод изменённого массива(26 строчка)*/
}