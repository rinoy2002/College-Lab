#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  char message[]="Hello From Server",client_response[50];
  int server_socket=socket(AF_INET,SOCK_STREAM,0);
  if(server_socket <0 ){
        printf("\nSocket Creation Failed\n");
        exit(0);
  }
 
  struct sockaddr_in server_address;
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(7001);
  server_address.sin_addr.s_addr=INADDR_ANY/*inet_addr("172.20.31.235")*/;

 
  if(bind(server_socket,(struct sockaddr*) &server_address, sizeof(server_address))<0){
    printf("\n Binding Error\n");
    exit(0);
  }

  printf("Listening for Connection......\n");
  if(listen(server_socket,5)<0){
     printf("Listen Error");
     exit(0);
  }
  
  int server_addrlen=sizeof(server_address);
  
  int client_socket= accept(server_socket ,(struct sockaddr*)&server_address,(socklen_t*)&server_addrlen);
  if(client_socket < 0 ){
      printf("\n Accept Failed\n");
      exit(0);
  }
  printf("Accepted the Connection......\n");
  
  send(client_socket,message,sizeof(message),0);
  read(client_socket,&client_response,sizeof(client_response));
  printf(" The received message is : %s \n",client_response);
  printf("Connection Closed...\n");
  
  close(server_socket);
  close(client_socket);
  return 0;
}


