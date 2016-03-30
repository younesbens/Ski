#include "graphe.h"
#include <stdio.h>


int main(int argc, char* argv[])
{
	Arc G[V][V];
	
	lectureGraphe("graphe.txt",G);
	
	
	//printf("%s\n",G[0][1].depart);
	afficheGraphe(G);
	
	return 0;
}
