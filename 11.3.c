#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define n 5  /*������ �������*/

int mai�()
{
	setlocale(LC_ALL, "RUS");

	int i, a[n];
	int min, z, res=0; 

	for (i = 0; i < n; i++) /* ���������� �������*/
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
		printf("\n");
	}

	min = abs(a[0]);

	for (i = 0; i < n; i++)  /*����� ����������� ��������*/
	{
		if (abs(a[i]) < min)
		{
			min = abs(a[i]);
			z = i;  /*����������� ����������� ������ ������*/
		}
		else z = 0;

	}

	for (i = z+1; i <= n-1; i++) /*���������� �����*/
	{
		res += a[i];
	}
	printf("����� = %d\n", res);
}