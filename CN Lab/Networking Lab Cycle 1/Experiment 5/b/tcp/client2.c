#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8000
#define MAXCLI 5

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        printf("Socket creation failed\n");
        exit(0);
    }
    else{
        printf("Socket created\n");
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        printf("Connection establishment failed\n");
        exit(0);
    }
    else{
        printf("Connection established\n");
    }

    int num=0;

    while(1)
    {
        int length = read(sockfd, &num, sizeof(int));
        if (length > 0)
        {
            printf("Message received from Server %d\n", num);
            break;
        }
    }
    close(sockfd);
}
