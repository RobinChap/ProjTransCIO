/* message.h : elements communs au serveur et aux clients */

#define CLE 0xcafe

#define PIDS 1 /* pid fictif du serveur */

/* la liste des commandes autorisees */
#define ADD  'A'
#define SOUS 'S'
#define MULT 'M'
#define ERR  'E'

/* structure pour les messages clients -> serveur */
struct mess1 {
   long type;
   long pid; /* pid du client */
   char com; /* code de la commande */
   double v1;
   double v2;
};
   
/* structure pour les messages serveur -> clients */
struct mess2 {
   long type;
   char com; /* code de la commande ou erreur */
   double r; /* resultat de la commande */
};
   

