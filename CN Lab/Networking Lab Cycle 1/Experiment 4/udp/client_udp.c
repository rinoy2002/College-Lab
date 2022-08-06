#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8890

void main() {
 int client_fd;
 struct sockaddr_in serv_addr;
 int buffer[50],size;
 float reply[3];
 client_fd = socket(AF_INET, SOCK_DGRAM, 0);
 if(client_fd < 0) {
   printf("Socket creation failed!\n");
   exit(0);
 }else{
    printf("Socket created\n");
 }
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = INADDR_ANY;
 serv_addr.sin_port = htons(PORT);
 int len = sizeof(serv_addr);
 printf("Enter the Array Size :");
 scanf("%d",&size);
 printf("Enter the Elements :");
 for(int j=0;j<size;j++){
   scanf("%d",&buffer[j]);
 }
 if(sendto(client_fd,&size,sizeof(int), 0, (struct sockaddr*) &serv_addr,len) < 0) {
   printf("Send failed!\n");
   exit(0);
 }else{
   printf("Arrray Size Send Sucessfully\n");
 }
 if(sendto(client_fd, buffer, size*sizeof(int), 0, (struct sockaddr*) &serv_addr,len) < 0) {
   printf("Send failed!\n");
   exit(0);
 }else{
   printf("Arrray Send Sucessfully\n");
 } 
 
 if(recvfrom(client_fd, reply, 3 * sizeof(float), 0, (struct sockaddr*) &serv_addr, &len) < 0) {
  printf("Receive failed!\n");
  exit(0);
 } 
 printf("Result received:\n");
 printf("Avg: %.2f\n", reply[0]);
 printf("Min: %.2f\n", reply[1]);
 printf("Max: %.2f\n", reply[2]);
 close(client_fd);
}
