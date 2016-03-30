#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getExperience(){
	char c;
	while(1){
		printf("Etes vous debutant o/n ?\n");
		scanf("%c",&c);
		if (c == 'o')
			return 1;
		if (c == 'n')
			return 0;
		scanf("%c",&c);	//libere le buffer
	}
}

int calculPoids(int couleur, int temps, int experience){	
	//convertit la couleur et le temps de l'arc en poids, en fonction de l'experience du skieur
	//0Vert 1Bleu 2Rouge 3Noir
	if (couleur==0)
		return temps;
	if (couleur==1)
		return (experience*temps + temps);
	if (couleur==2)
		return (experience*2*temps + temps);
	if (couleur==3)
		return (experience*3*temps + temps);
	return 0;
}


NOMS ajoutFinNoms(NOMS N, char* s)
{
    if (N == NULL){
		NOM* nouv = malloc(sizeof(NOM));
		nouv->val = s;
		nouv->suiv = N;
		N = nouv;
	}
	else
		N->suiv = ajoutFinNoms(N->suiv,s);
	return N;
}

POIDS ajoutFinPoids(POIDS P, int n)
{
    if (P == NULL){
		POID* nouv = malloc(sizeof(POID));
		nouv->val = n;
		nouv->suiv = P;
		P = nouv;
	}
	else
		P->suiv = ajoutFinPoids(P->suiv,n);
	return P;
}
