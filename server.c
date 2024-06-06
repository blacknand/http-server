#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>                                          // Definitions and data types in syscalls
#include <sys/socket.h>                                         // Defenitions of structs for sockets
#include <netinet/in.h>                                         // Consts and structs for internet domain access


void error(const char *msg) {
    perror(msg);
    exit(1);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "ERROR: No port provided\n");
        exit(1);
    }

    // sockfd and newsockfd are file descriptors
    // clilen is the size of the address of the client
    // n contains number of characters read or written for read() and write()
    int sockfd, newsockfd, portno, clilen, n = 0;
    char buffer[256];                                           // Read characters from socket connection
    struct sockaddr_in serv_addr, cli_addr;

    // Create a new socket using IPv4 and TCP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error encountered while opening socket\n");

    // Initalise serv_addr
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = atoi(argv[1]);

    // Setup info
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);                         // Convert to network byte order
    serv_addr.sin_addr.s_addr = INADDR_ANY;                     // Get IP address of machine on which the server is running

    // Bind socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Error encountered on binding\n");

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("Error encountered on accept\n");

    // Read from socket
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0)
        error("Error encountered while reading from socket\n");
    printf("Message from client: %s", buffer);

    n = write(newsockfd, "Server has successfully recieved message", 39);
    if (n < 0)
        error("Error encountered while writing to socket");

    return 0;
}