#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** allouerTableau(int nb_lignes,int nb_colonnes){
  int** p_tab = NULL;
  p_tab=malloc(nb_lignes * sizeof (int*));
  for (int i=0;i<nb_lignes;i++){
    p_tab[i]=  malloc(nb_colonnes * sizeof (int));
  }
  return p_tab;
}

void initTableau(int** p_tab,int nb_lignes,int nb_colonnes){
  int saisie;
  for(int i=0; i< nb_lignes; i++){
    for (int j=0; j<nb_colonnes; j++){
      printf("Ligne = %d      Colonne = %d \n",i,j );
      scanf("%d",&saisie);
      p_tab[i][j]=saisie;
    }
  }
}


void afficherTableau(int** p_tab, int nb_lignes, int nb_colonnes){
  for (int i=0;i<nb_lignes;i++){
    printf("|");
  for (int j=0;j<nb_colonnes;j++){
    printf(" %d | ",p_tab[i][j]);
  }
  printf("\n");
  }
}

int cptLigne(int** p_tab,int lignes,int nb_colonnes){
  int sommeligne= 0;
  for (int i= 0 ; i<nb_colonnes; i++){
    sommeligne = sommeligne + p_tab[lignes][i];
  }
  return sommeligne;

}

int cptDiagG(int** p_tab,int nb_lignes,int nb_colonnes){
  int sommediagG = 0;
  for (int i= 0 ; i<nb_lignes; i++){
    sommediagG = sommediagG + p_tab[i][i];
  }
  return sommediagG;
}

int cptDiagR(int** p_tab,int nb_lignes,int nb_colonnes){
  int sommediagG = 0;
  for (int i= 0 ; i<nb_lignes; i++){
    sommediagG = sommediagG + p_tab[i][i];
  }
  return sommediagG;
}

int main(){
  int **p_tab;
  int nb_lignes;
  int nb_colonnes;
  int sommeligne;
  int lignes;
  int sommediagG;
  printf("Saisir nb lignes \n");
  scanf("%d",&nb_lignes);
  printf("Saisir nb colonnes \n");
  scanf("%d",&nb_colonnes);
  p_tab=allouerTableau(nb_lignes,nb_colonnes);
  initTableau(p_tab,nb_lignes, nb_colonnes);
  afficherTableau(p_tab,nb_lignes,nb_colonnes);
  printf("De quel ligne voulez vous faire la somme \n");
  scanf("%d",&lignes);
  lignes = lignes -1;
  sommeligne = cptLigne(p_tab,lignes,nb_colonnes);
  printf("Somme ligne %d : %d \n",lignes +1,sommeligne);
  sommediagG = cptDiagG(p_tab,nb_lignes,nb_colonnes);
  printf("Somme diagonale gauche : %d \n",sommediagG);
  return 0;
}
/*for (int i=0;i<taille1;i++){
  free(p_tab[i]);
}
free(p_tab);
p_tab=NULL;*/
