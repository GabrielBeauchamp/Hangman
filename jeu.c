#include "jeu.h"

char lireCaractere()
{
  char caract = 0;
  
  caract = getchar(); /* Prends le caractere */
  caract = toupper(caract); /* Le met en MAJ. */

  /* Tant qu'on a pas atteint la fin d'un mot (ligne) on vide le 'buffer' */
  while( getchar() != '\n') ;
  
  return caract;
}

int comparerCaractere(int entre, int mot[], int motDeviner[], int longeurMot)
{
  int tmpc = 0; /* Caractere Temporaire */
  int i = 0, tmpi = 0; /* , Position Temporaire */
  int j, k;
  
  for(i = 0; i < 13; i++)
    {
      if(entre == mot[i]) /* Si le caractere entré est égual a un caractere du tableau */
	{
	  tmpi = i; 
	  tmpc = entre;
	  printf("Position dans le mot %d Valeur ASCII %d \n", tmpi, tmpc); /* on affiche pour les tests */
	  motDeviner[tmpi] = entre;
	}
    }
  return tmpc;
}

int nombreAleatoire()
{
  int positionMot;
  srand(time(NULL)); /* Pour sortir un nombre au hasard */
  positionMot = (rand() % (nombreMot - 0)) + 0; /* Les 2 derniers '0' pourrais très probablement être enlevé... */
  return positionMot;  
}
