#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    int c;
    struct sockaddr_in server;
    
    c = socket(AF_INET, SOCK_STREAM, 0);
    if(c < 0) {
        printf("Eroare la crearea socketului client!\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_port = htons(8888);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Eroare la conectarea la server!\n");
        return 1;
    }

    char sir[100];
    printf("Sir: ");
    fgets(sir, sizeof(sir), stdin);
    sir[strlen(sir)-1] = '\0';

    int len = strlen(sir);
    len = htons(len);

    send(c, &len, sizeof(len), 0);
    send(c, &sir, ntohs(len)*sizeof(char), 0);

    int nr_spatii = 0;
    recv(c, &nr_spatii, sizeof(int), MSG_WAITALL);
    nr_spatii = ntohs(nr_spatii);

    printf("Numarul de spatii a sirului este %d\n", nr_spatii);

    close(c);
}