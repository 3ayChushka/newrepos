#define _CRT_SECURE_NO_WARNINGS
#define e 2.71828
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	laba5();
	laba6();
	laba7();
}

int laba5()
{
	setlocale(LC_ALL, "RUS");

	double x, y, z, a;
	
	printf("Контрольный пример\n\nx=0.03981\ny=-1625\nz=0.512\n\na=0,991957\n\n");

	printf("Введите x\n");
	scanf("%lf", &x);

	printf("Введите y\n");
	scanf("%lf", &y);

	printf("Введите z\n");
	scanf("%lf", &z);

	a = pow(2, -x) * (sqrt(x + pow(fabs(y), 1 / 4))) * pow(pow(e, x - 1 / sin(z)), 1 / 3);

	printf("Ответ   %lf\n\n", a);
}
int laba6()
{
	setlocale(LC_ALL, "RUS");

	int x, y;

	printf("Контрольный пример:\nx=3   y=5\nПринадлежит\n\nx=1   y=2\nНе принадлежит\n\n");

	printf("Введите х\n");
	scanf("%d", &x);

	printf("Введите у\n");
	scanf("%d", &y);


	if (x >= 1 && x <= 7 && y <= 7 && y >= 1 && y <= x + 3 && y <= (-x) + 11 && y >= x - 3 && y >= -x + 5)printf("Принадлежит\n");
	else printf("Не принадлежит\n\n");
}
int laba7()
{
	setlocale(LC_ALL, "RUS");

	int a;

	printf("Введите число 1-12\n");

	scanf("%d", &a);

	switch (a)
	{
	case 1:
		printf("I\n"); break;
	case 2:
		printf("II\n"); break;
	case 3:
		printf("III\n"); break;
	case 4:
		printf("IV\n"); break;
	case 5:
		printf("V\n"); break;
	case 6:
		printf("VI\n"); break;
	case 7:
		printf("VII\n"); break;
	case 8:
		printf("VIII\n"); break;
	case 9:
		printf("IX\n"); break;
	case 10:
		printf("X\n"); break;
	case 11:
		printf("XI\n"); break;
	case 12:
		printf("XII\n"); break;
	default:
		printf("Неверное число\n\n"); break;
	}
}