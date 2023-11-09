#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    int s;
    struct sockaddr_in server, client;
    
    s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0) {
        printf("Eroare la crearea socketului server!\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_port = htons(8888);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;

    if(bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Eroare la bind!\n");
        return 1;
    }

    listen(s, 5);

    int l = sizeof(client);
    memset(&client, 0, l);

    while(1) {
        
        int c = accept(s, (struct sockaddr *) &client, &l);
        printf("S-a conectat un client!\n");

        int len;
        recv(c, &len, sizeof(int), MSG_WAITALL);
        char sir[ntohs(len)];
        recv(c, sir, ntohs(len)*sizeof(char), MSG_WAITALL);

        int nr = 0;
        for(int i = 0; i <= ntohs(len); i++) {
            if(sir[i] == ' ')
                nr++;
        }

        nr = htons(nr);
        send(c, &nr, sizeof(int), 0);

    }



}