#include <stdio.h>
#include "fonctions.h"
#include "trisLents.h"
#include "trisRapides.h"


int main(){
  int* monTab;
  int taille=10;
  monTab= allouer(taille);
  initialiser(monTab,taille);
  afficher(monTab,taille);
  printf("C'est le TP7 !\n");

  return 0;
}
