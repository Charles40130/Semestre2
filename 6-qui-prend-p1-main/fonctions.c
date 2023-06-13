#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "fonctions.h"

void regles(){ //fonction qui affiche les regles du jeu avec fichier csv
  int n=1000;
  char rep;
  printf("Voulez-vous d'abord connaître les règles du jeu? (o/n)\n");
  scanf("%c",&rep);
  if (rep == 'o'){
    FILE* mesJeux = NULL; char ligne[n];
    int nbLignesLues = 0; int nbColonnesLues = 0;
    char* laLigne;
    laLigne=malloc(sizeof(char)*n);
    mesJeux = fopen("regles.csv", "r");
    if (mesJeux == NULL) {
      printf("Erreur ouverture fichier \n");
    }else{
      while(fgets(ligne,n,mesJeux) !=NULL){
        laLigne= strtok(ligne," ");
        while (laLigne != NULL){
          printf("%s ",laLigne);
          laLigne = strtok(NULL, ";");
          nbColonnesLues++;
        }
        printf("\n");
        nbColonnesLues=0;
        nbLignesLues++;
      }
      fclose(mesJeux);
    }
  }
  else{
    printf("Parfait jouons\n\n");
  }
}



void creation_cartes(cartes pile[104]) {//crée les 104 cartes de jeu et les têtes de boeufs correspondantes
    for (int j = 0; j < 104; j++) {            //par défault les cartes ont 1 tdb
        pile[j].tdb = 1;
    }
    for (int i = 0; i < 104; i++) {
        pile[i].nb = i + 1;
        if (pile[i].nb % 5 == 0 && pile[i].nb % 10 != 0) {  //si nombre divisible par 5 alors tdb= 2
            pile[i].tdb = 2;
        }
        if (pile[i].nb % 10 == 0) {  //si nombre divisible par 10 alors tdb = 3
            pile[i].tdb = 3;
        }
        if (pile[i].nb % 11 == 0 && pile[i].nb != 55) { //si nombre divisible par 11 alors tdb = 5
            pile[i].tdb = 5;
        }
        if (pile[i].nb == 55) { //si nombre = 55 alors tdb = 7
            pile[i].tdb = 7;
        }}}


void shuffle(cartes pile[104]) { //fonction qui mélange les cartes
    srand(time(NULL));

    for (int i = 0; i < 104; i++) {
        int j = rand() % 104;

        cartes temp = pile[i];
        pile[i] = pile[j];
        pile[j] = temp;
    }}

void distribuer_cartes(cartes melange[104], int nb_joueurs, cartes cartes_joueurs[][10]) {
    int indice_carte = 0; //distribution des cartes par rapport au nombre de joueur

    for (int i = 0; i < nb_joueurs; i++) {
        for (int j = 0; j < 10; j++) {
            cartes_joueurs[i][j] = melange[indice_carte];
            indice_carte++;
        }}}

void echanger(cartes cartes_joueurs[][10], int i, int j,int indice){
  cartes temp = cartes_joueurs[indice][i];
  cartes_joueurs[indice][i]=cartes_joueurs[indice][j];
  cartes_joueurs[indice][j]=temp;
}

void trier_cartes(int nb_joueurs,cartes cartes_joueurs[][10]){
  int indice = 0;
  do{
    int min;
    for( int i=0; i<9;i++){
      min=i;
      for (int j=i+1; j<10; j ++){
        if ((cartes_joueurs[indice][j]) < (cartes_joueurs[indice][min])){
          min =j;
        }
      }
    echanger(cartes_joueurs[][10],i,min,int indice);
    }
    indice++;
  }while(indice<nb_joueurs);
}



void plateau_de_jeu(cartes plateau[4][6],cartes melange[104]){ //fonction qui affiche les cartes du plateau
  int indice_carte = 103;
  for(int i=0;i<4;i++){
    for(int j=0;j<6;j++){
      plateau[i][j].nb=0;
    }
  }
  for (int i=0;i<4;i++){
    plateau[i][0]= melange[indice_carte];
    indice_carte--;
  }
  for(int i=0;i<4;i++){
    for (int j=0;j<6;j++){
      if(plateau[i][j].nb == 0){
        printf("   __   ||");
      }
      else{
        printf("[");
        if (plateau[i][j].nb < 10) {
          printf("0");
        }
        printf("%d,%d]",plateau[i][j].nb,plateau[i][j].tdb);
        printf("   ||   ");
      }
    }
    printf("\n");
  }
}

void joueurs(int *joueursR, int *joueursIA){ //fonciton qui demande le nombre de participants
  int joueurs_reels=1,joueurs_IA=1;
  do{
    printf("Combien de joueurs (réels) veulent jouer? (1-10): ");
    scanf("%d",&joueurs_reels);
  }while(joueurs_reels<=0 || joueurs_reels>10);
  if(joueurs_reels == 10){
    printf("C'est parti, jouons!");
  }
  else{
  do{
    printf("Combien d'IA vont jouer? (1-%d): ",10-joueurs_reels);
    scanf("%d",&joueurs_IA);
  }while(joueurs_IA+joueurs_reels>10 || joueurs_IA<0);
  *joueursR=joueurs_reels;
  *joueursIA=joueurs_IA;
}
}

void tour_IA(int joueursR,int joueursIA,cartes cartes_a_jouer[],cartes cartes_joueurs[10][10],int nb_tour){
  int hasard;
  for(int i=0;i<joueursIA;i++){
    hasard= rand() % nb_tour;
    cartes_a_jouer[joueursR+i].nb=cartes_joueurs[joueursR+i][hasard].nb;
    cartes_a_jouer[joueursR+i].tdb=cartes_joueurs[joueursR+i][hasard].tdb;
  }
}

void afficher_cartes(int nb_joueurs, cartes cartes_a_jouer[nb_joueurs]) {
  printf("------ Cartes chosies par les joueurs ------\n");
  for (int i = 0; i<nb_joueurs; i++) {
    printf("Joueur %d : [%d,%d]\n", i+1, cartes_a_jouer[i].nb, cartes_a_jouer[i].tdb);
  }
}

void tour_de_jeu(int nb_tour,int nb_joueurs,cartes plateau[4][6],cartes melange[104],cartes cartes_joueurs[10][10],int joueursR,int joueursIA,cartes cartes_a_jouer[nb_joueurs]){
  for (int i=0;i<joueursR;i++){ //fonction qui demande au joueur quelle carte veut-il jouer
    int select;
    system("clear");
    plateau_de_jeu(plateau,melange);
    printf("\n\nVoici vos cartes:\n");
    for (int j=0;j<nb_tour;j++){
      printf("Carte %d : nb = %d, tdb = %d\n", j + 1, cartes_joueurs[i][j].nb, cartes_joueurs[i][j].tdb);
    }
    printf("\nQuelle cartes sélectionnez-vous pour ce tour?\n");
    scanf("%d",&select);
    cartes_a_jouer[i].nb=cartes_joueurs[i][select-1].nb;
    cartes_a_jouer[i].tdb=cartes_joueurs[i][select-1].tdb;
  }
  tour_IA(joueursR,joueursIA,cartes_a_jouer,cartes_joueurs,nb_tour);
  system("clear");
  afficher_cartes(nb_joueurs, cartes_a_jouer);
}
