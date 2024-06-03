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

    
}