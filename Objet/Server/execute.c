/*
 * execute.c : client TCP qui envoie une commande a executer sur le serveur
 * puis attend le resultat sur le socket
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define LBUF 100

int main(int N, char*P[])
{
int sock, n;
struct sockaddr_in sin;
struct hostent *h;
char nom[LBUF], addr[LBUF];

    if (N != 4 ) {
        fprintf(stderr,"Utilisation : %s nom_serveur port commande\n",P[0]);
        exit(1);
    }
    /* initialisation socket */
    if ((sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0) {
        perror("socket");
        exit(2);
    }
    if(!(h=gethostbyname(P[1]))) {
        perror("gethostbyname");
        exit(3);
    }
    /* initialisation de sin */
    bzero(&sin,sizeof(sin));
    sin.sin_family = AF_INET;
    bcopy(h->h_addr,&sin.sin_addr,h->h_length);
    sin.sin_port = htons(atoi(P[2]));
    if (connect(sock,(struct sockaddr*)&sin,sizeof(sin)) < 0) {
        perror("connect");
        exit(4);
    }
    write(sock,P[3],strlen(P[3]));
    write(sock,"\n",1); /* ajout de nl */
    while ((n=read(sock,addr,LBUF)) > 0) write(1,addr,n);
    close(sock);
}


