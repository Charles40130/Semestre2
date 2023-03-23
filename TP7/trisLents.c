#include "trisLents.h"
#include <stdio.h>
/* toutes mes signatures/prototypes de fonctions/méthodes + leur corps */


void triBulles(int* p_tab,int taille){
    int enDesordre;
    enDesordre=1;
    while (enDesordre){
        enDesordre=0;
        for(int j=0 ; j<taille-1;j++){
            if (p_tab[j] > p_tab[j+1]){
                echanger(p_tab,j,j+1);
                /*printf("Etape: \n");
                afficher(p_tab,taille);*/
                enDesordre=1;
            }
        }
    }
}

void triSelection(int* p_tab,int taille){
    int min;
    for(int i=0 ; i<taille-1;i++){
        min=i;
        for (int j=i+1; j<taille ; j++){
            if (p_tab[j] < p_tab[min]){
                min =j;
            }
            
        }
        echanger(p_tab,i,min );
        /*printf("Etape: \n");
        afficher(p_tab,taille);*/
    }
}

void triInsertion(int* p_tab,int taille){
    int j;
    int eltEnCours;
    for(int i=0 ; i<taille-1;i++){
        eltEnCours=p_tab[i];
        for (j=i; 0<j && p_tab[j-1]>eltEnCours; j--){
            p_tab[j]= p_tab[j-1];    
        }
        p_tab[j]=eltEnCours;
        printf("Etape: \n");
        afficher(p_tab,taille);
    }
}