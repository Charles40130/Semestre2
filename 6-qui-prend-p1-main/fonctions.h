#ifndef projet.c
#define projet.c


typedef struct {
    int nb;
    int tdb;
} cartes;

/* Auteur : Declosmesnil Mathis */
/* Date :  21/05 */
/* Résumé :  Demande combien de joueurs veulent jouer */
/* Entrée(s) :  Variable vide */
/* Sortie(s) :  Nombre de joueurs réels/ Nombre de joueurs virtuels */
void regles();

/* Auteur : Declosmesnil Mathis */
/* Date :  21/05 */
/* Résumé :  Demande combien de joueurs veulent jouer */
/* Entrée(s) :  Variable vide */
/* Sortie(s) :  Nombre de joueurs réels/ Nombre de joueurs virtuels */
void joueurs(int *joueursR,int *joueursIA);


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


/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
void distribuer_cartes(cartes melange[104], int nb_joueurs, cartes cartes_joueurs[][10]);

/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
void trier_cartes(int nb_joueurs,cartes cartes_joueurs[][10]);

/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
void plateau_de_jeu(cartes plateau[4][6],cartes melange[104], int nb_tour);

void echanger_carte_a_jouer(cartes cartes_a_jouer[],int i,int j);
void trier_cartes_a_jouer(int nb_joueurs, cartes cartes_a_jouer[nb_joueurs]);
void tour_IA(int joueursR,int joueursIA,cartes cartes_a_jouer[],cartes cartes_joueurs[10][10],int nb_tour);
void tour_de_jeu(int nb_tour,int nb_joueurs,cartes plateau[4][6],cartes melange[104],cartes cartes_joueurs[10][10],int joueursR,int joueursIA, cartes cartes_a_jouer[nb_joueurs],cartes cartes_ramassees_joueurs[nb_joueurs][30]);
void placer_carte(cartes carte, cartes plateau[4][6],int joueur, int nb_joueurs, cartes cartes_ramassees_joueurs[nb_joueurs][30], cartes melange[104], int nb_tour_restants);
void afficher_cartes(int nb_joueurs, cartes cartes_a_jouer[nb_joueurs]);
void chosir_serie(cartes carte, cartes plateau[4][6], int joueur, int nb_joueurs, cartes cartes_ramassees_joueurs[nb_joueurs][30], cartes melange[104], int nb_tour_restants);
void suppligne(cartes plateau[4][6]);
#endif
