#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 9092

void send_pid(){
    int sockfd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    if(connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address))<0){
        printf("Connection failed\n");
        exit(0);
    }

    int msg[2];
    msg[0] = getpid();
    msg[1] = -1;

    send(sockfd, msg,sizeof(msg),0);
    printf("PID : %d\n",msg[0]);
    close(sockfd);
}


void take_chopstick()
{

    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        printf("Error in creating connection");
    }

    int message[2];
    message[0] = getpid();
    message[1] = 1;
    send(sockfd, message, sizeof(message), 0);
    close(sockfd);
}

void put_chopstick()
{

    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address))<0)
    {
        printf("Error in creating connection");
    }

    int message[2];
    message[0] = getpid();
    message[1] = 0;
    send(sockfd, message, sizeof(message), 0);
    close(sockfd);
}


int main(){
    if(fork()!=0){
        fork();
        fork();
    }

    send_pid();
    sleep(rand()%5 +1);
    take_chopstick();     
    sleep(rand()%5 +1);
    put_chopstick();
    sleep(rand()%5 +1);
    take_chopstick();
    sleep(rand()%5 +1);

    return 0;
}
