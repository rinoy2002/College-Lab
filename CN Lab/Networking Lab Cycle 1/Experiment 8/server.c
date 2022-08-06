#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define WPORT 8800

char* get() {
	return "GET SUCCESS\n";
}

char* post(char* body) {
	char* temp = strdup(body);
	sprintf(body, "POST %s SUCCESS\n", temp);
	return body;
}

char* put(char* body) {
	char* temp = strdup(body);
	sprintf(body, "PUT %s SUCCESS\n", temp);
	return body;
}

char* patch(char* body) {
	char* temp = strdup(body);
	sprintf(body, "PATCH %s SUCCESS\n", temp);
	return body;
}


void main() {
	int server_fd, client_fd;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(WPORT);
	
	if(bind(server_fd, (struct sockaddr*) &address, addrlen) < 0) {
		printf("Binding failed!\n");
		exit(1);
	}
	
	char* buff;
	buff = malloc(100*sizeof(char));
	
	while(1) {
		if(listen(server_fd, 5) < 0) {
			printf("Listening failed!\n");
			exit(1);
		} else {
			printf("Server is running and listening for requests...\n");
		}
		
		if((client_fd = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
			printf("Accept failed!\n");
			exit(1);
		}
		
		if(recv(client_fd, buff, 6 * sizeof(char), 0) < 0) {
			printf("Reeceive failed!\n");
			exit(1);
		} else {
			printf("Request: %s\n", buff);
			
			if(!strcmp(buff, "GET")) {
				
				buff = get();
				
				if(send(client_fd, buff, 100 * sizeof(char), 0) < 0){
                    printf("Send failed!\n");
				}		
			} else if(!strcmp(buff, "POST")) {
				
				if(recv(client_fd, buff, 100 * sizeof(char), 0) < 0){
                    printf("Receive failed!\n");
				}
				buff = post(buff);
				
				if(send(client_fd, buff, 100 * sizeof(char), 0) < 0){
                    printf("Send failed!\n");
				}
					
			} else if(!strcmp(buff, "PUT")) {
				
				if(recv(client_fd, buff, 100 * sizeof(char), 0) < 0){
                    printf("Receive failed!\n");
				}
				buff = put(buff);
				
			    if(send(client_fd, buff, 100 * sizeof(char), 0) < 0){
                    printf("Send failed!\n");
			    }
					
			} else if(!strcmp(buff, "patch")) {
				if(recv(client_fd, buff, 100 * sizeof(char), 0) < 0){
                    printf("Receive failed!\n");
				}	
				buff = patch(buff);
				if(send(client_fd, buff, 100 * sizeof(char), 0) < 0){
                     printf("Send failed!\n");
				}		
			} else {
				buff = "INVALID REQUEST\n";
				if(send(client_fd, buff, 100 * sizeof(char), 0) < 0){
                      printf("Send failed!\n");
				}
			}
		}
		
		close(client_fd);
	}
	
	close(server_fd);
}