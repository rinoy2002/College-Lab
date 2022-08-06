#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <unistd.h>

#define PORT 9000
int main(){
  int valread,size;
  int send_buffer[50];
  float read_buffer[3];
  int network_socket=socket(AF_INET,SOCK_STREAM,0);
  if(network_socket<0){
    printf("Socket Creation Error\n");
  }
  else{
    printf("Socket created....\n");
  }

  struct sockaddr_in server_address;
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(PORT);
  server_address.sin_addr.s_addr=INADDR_ANY; 

  int status = connect(network_socket,(struct sockaddr*)&server_address,sizeof(server_address));
  
  if(status<0){
     printf("Connection couldn't be established\n");
  }else{
     printf("Connection established....\n");
  }
  printf("Enter the Array Size :");
  scanf("%d",&size);
  printf("Enter the Elements :");
  for(int j=0;j<size;j++){
    scanf("%d",&send_buffer[j]);
  }
  send(network_socket, &size, sizeof(int),0);
  printf("Sending Array Size to Server....\n");
  send(network_socket, send_buffer, size*sizeof(int),0);
  printf("Sending Array to Server....\n");
  
  valread = read(network_socket, read_buffer,3*sizeof(float));
  printf("Reading Data from Server......\n");
  printf("Average = %.2f\nMin = %.2f\nMax = %.2f\n",read_buffer[0], read_buffer[1],read_buffer[2]);
  close(network_socket);
  return 0;
}

