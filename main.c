#include "graphe.h"
#include <stdio.h>


int main(int argc, char* argv[])
{
	Arc G[V][V];
	
	lectureGraphe("graphe.txt",G);
	//Dans lectureGraphe tout a l'air de bien marcher, sauf quand j'essaye d'afficher les varaibles à l'exterieur de lectureGraphe,
	//Elles ont l'air de ne pas etre modifiées
	
	printf("%s\n",G[0][1].depart);
	afficheGraphe(G);
	
	return 0;
}
