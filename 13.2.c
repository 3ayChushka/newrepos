//#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFENCE
//#include <stdio.h>
//#include <locale.h>
//#include <string.h>
//#include <math.h>
//#define N 100
//
//double* full_array(double* ptr_array, int n)   /*Заполнение массива числами из func_11_2*/
//{
//	int i = 0;
//	float x = 0.1;
//
//	for (int i = 0; i < n; i++)    
//	{
//		ptr_array[i] = func_11_2(x);
//		x += 0.024;
//	}
//	return 0;
//}
//
//float func_11_2(float x)  /*Функция для функции из 11.1.2*/
//{
//	if (x <= 2.5) return x * x + 2.f * 3.14 * cos(3.14 * x);
//	else return 0;
//}
//
//double sum_elements(double* ptr_array, int n)  /*Сумма n-элементов массива*/
//{
//	float g = ptr_array[0];
//	for (int i = 1; i < n; i++)
//	{
//		g += ptr_array[i];
//	}
//	return g;
//}
//
//double* put_array(double* ptr_array, int n)   /*Вывод заполненного массива*/
//{
//	for (int i = 0; i < n; i++)
//		printf("a[%d] = %.6f\n", i, ptr_array[i]);
//	return 0;
//}
//
//int find(double * ptr_array, int n, float a)  /*Поиск индекса массива, под которым записано число а*/
//{
//
//	for (int i = 0; i < n; i++)
//	{
//		double g = ptr_array[i];
//		if (g == a)
//		{ 
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//
//	int n;
//	float array[N], summ=array[0], a;
//	double* ptr_array;
//
//	printf("Введите размер массива\n");
//	scanf("%d", &n);
//
//	full_array(array, n);  /*Заполнение массива(12 строчка)*/
//	put_array(array, n);  /*Вывод массива(35 строчка)*/
//
//	printf("\nЗадание 2.1\nСумма %d элементов массива = %lf\n", n, sum_elements(array, n, summ));  /*Вывод суммы элементов массива(26 строчка)*/
//
//	printf("Задание 2.2\n\nВведите число для поиска\n");
//	scanf("%f", &a);
//
//	printf("Элемент %f находится под индексом %d\n", a, find(array, n, a));  /*Вывод индекса, под котором записано число а(41 строчка)*/
//}