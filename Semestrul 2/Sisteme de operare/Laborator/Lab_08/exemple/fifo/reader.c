//
// Using named pipe (FIFO) - Read from a FIFO
//

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
	char buf[MAX_BUF];
    char* myfifo = "./myfifo";	// FIFO path

    // open the FIFO
    int fd = open(myfifo, O_RDONLY);
    if (fd == -1)
    {
        perror("open() error: ");
        exit(EXIT_FAILURE);
    }

    // read message from FIFO
    read(fd, buf, MAX_BUF);
    printf("Message: %s\n", buf);

    close(fd);
    return 0;
}