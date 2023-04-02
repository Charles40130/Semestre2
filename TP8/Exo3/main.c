#include "soccer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

  Joueur * j1,* j2,* j3,* j4,* j5,* j6, *j7=NULL;
  Equipe * e1=NULL;
  Equipe * e2=NULL;
  Joueur bestplayer;

  j1=malloc(sizeof(Joueur)*1);
  creationJoueur(j1);
  //afficherJoueur(j1[0]);

  j2=malloc(sizeof(Joueur)*1);
  creationJoueur(j2);
  //afficherJoueur(j2[0]);

  j3=malloc(sizeof(Joueur)*1);
  creationJoueur(j3);
  //afficherJoueur(j3[0]);

  j4=malloc(sizeof(Joueur)*1);
  creationJoueur(j4);
  //afficherJoueur(j4[0]);*/  

  e1=malloc(1*sizeof(Equipe));
  creationEquipe(e1);

  ajouterJoueur(e1,*j1);
  ajouterJoueur(e1,*j2);
  ajouterJoueur(e1,*j3);
  ajouterJoueur(e1,*j4);

  afficherEquipe(*e1);

  j5=malloc(sizeof(Joueur)*1);
  creationJoueur(j5);
  //afficherJoueur(j5[0]);

  j6=malloc(sizeof(Joueur)*1);
  creationJoueur(j6);
  //afficherJoueur(j6[0]);

  j7=malloc(sizeof(Joueur)*1);
  creationJoueur(j7);
  //afficherJoueur(j7[0]);

  e2=malloc(1*sizeof(Equipe));
  creationEquipe(e2);

  ajouterJoueur(e2,*j5);
  ajouterJoueur(e2,*j6);
  ajouterJoueur(e2,*j7);


  
  afficherEquipe(*e1);


  bestplayer=meilleurButeur(*e2);
  printf("Le meilleur buteur de l'équipe %s est : %s %s .\n",e1->nom,bestplayer.nom, bestplayer.prenom);
  
  free(j1);
  free(j2);
  free(j3);
  free(j4);
  free(j5);
  free(j6);
  free(e1);
  free(e2);
  return 0;
}
