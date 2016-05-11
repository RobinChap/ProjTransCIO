/*
 * servcom.c : exemple de serveur socket mode connecte
 * attend une commande a executer et envoie le resultat sur le socket
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

struct sockaddr_in Sin = {AF_INET}; /* le reste est nul */

int readlig(int fd, char *b, int max)
{
int n;
char c;
    for (n=0; n<max; n++) {
        if(read(fd, &c, 1) <= 0) break;
        if (c == '\n') break;
        *b++ = c;
    }
    *b = '\0';
    return(n);
}

#define LBUF 100
void service(int sid)
{
int n, i;
char buf[LBUF];
    n = readlig(sid,buf,LBUF);
    if (n < 0) {
       perror("readlig");
       return;
    }
    write(sid,buf,strlen(buf));
    write(sid,"\nCette commande n'a pas ete trouvee !!\n", 40);
    close(sid);
}

int main(int N, char *P[])
{
int ln, sock, nsock;
    /* creation du socket */
    if((sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0) {
        perror("socket");
        exit(1);
    }
    /* ATTACHEMENT AU PORT */
    if(bind(sock,(struct sockaddr*)&Sin, sizeof(Sin)) < 0) {
        perror("bind");
        exit(2);
    }
    ln = sizeof(Sin);
    if (getsockname(sock,(struct sockaddr*)&Sin,(socklen_t*)&ln) < 0) {
        perror("getsockname");
        exit(3);
    }
    printf("Le serveur est attache au port %u\n",ntohs(Sin.sin_port));
    /* definition du nb d'appels simultanes */
    if (listen(sock,5) < 0) {
        perror("listen");
        exit(4);
    }
    /* boucle d'attente */
    for (;;) {
        if((nsock=accept(sock,(struct sockaddr*)&Sin,(socklen_t*)&ln))<0) {
            perror("accept");
            exit(5);
        }
        service(nsock);
    }
}




