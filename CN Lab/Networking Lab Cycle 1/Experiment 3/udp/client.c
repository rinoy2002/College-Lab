#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
    
    
// Driver code 
int main() { 
    int sockfd; 
    char buffer[50],message[] = "Hello I am Client"; 

    struct sockaddr_in   server_addr; 
    
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        printf("Socket Creation Failed"); 
        exit(0); 
    } 
    
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(7071); 
    server_addr.sin_addr.s_addr = inet_addr("172.20.31.235"); 
        
    int n,len; 
   
    sendto(sockfd, (char *)message, strlen(message),0, (struct sockaddr *) &server_addr, sizeof(server_addr)); 
   
    n = recvfrom(sockfd, (char *)buffer,50, 0, (struct sockaddr *) &server_addr,&len); 
    buffer[n] = '\0'; 
    
    printf("Message from Server : %s\n", buffer); 
    
    close(sockfd); 
    return 0; 
}
