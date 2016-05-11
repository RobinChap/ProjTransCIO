/* exemple d'un lient de message base sur les outils IPC */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#include "message.h"

#define LBUF 512
char buf[LBUF];  /* buffer de reception du resultat */

/* parametres passes au client :
P[1] = code de la commande A,S ou M
P[2] = valeur 1
P[3] = valeur 2
*********************************/

int main(int N, char *P[])
{
int qid;
long MonType;
struct mess1 M1;
struct mess2 *M2;
   if (N != 4) {
       fprintf(stderr,"Utilisation : %s commande valeur1 valeur2\n", P[0]);
       return 1;
   }
   /* recuperation de l'id de la message queue */
   if ((qid = msgget(CLE, 0)) == -1) {
      perror("msgget"); return 2;
   }
   M2 = (struct mess2*)buf;
   /* preparation du message au serveur */
   M1.type = (long)PIDS;
   MonType = (long)getpid();
   M1.pid = MonType;
   /* il n'y a pas de control sur la structure des parametres afin de pouvoir
      tester la capacite du serveur a gerer les erreurs !! */
   M1.com = P[1][0];
   M1.v1 = atof(P[2]);
   M1.v2 = atof(P[3]);
   /* envoi la demande au serveur */
   if (msgsnd(qid,(void*)&M1, (size_t)sizeof(M1), 0) == -1)
         perror("msgsnd");
   /* attend la réponse du serveur */
   if (msgrcv(qid, (void*)buf, (size_t)LBUF, MonType, 0)==-1) 
         perror("msgrcv");
   else { /* lecture de la reponse */
     if (M2->com == ERR) printf("Erreur dans la commande !\n");
     else printf("Resultat = %g\n", M2->r);
   }
   printf("Fin du client"); 
}


