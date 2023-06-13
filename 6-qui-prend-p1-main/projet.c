#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"


int main(){
    regles();
    int joueursR=0; //nb joueurs réels
    int joueursIA=0; //nb joueurs virtuels
    int nb_joueurs=0; //somme des joueurs réels et virtuels
    int nb_tour_restants=10; //tour avant de redistribuer les cartes
    cartes pile[104]; //les 104 cartes dans l'ordre
    cartes melange[104]; //les 104 cartes mélangés
    cartes cartes_joueurs[10][10]; //les cartes une fois qu'elles ont été distribué aux joueurs
    cartes plateau[4][6]; //les cartes appartenant au plateau de jeu
    cartes cartes_a_jouer[nb_joueurs]; // liste de cartes chosies par les joueurs

    joueurs(&joueursR,&joueursIA); //demande combien de joueurs vont jouer
    nb_joueurs=joueursR+joueursIA;
    cartes tour[nb_joueurs];

    creation_cartes(pile); //fonction qui crée les 104 cartes et donne les tête de taureaux correspondantes
    for (int i = 0; i < 104; i++) {
        melange[i] = pile[i];
    }
    shuffle(melange); //fonction qui mélange les 104 cartes
    distribuer_cartes(melange, nb_joueurs, cartes_joueurs); //fonction qui distribue les cartes en fonction du nombre de joueurs


    tour_de_jeu(nb_tour_restants,nb_joueurs,plateau,melange,cartes_joueurs,joueursR,joueursIA,cartes_a_jouer);

    return 0;
}
