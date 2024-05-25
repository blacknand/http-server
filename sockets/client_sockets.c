#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char* argv[]) {
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* message = "Hello from the client";
    char buffer[1024] = {0};
    
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address\n");
        return -1;
    }

    if ((status = connect(client_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr))) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    // Close socket connection
    send(client_fd, message, strlen(message), 0);
    printf("Message sent\n");
    valread = read(client_fd, buffer, 1024 - 1);
    printf("%s\n", buffer);
    close(client_fd);
    return 0;
}