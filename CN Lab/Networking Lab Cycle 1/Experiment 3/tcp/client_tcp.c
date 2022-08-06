#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){

  int network_socket=socket(AF_INET,SOCK_STREAM,0);
  if(network_socket<0){
    printf("\nSocket Creation Error\n");
    exit(0);
  }

  struct sockaddr_in server_address;
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(7071);
  server_address.sin_addr.s_addr=INADDR_ANY ;

  int status=connect(network_socket,(struct sockaddr*)&server_address,sizeof(server_address));
  
  if(status<0){
     printf("Connection couldn't be established");
  }

  char server_response[50],message[]="Hello from Client";
  recv(network_socket,&server_response,sizeof(server_response),0);
  send(network_socket,&message,sizeof(message),0);
  printf(" The received message is : %s \n",server_response);
  
  close(network_socket);
  return 0;
}

