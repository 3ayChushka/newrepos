#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>

int proverka(slova, poisk_slova, rez);

int main()
{
	setlocale(LC_ALL, "RUS");

	char slova[100], poisk_slova[100];
	int rez=0;

	printf("Введите слова\n");
	fgets(slova, 99, stdin);

	printf("Введите слово для поиска\n");
	fgets(poisk_slova, 99, stdin);

	rez=proverka(slova, poisk_slova, rez);

	printf("Слово встречается %d раз\n", rez);
}

int proverka(char *slova, char *poisk_slova, int rez)
{
	int dop=0, i3=0;

	for (int i = i3; i <= strlen(slova)-1; i++)
	{
		for (int i2 = 0; i2 <= strlen(poisk_slova) - 1; i2++)
		{
			if (slova[i] == poisk_slova[i2])
			{
				dop++;
				i3++;
				
				if (dop == strlen(poisk_slova) - 1) { rez++; dop = 0; }
				else;
			}
			else continue;
		}
	}
	return rez;
}
