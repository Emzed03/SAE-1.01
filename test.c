#include <stdio.h>
#include <stdlib.h>
#include "test.h"

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
	scanf("%f", prix);
	while (*prix<0)
	{
		printf("Erreur, le prix doit être positif. Retapez :\n");
		scanf("%f", prix);
	}
}

int chargement(int ref[], int qte[], float prix[],int secu[], int tmax) //retourne i = taille physique des tables
								// retourne -1 ou -2 si erreur
{
	FILE * flot;
	float p;
	int r, q, s, i=0;
	flot=fopen("stock.txt","r");
	if(flot==NULL)
	{
		printf("Problème d'ouverture du fichier en lecture.\n");
		return -1;
	}
	fscanf(flot,"%d%d%.2f%d", &r, &q, &p, &s);
	while(!feof(flot))
	{
		if (i==tmax)
		{	printf("Le tableau est plein.\n");
			return -2;
		}
			ref[i]=r;
			qte[i]=q;
			prix[i]=p;
			secu[i]=s;
			i=i+1;
		}
		fscanf(flot,"%d%d%.2f%d", &r, &q, &p, &s);
	}
	fclose(flot);
	return i;
}


void etatStock(int ref[], int qte[], float prix[], int secu[], int nb)
{
	int i;
	printf("Référence\tQuantité\tPrix\tSeuil."); //à modifier par rapport à taille des tableaux
	for(i=0; i<nb; i=i+1)
	{	printf("%d\t", ref[i]);
		printf("%d\t", qte[i]);
		printf("%.2f\t", prix[i]);
	 	printf("%d\t\n", secu[i]);
	}
}

int fRecherche(int tab[], int nb, int n)
{
	int i;
	for(i=0;i<nb;i++)
	{
		if((tab[1]==n)
		  return i;
		   }
return -1;
		   }
		   
		 
int menu(void)
{
    int commande;

    printf("<<<<<bienvenus>>>>>\n");
    printf("Cliquez sur 1 pour Entrer un ou plusieurs nouveaux items\n");
    printf("Cliquez sur 2 pour Supprimer un ou plusieurs items\n");
    printf("Cliquez sur 3 pour Faire un devis\n");
    printf("Cliquez sur 4 pour Recapitulatif des ventes\n");
    printf("Cliquez sur 5 pour Approvisionner le stock\n");
    printf("Cliquez sur 6 pour Traiter une commande\n");
    printf("0 pour annuler et quitter\t");
    scanf("%d",&commande);
     return commande;

}


	

