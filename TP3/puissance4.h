#include <stdio.h>

#ifndef __puissance4_H_
#define __puissance4_H_
/* toutes mes signatures/prototypes de fonctions/procédures */
#endif

/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé : */
/* Entrée(s) : taille */
/* Sortie(s) :  */
int** allouer(int taille);


/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé : */
/* Entrée(s) : maGrille(tableau d'entiers), entier taille */
/* Sortie(s) :  */
void initialiser(int** maGrille,int taille);

/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé : */
/* Entrée(s) : maGrille(tableau d'entiers), entier taille */
/* Sortie(s) :  */
void afficher(int** maGrille,int taille);

/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé :  ...*/
/* Entrée(s) : maGrille(tableau d'entiers), entier taille, entier joueur */
/* Sortie(s) :  ... */
int jouer(int** maGrille,int taille, int joueur);

/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé : */
/* Entrée(s) : maGrille(tableau d'entiers), entier taille */
/* Sortie(s) :  */
int verifcolonnes(int** maGrille,int taille);

/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé : */
/* Entrée(s) : maGrille(tableau d'entiers), entier taille */
/* Sortie(s) :  */
int veriflignes(int** maGrille,int taille);

/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé : */
/* Entrée(s) : maGrille(tableau d'entiers), entier taille */
/* Sortie(s) :  */
int verifdiag1(int** maGrille,int taille);

/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé : */
/* Entrée(s) : maGrille(tableau d'entiers), entier taille */
/* Sortie(s) :  */
int verifdiag2(int** maGrille,int taille);

/* Auteur : Mendiburu Charles */
/* Date : 22/03/2023 */
/* Résumé : */
/* Entrée(s) : maGrille(tableau d'entiers), entier taille */
/* Sortie(s) :  */
int aGagne(int** maGrille,int taille);
