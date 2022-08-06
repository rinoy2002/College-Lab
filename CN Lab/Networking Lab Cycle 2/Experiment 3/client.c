#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

struct node
{
	unsigned dist[20];
	unsigned from[20];
};


#define PORT 9000

void main()
{
	int server_fd,client_fd;
	int opt=1;
	char msg[50];
	struct sockaddr_in server_addr,client_addr;
	
	server_fd=socket(AF_INET,SOCK_STREAM,0);
	
	if(server_fd<0){
		printf("Socket creation failed");
		exit(1);
	}
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	
	if(connect(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
	{
		printf("Connect failed");
		exit(1);
	}
	int n,i,j,k;
	printf("\nEnter the number of Nodes : ");
	scanf("%d",&n);
	struct node rt[n];
	printf("\nEnter the Cost Matrix (put 99 for infinity):\n");
	int dmat[n][n];
	for(i=0;i<n;i++)
	{
		int c;
		for(j=0;j<n;j++)
		{	
			scanf("%d",&dmat[i][j]);
			
		}
	}
    while(1){
        printf("\nEnter the Root Node(-1 to exit):");
        int s;
        scanf("%d", &s);
        if(s==-1)
           break;
        struct node result[n];
        send(server_fd, &n, sizeof(int), 0);
        send(server_fd, dmat, sizeof(int) * n * n, 0);
        send(server_fd, &s, sizeof(int), 0);

        int dist[n];
        recv(server_fd, dist, sizeof(int) * n, 0);
        printf("Node %d as Source\n\n", s);
        printf("Node \tDistance\n");
        printf("----------------\n");
        for (int i = 0; i < n; i++)
            printf("Node %d \t %d\n", i, dist[i]);

        printf("\n\n");
    }
	
}