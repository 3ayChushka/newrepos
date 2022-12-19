#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

void sinus();
double sin_n(double, double);
double sin_eps(double, double);

int main()
{
	setlocale(LC_ALL, "RUS");

	int v = 10;
	double x, n, eps;

	while (v != 0)
	{
		printf("Выберите функцию\n1-Вычисление синуса при помощи стандартной функции sin(x)\n2-Вычисление синуса с помощью вычисления значния как сумму ряда\n3-Через ряд Маклорена с заданной точностью\n0-выход\n");
		scanf("%d", &v);

		switch (v)
		{
		case 1:
		{
			sinus();
			break;
		}

		case 2:
		{
			printf("Введите x\n");
			scanf("%lf", &x);
			printf("Введите количество суммируемых элементов\n");
			scanf("%lf", &n);

			printf("sin(%g)=%lf\n",x, sin_n(x, n));

			break;
		}
		case 3:
		{
			printf("Введите x\n");
			scanf("%lf", &x);
			printf("Введите точность\n");
			scanf("%lf", &eps);

			printf("sin(%g)=%lf\n", x, sin_eps(x, eps));
			break;
		}
		}
	}
	
}

void sinus()
{
	double x;

	printf("Введите x\n");
	scanf("%lf", &x);

	printf("sin(%g)=%lf\n", x, sin(x));
}

double sin_n(double x, double n)
{
	double y=0, fact;

	for (int k = 1; k < n; k++)
	{
		fact = 1;
		for (int o = 1; o <= 2 * k - 1; o++)
			fact *= o;

		y += powl(-1, k - 1) * powl(x, 2 * k - 1) / fact;
	}

	return y;
}

double sin_eps(double x, double n)
{
	
}
