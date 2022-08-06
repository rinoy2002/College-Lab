#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#define port 9000
struct node
{
	unsigned dist[20];
	unsigned from[20];
};




void main()
{
	int server_fd,client_fd;
	int opt=1;
	
	char msg[50];
	
	
	
	struct sockaddr_in server_addr,client_addr;
	
	server_fd=socket(AF_INET,SOCK_STREAM,0);
	
	if(server_fd<0)
	{
		perror("Socket creation failed");
		exit(0);
	}
	
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;
	
	
	if(connect(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
	{
		perror("connect failed");
		exit(0);
	}
	int n,i,j,k;
	printf("\nEnter the number of Nodes : ");
	scanf("%d",&n);
	struct node rt[n];
	printf("\nEnter the Distance Matrix :\n");
	int dmat[n][n];
	for(i=0;i<n;i++)
	{
		int c;
		for(j=0;j<n;j++)
		{	
			scanf("%d",&dmat[i][j]);	
		}
	}

	struct node route[n];
	send(server_fd,&n,sizeof(int),0);
	send(server_fd,dmat,sizeof(int)*n*n,0);
	recv(server_fd,route,sizeof(struct node)*n,0);
    for (int i = 0; i < n; i++)
    {
        printf("Router Information for router: %d\n", i+1);
        printf("Node\tNext Hop\tDistance\n");
        for (int j = 0; j < n; j++)
            printf("%d\t%d\t\t%d\n", j+1,route[i].from[j]+1,route[i].dist[j]);
        printf("\n");
    }	
	printf("\n\n");
	
}
	
