/*
Advent of code 2021
Emile BONDU
04/12/2021
(oui j'ai un peu de retard)
ca va me perettre de reviser les fichiers en c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int depth = 0;
	int horizontal = 0;
	int aim = 0;

	FILE* f = NULL;

	char* line;
	int arg = 0;
	
	f = fopen("Day2/d2.txt", "r+");

	if(f == NULL)
	{
		printf("le fichier ne s'est pas ouvert");
	}

	for(int i = 0; i < 1000 ; i++)
	{
		fscanf(f, "%s %d", line, &arg);

		//printf("%s %d\n", line, arg);

		if(!strcmp(line, "forward"))
		//ca marche mieux si on inverse le resultat du test
		{
			//printf("%d %d\n", horizontal, arg);
			horizontal += arg;
			depth += arg * aim;
		}
		else if (!strcmp(line, "up"))
		{
			//depth -= arg;
			aim -= arg;
		}
		else if (!strcmp(line, "down"))
		{
			//depth += arg;
			aim += arg;
		}
		else
		{
			printf("mauvais mot entre : %s\n", line);
		}
	}

	printf("final coords : %d - %d\n", depth, horizontal);
	printf("product : %d\n", depth * horizontal);

	return 0;
}
