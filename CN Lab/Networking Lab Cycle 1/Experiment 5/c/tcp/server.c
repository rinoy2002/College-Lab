#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 9000
#define MAXCLIENT 5

int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cliaddr;
    pid_t childpid;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Socket creation failed\n");
        exit(0);
    }
    else
    {
        printf("Socket created\n");
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Socket binding failed\n");
        exit(0);
    }
    else
    {
        printf("Socket binded\n");
    }

    if (listen(sockfd, MAXCLIENT) < 0)
    {
        printf("Listen failed\n");
        exit(0);
    }
    else
    {
        printf("Listening on port %d\n", PORT);
    }
    
    memset(&cliaddr, 0, sizeof(cliaddr));
    len = sizeof(cliaddr);
    float num;

    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd > 0)
    {
        printf("Connection established with Client 1\n");
    }
    else
    {
        printf("Connection establishment failed\n");
        exit(0);
    }
    
    while(1)
    {
        int val = read(connfd, &num, sizeof(float));
        if (val > 0)
        {
            printf("Message received from Client 1 %f\n", num);
            break;
        }
    }

    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd > 0)
    {
        printf("Connection established with Client 2\n");
    }

    float power =pow(num,1.5);
    int val = send(connfd, &power, sizeof(float), 0);
    if (val > 0)
    {
        printf("Message send to client %f\n", power);
    }
    close(sockfd);
}

