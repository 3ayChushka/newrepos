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
void zapis(Tfun);
double max(Tfun);

int main()
{
	setlocale(LC_ALL, "RUS");

	double n, k;
	int v = 10, v2 = 10, v3 = 10;
	double y;

	while (v != 0)
	{
		printf("Выберите действие:\n1-Вычислить значение в точке\n2-Табулирование функции\n3-Записать в файл результаты\n4-Поиск максимального значения\n0-Выход\n");
		scanf("%d", &v);

		switch (v)
		{
		case 1:  /*Вычисление в точке*/
		{
			printf("Выберите функцию:\n1-Y(x)\n2-V(x)\n3-S(x)\n");
			scanf("%d", &v2);

			if (v2 == 1) y = calc_to(Y);
			else if (v2 == 2) y = calc_to(V);
			else if (v2 == 3) y = calc_to(S);
			printf("y=%lf\n", y);
			break;
		}
		case 2:  /*Табуляция*/
		{
			tab_func();
			break;
		}
		case 3:  /*Запись в файл*/
		{
			printf("Выберите функцию\n1-Y(x)\n2-V(x)\n3-S(x)\n");
			scanf("%d", &v3);

			if (v3 == 1) zapis(Y);
			else if (v3 == 2) zapis(V);
			else if (v3 == 3) zapis(S);
			break;
		}
		case 4:  /*Поиск максимального значения*/
		{
			printf("Выберите функцию\n1-Y(x)\n2-V(x)\n3-S(x)\n");
			scanf("%d", &v3);

			if (v3 == 1) printf("Максимальное значние на промежутке = %lf\n",max(Y));
				else if (v3 == 2) printf("Максимальное значние на промежутке = %lf\n", max(V));
					else if (v3 == 3)  printf("Максимальное значние на промежутке = %lf\n", max(S));

			break;
		}
		}
	}
}

double Y(double x)
{
	if (x > 0)return log(fabs(sqrt(pow(x, 3))));
	return -1;
}
double V(double x)
{

	if (x > 1) return sqrt(tanh((x * x - 1.f) / 57));
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

void zapis(Tfun f)
{
	FILE* rez;
	double a1, b1, h1;

	printf("Введите начальное значение\n");
	scanf("%lf", &a1); getchar();

	printf("Введите конечное значение\n");
	scanf("%lf", &b1); getchar();

	printf("Введите шаг\n");
	scanf("%lf", &h1); getchar();

	rez = fopen("dat.txt", "w");

	for (double x = a1; x <= b1; x++)
	{
		fprintf(rez, "%lf, ", f(x));
	}
	fclose(rez);
}

double max(Tfun f)
{
	double a2, b2, h2;

	printf("Введите начальное значение\n");
	scanf("%lf", &a2); getchar();

	printf("Введите конечное значение\n");
	scanf("%lf", &b2); getchar();

	printf("Введите шаг\n");
	scanf("%lf", &h2); getchar();

	double max = f(a2);
	for (double i = a2 + 1; i <= b2; i += h2)
	{
		if (max <= f(i))max = f(i);
	}

	return max;

}
