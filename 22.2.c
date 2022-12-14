#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef double (*Tfun)(double);

double Y(double);
double S(double);
double V(double);

void viv_rez(Tfun, double, double, double);

double calc_to(Tfun);

void tab_func();

void plot(double, double, Tfun);

int main()
{
	setlocale(LC_ALL, "RUS");

	double n, k;
	int v = 10, v2=10, v3=10;
	double y;

	while (v != 0)
	{
		printf("Выберите действие:\n1-Вычислить значение в точке\n2-Табулирование функции\n3-Нарисовать график функции\n0-Выход\n");
		scanf("%d", &v);

		switch (v)
		{
		case 1:  /*Вычисление в точке*/
			{
				printf("Выберите функцию:\n1-Y(x)\n2-V(x)\n3-S(x)\n");
				scanf("%d", &v2);
				
				if (v2 == 1) y=calc_to(Y);
					else if (v2 == 2) y=calc_to(V);
						else if (v2 == 3) y=calc_to(S);
				printf("y=%lf\n", y);
				break;
			}
		case 2:  /*Табуляция*/
			{
				tab_func();
				break;
			}
		case 3:
			{
			printf("Выберите функцию\n1-Y(x)\n2-V(x)\n3-S(x)\n");
			scanf("%d", &v3);

			printf("Введите начальное значение\n");
			scanf("%lf", &n);

			printf("Введите конечное значение\n");
			scanf("%lf", &k);

			if (v3 == 1) plot(n, k, Y);
				else if (v3 == 2) plot(n, k, V);
					else if (v3 == 3) plot(n, k, S);
			break;
			}
		}
	}
}

double Y(double x) 
{
    if(x>0)return log(fabs(sqrt(pow(x, 3))));
	return -1;
}
double V(double x) 
{

    if (x > 1) return sqrt(tanh((x*x-1.f)/57));
        else if (x >= 0 && x <= 1) return -2 * x;
            else if (x < 0) return exp(cos(x));
	return -1;
}
double S(double r) {
    return (r - 1) / (r + 1) + 1. / 3 * pow((r - 1) / (r + 1), 3) + 1. / 5 * pow((r - 1) / (r + 1), 5) + 1. / 7 * pow((r - 1) / (r + 1), 7);
}


void viv_rez(Tfun f, double a, double b, double h)
{
	for (double i = a; i <= b; i += h)
		printf("|x = %5.2lf| y = %8.4lf|\n", i, f(i));
}

double calc_to(Tfun f)
{
	double x;

	printf("Введите значение\n");
	scanf("%lf", &x);

	printf("x=%lf  ", x);
	return f(x);
}

void tab_func()
{
	double a, b, h;

	printf("Введите начальное значение\n");
	scanf("%lf", &a); getchar();

	printf("Введите конечное значение\n");
	scanf("%lf", &b); getchar();

	printf("Введите шаг\n");
	scanf("%lf", &h); getchar();

	printf("\tV(x)\t\n");
	viv_rez(V, a, b, h);

	printf("\tS(x)\t\n");
	viv_rez(S, a, b, h);

	printf("\tY(x)\t\n");
	viv_rez(Y, a, b, h);
}

void plot(double x0, double x1, Tfun f)
{
	char screen[60][40];
	double x, y[60], ymin = 0, ymax = 0, hx, hy;
	int i, j, xz, yz;

	hx = (x1 - x0) / (60 - 1);

	for (i = 0, x = x0; i < 60; ++i, x += hx) 
	{
		y[i] = f(x);
		if (y[i] < ymin) ymin = y[i];
		if (y[i] > ymax) ymax = y[i];

	}

	hy = (ymax - ymin) / (40 - 1);
	yz = (int)floor(ymax / hy + 0.5);
	xz = (int)floor((0. - x0) / hx + 0.5);

	for (j = 0; j < 40; ++j)
		for (i = 0; i < 60; ++i) 
		{
			if (j == yz && i == xz) screen[i][j] = '+';
				else if (j == yz) screen[i][j] = '-';
					else if (i == xz) screen[i][j] = '|';
						else screen[i][j] = ' ';
		}

	for (i = 0; i < 60; ++i) 
	{
		j = (int)floor((ymax - y[i]) / hy + 0.5);
		screen[i][j] = '*';
	}

	for (j = 0; j < 40; ++j) {
		for (i = 0; i < 60; ++i)  putchar(screen[i][j]);
		putchar('\n');
	}

}
