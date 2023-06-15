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
          nbColonnesLues++;}
        printf("\n");
        nbColonnesLues=0;
        nbLignesLues++;}
      fclose(mesJeux);
    }}
  else{
    printf("Parfait jouons\n\n");
  }}



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


void echanger_carte_joueurs(cartes cartes_joueurs[][10], int i, int j,int indice){
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
      for (int j=i+1; j<10;j++){
        if (cartes_joueurs[indice][j].nb < cartes_joueurs[indice][min].nb){
          min =j;
        }
      }
    echanger_carte_joueurs(cartes_joueurs,i,min,indice);
    }
    indice++;
  }while(indice<nb_joueurs);
}

void initialiser_plateau(cartes melange[104], cartes plateau[4][6]) {
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
}

void plateau_de_jeu(cartes plateau[4][6]){ //fonction qui affiche les cartes du plateau
  for(int i=0;i<4;i++){
    for (int j=0;j<6;j++){
      if(plateau[i][j].nb == 0){
        printf("          __            ||");
      }
      else{
        printf("  [");
        if (plateau[i][j].nb < 10) {
          printf("  ");
        }
        if (plateau[i][j].nb > 9 && plateau[i][j].nb < 100){
          printf(" ");
        }
        printf("%d,",plateau[i][j].nb);
        for(int k=0;k<plateau[i][j].tdb;k++){
          printf("🐮");
        }
        printf("]  ");
        for(int h=0;h<14-(plateau[i][j].tdb*2);h++){
          printf(" ");
        }
        printf("||");
      }
    }
    printf("\n");
  }
}

void main_joueurs(cartes cartes_joueurs[][10],int i,int nb_tour){
  printf("\n\nVoici vos cartes:\n");
  for (int j=0;j<nb_tour;j++){
    if(cartes_joueurs[i][j].nb!=0){
      printf("----------------   ");
    }}
    printf("\n");
  for (int j=0;j<nb_tour;j++){
    printf("|     ");
    if(cartes_joueurs[i][j].nb!=0){
      if (cartes_joueurs[i][j].nb < 10) {
        printf("  ");
      }
      if (cartes_joueurs[i][j].nb > 9 && cartes_joueurs[i][j].nb < 100){
        printf(" ");
      }
      printf("%d      ",cartes_joueurs[i][j].nb);
      }
      printf("|   ");
    }
    printf("\n");
  for (int j=0;j<nb_tour;j++){
    if(cartes_joueurs[i][j].nb!=0){
      printf("|");
      for (int f=0;f<(14-cartes_joueurs[i][j].tdb*2)/2;f++){
        printf(" ");
      }
      for (int h=0;h<cartes_joueurs[i][j].tdb;h++){
        printf("🐮");
      }
      for (int f=0;f<(14-cartes_joueurs[i][j].tdb*2)/2;f++){
        printf(" ");
      }
      printf("|   ");
    }}
  printf("\n");
  for (int j=0;j<nb_tour;j++){
    if(cartes_joueurs[i][j].nb!=0){
      printf("----------------   ");
    }}
  printf("\n");
  printf("\nQuelle cartes sélectionnez-vous pour ce tour?\n");
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

void tour_IA(int joueursR,int joueursIA,cartes cartes_a_jouer[],cartes cartes_joueurs[10][10],int nb_tour){
  int hasard;
  for(int i=0;i<joueursIA;i++){
    hasard= rand() % nb_tour;
    cartes_a_jouer[joueursR+i].nb=cartes_joueurs[joueursR+i][hasard].nb;
    cartes_a_jouer[joueursR+i].tdb=cartes_joueurs[joueursR+i][hasard].tdb;
  }}


void echanger_carte_a_jouer(cartes cartes_a_jouer[],int i,int j){
  cartes temp = cartes_a_jouer[i];
  cartes_a_jouer[i]=cartes_a_jouer[j];
  cartes_a_jouer[j]=temp;

}

void trier_cartes_a_jouer(int nb_joueurs, cartes cartes_a_jouer[nb_joueurs]){
  int min;

  for(int i=0 ; i<nb_joueurs-1;i++){
      min=i;
      for (int j=i+1; j<nb_joueurs ; j++){
          if (cartes_a_jouer[j].nb < cartes_a_jouer[min].nb ){
              min =j;
          }
      }
      echanger_carte_a_jouer(cartes_a_jouer,i,min );
  }
}

void afficher_cartes(int nb_joueurs, cartes cartes_a_jouer[nb_joueurs]) {
  printf("------ Cartes choisies par les joueurs ------\n");
  for (int i=0; i<nb_joueurs;i++){
    printf("Cartes n°%d : [%d,%d]\n", i+1, cartes_a_jouer[i].nb, cartes_a_jouer[i].tdb);
  }
}

void supprime_elements_similaires(cartes cartes_joueurs[][10], int nb_joueurs, int nb_tour, cartes cartes_a_jouer[]) {
    for (int i = 0; i < nb_joueurs; i++) {
        for (int j = 0; j < nb_joueurs; j++) {
            for (int k = 0; k < nb_joueurs; k++) {
                if (cartes_joueurs[i][k].nb == cartes_a_jouer[j].nb && cartes_joueurs[i][k].tdb == cartes_a_jouer[j].tdb) {
                    for (int l = k; l < nb_tour - 1; l++) {
                        cartes_joueurs[i][l] = cartes_joueurs[i][l + 1];
                    }
                    cartes_joueurs[i][nb_tour - 1].nb = 0;
                    cartes_joueurs[i][nb_tour - 1].tdb = 0;
                    k--;
                }}}}}

void chosir_serie(cartes carte, cartes plateau[4][6], int joueur, int nb_joueurs, cartes cartes_ramassees_joueurs[nb_joueurs][30]) {
  int serie;
  plateau_de_jeu(plateau);
  printf( "Joueur %d : votre carte ne peut pas être placée car elle est trop faible !\nVeuillez entrer le numéro d'une des 4 séries sur le plateau pour y ramasser toutes les cartes !\n",joueur+1);
  scanf("%d", &serie);
  int i=0;
  while (cartes_ramassees_joueurs[joueur][i].nb != 0) {
    i=i+1;
  }
  int j=0;
  while (j<6 && plateau[serie-1][j].nb != 0) {
    cartes_ramassees_joueurs[joueur][i] = plateau[serie-1][j];
    plateau[serie-1][j].nb = 0;
    j=j+1;
  }
  plateau[serie-1][0] = carte;
}

void placer_carte(cartes carte, cartes plateau[4][6],int joueur, int nb_joueurs, cartes cartes_ramassees_joueurs[nb_joueurs][30]) {
  int difference = 104;
  int colonnes[4];
  int ligne;
  cartes dernieres_cartes[4];
  for (int i = 0; i<4; i++) {
    int j = 0;
    int petit = 0;
    while (j<6 && plateau[i][j].nb != 0 && petit == 0) {
      if (carte.nb - plateau[i][j].nb < 0) {
        dernieres_cartes[i].nb = 0;
        petit = 1;
      } else {
        dernieres_cartes[i] = plateau[i][j];
        colonnes[i] = j+1;
        j=j+1;
      }
    }
  }
  for (int i = 0; i<4; i++) {
    if(carte.nb - dernieres_cartes[i].nb < difference) {
      difference = carte.nb - dernieres_cartes[i].nb;
      ligne = i;
    }
  }
  if (difference != carte.nb) {
    int i = ligne;
    int j = colonnes[ligne];
    plateau[i][j] = carte;

  } else {
    chosir_serie(carte, plateau, joueur, nb_joueurs, cartes_ramassees_joueurs);
  }
}

 void lignecomplete(cartes plateau[4][6],cartes cartes_ramassees_joueurs[][30],int id_joueur){
   //Balaye les lignes du plateau pour savoir si la 6ème colonne est complétée !
   for(int i=0; i<4;i++){
     if(plateau[i][5].nb!=0){

       //Recherche à partir de quel indice du tableau carte_ramassée_joueur le tableau n'est pas complété
       int k=0;
       while (cartes_ramassees_joueurs[id_joueur][k].nb != 0) {
         k=k+1;
       }

       //met les élément du tableau dans les cartes ramassées//
       for( int h=0;h<5;h++){
         cartes_ramassees_joueurs[id_joueur][k+h]=plateau[i][h];
       }
       printf("La ligne n° %d est pleine! Joueur n°%d tu récupère les cartes de la ligne !\n",i+1,id_joueur+1);


       ///remet la ligne à 0 et la 6ème élement au début de la ligne du plateau//
       plateau[i][0]=plateau[i][5];
       for (int j=1;j<6;j++){
         plateau[i][j].nb=0;
       }
     }
   }
 }

void noms(int joueursR,char noms_des_joueurs[joueursR][30]){
  char nom[30];
  for (int i=0;i<joueursR;i++){
    printf("Quel est le nom du joueur n°%d\n",i+1);
    scanf("%s",nom);
    for (int j=0;j < sizeof(nom);j++){
      noms_des_joueurs[i][j]=nom[j];
    }
  }
}

void tour_de_jeu(int nb_tour,int nb_joueurs,cartes plateau[4][6],cartes melange[104],cartes cartes_joueurs[10][10],int joueursR,int joueursIA,cartes cartes_a_jouer[nb_joueurs],cartes cartes_ramassees_joueurs[nb_joueurs][30],char noms_des_joueurs[][30]){
  for (int i=0;i<joueursR;i++){ //fonction qui demande au joueur quelle carte veut-il jouer
    int select;
    system("clear");
    plateau_de_jeu(plateau);
    do{
    main_joueurs(cartes_joueurs,i,nb_tour);
    scanf("%d",&select);
  }while(select<1 || select>10);
    cartes_a_jouer[i].nb=cartes_joueurs[i][select-1].nb;
    cartes_a_jouer[i].tdb=cartes_joueurs[i][select-1].tdb;
  }
  tour_IA(joueursR,joueursIA,cartes_a_jouer,cartes_joueurs,nb_tour);
  system("clear");
  trier_cartes_a_jouer(nb_joueurs, cartes_a_jouer);
  afficher_cartes(nb_joueurs, cartes_a_jouer);
  for (int j=0;j<nb_joueurs;j++){
    placer_carte(cartes_a_jouer[j], plateau, j, nb_joueurs, cartes_ramassees_joueurs);
    lignecomplete(plateau,cartes_ramassees_joueurs,j);
  }
  plateau_de_jeu(plateau);
  supprime_elements_similaires(cartes_joueurs, nb_joueurs, nb_tour, cartes_a_jouer);
  sleep(6);
}

int verifpts(int nb_joueurs,cartes cartes_ramassees_joueurs[nb_joueurs][30]){ //Fonction qui compte le total de tête de boeuf de chaque joueur ,la fonction renvoi le numéro du joueur si celui ci est à plus de 66pts!
  int total;
  int j;
  for(int i=0;i<nb_joueurs;i++){
    total=0;
    j=0;
    while(cartes_ramassees_joueurs[i][j].nb != 0){
      total=total + cartes_ramassees_joueurs[i][j].tdb;
      j++;
      if (total>65){
        return i+1;
      }
    }
  }
  return 0;
}