#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000


int main() {
  FILE* mesFringues = NULL; char ligne[N];
  FILE* mesFringues2=NULL;
  int nbLignesLues = 0; int nbColonnesLues = 0;
  char* laLigne;
  int temp=0;
  laLigne=malloc(sizeof(char)*N);

  mesFringues = fopen("mesFringues.csv", "r");
  mesFringues2 =fopen("mesFringues2.json" ,"w");


  if (mesFringues == NULL || mesFringues2 == NULL) {
    printf("Erreur ouverture fichier \n");
  }else{
    fprintf(mesFringues2,"[ \n");
    while(fgets(ligne,N,mesFringues) !=NULL){
      laLigne= strtok(ligne,";");
      fprintf(mesFringues2,"{ \n");
        while (laLigne != NULL){
          switch(temp){
            case 0 :
              fprintf(mesFringues2,"'id' : '%s',  \n",laLigne );
            break;
            case 1 :
            fprintf(mesFringues2,"'appelation': '%s', \n",laLigne);
            break;
            case 2:
            fprintf(mesFringues2,"'taille': '%s',\n",laLigne);
            break;
            case 3:
            fprintf(mesFringues2,"'prix' : '%s', \n",laLigne);
            break;
          }
            temp++;
            laLigne = strtok(NULL, ";");
            nbColonnesLues++;
        }
        fprintf(mesFringues2,"}, \n");
        temp = 0;
          nbColonnesLues=0;
          nbLignesLues++;
      }
      fprintf(mesFringues2,"] \n");
    fclose(mesFringues);
    fclose(mesFringues2);
  }
  return 0;
}
