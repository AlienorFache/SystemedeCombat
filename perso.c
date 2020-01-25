#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Monstre
{

    int life;
    int pm;
    int degats;
    int resistance;
    int poison;
    int agro;
};

typedef struct Monstre monstre;

struct Perso
{
    int id;
    int life;
    int pm;
    int degat;
    int resistance;
    int choix;
};

typedef struct Perso perso;

void actionPerso(perso *perso, monstre *monstre, struct Perso tPerso[])
{

    int check = 0;
    while (check == 0)
    {
        printf("Tape 1 pour attaquer, 2 pour l'action speciale ou 3 pour te proteger.\n");
        scanf("%d", &perso->choix);
        if (perso->choix <= 3 || perso->choix >= 1)
        {
            check++;
        }
    }

    if (perso->choix == 1)
    {

        /*printf("Choisissez un monstre a attaquer.\n");
        scanf("%d",monstreChoisi)*/

        monstre->life -= perso->degat;
        printf("%d life monstre\n", monstre->life);
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
            if (tPerso[i].life > 100)
            {
                tPerso[i].life = 100;
            }
            printf("vie : %d\n", tPerso[i].life);
        }
        //archer
        if (perso->id == 2)
        {
            /*printf("Choisissez un monstre a attaquer.\n");
            scanf("%d",monstreChoisi)*/
            monstre->life -= 10;
            monstre->poison = 2;
            perso->pm -= 5;
            printf("pm : %d, pv monstre : %d \n", perso->pm, monstre->life);
        }
        //tank
        if (perso->id == 3)
        {
            monstre->agro = 1;
            printf("alfred agro le tank %d", monstre->agro);
        }
    }
}

int main()
{

    int monstreChoisi;
    int persoChoisi;

    monstre alfred = {100, 20, 2, 1, 0, 0};

    //Creation Perso

    perso mage = {1, 100, 20, 2, 1};
    perso archer = {2, 100, 5, 20, 1};
    perso tank = {3, 100, 0, 15, 2};

    perso tPerso[3] = {mage, archer, tank};

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
        if (alfred.poison > 0)
        {
            alfred.poison--;
            alfred.life -= 10;
            printf("%d pv d'alfred avec poison\n", alfred.life);
        }

        //tour de jeu pour chaque perso
        printf("\nVous jouez le mage :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : soin\n", mage.life, mage.pm, mage.degat, mage.resistance);
        actionPerso(&tPerso[0], &alfred, tPerso);
        printf("\nVous jouez l'archer :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : fleche empoisonnes\n", archer.life, archer.pm, archer.degat, archer.resistance);
        actionPerso(&tPerso[1], &alfred, tPerso);
        printf("\nVous jouez le tank :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : agro\n", tank.life, tank.pm, tank.degat, tank.resistance);
        actionPerso(&tPerso[2], &alfred, tPerso);

        //Une fois le tour terminer
        mage.resistance = 1;
        archer.resistance = 1;
        tank.resistance = 2;
        alfred.agro = 0;
    }
    return 0;
}
