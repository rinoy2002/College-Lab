#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>

#define PORT 9000

int n;

int minDistance(int dist[], bool sptSet[])
{
    int min = 99, min_index;
  
    for (int v = 0;v<n;v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

void main()
{
	int server_fd,client_fd;
	int opt=1;
	
	char msg[50];
	
	
	struct sockaddr_in server_addr,client_addr;
	
	server_fd=socket(AF_INET,SOCK_STREAM,0);
	
	if(server_fd<0)
	{
		printf("Socket creation failed");
		exit(1);
	}
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=INADDR_ANY;	
	
	if(bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
	{
		printf("Binding failed");
		exit(1);
	}
	
	
	listen(server_fd,5);
	
	int c=sizeof(struct sockaddr_in);
	
	client_fd=accept(server_fd,(struct sockaddr*)&client_addr,(socklen_t *)&c);
	
	if(client_fd<0)
	{
		printf("Accept failed");
		exit(1);
	}
	while(1){
        int i, j, k, count = 0;
        recv(client_fd, &n, sizeof(int), 0);
        int dmat[n][n];
        recv(client_fd, dmat, sizeof(int) * n * n, 0);
        int s;
        recv(client_fd, &s, sizeof(int), 0);

        int g[n];
        int d[n];

        int dist[n];

        bool sptSet[n];

        for (int i = 0; i < n; i++)
        {
            dist[i] = 99;
            sptSet[i] = false;
        }

        dist[s] = 0;

        for (count = 0; count < n - 1; count++)
        {
            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            for (int v = 0; v < n; v++)

                if (!sptSet[v] && dmat[u][v] != 99 && dist[u] != 99 && dist[u] + dmat[u][v] < dist[v])
                    dist[v] = dist[u] + dmat[u][v];
        }

        send(client_fd, dist, sizeof(int) * n, 0);
        printf("Node %d as Source\n\n", s);
        printf("Node \tDistance \n");
        printf("----------------\n");
        for (int i = 0; i < n; i++)
            printf("Node %d \t %d\n", i, dist[i]);
        printf("\n\n");
    }
}