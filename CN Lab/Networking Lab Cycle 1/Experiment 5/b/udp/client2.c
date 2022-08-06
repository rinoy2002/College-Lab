#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8000


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
    
    int num=0;
    int len=sizeof(servaddr);
    
    while(1)
    {
        int length = recvfrom(sockfd, &num, sizeof(int),0, (struct sockaddr *) &servaddr,&len);
        if (length > 0)
        {
            printf("Message received from Server %d\n", num);
            break;
        }
    }
    close(sockfd);
}
