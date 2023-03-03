#include <stdio.h>
#include <stdlib.h>
#include "puissance4.h"

#define TAILLE 7
int main(){
  int** maGrille;
  int joueur;
  int cptTour;

  joueur=2;
  cptTour=0;
  printf("C'est le puissance 4 ! \n");
  maGrille=allouer(TAILLE);
  initialiser(maGrille,TAILLE);
  afficher(maGrille,TAILLE);


  do{
    if(joueur ==1){
      joueur=2;
    }else{
      joueur =1;
    }
    jouer(maGrille,TAILLE,joueur);
    afficher(maGrille,TAILLE);
    cptTour=cptTour + 1;
  }while(!(aGagne(maGrille,TAILLE)) && (cptTour!=(TAILLE*TAILLE)));
  if (cptTour!=(TAILLE*TAILLE)){
    printf("Le gagné est le joueur n°%d. \n",joueur);
  }else{
    printf("Il y a match nul \n");
  }

  free(maGrille);
  maGrille=NULL;
  return 0;
}
