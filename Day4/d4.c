/*
Advent of code 2021
Emile BONDU
10/12/2021
bon finalement le retard empire
mais au moins je vais bosser un peu les structs
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_bingo
{
	int val[5][5];
	bool check[5][5];
} bingo;

void afficher_b(bingo b);
bool isFinished(bingo b);
bool testAll(bingo listBingo[100], int* nbWins, bool asWin[100]);
void testValue(bingo* b, int val);
void testValueForAll(bingo listBingo[100], int value);
void afficher(bingo listBingo[100]);

bool isFinished(bingo b)
//si une ligne est complete
{
	bool isLineComplete = true;
	bool isRowComplete = true;
	bool firstDiag = true;
	bool secongDiag = true;

	//on verifie les lignes et les colonnes
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(!b.check[i][j])
			{
				isLineComplete = false;
			}
		}
		if(isLineComplete)
		{
			return true;
		}
		isLineComplete = true;
	}
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(!b.check[j][i])
			{
				isRowComplete = false;
			}
		}
		if(isRowComplete)
		{
			return true;
		}
		isRowComplete = true;
	}


	//et enfin les diagonales
	for(int i = 0; i < 5; i++)
	{
		if(!b.check[i][i])
		{
			firstDiag = false;
		}
		if(!b.check[i][4 - i])
		{
			secongDiag = false;
		}
	}
	return firstDiag || secongDiag;
}

bool testAll(bingo listBingo[100], int* nbWins, bool asWin[100])
{
	bool value = false;
	for(int i = 0; i < 100; i++)
	{
		if(isFinished(listBingo[i]))
		{
			value = true;
			nbWins++;
			asWin[i] = true;
		}
	}

	return false;
}

void testValue(bingo* b, int val)
{
	bool isAffichable = false;
	if(b->val[0][0] == 72 && val == 72)
	{
		isAffichable = true;
	}
	if(isAffichable)
		afficher_b(*b);

	for(int i = 0 ; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(b->val[i][j] == val)
			{
				b->check[i][j] = true;
			}
		}
	}

	if(isAffichable)
		afficher_b(*b);
}

void testValueForAll(bingo listBingo[100], int value)
{
	for(int i = 0; i < 100; i++)
	{
		testValue(&listBingo[i], value);
	}
	printf("%d\n",  value);
}

void afficher_b(bingo b)
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(b.check[i][j])
			{
				printf("__ ");
			}
			else
			{
				printf("%d ", b.val[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void afficher(bingo listBingo[100])
{
	for(int i = 0; i < 100; i++)
	{
		afficher_b(listBingo[i]);
	}
}

int valDeRetour(bingo b, int val)
{
	int sum = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(!b.check[i][j])
			{
				sum += b.val[i][j];
			}
		}
	}
	return sum * val;
}

int main()
{
	int tirage[100];
	int indice_t = -1;
	bingo listBingo[100]; //oui c'est du lourd toutes ces donees
	FILE *f = NULL;
	char temp;
	bool continuer = true;

	int nbWins = 0;
	bool asWin[100] = { false };
	bool oldWin[100];
	int it_lastwin;

	f = fopen("Day4/d4.txt", "r+");

	if(f == NULL)
	{
		printf("le fichier ne s'est pas ouvert");
	}

	//on commence par charger le tirage
	for(int i = 0; i < 100; i++)
	{
		fscanf(f, "%d", &tirage[i]);
		fscanf(f, "%c", &temp);
	}

	//on charge ensuite les plateaux de bingo
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			for(int k = 0; k < 5; k++)
			{
				fscanf(f, "%d", &listBingo[i].val[j][k]);
				listBingo[i].check[j][k] = false;
			}
		}
	}

	/*
	afficher(listBingo);
	for(int i = 0; i < 100; i++)
	{
		printf("%d ", tirage[i]);
	}
	printf("\n"); */

	//on joue !
	while(continuer && indice_t < 100)
	{
		indice_t++;
		for(int i = 0; i < 100; i++)
		{
			oldWin[i] = asWin[i];
		}

		testValueForAll(listBingo, tirage[indice_t]);

		continuer = !testAll(listBingo, &nbWins, asWin);

		if(nbWins == 99)
		{
			break;
		}

		//afficher(listBingo);
		nbWins = 0;
	}

	//afficher(listBingo);

	for(int i = 0; i < 100; i++)
	{
		if(oldWin[i] = false)
		{
			it_lastwin = i;
		}
	}

	afficher_b(listBingo[it_lastwin]);
	printf("%d", it_lastwin);

	//afficher_b(listBingo[51]);
	//afficher_b(listBingo[52]);

	//printf("%d\t", valDeRetour(listBingo[51], tirage[indice_t]));

	return 0;
}
