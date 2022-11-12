#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#define N 100

float func_11_2(float x)  /*������� ��� ������� �� 11.1.2*/
{
	if (x <= 2.5) return x * x + 2.f * M_PI * cos(M_PI * x);
	else return 0;
}

double* full_array(double* ptr_array, int n)   /*���������� ������� ������� �� func_11_2*/
{
	int i = 0;
	float x = 0.1;
	for (int i=0; i<n;i++)    /*���������� ������� �� � ������������ �� � ������������ � ������ ���������� � ������*/
	{
		ptr_array[i] = func_11_2(x);
		x += 0.024;
	}
	return 0;
}

double* put_array(double* ptr_array, int n)   /*����� ������������ �������*/
{
	for (int i = 0; i < n; i++)
		printf("a[%d] = %g\n", i, ptr_array[i]);
	return 0;
}

double* calc_array(double* ptr_array, int n) /*���������� ��� ���������� �������*/
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

	printf("������� ������ �������\n");
	scanf("%d", &n);

	full_array(array, n);  /*���������� �������(15 �������)*/
	put_array(array, n);  /*����� ������������ ������� �������(26 �������)*/
	printf("\n");
	calc_array(array, n);  /*���������� ��� ���������� �������(32 �������)*/
	put_array(array, n);  /*����� ���������� �������(26 �������)*/
}