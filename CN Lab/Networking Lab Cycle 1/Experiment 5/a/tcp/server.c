#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 9090
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
    char buf[100], rev_buf[100];

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
        int val = read(connfd, buf, sizeof(buf));
        if (val > 0)
        {
            printf("Message received from client 1 %s\n", buf);
            break;
        }
    }
    int j = 0;
    for (int i = strlen(buf) - 1; i >= 0; i--)
    {
        rev_buf[j] = buf[i];
        j++;
    }
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd > 0)
    {
        printf("Connection established with Client 2\n");
    }
    int val = send(connfd, rev_buf, sizeof(rev_buf), 0);
    if (val > 0)
    {
        printf("Message send to client %s\n", rev_buf);
    }
    close(sockfd);
}

