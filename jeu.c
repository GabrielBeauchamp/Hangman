#include "jeu.h"

char lireCaractere()
{
    char caract = 0;

    caract = getchar();		/* Prends le caractere */
    caract = toupper(caract);	/* Le met en MAJ. */

    /* Tant qu'on a pas atteint la fin d'un mot (ligne) on vide le 'buffer' */
    while (getchar() != '\n');

    return caract;
}

int comparerCaractere(int entre, int mot[], int motDeviner[],
		      int longeurMot)
{
    int tmpc = 0;		/* Caractere Temporaire */
    int i = 0, tmpi = 0;	/* , Position Temporaire */
    int j, k;

    for (i = 0; i < 13; i++) {
	/* Si le caractere entré est égual a un caractere du tableau */
	if (entre == mot[i]) {
	    tmpi = i;
	    tmpc = entre;
	    /* on affiche pour les tests */
	    printf("Position dans le mot %d Valeur ASCII %d \n", tmpi, tmpc);
	    motDeviner[tmpi] = entre;
	}
    }
    return tmpc;
}

int nombreAleatoire(int nombreMot)
{
    int positionMot;
    srand(time(0));		/* Pour sortir un nombre au hasard */
    positionMot = (rand() % nombreMot);
    return positionMot;
}
