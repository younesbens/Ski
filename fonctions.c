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

int calculPoids(char* couleur, int temps, int experience){	
	//convertit la couleur et le temps de l'arc en poids, en fonction de l'experience du skieur
	if (!strcmp(couleur,"vert"))
		return temps;
	if (!strcmp(couleur,"bleu"))
		return experience*temps + temps;
	if (!strcmp(couleur,"rouge"))
		return experience*2*temps + temps;
	if (!strcmp(couleur,"noir"))
		return experience*3*temps + temps;
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
