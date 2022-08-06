#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>

int main(){

  int network_socket=socket(AF_INET,SOCK_STREAM,0);
  if(network_socket<0){
    printf("\nSocket Creation Error\n");
    exit(0);
  }

  struct sockaddr_in server_address;
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(8888);
  server_address.sin_addr.s_addr=INADDR_ANY; 

  int status=connect(network_socket,(struct sockaddr*)&server_address,sizeof(server_address));
  
  if(status<0){
     printf("Connection couldn't be established");
  }

  char server_response[50];
  read(network_socket,&server_response,sizeof(server_response));
  printf(" The received message is : %s \n",server_response);
  return 0;
}

