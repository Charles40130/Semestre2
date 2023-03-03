#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculerDelta (double a, double b, double c){
  return pow(b,2)-4*a*c;

}

void solutions(int* nbsolution, double* s1, double* s2,double a, double b, double c){
  switch (nbsolution){
    case 2:
      s1=;
      s2=;
      break;
    case 1:
      s1=-b;
      break;
    default:
      break;
  }
}


//Procédures qui permet de vider le tampon
void emptyBuffer() {
  char c;
  while (((c = getchar()) != '\n') && (c != EOF));
}



int main(){
  double monReel;
  double a,b,c;
  double delta;
  int* nbsolution;
  double* s1;
  double* s2;


  printf("entrez un réel \n");
  scanf("%lf",&a);
  emptyBuffer();
  printf("entrez un réel \n");
  scanf("%lf",&b);
  emptyBuffer();
  printf("entrez un réel \n");
  scanf("%lf",&c);
  emptyBuffer();
  delta = calculerDelta(a,b,c);
  printf("delta : %.3lf \n",delta);
  printf("%lf", nbsolution);
  solutions(nbsolution,s1,s2,a,b,c);
  if (delta>0){
    nbsolution=2;
  }else if (delta==0){
    nbsolution=1;
  }else{
    nbsolution=0;
  }
  printf("%lf",*s1);
  printf("%lf",*s2);


  /*scanf("%lf",&monReel);
  printf("Mon réel avec tous les chiffres après la virgule %lf \n",monReel);
  printf("Mon réel avec 2 chiffres après la virgule %.2lf \n",monReel);
  printf("Mon réel avec 3 chiffres après la virgule %.3lf \n",monReel);*/
  return 0;
}
