#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef double (*Tfun)(double);

double Y(double);
double S(double);
double V(double);

void viv_rez(Tfun, double, double, double);

int main()
{
	setlocale(LC_ALL, "RUS");

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
