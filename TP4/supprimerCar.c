#include <stdlib.h>
#include <stdio.h>
#define MAX 100

/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
void supprCar(char maPhraseInitiale[MAX],char car,int i,int j, char maPhraseModifiee[MAX]);

void emptyBuffer(){
  char c;
  while (((c = getchar()) != '\n') && (c != EOF));
}

int main(){
  char maPhrase[MAX];
  char maPhraseModifiee[MAX];
  char car;
  printf("Entrez la phrase : \n");
  fgets(maPhrase,sizeof(char)*100,stdin);
  emptyBuffer();
  printf("Entrez le caractère à supprimer dans le phrase \n");
  scanf("%c",car);
  supprCar(maPhraseInitiale,car,i,j,maPhraseModifiee);
  return 0;
}


void supprCar(char maPhraseInitiale[MAX],char car,int i,int j, char maPhraseModifiee[MAX]){
  for(i,i++,i>)
}
