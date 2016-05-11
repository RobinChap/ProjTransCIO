/* exemple simple de recuperation des informations du CPU en allant
   consulter l'interface /proc/stat
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NomFic "/proc/stat"
#define NomFic2 "/proc/cpuinfo"

/* fonction qui accede a l'interface et qui calcule le pourcentage */
double cpuPcent(void)
{
FILE * fp;
char nom [10];
long v1, v2, v3, v4;
long vp1, vp2, vp3, vp4;
long d1, d2, d3, d4;
double res=0.;
   if ((fp = fopen(NomFic, "r")) == NULL) return (double)-1;
   fscanf(fp,"%s %ld %ld %ld %ld", nom, &v1, &v2, &v3, &v4);
   printf("%s %ld %ld %ld %ld\n",nom,v1,v2,v3,v4);
   /* on attend 1 sec */
   sleep(1);
   rewind(fp);
   if ((fp = fopen(NomFic, "r")) == NULL) return (double)-1;
   fscanf(fp,"%s %ld %ld %ld %ld", nom, &vp1, &vp2, &vp3, &vp4);
   printf("%s %ld %ld %ld %ld\n",nom,vp1,vp2,vp3,vp4);
   d1 = vp1 - v1;
   d2 = vp2 - v2;
   d3 = vp3 - v3;
   d4 = vp4 - v4;
   res = (double)((d1+d2+d3) * 100L) / (double)(d1+d2+d3+d4);
   return res;
}

#define LBUF 500
void liste(void)
{
FILE * fp;
char nom [100];
char nom2[200];
char reste[200];
char buf[LBUF], *b;
int n, s1,s2;
   if ((fp = fopen(NomFic2, "r")) == NULL) return;
   while (fgets(buf, LBUF, fp) != NULL) {
      n=strlen(buf);
      buf[n-1]='\0';
      s1 = sscanf(buf,"%s %s :", nom, nom2);
      b = strchr(buf,':');
      if (b==NULL) continue;
      s2 = sscanf(b+1," %s", reste);
      printf("Lu : <%s> s1=%d s2=%d nom=%s reste=%s\n", buf, s1, s2, nom, b+1);
   }
   fclose(fp);
}

int main(int N, char * P[])
{
double v;
    liste();
/*
    v = cpuPcent();
    printf("Le Pcentage CPU instantanne est %g\n", v);
*/
    return 0;
}


