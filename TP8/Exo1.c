#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    char maChaine1[10];
    char newchaine[10];

    printf("Entrer une chaîne de caractère : \n");
    scanf("%s",maChaine1);
    printf("L'utilisateur a rentré la chaine suivante : %s \n",maChaine1);

    strcpy(newchaine,maChaine1);
    printf("%s \n",newchaine);
    return 0;
}
