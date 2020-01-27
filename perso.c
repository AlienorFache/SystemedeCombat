#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Monstre
{

    int life;
    int pm;
    int degats;
    int oResistance;
    int resistance;
    int poison;
    int agro;
	int choix
};

typedef struct Monstre monstre;

struct Perso
{
    int id;
    int life;
    int maxLife;
    int pm;
    int degat;
    int xp;
    int niveau;
    int resistance;
    int choix;
};

typedef struct Perso perso;

void creationMonstre(struct Monstre tMonstre[], int nbMonstre)
{

    for (int i = 0; i < nbMonstre; i++)
    {

        tMonstre[i].life = 1;

        tMonstre[i].pm = 5;

        
            tMonstre[i].degats = (rand() % 11) + 10;

        if (tMonstre[i].degats > 15)
        {
            tMonstre[i].oResistance = 1;
        }
        else
        {
            tMonstre[i].oResistance = 2;
        }

        tMonstre[i].resistance = tMonstre[i].oResistance;
        tMonstre[i].poison = 0;
        tMonstre[i].agro = 0;
    }
}

void xpPerso(perso *perso)
{
    if (perso->xp == perso->niveau)
    {
        perso->maxLife += 10;
        perso->life = perso->maxLife;
        perso->niveau++;
        perso->xp = 0;

        //printf("xp : %d, niveau : %d, maxlife: %d, life : %d\n",perso->xp, perso->niveau, perso->maxLife, perso->life);
    }
}

void actionPerso(perso *perso, struct Monstre tMonstre[], struct Perso tPerso[])
{
    int monstreChoisi;
    int check = 0;
    while (check == 0)
    {
        printf("Tape 1 pour attaquer, 2 pour l'action speciale ou 3 pour te proteger.\n");
        scanf("%d", &perso->choix);

        //Verifie que le joueur ne donne pas un autre chiffre que 1, 2 ou 3
        //Vérifie si le mage et l'archer ont assez de mana pour leurs actions spéciales
        if (perso->choix == 2 && perso->pm >= 5 && perso->id != 3)
        {
            check = 1;
        }
        else if (perso->choix == 2 && perso->pm < 5 && perso->id != 3)
        {
            printf("Vous n'avez plus assez de pm.\n");
        }
        //Vérifie les deux autres actions
        if (perso->choix == 3 || perso->choix == 1)
        {
            check = 1;
        }
    }

    if (perso->choix == 1)
    {

        printf("Choisissez un monstre a attaquer.\n");
        scanf("%d", &monstreChoisi);

        tMonstre[monstreChoisi].life -= perso->degat;
        printf("%d life monstre\n", tMonstre[monstreChoisi].life);

        if(tMonstre[monstreChoisi].life <= 0)
        {
            printf("le monstre est mort");
            perso->xp ++;
            xpPerso(perso);
        }
    }
    if (perso->choix == 3)
    {

        perso->resistance *= 2;
        printf("%d resistance", perso->resistance);
        printf("Vous subissez 2x moins de degats pendant se tour.\n");
    }

    if (perso->choix == 2)
    {

        //mage
        if (perso->id == 1)
        {
            int i;
            printf("choix du perso a soigner 1mage 2archer 3tank\n");
            scanf("%d", &i);
            i--;
            tPerso[i].life += 20;
            perso->pm -= 5;
            if (tPerso[i].life > 100)
            {
                tPerso[i].life = 100;
            }
            printf("vie : %d\n", tPerso[i].life);
        }
        //archer
        if (perso->id == 2)
        {
            printf("Choisissez un monstre a attaquer.\n");
            scanf("%d", &monstreChoisi);
            tMonstre[monstreChoisi].life -= 10;
            tMonstre[monstreChoisi].poison = 2;
            perso->pm -= 5;
            printf("pm : %d, pv monstre : %d \n", perso->pm, tMonstre[monstreChoisi].life);
        }

        //tank
        if (perso->id == 3)
        {
            printf("Choisissez un monstre a attaquer.\n");
            scanf("%d", &monstreChoisi);
            tMonstre[monstreChoisi].agro = 1;
            printf("alfred agro le tank %d", tMonstre[monstreChoisi].agro);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
void actionMonstre(struct Monstre tMonstre[], struct Perso tPerso[], int nbMonstre){
	int persoChoisi=(rand()%3)+1;
	
	for (int i = 0; i < nbMonstre; i++){
		
		if (tMonstre[monstreChoisi].agro = 1){
			tPerso[2]->life -= tMonstre[i].degats;
		}
		else{
			if (tMonstre[i]->pm >=5) {
				
				//1 pour le soin, 2 pour l'attaque et 3 pour se protéger
				tMonstre[i]->choix=(rand ()%3)+1; //entre 1 et 3
			}
			if (tMonstre[i]->pm < 5) {
				
				//2 pour l'attaque et 3 pour se protéger
				tMonstre[i]->choix=(rand ()%2)+2; // entre 2 et 3
			}
			
			if{ tMonstre[i]->choix == 1){
				tMonstre[i]->life += 20;
			if (tMonstre[i]->life > 100){
                	tMonstre[i]->life = 100;
            }
			tMonstre[i]->pm -= 5;
			printf("Le monstre se soigne, il a maintenant %d de points de vie\n", tMonstre[i]->life);
				
			}
			
			if{ tMonstre[i]->choix == 2){
				
				tperso[persoChoisi]->life -= 10 /tperso[persoChoisi]->resistance;
				printf("Le monstre attaque, vous avez maintenant %d de points de vie\n",tPerso[persoChoisi].life);
			}
			
			if(tMonstre[i]->choix==3){
				tMonstre[i]->resistance *= 2;
			printf("Le monstre resiste ! Les degats qu'il recoit sont divises par %d. \n", tMonstre[i]->resistance);
			}
		}
		
		
	}
}

int main()
{

    int persoChoisi;
    int nbMonstre;

    //Creation Perso

    perso mage = {1, 100, 100, 20, 2, 0, 1, 1};
    perso archer = {2, 100, 100, 5, 20, 0, 1, 1};
    perso tank = {3, 100, 100, 0, 15, 0, 1, 2};

    perso tPerso[3] = {mage, archer, tank};

    srand(time(NULL));

    printf("Combien de monstres voulez vous affronter ?");
    scanf("%d", &nbMonstre);

    monstre tMonstre[nbMonstre];
    creationMonstre(tMonstre, nbMonstre);

    while (mage.life > 0 && archer.life > 0 && tank.life > 0)
    {
        //avant que le joueur ne joue
        //regain d'un point de mana
        if (mage.pm < 20)
        {
            mage.pm++;
        }
        if (archer.pm < 5)
        {
            archer.pm++;
        }

        //action du poison si necessaire
        for (int i = 0; i < nbMonstre; i++)
        {
            if (tMonstre[i].poison > 0)
            {
                tMonstre[i].poison--;
                tMonstre[i].life -= 10;
                printf("%d pv d'alfred avec poison\n", tMonstre[i].life);
            }
        }

        //tour de jeu pour chaque perso
        printf("\nVous jouez le mage :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : soin\n", mage.life, mage.pm, mage.degat, mage.resistance);
        actionPerso(&tPerso[0], tMonstre, tPerso);
        printf("\nVous jouez l'archer :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : fleche empoisonnes\n", archer.life, archer.pm, archer.degat, archer.resistance);
        actionPerso(&tPerso[1], tMonstre, tPerso);
        printf("\nVous jouez le tank :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : agro\n", tank.life, tank.pm, tank.degat, tank.resistance);
        actionPerso(&tPerso[2], tMonstre, tPerso);

	    
	    actionMonstre(tMonstre, tPerso, nbMonstre);
        //apres le tour des monstres
        for (int i = 0; i < nbMonstre; i++)
        {
            tMonstre[i].resistance = tMonstre[i].oResistance;
        }

        //Une fois le tour terminer
        mage.resistance = 1;
        archer.resistance = 1;
        tank.resistance = 2;
    }

    return 0;
}
