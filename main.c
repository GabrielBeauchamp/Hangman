#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "jeu.h"
#include "dictionnaire.h"

int main(int argc, char *argv[])
{
    FILE *fichierMot = NULL;
    int nombreMot = 0, positionMot = 0, longeurMot = 0, mot[15];
    int motDeviner[15];
    int entre = 0, positionCaractere = 0, j = 0, i = 0;
    int essaiRestant = 10, nombreEssai = 0;

    fichierMot = fopen("mot", "r");	/* On ouvre le fichier */
    if (fichierMot == NULL) {	/* On teste pour savoir si tou c'est bien passé */
	printf("Le fichier \"mot\" ne peut être ouvert\n");
	return 1;
    }

    nombreMot = compterMot(fichierMot);	/* Compte le nombre de mot */
    /* Ceci est uniquement pour le debugage. */
    printf("Ceci est le nombre de mot dans le fichier 'mot' %d\n",
	   nombreMot);

    /* Position du mot dans la liste de tout les mots. */
    positionMot = nombreAleatoire(nombreMot);

    /* Longeur du mot en caractere. */
    longeurMot = lireMot(fichierMot, positionMot, mot);	/* On sort la longeur du mot en même temps */
    printf("Ceci est la longeur en caractere du mot %d\n", longeurMot);	/* On affiche ensuite la longeur du sus-choisi mot */


    //    int i;			/* "fonction" test pour savoir le mot */
    //for (i = 0; i < longeurMot; i++) {
    //	printf("%c", mot[i]);
    //}

    /* Initialisation du tableau */
    for (i = 0; i <= longeurMot; i++) {
	motDeviner[i] = '*';
    }
    /* Démarrage du jeu a proprement parler. */
    printf("\nBienvenue dans mon pendu.\n");
    printf("Un mot a été choisi, vous avez 10 chances.\n");
    printf("Bonne chance !\n");

    while (essaiRestant > 0) {	/* Boucle principale */
	int j = 0, k = 0;	/* Afficher le nombre de caractere restant. */
	for (j = 0; j < longeurMot; j++) {
	    printf("%c", motDeviner[j]);
	}

	/* Et on fait un retour de chariot */
	printf("\n> ");		/* Au moins, personne ne peut dire que le programme à planté... */
	entre = lireCaractere();

	positionCaractere =
	    comparerCaractere(entre, mot, motDeviner, longeurMot);

	if (positionCaractere != entre) {
	    essaiRestant--;
	    printf
		("Il reste %d essai restant avant une mort certaine...\n",
		 essaiRestant);
	}

	/* Donc on compare les deux tableau de "mot" et on incrémente k a chaque caractere valide */
	for (j = 0; j < longeurMot; j++) {
	    if (mot[j] == motDeviner[j])
		k++;
	}
	/* Si k est égual à longeurMot cela veux dire que les deux chaines sont identiques. Donc, victoire! */
	if (k == longeurMot) {
	    printf("Vous avez gagner! En %d coups!\n", nombreEssai);
	    fclose(fichierMot);
	    return 0;
	}
	nombreEssai++;
    }

    fclose(fichierMot);
    return 0;
}
