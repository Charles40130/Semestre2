#include "puissance4.h"
#include <stdlib.h>
/* corps des différentes fonctions/procédures */

int** allouer(int taille){
  int** maGrille = NULL;
  maGrille=malloc(taille * sizeof (int*));
  for (int i=0;i<taille;i++){
    maGrille[i]=  malloc(taille * sizeof (int));
  }
  return maGrille;
}

void initialiser(int** maGrille,int taille){
  for (int i=0 ; i<taille; i++){
    for (int j=0; j<taille ; j++){
      maGrille[i][j]=-1;
    }
  }
}

void afficher(int** maGrille,int taille){
  printf("  ");
  for (int h=1; h<taille+1;h++){

    printf("  %d ",h);
  }
  printf("\n");
  for (int i=0 ; i<taille; i++){
    printf("%d |",i+1);
    for (int j=0; j<taille ; j++){
      switch (maGrille[i][j]){
        case 1:
          printf("\033[31m");
          printf(" X");
          printf("\033[00m");
          printf(" |");
          break;
        case 2:
          printf("\033[1;33m");
          printf(" O");
          printf("\033[00m");
          printf(" |");
          break;
        default:
          printf("   |");
          break;
      }
    }
    printf("\n");
  }
}

int jouer(int** maGrille,int taille, int joueur){
  int x;
  int y;
  do{
    printf("Saisir lignes\n");
    scanf("%d",&x);
    printf("Saisir colonnes\n");
    scanf("%d",&y);


  }while((x-1<0) || (y-1<0)||(x>taille) || (y>taille) || (maGrille[x-1][y-1]==1 )|| (maGrille[x-1][y-1]==2));
  maGrille[x-1][y-1]=joueur;

  return 1;
}

int veriflignes(int** maGrille,int taille){
  for(int i=0; i<taille; i++){
    for (int j=0;j<taille-3;j++){
      if((maGrille[i][j]!=-1) && ( (maGrille[i][j])==(maGrille[i][j+1])== (maGrille[i][j+2]) == (maGrille[i][j+3])) ){
        printf("Test1\n");
        return 1;
      }
    }
  }
  return 0;
}

int verifcolonnes(int** maGrille,int taille){
  for (int i=0;i<taille-3;i++){
    for (int j=0;j<taille;j++){
      if((maGrille[i][j]!=-1) && ( (maGrille[i][j])== (maGrille[i+1][j]) == (maGrille[i+2][j]) == (maGrille[i+3][j]) )){
        printf("Test2\n");
        return 1;
      }
    }
  }
  return 0;
}

int verifdiag1(int** maGrille,int taille){
  for(int i=0; i<taille-3 ; i++){
    for (int j=0;j<taille-3 ;j++){
      if((maGrille[i][j]!=-1) && ( (maGrille[i][j]) == (maGrille[i+1][j+1]) == (maGrille[i+2][j+2]) == (maGrille[i+3][j+3]))){
        printf("Test3\n");
        return 1;
      }
    }
  }
  return 0;
}
int verifdiag2(int** maGrille,int taille){
  for(int i=3; i<taille ; i++){
    for (int j=0;j<taille-3 ;j++){
      if((maGrille[i][j]!=-1) && ( (maGrille[i][j]) ==(maGrille[i-1][j+1]) == (maGrille[i-2][j+2])== (maGrille[i-3][j+3]))){
        printf("Test4\n");
      }
    }
  }
  return 0;
}

int aGagne(int** maGrille,int taille){
  if( (veriflignes(maGrille,taille)) || (verifcolonnes(maGrille,taille)) || (verifdiag1(maGrille,taille)) || (verifdiag2(maGrille,taille)) ){
    return 1;
  }
  return 0;
}
