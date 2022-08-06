#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include<string.h>    
     
int main() { 
    int socket_fd; 
    char buffer[50]; 
    char message[]= "Hello Rinoy"; 
    struct sockaddr_in server_addr, client_addr; 
        
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (socket_fd< 0 ) { 
        printf("\nSocket Creation Failed"); 
        exit(0); 
    } 
        
         
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(8899); 
         
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 ){ 
        printf("\nBind Failed"); 
        exit(0); 
    } 
        
    int n; 
    
    int client_addrlen = sizeof(client_addr);
    
    n = recvfrom(socket_fd, (char *)buffer,50,0, ( struct sockaddr *) &client_addr,&client_addrlen); 
    buffer[n] = '\0'; 
    printf("Message from Client : %s\n", buffer); 
    sendto(socket_fd, (char *)message, strlen(message),0, (struct sockaddr *) &client_addr,client_addrlen);       
    return 0; 
}

