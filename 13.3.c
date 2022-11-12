#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
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

	for (int i = 0; i < n; i++)    
	{
		ptr_array[i] = func_11_2(x);
		x += 0.024;
	}
}

double* put_array(double* ptr_array, int n)   /*����� ������������ �������*/
{
	for (int i = 0; i < n; i++)
		printf("a[%d] = %.6f\n", i, ptr_array[i]);
	return 0;
}

float maxim_che(double* ptr_array, int n)  /*����� ���������� �������� ������ ��������*/
{
	float max1 = ptr_array[0];
	for (int i = 0; i < n; i+=2)  
	{
		float g = ptr_array[i];
		if (max1 < g) max1 = g;
	}
	return max1;
}
float maxim_neche(double* ptr_array, int n)  /*����� ���������� �������� �������� ��������*/
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

	printf("������� ������ ������� > \n");
	scanf("%d", &n);

	full_array(array, n);  /*���������� �������, 14 �������*/
	put_array(array, n);  /*����� �������*/
	maxim_che(array, n);  /*����������� ������������� �������� �������� ������������ �� ������ ��������*/
	maxim_neche(array, n);  /*����������� ������������� �������� �������� ������������ �� �������� ��������*/

	printf("���������� �������� ������ �������� = %f\n���������� �������� �������� �������� = %f\n", maxim_che(array, n), maxim_neche(array, n));  /*����� ���������� */
}
