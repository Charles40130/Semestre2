#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "trisLents.h"
#include "trisRapides.h"


int main(){
  int* monTab;
  int taille=10;
  int choix;
  int pas;
  clock_t t_initial; /* Temps initial en micro-secondes */
  clock_t t_final; /* Temps final en micro-secondes */
  float temps_total; /* Temps total en secondes */
  pas =0;
  monTab= allouer(taille);
  initialiser(monTab,taille);

  printf("Tableau initial: \n");
  afficher(monTab,taille);
  printf("Choisissez votre tri : \n");
  printf("1 : Tri par selection   2: Tri a bulles   3: Tri Insertion   4: Tri Rapide  5:Tri Fusion \n ");
  scanf("%d", &choix);
  switch (choix){
    case 1:
      //t_initial= clock();
      triSelection(monTab,taille);
      /*t_final= clock();
      temps_total= (float)(t2-t1)* */
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
    case 4:
      triRapide(monTab,pas,taille);
      printf("Voilà le tri Rapide : \n");
      break;
    case 5:
      triFusion(monTab,pas,taille-1);
      printf("Voilà le tri Fusion : \n");
      break;
    default :
      printf("Pourquoi tu veux pas trier ton tableau sale merde... \n");

  }
  afficher(monTab,taille);
  free(monTab);
  //printf("ma Super Fonction a mis %f de secondes à s'executer \n",temps_total);
  printf("C'est le TP7 !\n");

  return 0;
}
