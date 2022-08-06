#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8090
#define MAXCLIENT 5

int main()
{
    int sockfd, len;
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

    
    
    memset(&cliaddr, 0, sizeof(cliaddr));
    len = sizeof(cliaddr);
    int num;

    
    while(1)
    {
        int val = recvfrom(sockfd, &num, sizeof(int),0, (struct sockaddr *) &cliaddr,&len);
        if (val > 0)
        {
            printf("Message received from Client 1 %d\n", num);
            break;
        }
    }

    
    int square =num*num;
    int val = sendto(sockfd, &square, sizeof(int), 0, ( struct sockaddr *) &servaddr,sizeof(servaddr));
    if (val > 0)
    {
        printf("Message send to client %d\n", square);
    }
    close(sockfd);
}

