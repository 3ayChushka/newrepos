#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

float area_rectangle(float a, float s)
{
	s = a * a;
	return s;
}

void draw_rectangle(int a)
{

	//while (y != a)
	//{
	//	x = 0;
	//	while (x != (a*2-1))
	//	{
	//		printf("*");
	//		x++;
	//	}
	//	printf("\n");
	//	y++;
	//}

	int x, y;

	for (y = 0; y >= -(a*2); y--)
	{
			for (x = -(a*2); x <= 0; x++)
			{
				if (y<=x+(a-1) && y <= -x - (a-1) && y >= x - (a-1) && y >= -x - ((a-1)*3)) printf("*");
				else printf(" ");
			}
		printf("\n");
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	float a, s=1;
	int v;

	printf("�������\n\n������� ������� ��������\n");
	scanf("%f", &a);
	
	printf("�������� ��������:\n1 - ��������� �������\n2 - ������� ����������� ������\n3 - ���������� ������\n");
	scanf("%d", &v);
	printf("\n");

	switch (v)
	{
	case 1:
		printf("������� �������� = %g", area_rectangle(a, s)); break;
	case 2:
		printf("������� - ���������� ��������������, � �������� ��� ������� � ���� ����� ����� �����."); break;
	case 3:
		draw_rectangle(a);
	}
}