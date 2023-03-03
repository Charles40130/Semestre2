#include <stdlib.h>
#include <stdio.h>

/* Auteur : Mendiburu Charles */
/* Date :  2/03/2023 */
/* Résumé :  Fonction qui calcule la somme des chiffres d'un nombre */
/* Entrée(s) :  nb, acc */
/* Sortie(s) :  somme */
int sommeTer(int nb,int acc);

int main(){
  int nb;
  int somme;
  nb=2195;
  int acc =0;
    somme= sommeTer(nb,acc);
    printf("Somme de nb est : %d \n",somme);
    return 0;
}

int sommeTer(int nb,int acc){
  if (nb /10 == 0){
    acc= acc + nb%10;
    return acc;
  }else{
    return sommeTer(nb/10,acc+ nb %10);
  }
}
