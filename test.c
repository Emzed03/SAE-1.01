#include <stdio.h>
#include <stdlib.h>
#include "test.h"


void fEnregStock(void)
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

void fSaisieStock(int *ref, int *qte, float *prix, int *secu, char *rep)
{
	printf("Donnez le numero de produit: ");
	scanf("%d", nProd);
	while (*nProd<0)
	{	
		printf("Erreur, le numéro de produit doit être positif(ou nul pour arrêter). Retapez :");
		scanf("%d", nProd);
	}
	printf("Rentrez la date (jj/mm/aaaa) :");
	scanf("%d/%d/%d", j, m, a);
	rep=fVerifDate(j, m);
	while (rep!=0)
	{
		if (rep==1)
		{	printf("Erreur, la date est incorrecte, les mois sont numérotés de 1 à 12. Retapez :");
			scanf("%d/%d/%d", j, m, a);
			rep=fVerifDate(j, m);
		}
		else
		{	printf("Erreur, la date est incorrecte, les jours sont numérotés de 1 à 31. Retapez :");
			scanf("%d/%d/%d", j, m, a);
			rep=fVerifDate(j, m);
		}
	}
	printf("Saisir le numéro de destinataire :");
	scanf("%d", nDest);
	while (*nDest<0)
	{	
		printf("Erreur, le numéro de destinataire doit être positif. Retapez :");
		scanf("%d", nDest);
	}
	printf("Saisir la quantité :");
	scanf("%d", qte);
	while (*qte<0)
	{	
		printf("Erreur, la quantité doit être positif. Retapez :");
		scanf("%d", qte);
	}
	printf("Saisir le poids :");
	scanf("%d", poids);
	while (*poids<0)
	{	
		printf("Erreur, le poids doit être positif. Retapez :");
		scanf("%f", poids);
	}
}
