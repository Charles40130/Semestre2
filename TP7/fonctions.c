#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* toutes mes signatures/prototypes de fonctions/méthodes + leur corps */


int* allouer(int taille){
  int* monTab = NULL;
  monTab=malloc(taille * sizeof (int));
  return monTab;
}

void initialiser(int* monTab,int taille){
  srand (time (NULL));
  for (int i=0 ; i<taille; i++){
      monTab[i]= rand() % 100;
  }
}

void afficher(int* monTab,int taille){
  printf("|");
  for(int i=0; i<taille ; i++){
    printf("%d |",monTab[i]);
  }
  printf("\n");
}

void echanger(int* monTab,int i,int j){
  int temp = monTab[i];
  monTab[i]=monTab[j];
  monTab[j]=temp;
}
