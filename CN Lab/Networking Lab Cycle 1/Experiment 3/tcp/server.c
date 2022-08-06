#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(){
  char message[]="TCP Connection";
  int server_socket=socket(AF_INET,SOCK_STREAM,0);
  if(server_socket <0 ){
        printf("\nSocket Creation Failed\n");
        exit(1);
  }
 
  struct sockaddr_in server_address;
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(888);
  server_address.sin_addr.s_addr=INADDR_ANY;

 
  if(bind(server_socket,(struct sockaddr*) &server_address, sizeof(server_address))<0){
    printf("\n Binding Error\n");
  }

  printf("Listening for Connection......\n");
  if(listen(server_socket,5)<0){
     printf("Listen Error");
     exit(1);
  }
  
  int server_addrlen=sizeof(server_address);
  int client_socket= accept(server_socket ,(struct sockaddr*)&server_address,(socklen_t*)&server_addrlen);
  if(client_socket < 0 ){
      printf("\n Accept Failed\n");
      exit(1);
  }
  printf("Accepted the Connection......\n");
  
  send(client_socket,message,sizeof(message),0);
  printf("Connection Closed...\n");
  return 0;
  
}


