#include <stdio.h>
#include "fonctions.h"
#include "trisLents.h"
#include "trisRapides.h"


int main(){
  int* monTab;
  int taille=10;
  int choix;
  monTab= allouer(taille);
  initialiser(monTab,taille);

  printf("Tableau initial: \n");
  afficher(monTab,taille);
  printf("Choisissez votre tri : \n");
  printf("1 : Tri par selection   2: Tri a bulles   3: Tri Rapide   4: Tri Fusion \n ");
  scanf("%d", &choix);
  switch (choix){
    case 1:
      triSelection(monTab,taille);
      printf("Voilà le tri par Selection : \n");
      break;
    case 2:
      triBulles(monTab,taille);
      printf("Voilà le tri à Bulles : \n");
      break;
    case 3:
      triInsertion(monTab,taille);
      printf("Voilà le tri à Insertion : \n");
      break;
    default :
      printf("Ok \n");
      break;

  }
  afficher(monTab,taille);
  printf("C'est le TP7 !\n");

  return 0;
}
