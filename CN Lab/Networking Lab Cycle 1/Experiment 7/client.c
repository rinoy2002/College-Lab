#include<sys/socket.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include <string.h>
#include<pthread.h>
#define PORT 9090

void * recievedata(void* sockfd_arg){
    int* sockfd = (int*) sockfd_arg;
    char buffer[1024] = {'\0'};
     while(1){
        recv(*sockfd, buffer, 1024,0);
        if(strcmp(buffer,"STOP") == 0){
            pthread_exit(NULL);
        }
        printf("%s",buffer);
     }
}

int main(){
	pthread_t read_thread;
	
	int client_socket;
	char buffer[1024];
	
	struct sockaddr_in server_addr;
	
	client_socket= socket(AF_INET, SOCK_STREAM,0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);
	socklen_t addr_size = sizeof(server_addr);
	
	if(connect(client_socket, (struct sockaddr*)&server_addr, addr_size)!=0){
	    perror("connect falied");
	    exit(EXIT_FAILURE);
	}
	
	pthread_create(&read_thread,NULL, recievedata, (void*)&client_socket);
	
    while(1){
        scanf("%[^\n]%*c",buffer);
        int len = strlen(buffer);
        send(client_socket,buffer,len+1,0);
    }
	pthread_join(read_thread,NULL);
    return 0;
}
