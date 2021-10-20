#include <stdio.h>
#include <stdlib.h>
#include "test.h"

void fEnregEnvoisV1(void)
{
	FILE *flot;
	int ref, qte, secu;
	char rep;
	float prix;
	flot=fopen("stock.txt", "a");
	if (flot == NULL)
	{
		printf("Problème d'ouverture en écriture du fichier.\n");
		exit(1);
	}
	fSaisieStock(&ref, &qte, &prix, &secu,&rep);
	while (rep!='oui')
	{
		fprintf(flot,"%d\t %d/\t %.2f\t %d\t \n", ref, qte, prix, secu);
		fSaisieStock(&ref, &qte, &prix, &secu,&rep);
	}
	fclose(flot);
}	
