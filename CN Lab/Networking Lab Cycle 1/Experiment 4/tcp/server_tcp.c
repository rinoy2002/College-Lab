#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <limits.h>
#include<arpa/inet.h>
#include <unistd.h>

#define PORT 9000

int main(){
  int buffer[50],size;
  float result[3]={-1};

  int server_socket=socket(AF_INET,SOCK_STREAM,0);
  if(server_socket <= 0 ){
        printf("\nSocket Creation Failed\n");
        exit(0);
  }
  else{
        printf("Socket created....\n");
  }

  
  struct sockaddr_in server_address;
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(PORT);
  server_address.sin_addr.s_addr=INADDR_ANY;  

 
  if(bind(server_socket,(struct sockaddr*) &server_address, sizeof(server_address))<0){
    printf("\nBind Failed\n");
    exit(0);
  }
  else{
    printf("Socket binded....\n");
  }
  
  printf("Listening for Connection......\n");
  if(listen(server_socket,5)<0){
     printf("Listen Error");
     exit(1);
  }
  else{
    printf("Listening on port %d....\n", PORT);
  }
  
 
  int server_addrlen=sizeof(server_address);
  int client_socket= accept(server_socket ,(struct sockaddr*)&server_address, (socklen_t*)&server_addrlen);
  if(client_socket < 0 ){
      printf("\n Accept Failed\n");
      exit(1);
  }
  printf("Accepted the Connection......\n");
  int valread = read(client_socket,&size,sizeof(int));
  printf("Reading Array Size from Client......\n");
  valread = read(client_socket,buffer,size*sizeof(int));
  printf("Reading Array  from Client......\n");
  printf("Performing Required Operations......\n");
  int sum = 0;
  int max = INT_MIN;
  int min = INT_MAX;
   for(int i=0; i< size; i++){
        sum += buffer[i];
        if(buffer[i] < min ){
           min = buffer[i];
        }
        if(buffer[i] > max ){ 
           max = buffer[i];
        }
   }
   result[0] = (float)sum/size;
   result[1] = min;
   result[2] = max;
   send(client_socket,result, 3*sizeof(float),0);
   printf("Sending data back to Client....\n");
   printf("Connection Closed...\n");
   close(server_socket);
   close(client_socket);
  return 0;
  
}


