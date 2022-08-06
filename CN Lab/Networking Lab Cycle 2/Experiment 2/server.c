#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

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
		printf("Socket creation failed");
		exit(0);
	}
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=INADDR_ANY;	
	
	if(bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
	{
		printf("Binding failed");
		exit(0);
	}
	
	
	listen(server_fd,5);
	
	int c=sizeof(struct sockaddr_in);
	
	client_fd=accept(server_fd,(struct sockaddr*)&client_addr,(socklen_t *)&c);
	
	if(client_fd<0)
	{
		printf("Accept failed");
		exit(0);
	}
	
	int n,i,j,k,count=0;
	recv(client_fd,&n,sizeof(int),0);
	struct node route[n];
	int dm[n][n];
	recv(client_fd,dm,sizeof(int)*n*n,0);

	 for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    
    int flag;
    do
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    int sum = (route[i].dist[k] + route[k].dist[j]);
                    if ((route[i].dist[j]) > sum){
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

	send(client_fd,route,sizeof(struct node)*n,0);
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
