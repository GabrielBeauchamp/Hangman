#include <stdlib.h>
#include <stdio.h>

int compterMot(FILE* fichier)
{
  int nombreMot = 0;
  int caract = 0;

  while( caract != EOF) 
    {
      /* printf("%c", caract); */ /* Ceci est pour les tests. Affiche les mots. */
      caract = fgetc(fichier);
      
      if(caract == '\n')
	{
	  nombreMot += 1;
	}
    }

  rewind(fichier); /* S'assure que le "curseur" soit placé en début de fichier. */
  return nombreMot; /* Si on peut éviter les pointeurs... */
}

int lireMot(FILE* fichier, int motALire, int mot[])
{
  int caract = 0, i = 0, compte = 0;
  int test = 0, longeur = 0;
   
  do /* Pour mettre le "curseur" a la bonne place */
    {
      caract = fgetc(fichier);
      if(caract == '\n')
	{
	  i++;
	}
    }while(i != motALire);

 /* Ceci fonctionne sauf pour la premiere position... Il manque un caractere... */
 if(motALire == 0)
   {
     rewind(fichier);
   }

 /* Théoriquement on est a la bonne place... */
 for(compte = 0; test != '\n'; compte++)
    {
      test = fgetc(fichier);
      mot[compte] = test;
      longeur++;
      if(compte == 13) /* Pour tenté d'éviter un 'buffer-overflow' */
	{ 
	  break;
	}
    }
 longeur--; /* Je sais pas pourquoi mais il compte un caractere de trop... */
 return longeur;
}

/* Finalement pas utilisé, alors, pour une raison obscure il est important que je la gare... */
/* D'ailleurs, elle fonctionne probablement pas... */
int longeurMot(int mot[])
{
  int i = 0;
  for(i = 0; mot[i] != '\n'; i++){}
  return i;
}
