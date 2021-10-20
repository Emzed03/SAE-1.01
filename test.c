#include <stdio.h>
#include <stdlib.h>
#include "test.h"

//wAllah je t'aime zak fais moi des enfants bordel



void fEnregStock(void)  //fonction enregistrement de stock
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

void fSaisieStock(int *ref, int *qte, float *prix, int *secu, char *rep)  //fonction saisie de stock
{
	prinft("Voulez-vous ajouter une ligne de stock ? (répondre oui ou non)\n");
	scanf("%c", rep);
	if (*rep='non')
		exit(1);
	printf("Donnez la référence du produit: \n");
	scanf("%d", ref);
	while (*ref<0)
	{	
		printf("Erreur, la référence du produit doit être positif. Retapez :\n");
		scanf("%d", ref);
	}
	printf("Rentrez le seuil de sécurité :\n");
	scanf("%d/", secu);
	while (*secu<0)
	{
		printf("Erreur, le seuil de sécurité doit être positif. Retapez :\n");
		scanf("%d", secu);
	}
	printf("Rentrez la quantité :\n");
	scanf("%d", qte);
	while (*qte<0)
	{
		printf("Erreur, la quantité doit être positif. Retapez :\n");
		scanf("%d", qte);
	}
	printf("Rentrez le prix :\n");
	scanf("%.2f", prix);
	while (*prix<0)
	{
		printf("Erreur, le prix doit être positif. Retapez :\n");
		scanf("%.2f", qte);
	}
}
