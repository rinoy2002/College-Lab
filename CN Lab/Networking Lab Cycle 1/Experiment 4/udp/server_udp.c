#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <limits.h>
#define PORT 8890
void main() {
 int server_fd, client_fd;
 int n;
 int buffer[10],size;
 float result[3];
 if((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
   printf("Socket creation failed!\n");
   exit(0);
 }else{
   printf("Socket created\n");
 }

 struct sockaddr_in address, cli_addr;
 address.sin_family = AF_INET;
 address.sin_addr.s_addr = INADDR_ANY;
 address.sin_port = htons(PORT);
 
 int addrlen = sizeof(address);
	
 if(bind(server_fd, (struct sockaddr*) &address, addrlen) < 0) {
    printf("Socket binding failed!\n");
    exit(0);
 }else{
    printf("Bind Sucessful\n");
 } 
	
 int len = sizeof(cli_addr);
 if(recvfrom(server_fd,&size, sizeof(int), 0, (struct sockaddr*) &cli_addr, &len) < 0) {
   printf("Receive failed!\n");
   exit(0);
 }else{
   printf("Array Size Received Sucessfully\n");
 }
 if(recvfrom(server_fd, buffer, 10*sizeof(int), 0, (struct sockaddr*) &cli_addr, &len) < 0) {
   printf("Receive failed!\n");
   exit(0);
 }else{
   printf("Array Received Sucessfully\n");
 }
	
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
 if(sendto(server_fd, result, 3*sizeof(float), 0, (struct sockaddr*) &cli_addr, len) < 0) {
   printf("Send failed!\n");
   exit(0);
 }else{
   printf("Result Send to Client\n");
 }
 close(server_fd);
 close(client_fd);
}
