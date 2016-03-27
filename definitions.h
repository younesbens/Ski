//definition du nombre de sommets et du nombre d'arcs du graphe orienté représentant la carte
#define V 5		//nombre de sommets
#define E 7		//nombre d'arcs

typedef struct Nom	
{//Represente un nom
	char* val;
	struct Nom* suiv;
} NOM;

typedef NOM* NOMS;		//Represente les noms de tous les arcs d'un sommet vers un autres

typedef struct Poid	
{//Represente un poids
	int val;
	struct Poid* suiv;
} POID;

typedef POID* POIDS;	//Represente les poids de tous les arcs d'un sommet vers un autres

typedef struct arc Arc;

struct arc
{
	NOMS nom;		//noms des arcs, liste de noms à laquelle on ajoute un element à chaque nouveau arc
	char* depart;	//nom sommet depart
	char* arrivee;	//nom sommet arrivee
	POIDS poids;	//poids des arcs, liste de poids à laquelle on ajoute un element à chaque nouveau arc
	int nbArcs;		//nombre d'arcs reliant le sommet de depart au sommet d'arrivee
};
