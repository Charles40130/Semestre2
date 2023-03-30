#include "soccer.h"
#include <stdlib.h>
#include <stdio.h>



void creationJoueur(Joueur* j){
  j->nom=malloc(100*sizeof(char));
  printf("NOM ? \n");
  scanf("%s",j->nom);

  j->prenom=malloc(100*sizeof(char));
  printf("PRENOM ? \n");
  scanf("%s",j->prenom);

  j->poste=malloc(100*sizeof(char));
  printf("POSTE ? \n");
  scanf("%s",j->poste);

  printf("NUMERO ? \n");
  scanf("%d",&j->numero);

  printf("AGE ? \n");
  scanf("%d",&j->age);

  printf("NOMBRE DE BUTS ? \n");
  scanf("%d",&j->nb_buts);

}



void afficherJoueur(Joueur j){
  printf("------JOUEUR-------- \n");
  printf("nom : %s \n",j.nom);
  printf("prenom : %s \n",j.prenom);
  printf("niveau : %s \n",j.poste);
  printf("numero : %d\n",j.numero);
  printf("age : %d \n",j.age);
  printf("nombre de but(s): %d \n",j.nb_buts);
}

void creationEquipe(Equipe* e){
  e->nom=malloc(100*sizeof(char));
  printf("NOM ? \n");
  scanf("%s",e->nom);

  e->pays=malloc(100*sizeof(char));
  printf("PAYS ? \n");
  scanf("%s",e->pays);

  e->championnat=malloc(100*sizeof(char));
  printf("CHAMPIONNAT ? \n");
  scanf("%s",e->championnat);

  printf("CLASSEMENT ? \n");
  scanf("%d",&e->classement);

  e->nb_Joueurs=0;
}


void ajouterJoueur(Equipe* e,Joueur j){
   int indexJ;
   indexJ=e->nb_Joueurs;
   if (indexJ==0){
     e->mesJoueurs=malloc(1*sizeof(Joueur));
     e->mesJoueurs[0]=j;
     e->nb_Joueurs=1;
   }else{
     e->mesJoueurs=realloc(e->mesJoueurs,indexJ+1);
     e->mesJoueurs[indexJ]=j;
     e->nb_Joueurs=indexJ+1;
   }
}

void afficherEquipe(Equipe e){
  printf("------EQUIPE-------- \n");
  printf("NOM : %s \n",e.nom);
  printf("PAYS : %s \n",e.pays);
  printf("CHAMPIONNAT : %s \n",e.championnat);
  printf("NOMBRE DE JOUEURS: %d \n",e.nb_Joueurs);

  for(int i =0; i<e.nb_Joueurs;i++){
    afficherJoueur(e.mesJoueurs[i]);
  }
}
