#include <stdio.h>
#include <stdlib.h>
#include "test.h"

void fEnregEnvoisV1(void)
{
	FILE *flot;
	int ref, qte, secu;
	float prix;
	flot=fopen("stock.txt", "a");
	if (flot == NULL)
	{
		printf("Problème d'ouverture en écriture du fichier.\n");
		exit(1);
	}
	fSaisieStock(&nProd, &j, &m, &a, &nDest, &qte, &poids);
	while (nProd!=0)
	{
		fprintf(flot,"%d\t %d/%d/%d\t %d\t %d\t %.1f\t \n", nProd, j, m, a, nDest, qte, poids);
		fSaisieStock(&nProd, &j, &m, &a, &nDest, &qte, &poids);
	}
	fclose(flot);
}	
