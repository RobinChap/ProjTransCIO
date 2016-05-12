#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NomFic "/proc/net/netlink"
#define TailleMax 50

double RAMPcent(){
FILE * fp;
double result = 0;
int compteur = 0,i = 0;
double MemTotal = 1, MemFree = 1;
int valeur = -1;

char ligne[TailleMax];
char Nom[TailleMax];
char Unit[5];

if((fp = fopen(NomFic, "r")) == NULL) return (double)-1;




while(fgets(ligne, TailleMax, fp) != NULL){
  compteur ++;

   sscanf(ligne,"%s %d %s",Nom, &valeur, Unit);
    printf("%s %d %s\n", Nom, valeur, Unit);

    if(compteur == 1)
    {
        MemTotal = valeur;
    }
    if(compteur == 2){
        MemFree = valeur;
    }
}
result = 100 - (MemFree/MemTotal)*100;
return result;
}


int main(int N, char * P[])
{
double v;
int continuer = 1;
    while(continuer){
         sleep(1);
    v = RAMPcent();

    continuer = 0;
    }
    return 0;
}

