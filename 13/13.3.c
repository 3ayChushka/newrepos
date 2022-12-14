#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>

int proverka(slova, poisk_slova, rez);

int main()
{
	setlocale(LC_ALL, "RUS");

	char slova[200], poisk_slova[100];
	int rez = 0;

	printf("Введите слова\n");
	fgets(slova, 200, stdin);

	printf("Введите слово для поиска\n");
	fgets(poisk_slova, 99, stdin);

	rez = proverka(slova, poisk_slova, rez);

	printf("Слово встречается %d раз\n", rez);
}

int proverka(char* slova, char* poisk_slova, int rez)
{
	int dop=0;
	for (int o = 0; o < strlen(slova); o++)
	{
		rez += dop / (strlen(poisk_slova) - 1);
		dop = 0;
		for (int i = 0; i < strlen(poisk_slova); i++)
		{
			if (slova[o+i] == " ") break;

			if (slova[o+i] == poisk_slova[i])dop++;
		}
	}
	
	return rez;
}
