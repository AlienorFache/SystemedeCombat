#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// JE DONNE UN NOM A LA STRUCTURE pour eviter d'ecrire struct a chaque fois

typedef struct Monstre monstre;

//je cree la structure contenant les caracteristiques que peut avoir chaque monstre
struct Monstre {
	int randLife;
	int randManas;
	int randDegat;
	int randResistance;
	int choix;
};

//fonction qui ne renvoie rien 
void actionMonstre (struct Monstre*monstre) {
	printf ("Combien de monstres veux tu ?");
	scanf ("%d",&monstre.choix);
	
	if (monstre.choix == 1) {
		
	}
	
	if (monstre.choix == 2) {
		
	}
	
	if (monstre.choix == 3) {
		
	}
	
	

}
int main(){
	
	int choixMonstre;

	int randLife=(rand()%100)+1;
	int randManas=(rand()%20)+1;
	int randDegat=(rand()%20)+1;
	int randResistance=(rand()%3);
	
	if (randLife=<30){
		randManas*2;
	}
	else (randLife>=50){
		randManas/2;
	}

	
	return 0;
};