#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 9092

int main()
{
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;
    int chopstick[5] = {0};
    int opt = 1;
    setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt));

	if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address))<0){
        perror("Bind failed");
        
    }

	listen(server_socket, 10);
    int pid[5];
    int message[2];
    int i=0;

    while(1){
        if(i>=5){
            break;
        }
        int client_socket = accept(server_socket,NULL,NULL);
        recv(client_socket,&message,sizeof(message),0);
        pid[i] = message[0];
        i++;
        printf("PID %d\n",message[0]);
    }

    int small = pid[0];
    for(int i=1; i<5; i++){
        if(small > pid[i])
            small = pid[i];
    }

    for(int i = 0; i<5; i++){
        printf("Philosopher %d is THINKING\n",pid[i]-small);
    }

    while(1){
        int client_socket = accept(server_socket,NULL,NULL);
        recv(client_socket,&message,sizeof(message),0);

        int phil_no = message[0] - small; 
        if(message[1] == 1){
            printf("Philosopher %d wants to take the CHOPSTICK\n",phil_no+1);
            
            if(chopstick[phil_no] == 0 && chopstick[(phil_no+1)%5] == 0){

                printf("   Philosopher %d took the CHOPSTICK\n",phil_no+1);
                chopstick[(phil_no+1)%5] = 1;
                chopstick[phil_no] = 1;
            }
            else{
                printf("   Philosopher %d can't take CHOPSTICK\n",phil_no + 1);
            }
        }else if(message[1] == 0){
            if(chopstick[phil_no]==1 && chopstick[(phil_no + 1) % 5] == 1){ 

                printf("   Philosopher %d has put down the CHOPSTICK\n",phil_no + 1);
                chopstick[phil_no] = 0;
                chopstick[(phil_no + 1) % 5] = 0;
            }
            else{
                
                printf("   Philosopher %d is no longer holding the CHOPSTICK\n",phil_no + 1);
            }
        }
     }

    close(server_socket);

    return 0;
}
