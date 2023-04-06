

struct Etudiant{
  int num;
  char* nom;
  char* nom;
  int mesNotes[5];

  };
typedef struct Etudiant Etudiant;



struc tabEtudiants{
  int taille;
  Etudiant* tabetudiants;

}
typedef struct tabEtudiants tabEtudiants:

/* Auteur : ... */
/* Date :   ... */
/* Résumé : ... */
/* Entrée(s) : ... */
/* Sortie(s) :  ...  */

tabEtudiants* lireCSV(char* fichierNotes);
