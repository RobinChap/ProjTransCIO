/* exemple d'un serveur de message base sur les outils IPC */
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "message.h"
/* a decommenter pour avoir la trace des demandes 
#define TRACE
*/

int RUN=1;
#define LBUF 512
char buf[LBUF];  /* buffer de lecture */

void interrupt(int S)
{
   switch(S) {
   case SIGINT :
   case SIGTERM :
       RUN=0; /* arret du serveur */
       break;
   default :
       fprintf(stderr,"Recu le signal no %d !?\n", S);
   }
   return;
}

int main(int N, char *P[])
{
int qid;
struct mess1 *M1;
struct mess2 M2;
   signal(SIGINT,interrupt);
   signal(SIGTERM,interrupt);
   /* creation de la message queue */
   if ((qid = msgget(CLE, IPC_CREAT | IPC_EXCL | 0666)) == -1) {
      perror("msgget"); return 1;
   }
   M1 = (struct mess1*)buf;
   /* traitement des messages */
   while (RUN) {
      if (msgrcv(qid, (void*)buf, (size_t)LBUF, (long)PIDS, 0)==-1) {
         perror("msgrcv");
         continue;
      }
      if (M1->pid<2) continue;
      M2.type=M1->pid; /* retour avec le pid du client */
#ifdef TRACE
      printf("Recu com=%c, v1=%g, v2=%g\n",M1->com,M1->v1, M1->v2);
#endif
      M2.com = M1->com;
      /* traitement du message */
      switch(M1->com) {
        case ADD :
          M2.r = M1->v1 + M1->v2;
          break;
        case SOUS :
          M2.r = M1->v1 - M1->v2;
          break;
        case MULT :
          M2.r = M1->v1 * M1->v2;
          break;
        default : /* commande inconnue */
          M2.com = ERR;
      }
      if (msgsnd(qid,(void*)&M2, (size_t)sizeof(M2), 0) == -1)
         perror("msgsnd");
   }
   /* destruction de la queue */
   msgctl(qid, IPC_RMID, NULL);
   printf("Arret du serveur"); 
}


