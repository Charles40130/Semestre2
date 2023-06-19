#ifndef projet.c
#define projet.c


typedef struct {  //Structure cartes
  int nb;
  int tdb;
}cartes;


typedef struct{ //Structure joueurs
  cartes* jeu
  char* nom


}joueurs;

typedef struct{
  int nb_joueurs_reel;
  int nb_joueurs_IA
  joueur tabjoueurs[]
}tabJoueurs;

/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
void creation_cartes(cartes pile[104]);


/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
void shuffle(cartes pile[104]);
