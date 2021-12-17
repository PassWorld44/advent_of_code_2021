/*
Advent of code 2021
Emile BONDU
05/12/2021
(le retard se ratrappe)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	int nbOnes[12] = { 0 };
	char ligne[14];
	char gamma_c[13];
	char epsilon_c[13];
	long int gamma_i;
	long int epsilon_i;

	char oxygen[13];
	char CO2[13];
	int OxyNbOnes;
	int CO2NbOnes;
	int nbO2;
	int nbCO2;
	int CO2_i;
	int O2_i;

	gamma_c[12] = '\0';
	epsilon_c[12] = '\0';
	oxygen[12] = '\0';
	CO2[12] = '\0';

	FILE* f = NULL;
	f = fopen("Day3/d3.txt", "r+");

	if(f == NULL)
	{
		printf("le fichier ne s'est pas ouvert\n");
	}

	for(int i = 0; i < 1000; i++)
	{
		fgets(ligne, 14, f);

		for(int i = 0; i < 12; i++)
		{
			if ( ligne[i] == '1' )
			{
				nbOnes[i]++;
			}
		}
	}

	//find the oxygen and CO2
	for(int i = 0; i < 12; i++)
	//we iterate 12 times over the 1000 values but don't consider a lot of them
	{
		for(int j = 0; j < 1000 ; j++)
		{
			fgets(ligne, 14, f);
			
			bool isO2 = true;
			bool isCO2 = true;

			nbCO2 = 0;
			nbO2 = 0;
			CO2NbOnes = 0;
			OxyNbOnes = 0;

			for(int k = 0; k < i - 1; k++)
			{
				if(ligne[k] != oxygen[k])
				{
					isO2 = false;
				}

				if(ligne[k] != CO2[k])
				{
					isCO2 = false;
				}
			}

			if(isO2)
			{
				if(ligne[i] = '1')
				{
					OxyNbOnes++;
				}

				nbO2++;
			}

			if(isCO2)
			{
				if(ligne[i] = '1')
				{
					CO2NbOnes++;
				}

				nbCO2++;
			}

			if(CO2NbOnes / (float)nbCO2 >= 0.5)
			{
				CO2[i] = '0';
			}
			else
			{
				CO2[i] = '1';
			}

			if(OxyNbOnes / (float)nbO2 <= 0.5)
			{
				oxygen[i] = '1';
			}
			else
			{
				oxygen[i] = '0';
			}

		}
	}

	for(int i = 0; i < 12; i++)
	{
		printf("%d ", nbOnes[i]);

		if(nbOnes[i] <= 500)
		// le bit le plus commun est 0
		{
			gamma_c[i] = '0';
			epsilon_c[i] = '1';
		}
		else
		//le bit le plus commun est 1
		{
			gamma_c[i] = '1';
			epsilon_c[i] = '0';
		}
	}
	printf("\n");

	printf("valeurs en binaire : \n");
	printf("gamma : %s, epsilon : %s\n", gamma_c, epsilon_c);
	printf("O2 : %s, CO2 : %s\n", oxygen, CO2);

	gamma_i = strtol(gamma_c, NULL, 2);
	epsilon_i = strtol(epsilon_c, NULL, 2);
	O2_i = strtol(oxygen, NULL, 2);
	CO2_i = strtol(CO2, NULL, 2);

	printf("gamma : %ld, epsilon : %ld\n", gamma_i, epsilon_i);
	printf("et le produit : %ld\n", gamma_i * epsilon_i);

	printf("\n");
	printf("O2 : %d, CO2 : %d\n", O2_i, CO2_i);
	printf("et le produit : %d\n", O2_i * CO2_i);

	fclose(f);

	return 0;
}
