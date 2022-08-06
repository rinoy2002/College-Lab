#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<pthread.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<ctype.h>
#define PORT 9090

#define MAX_CLIENTS 32

struct client{
		int index;
		int sockId;
		struct sockaddr_in clientAddr;
		int len;
		int stat;
};

struct client client_list[MAX_CLIENTS];
pthread_t client_threads[MAX_CLIENTS];
int client_count;

void* talk_client(void* client_info_arg){
    struct client* client_info = (struct client*)client_info_arg;
    int client_fd = client_info -> sockId;
    
    char buffer[1024] = {'\0'};
    int num_words = 0;
    
    while(1){     
        int val_read = recv(client_fd, buffer, 1023, 0);
    
        if(strcmp(buffer, "START") == 0){
            printf("Client %d wants to start\n",client_info -> index+1);
            break;  
        }
    }
    
    while(1){

        int val_read = recv(client_fd, buffer, 1023, 0);
        for(int i=0; buffer[i]!='\0' || num_words > 25; i++ ){
            if(isspace(buffer[i]) || buffer[i] == '.' ){
                num_words ++;
            }
        }
        num_words = num_words > 25 ? num_words : num_words+1 ;
        
        char temp_buf[1240] = {'\0'};
        sprintf(temp_buf,"Client %d: %s\n",client_info->index,buffer);
        printf("%s", temp_buf);
        for(int i=0; i<client_count; i++){
            if( client_info->index != client_list[i].index ){
                send(client_list[i].sockId,temp_buf,1024,0);
                printf("Sent data to Client %d Number of words spoken till now %d\n",client_list[i].index+1,num_words);
            }
        }
        
        if(strcmp(buffer, "STOP") == 0 || num_words >= 25){
            sprintf(temp_buf,"STOP");
            send(client_fd,temp_buf,1024,0);
            printf("Client %d has left the chat\n",client_info->index+1);
            break;  
        }
        
    }
    
    pthread_exit(NULL);
    return NULL;
}

int main(){
        client_count = 0;
		int server_socket;
		struct sockaddr_in server_addr;
		socklen_t addr_size;		
		server_socket= socket(AF_INET, SOCK_STREAM,0);

		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = INADDR_ANY;
		server_addr.sin_port = htons(PORT);
		addr_size = sizeof(server_addr);

		if(bind(server_socket,(struct sockaddr*)&server_addr,addr_size) == -1){
				perror("bind failed");
				exit(EXIT_FAILURE);
		}

		if(listen(server_socket, 20)==-1){
				perror("listen error");
		}

		while(1){
				client_list[client_count].sockId = accept(server_socket, 
				(struct sockaddr*)&client_list[client_count].clientAddr, &client_list[client_count].len);
				
				printf("Got Client %d \n",client_count + 1);
				
				client_list[client_count].index  = client_count;
				pthread_create(client_threads+client_count,NULL,talk_client,(void *)&client_list[client_count]);
				client_count ++;
				
		}
		return 0;
}
