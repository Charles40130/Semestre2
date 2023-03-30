#include "soccer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

  Joueur* j1=NULL;
  Equipe * e1=NULL;

  j1=malloc(sizeof(Joueur)*1);
  creationJoueur(j1);
  //afficherJoueur(j1[0]);
  e1=malloc(1*sizeof(Equipe));
  creationEquipe(e1);

  ajouterJoueur(e1,*j1);
  afficherEquipe(*e1);
  return 0;
}
