#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 9090

int queue[100],FRONT=-1,REAR=-1,REMAINING,SIZE;
void enqueue(int i) {
	if(FRONT == -1)
		FRONT = 0;
	else if((REAR + 1) % SIZE == FRONT)
		return;
	REAR = (REAR + 1) % SIZE;
	queue[REAR] = i;
}

int dequeue() {
	int data;
	if(FRONT == -1)
		return -1;
	else if(FRONT == REAR) {
		data = queue[FRONT];
		FRONT = -1;
		REAR = -1;
	} else {
		data = queue[FRONT];
		FRONT = (FRONT + 1) % SIZE;
	}
	REMAINING++;
	return data;
}

void sendData(int client_fd, int size) {
	int k = 0, n;
	
	while(1) {
		printf("\n");
		for(int i = 0; i < size; i++) {
			n = dequeue();
			
			if(n == -1)
				return;
			else if(n == 0)
				k++;
			if(send(client_fd, &n, sizeof(int), 0) < 0) {
				printf("Send failed!\n");
				exit(1);
			} else {
				printf(" Packet %d: %d\n", k, n+1);
			}
		}
		
		sleep(1);
	}
}

void main() {
	int  client_fd;
	struct sockaddr_in serv_addr;
	
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(client_fd < 0) {
		printf("Socket creation failed!\n");
		exit(1);
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);
	
	if(connect(client_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		printf("Connection failed!\n");
		exit(1);
	}
	
	int num, size;
	
	printf("Enter bucket size: ");
	scanf("%d", &size);
	SIZE = size;
	REMAINING=size;
	printf("Enter the flow rate: ");
	scanf("%d", &size);
	
	while(1) {
		printf("\nEnter number of packets to send: ");
		scanf("%d", &num);
		
		int packets[num];
		
		for(int i = 0; i < num; i++) {
			printf("Enter packet %d size: ", i + 1);
			scanf("%d", &packets[i]);
		}
		
		for(int i = 0; i < num; i++) {
			if(REMAINING < packets[i]) {
				printf("\nBucket full! Packet %d rejected!\n", i + 1);
				continue;
			}
			
			for(int j = 0; j < packets[i]; j++) {
				enqueue(j);
				REMAINING--;
			}
		}
		printf("\nFlow Out of Bucket\n");
		sendData(client_fd,size);
	}
	
	close(client_fd);
}
