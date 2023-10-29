//Un client TCP transmite unui server un sir de caractere. 
//Serverul va returna clientului acest sir oglindit (caracterele sirului in ordine inversa). 
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

void deservire_client(int c) {
	// deservirea clientului
  char sir[10],sirI[10];	
  int i;
    recv(c, &sir, sizeof(sir), MSG_WAITALL);
    for(i=0;i<strlen(sir);i++)
      sirI[i]=sir[strlen(sir)-1-i];
    sirI[strlen(sir)]=sir[strlen(sir)];

    send(c, &sirI, sizeof(sirI), 0);
    close(c);
    // sfarsitul deservirii clientului;
}

int main() {
  int s;
  struct sockaddr_in server, client;
  int c, l;
  
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    printf("Eroare la crearea socketului server\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(server));
  server.sin_port = htons(1234);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  
  if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Eroare la bind\n");
    return 1;
  }

  listen(s, 5);
  
  l = sizeof(client);
  memset(&client, 0, sizeof(client));
  
  while (1) {
    uint16_t a, b, suma;
    c = accept(s, (struct sockaddr *) &client, &l);
    printf("S-a conectat un client.\n");
	
	 if (fork() == 0) { // fiu
      deservire_client(c);
      return 0;
    }
    
  }
}

