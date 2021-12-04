/*
Advent of code 2021
Emile BONDU
04/12/2021
(oui j'ai un peu de retard)
ca va me perettre de reviser les fichiers en c
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nbIncrease = 0;
	int nbIncreaseLarge = 0;
	FILE* f = NULL;
	int val; //derniere val mesuree
	int lastVal = 424242;
	int lastSum = 424242;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int it = 0;

	f = fopen("Day1/1.txt", "r+");

	if(f == NULL)
	{
		printf("le fichier ne s'est pas ouvert");
	}

	for(int i = 0; i < 2000 ; i++)
	{
		fscanf(f,"%d", &val);

		sum1 += val;
		sum2 += val;
		sum3 += val;

		if(val > lastVal)
		{
			nbIncrease++;
			//printf("%de - %d m\n", nbIncrease, val);
		}

		it++;

		//depart avec retard
		if(it == 1)
		{
			sum2 = 0;
		}
		if(it == 2)
		{
			sum3 = 0;
		}		

		if(it >= 3)
		{
			switch(it % 3)
			{
			case 0 :
				if(lastSum < sum1)
				{
					nbIncreaseLarge++;
					//printf("%d %d %d\n", val, sum1, lastSum);
				}
				else
				{
					printf("%d %d %d\n", val, sum1, lastSum);
				}
				lastSum = sum1; //c'est mieux si on reset pas a 0 lastSum a chaque fois x)
				sum1 = 0;
				break;
			case 1 :
				if(lastSum < sum2)
				{
					nbIncreaseLarge++;
				}
				lastSum = sum2;
				sum2 = 0;
				break;
			case 2 :
				if(lastSum < sum3)
				{
					nbIncreaseLarge++;
				}
				lastSum = sum3;
				sum3 = 0;
				break;
			default : //ne devrait pas arriver
				printf("on a un probleme\n");
				break;
			}
		}

		lastVal = val;

	}

	printf("\n");
	printf("%d\n", nbIncrease);
	printf("%d\n", nbIncreaseLarge);

	return 0;
}
