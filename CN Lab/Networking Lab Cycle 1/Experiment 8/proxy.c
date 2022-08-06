#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define PPORT 9990

void main(int argc, char *argv[]) {
	struct sockaddr_in address, serv_addr;
	int server_fd, client_fd,client_fd1, addrlen = sizeof(address),WPORT;
	char* buff = malloc(6*sizeof(char));
	char* body = malloc(100*sizeof(char));
	
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PPORT);
	
	if(bind(server_fd, (struct sockaddr*) &address, addrlen) < 0) {
		printf("Binding failed!\n");
		exit(1);
	}
    while(1) {
		if(listen(server_fd, 5) < 0) {
			printf("Listening failed!\n");
			exit(1);
		} else {
			printf("Proxy server is running and listening for requests...\n");
		}
		if((client_fd = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
			printf("Accept failed!\n");
			exit(1);
		}
		
		if(recv(client_fd, &WPORT, sizeof(int), 0) < 0) {
			printf("Receive failed!\n");
			exit(1);
		} else {
			if(recv(client_fd, buff, 6 * sizeof(char), 0) < 0) {
				printf("Receive failed!\n");
				exit(1);
			}else{
				printf("Request received: %d %s\n", WPORT, buff);
				if(!strcmp(buff, "POST") || !strcmp(buff, "PUT") || !strcmp(buff, "PATCH")) {
					if(recv(client_fd, body, 100 * sizeof(char), 0) < 0) {
						printf("Receive failed!\n");
						exit(1);
					}
				}
				
				serv_addr.sin_family = AF_INET;
				serv_addr.sin_addr.s_addr = INADDR_ANY;
				serv_addr.sin_port = htons(WPORT);
				  
				if((client_fd1 = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
					printf("Socket creation failed!\n");
					exit(1);
				}
				
				if(connect(client_fd1, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
					printf("Connection failed!\n");
					close(client_fd1);
					if(send(client_fd, "SERVER NOT FOUND\n", 20 * sizeof(char), 0) < 0) {
						printf("Sending failed!\n");
						exit(1);
					}
					continue;
				}
				
				if(send(client_fd1, buff, 6 * sizeof(char), 0) < 0) {
					printf("Sending failed!\n");
					exit(1);
				} else {
					if(!strcmp(buff, "POST") || !strcmp(buff, "PUT") || !strcmp(buff, "PATCH")) {
						
						if(send(client_fd1, body, 100 * sizeof(char), 0) < 0) {
							printf("Sending failed!\n");
							exit(1);
						}
					}
					
					printf("Request sent to server %d: %s\n", WPORT, buff);
					
					if(recv(client_fd1, body, 100 * sizeof(char), 0) < 0) {
						printf("Receive failed!");
						exit(1);
					} else {
						if(send(client_fd, body, 100 * sizeof(char), 0) < 0) {
							printf("Sending failed!\n");
							exit(1);
						}
					}
				}
				
				close(client_fd1);
			}
		}
		
		close(client_fd);
	}
	
	close(server_fd);
}
