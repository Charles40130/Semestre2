


struct Joueur{
  char* nom;
  char* prenom;
  char* poste;
  int numero;
  int age;
  int nb_buts;
};
typedef struct Joueur Joueur;

struct Equipe{
  char* nom;
  char* pays;
  char* championnat;
  int classement;
  int nb_Joueurs;
  Joueur* mesJoueurs;
};
typedef struct Equipe Equipe;
/* Auteur : ... */
/* Date :   ... */
/* Résumé : ... */ 
/* Entrée(s) : ... */
/* Sortie(s) :  ...  */

void creationJoueur(Joueur* j);


void afficherJoueur(Joueur j);

void creationEquipe(Equipe* e);

/* Auteur : ... */
/* Date :   ... */
/* Résumé : ... */
/* Entrée(s) : ... */
/* Sortie(s) :  ...  */

void ajouterJoueur(Equipe* e,Joueur j);

void afficherEquipe(Equipe e);


/* Auteur : ... */
/* Date :   ... */
/* Résumé : ... */
/* Entrée(s) : ... */
/* Sortie(s) :  ...  */

Joueur meilleurButeur(Equipe e);

