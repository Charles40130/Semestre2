#include "trisRapides.h"
#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* toutes mes signatures/prototypes de fonctions/méthodes + leur corps */



void triRapide(int* monTab, int pas, int taille){
  int q;
  if (pas < taille){
    q = partitionner(monTab,pas,taille);
    triRapide(monTab,pas,q);
    triRapide(monTab,q+1,taille);
  }
}

int partitionner(int* monTab,int pas, int taille){
  int pivot;
  pivot= monTab[pas];
  int i= pas-1;
  int j= taille +1;
  while(i<j){
    do{
      j=j-1;
    }while(monTab[j]>pivot);
    do{
      i=i+1;
    }while(monTab[i]<pivot);
    if (i<j){
      echanger(monTab,i,j);
    }
  }
  return(j);
}

void triFusion(int* monTab, int deb, int fin){
  int milieu;
  if(deb<fin){
    milieu= (deb+fin)/2;
    triFusion(monTab,deb,milieu);
    triFusion(monTab,milieu+1,fin);
    fusionner(monTab,deb,milieu,fin);
  }
}

void fusionner(int* monTab,int deb, int milieu,int fin){
  int max;
  int i=0;
  int gauche,droite;
  int* tabTemp;
  max= fin-deb;
  gauche=deb;
  droite= milieu +1;
  tabTemp = allouer((deb+fin)/2);
  while(gauche <= milieu && droite <= fin){
    if (monTab[gauche]< monTab[droite]){
      tabTemp[i]=monTab[gauche];
      gauche= gauche+1;
    }else{
      tabTemp[i]=monTab[droite];
      droite= droite+1;
    }
    i=i+1;
  }
  while (gauche <=milieu){
    tabTemp[i]=monTab[gauche];
    gauche = gauche +1;
    i=i+1;
  }
  while(droite <= fin){
    tabTemp[i]=monTab[droite];
    droite = droite +1;
    i=i+1;
  }
  for (int i=0; i<max+1; i++){
    monTab[i+deb]= tabTemp[i];
  }
  free(tabTemp);
}
/*
PROCEDURE triRapide ( tab : pointeur de tableau d entier, p : entier, r : entier)
VARIABLE :
    q : entier
DEBUT
    SI p < r FAIRE
        q <- partitionner(tab,p,r)
        triRapide(tab,p,q)
        triRapide(tab,q+1,r)
    FIN SI
FIN


FONCTION partitionner ( tab : pointeur de tableau d entier, p : entier, r : entier) : ent
VARIABLES :
    pivot, i,j : entier
DEBUT
    pivot<-tab[p]
    i<- p-1
    j<- r+1
    TANT QUE (i<j) FAIRE
        FAIRE
           j <- j-1
        TANT QUE (tab[j] > pivot)
        FAIRE
           i <- i-1
        TANT QUE (tab[i] < pivot)
        SI (i<j) ALORS
        echanger(tab,i,j);
        FIN SI
    FIN TANT QUE
    retourner (j)
FIN


PROCEDURE triFusion ( tab : pointeur de tableau d entier,
                        monDebut : entier, maFin : entier)
VARIABLE :
    milieu : entier
DEBUT
    SI monDebut< maFin
        milieu <-(monDebut+maFin)/2;
        triFusion(tab, monDebut, milieu);
        triFusion(tab, milieu+1, maFin);
        fusionner(tab,monDebut,milieu,maFin);
    FIN SI
FIN



PROCEDURE fusionner ( tab : pointeur de tableau d entier, monDebut : entier,
                        monMilieu : entier, maFin : entier)
VARIABLES :
    i,max : entier
    gauche,droite : entier
    tabTemp : pointeur de tableau d entier
DEBUT
 i<-0
 max<-maFin-monDebut
 gauche<-monDebut
 droite<- monMilieu+1
 allouer(tabTemp)
 TANT QUE gauche<=monMilieu ET droite <= maFin
   SI tab[gauche]<tab[droite]
       tabTemp[i]<-tab[gauche]
       gauche<-gauche+1
   SINON
       tabTemp[i]<-tab[droite]
       droite<-droite+1
   FIN SI
   i<-i+1
FIN TANT QUE
TANT QUE gauche <= monMilieu
   tabTemp[i]=tab[gauche];
   gauche<-gauche+1
   i<-i+1
FIN TANT QUE
TANT QUE droite <= maFin
   tabTemp[i]<-tab[droite]
   droite<-droite+1
   i<-i+1
FIN TANT QUE
POUR i allant de 0 à max+1 FAIRE
   tab[i+monDebut]<-tabTemp[i]
FIN POUR
liberer(tabTemp)
FIN
*/
