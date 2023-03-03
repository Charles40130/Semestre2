#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

/* Auteur : Mendiburu Charles */
/* Date :  2/03/2023 */
/* Résumé : Fonction récursive qui indique si un mot simple est un palindrome.  */
/* Entrée(s) :  chaine monMot[MAX], entier debut, entier fin */
/* Sortie(s) :  booléen */
int estPalindromeMot(char monMot[MAX],int deb,int fin);

/* Auteur : Mendiburu Charles */
/* Date :  ... */
/* Résumé :  Fonction récursive qui indique si une phrase est un palindrome. */
/* Entrée(s) :  chaine phrase, entier début , entier fin */
/* Sortie(s) :  booléen */
int estPalindromePhrase(char monMot[MAX],int deb,int fin);


void emptyBuffer(){
  char c;
  while (((c = getchar()) != '\n') && (c != EOF));
}

int main(){

  char monMot[MAX];
  char maPhrase[MAX];
  int bool;
  int bool2;
  printf("Entrer votre mot ! \n");
  scanf("%s",monMot);
  bool =estPalindromeMot(monMot,0,strlen(monMot)-1);
  if (bool){
    printf("C'est un palindrome \n");
  } else{
    printf("Ce n'est pas un palindrome \n");
  }

  emptyBuffer();


  printf("Entrez la phrase : \n");
  fgets(maPhrase,sizeof(char)*100,stdin);
  bool2 =estPalindromePhrase(maPhrase,0,strlen(maPhrase)-2);
  if (bool2){
    printf("C'est un palindrome \n");
  } else{
    printf("Ce n'est pas un palindrome \n");
  }

    return 0;
}



int estPalindromeMot(char monMot[MAX], int deb,int fin){
  if (fin<deb){
    return 1;
  }else if(monMot[deb]!=monMot[fin]){
    return 0;
  }else{
    return estPalindromeMot(monMot,deb+1,fin-1);
  }
}

int estPalindromePhrase(char monMot[MAX],int deb,int fin){
  if (fin<deb){
    return 1;
  }
  if(monMot[deb]==' '){
    estPalindromePhrase(monMot,deb+1,fin);
  }
  else if(monMot[fin]==' '){
    estPalindromePhrase(monMot,deb ,fin-1);
  }
  if(monMot[deb]!=monMot[fin]) {
    return 0;
  }else{
    return estPalindromePhrase(monMot,deb+1,fin-1);
  }
}
