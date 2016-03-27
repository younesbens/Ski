#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialise(Arc G[V][V])
{	//initialise le graphe
	int i, j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			G[j][i].nom = NULL;
			G[j][i].poids = NULL;
			G[j][i].depart = "inconnu";
			G[j][i].arrivee = "inconnu";
			G[j][i].nbArcs = 0;
		}
	}
}
	
int indiceSommet(char* nomSommet)
{	//prend un nom de sommet et retourne son indice dans le tableau
	if (!strcmp(nomSommet,"Pic_Blanc"))
		return 0;
	if (!strcmp(nomSommet,"Grotte_De_Glace"))
		return 1;
	if (!strcmp(nomSommet,"Lac_Blanc"))
		return 2;
	if (!strcmp(nomSommet,"Sommet_3060"))
		return 3;
	if (!strcmp(nomSommet,"Glacier_De_Sarenne"))
		return 4;
	return -1;
}


void lectureGraphe(char* nomFichier, Arc G[V][V])
{
	FILE* F = fopen(nomFichier,"r");	//doit etre deja present, sinon NULL
	
	if (F == NULL){
		printf("fichier du graphe introuvable\n");
		return;
	}
	
	int k, temps; //experience = getExperience();
	
	initialise(G);
		
	for (k = 0; k < E; k++)			//boucle qui parcourt les lignes du fichier : E lignes <=> E arcs en comptant les arcs qui se repetent
	{
		char SommetDepart[30], SommetArrivee[30], nomArc[30], couleur[10];
		
		fscanf(F,"%s %s %s %s %d",SommetDepart, SommetArrivee, nomArc, couleur, &temps);
		
		int i = indiceSommet(SommetDepart);
		int j = indiceSommet(SommetArrivee);
		
		G[i][j].depart = SommetDepart;
		G[i][j].arrivee = SommetArrivee;
		G[i][j].nbArcs++;
		G[i][j].nom = ajoutFinNoms(G[i][j].nom,nomArc);
		//G[i][j].poids = ajoutFinPoids(G[i][j].poids,calculPoids(couleur,temps,experience));
		printf("%s - %s : %d arc(s) : %s\n",G[i][j].depart,G[i][j].arrivee,G[i][j].nbArcs,G[i][j].nom->val);
		
	}
	
	fclose(F);
	
}

void afficheGraphe(Arc G[V][V]){
	int i,j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			while(i !=j && G[i][j].nom!=NULL){
					printf("%s - %s : %d arc(s) : %s\n",G[i][j].depart,G[i][j].arrivee,G[i][j].nbArcs,G[i][j].nom->val);
					G[i][j].nom = G[i][j].nom->suiv;
			}
		}
		
	}
}
	
	
