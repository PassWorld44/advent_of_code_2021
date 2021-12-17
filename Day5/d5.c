/*
Advent of code 2021
Emile BONDU
016/12/2021
bon mon retard augmente de plus en plus,
mais ca reste sympa de coder de temps en temps
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b)
{	
	return (a + b + abs(a-b) ) / 2;
}

int min(int a, int b)
{	
	return (a + b - abs(a-b) ) / 2;
}

int main()
{
	int map [1000][1000] = {0};
	FILE* f = NULL;
	int x1, x2, y1, y2;
	char trash;
	int countCollisions = 0;
	bool isFirstTheLeft;
	bool isFirstUpper;

	f = fopen("Day5/d5.txt", "r+");

	if(f == NULL)
	{
		printf("le fichier ne s'est pas ouvert");
	}

	//input
	for(int i = 0; i < 500; i++)
	{
		fscanf(f, "%d%c%d", &x1, &trash, &y1);
		fscanf(f, "%c%c%c", &trash, &trash, &trash);
		fscanf(f, "%d%c%d", &x2, &trash, &y2);

		

		if(x1 == x2)
		{
			//we are going to count the line
			for(int i = min(y1, y2); i <= max(y1, y2) ; i++)
			{
				map[x1][i] += 1;
			}
			//printf("%d %d %d %d\n", x1, y1, x2, y2);
		}

		if(y1 == y2)
		{
			//we are going to count the collumn
			for(int i = min(x1, x2); i <= max(x1, x2) ; i++)
			{
				map[i][y1] += 1;
			}
			//printf("%d %d %d %d\n", x1, y1, x2, y2);
		}

		if(abs(x1 - x2) == abs(y1 - y2) )
		//diagonals too
		{
			printf("%d %d\n", x1-x2, y1- y2);

			isFirstTheLeft = (y1 - y2) < 0;
			isFirstUpper = (x1 - x2) > 0;

			if(x1 < x2 && y1 < y2)
			{
				for(int i = x1; i <= x2; i++)
				{
					map[i][i - x1 + y1] +=1;
				}
			}
			else if(x1 < x2 && y2 < y1)
			{
				for(int i = x1; i <= x2; i++)
				{
					map[i][- i + x1 + y1] +=1;
				}
			}
			else if(x2 < x1 && y2 < y1)
			{
				for(int i = x2; i <= x1; i++)
				{
					map[i][- i + x1 + y1] +=1;
				}
			}
			else if(x2 < x1 && y1 < y2)
			{
				for(int i = x2; i <= x1; i++)
				{
					map[i][i - x1 + y1] +=1;
				}
			}
			else
			{
				printf("pb : %d %d %d %d\n", x1, y1, x2, y2);
			}
		}
	}
	
	//count the number of intersects
	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < 1000; j++)
		{
			if(map[i][j] > 1)
			{
				countCollisions++;
			}
		}
	}

	printf("%d\n", countCollisions);

	//outpout the map in a file for readable reasons

	FILE *f2 = NULL;
	f2 = fopen("Day5/map.txt", "w+");

	if(f2 == NULL)
	{
		printf("le fichier ne s'est pas ouvert");
	}

	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < 1000; j++)
		{
			fprintf(f2, "%d ", map[i][j]);
		}
		fprintf(f2, "\n");
	}

	return 0;
}
