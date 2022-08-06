#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#define PORT 9090

void main() {
	
	int server_fd, client_fd;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	
	printf("Concurrent File Server\n");
	
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	if(bind(server_fd, (struct sockaddr*) &address, addrlen) < 0) {
		printf("Socket binding failed!\n");
		exit(1);
	}
	
	if(listen(server_fd, 5) < 0) {
		printf("Listening failed!\n");
		exit(1);
	}
	
	while(1) {
		if((client_fd = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
			printf("Connection failed!\n");
			exit(1);
		}else{
			printf("Connected to client.\n");
		}

		if(fork() == 0) {
			char filename[100];
            char line[100];
	        char body[1000];
	
	        if(recv(client_fd, filename, 100 * sizeof(char), 0) <= 0) {
		        printf("Connection lost!\n");
		        exit(1);
	        }
	
	        FILE* fp = fopen(filename, "r");
	        int pid = getpid();
	
	        if(fp == NULL) {
		        body[0] = '\0';
		
		        if(send(client_fd, body, sizeof(char), 0) <= 0) {
			        printf("GET failed!\n");
			        exit(1);
		        }
		
		        if(send(client_fd, &pid, sizeof(int), 0) <= 0) {
			        printf("GET failed!\n");
			        exit(1);
		        }
                
		        if(send(client_fd, "400 BAD", 8 * sizeof(char), 0) <= 0) {
			        printf("GET failed!\n");
			        exit(1);
                }else{
                    printf("400 BAD\n");
                    exit(1);
                }
	        }else{
                body[0] = '\0';
	
	            while(fgets(line, 100, fp) != NULL) {
		            strcat(body, line);
	            }
	            fclose(fp);
	
	            if(send(client_fd,body, 1000 * sizeof(char), 0) <= 0) {
		            printf("GET failed!\n");
		            exit(1);
	            }
	
	            if(send(client_fd, &pid, sizeof(int), 0) <= 0) {
		            printf("GET failed!\n");
		            exit(1);
                }
	            if(send(client_fd, "200 OK", 7 * sizeof(char), 0) <= 0) {
		            printf("GET failed!\n");
		            exit(1);
	            } else {
		            printf("200 OK\n");
		            exit(1);
	            }
            }	        
			close(client_fd);
		}
	}
	close(server_fd);
}