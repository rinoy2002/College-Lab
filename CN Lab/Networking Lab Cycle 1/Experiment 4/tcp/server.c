#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <limits.h>

#define PORT 8080

int main(){
    int server_fd, client_socket, valread;
    struct sockaddr_in address;
    int opt =1;
    int addrlen = sizeof(address);
    int rec_buffer[100] = { 0 };
    int send_buffer[3] = { 0 };

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(server_fd <= 0 ){
        perror("\nsocket creation failed\n");
        exit(1);
    }
    printf("Socket Created...\n");

    if(setsockopt(server_fd, SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT, &opt, sizeof(opt))){
        perror("\nCant modify socket options.\n");
        exit(1);
    }

    //set the ip address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr*)&address, sizeof(address))<0){
        perror("\nBind failed\n");
        exit(1);
    }
    
    printf("Listening for connection......\n");
    if(listen(server_fd, 3)>0){
        perror("Listen error");
        exit(1);
    }


   client_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen); //accept new connection

   if(client_socket < 0 ){
        perror("\n accept failed\n");
        exit(1);
   }

   printf("Connection received\n");

   valread = read(client_socket,rec_buffer,100*sizeof(int));

   /*int temp,len=0;
   while((valread = recv(client_socket, &temp, sizeof(int),0) ) > 0 ){
        rec_buffer[len] = temp;
        printf("%d",valread);
        len++;
   }*/

   int len = valread/(sizeof(int)); 
   //printf("%d\n",len);
   int sum = 0;
   int max = INT_MIN;
   int min = INT_MAX;
   for(int i=0; i< len; i++){
        sum += rec_buffer[i];
        if(rec_buffer[i] < min ) min = rec_buffer[i];
        if(rec_buffer[i] > max ) max = rec_buffer[i];
   }
   send_buffer[0] = sum / len;
   send_buffer[1] = min;
   send_buffer[2] = max;

   send(client_socket,send_buffer, 3*sizeof(int),0);
   printf("Sending data....\n");
   printf("Connection Closed...\n");


   return 0;
}
