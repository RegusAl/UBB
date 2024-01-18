#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define TCP_IP "127.0.0.1"
#define TCP_PORT 8888

void main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Eroare la crearea socketului client\n");
        return 1;
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(TCP_PORT);
    inet_pton(AF_INET, TCP_IP, &(server_address.sin_addr));

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    char nr[100];

    printf("Numar: ");
    fgets(nr, sizeof(nr), stdin);
    nr[strcspn(nr, "\n")] = '\0';  // Remove the newline character

    while (strcmp(nr, "0") != 0) {
        printf("%s\n", nr);
        send(client_socket, nr, strlen(nr), 0);

        char received_data[100];
        recv(client_socket, received_data, sizeof(received_data), 0);
        uint16_t numar_echilibrat = atoi(received_data);
        numar_echilibrat = ntohs(numar_echilibrat);
        printf("Numarul echilibrat: %d\n", numar_echilibrat);

        printf("Numar: ");
        fgets(nr, sizeof(nr), stdin);
        nr[strcspn(nr, "\n")] = '\0';  // Remove the newline character
    }

    send(client_socket, nr, strlen(nr), 0);

    close(client_socket);
}
