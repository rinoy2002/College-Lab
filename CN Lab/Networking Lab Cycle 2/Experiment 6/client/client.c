#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 9090
void main() {
	int client_fd;
	struct sockaddr_in serv_addr;
	
	printf("File Client\n");
	
	while(1) {
		
        serv_addr.sin_family = AF_INET;
	    serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(PORT);
				
		if((client_fd = socket(AF_INET, SOCK_STREAM, 0))< 0) {
			printf("Socket creation failed!\n");
			exit(1);
		}
		
		if(connect(client_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
			printf("Connection failed!\n");
			exit(1);
		}
		
		char filename[100],msg[100],body[1000];
        int pid;
	    printf("Enter filename: ");
	    scanf("%s", filename);
	    if(send(client_fd, filename, 100 * sizeof(char), 0) <= 0) {
		    printf("GET failed!\n");
		    exit(1);
	    } else {
		    if(recv(client_fd, body,1000 * sizeof(char), 0) <= 0) {
			    printf("GET failed!\n");
                exit(1);
		    }
		    if(recv(client_fd, &pid, sizeof(int), 0) <= 0) {
			    printf("GET failed!\n");
			    exit(1);
		    }
		    if(recv(client_fd, msg, 100 * sizeof(char), 0) <= 0) {
			    printf("GET failed!\n");
			    exit(1);
		    }
		    if(!strcmp(msg, "200 OK")) {
			    FILE* fp = fopen(filename, "w");
			    fputs(body, fp);
			    printf("GET 200 OK : PID %d\n", pid);
				printf("\n------------------BODY------------------\n%s\n\n",body);
		        fclose(fp);
		    }else{
		        printf("GET 400 BAD : PID %d\n", pid);
		    }
	    }
	close(client_fd);
	}
}