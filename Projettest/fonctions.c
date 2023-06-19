#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "fonctions.h"




void creation_cartes(cartes pile[104]) {//crée les 104 cartes de jeu et les têtes de boeufs correspondantes
  for (int j = 0; j < 104; j++) {            //par défault les cartes ont 1 tdb
        pile[j].tdb = 1;}
    for (int i = 0; i < 104; i++) {
        pile[i].nb = i + 1;
        if (pile[i].nb % 5 == 0 && pile[i].nb % 10 != 0) {  //si nombre divisible par 5 alors tdb= 2
            pile[i].tdb = 2;}
        if (pile[i].nb % 10 == 0) {  //si nombre divisible par 10 alors tdb = 3
            pile[i].tdb = 3;}
        if (pile[i].nb % 11 == 0 && pile[i].nb != 55) { //si nombre divisible par 11 alors tdb = 5
            pile[i].tdb = 5;}
        if (pile[i].nb == 55) { //si nombre = 55 alors tdb = 7
            pile[i].tdb = 7;
        }
    }
  }

void shuffle(cartes pile[104]) { //fonction qui mélange les cartes
      srand(time(NULL));

      for (int i = 0; i < 104; i++) {
          int j = rand() % 104;){

          cartes temp = pile[i];
          pile[i] = pile[j];
          pile[j] = temp;
      }
    }
}

void joueurs(int *joueursR, int *joueursIA){ //fonciton qui demande le nombre de participants
  int joueurs_reels=0,joueurs_IA=0;
  do{
    printf("Combien de joueurs (réels) veulent jouer? (1-10): ");
    scanf("%d",&joueurs_reels);
  }while(joueurs_reels<=0 || joueurs_reels>10);
  if(joueurs_reels == 10){
    printf("C'est parti, jouons!\n");
  }
  else{
  do{
    printf("Combien d'IA vont jouer? (0-%d): ",10-joueurs_reels);
    scanf("%d",&joueurs_IA);
  }while(joueurs_IA+joueurs_reels>10 || joueurs_IA<0);
  }
  *joueursR=joueurs_reels;
  *joueursIA=joueurs_IA;
}
