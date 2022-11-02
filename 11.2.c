#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 100
#define ot 0.1
#define doo 2.5

float srznach(float a[N])  /*������� �������������� ���� ������������� �����*/
{
	float srznach=0, s=0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] > 0) 
		{ 
			srznach += a[i];
			s++;
		}
	}
	srznach = srznach / s;
	return srznach;
}  

int main()
{
	setlocale(LC_ALL, "RUS");

	float a[N], x, z;
	int i = 0, p = 0, o=0;

	for (x = ot; x < doo, i < N; x += (doo - ot) / N)    /*���������� ������� �� � ������������ �� � ������������ � ������ ���������� � ������*/
	{
		a[i] = x * x + 2.f * 3.14 * cos(3.14 * x);
		i++;
	}

	for (i = 0; i < N; i++)   /*����� �����������*/
	{
		printf("a[%d] = %f\n", i, a[i]);
		if (a[i] > 0) p++;  /*������� ������������� � ������������� �������� */
		else o++;
	}

	printf("\n������ a[%d]:\n����� ������������� ���������: %d\n����� ������������� ���������: %d\n", N, p, o);
	printf("������� �������������� ���� ������������� ����� = %f", srznach(a));
}