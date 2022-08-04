#include<stdio.h>
#include<stdlib.h>
int stack[100];
int queue[100];
int top = -1;
int front = -1,rear=-1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    if(top!=-1){
        int x = stack[top];
        top--;
        return x;
    }
}

void enqueue(int x){
    if(front == -1){
        front = 0;
        rear = 0;
        queue[rear]=x;
    }else{
        queue[++rear]=x;
    }
}
int dequeue(){
    if(front != -1){
        int x = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = front + 1;
        }
        return x;
    }
}

void dfs_traversal(int n ,int value[], int adj[][n]){
    int flag = 0;
    int index=0,j,k;
    int vertex;
    int visit[n];
    push(value[0]);
    while(top!=-1){
        vertex = pop();
        for(j=0; j<n; j++){
            if(visit[j] == vertex){
                flag =1;
            }
        }
        if(flag == 0){
            visit[index] = vertex;
            printf("  %d  ",vertex);
            for(j=0; j<n; j++){
                if(value[j] == vertex){
                    for(k=0; k<n; k++){
                        if(adj[j][k] == 1 ){
                            push(value[k]);
                        }
                    }
                    break;
                }
            }
            index++;
        }
        flag = 0;
    }
}

void bfs_traversal(int n ,int value[], int adj[][n]){
    int index = 0;
    int flag = 0,vertex,j,k,i;
    int visit[n];
    enqueue(value[0]);
    printf("  %d  ", value[0]);
    visit[index++] = value[0];
    while(front!= -1){
        vertex = dequeue();
        for( j=0; j<n; j++){
            if(value[j] == vertex){
                for(k=0; k<n; k++){
                    if(adj[j][k] == 1){
                        for( i=0; i<n; i++){
                            if(visit[i] == value[k]){
                                flag = 1;
                            }
                        }
                        if(flag == 0){
                            enqueue(value[k]);
                            printf("  %d  ", value[k]);
                            visit[index] = value[k];
                            index++;
                        }
                        flag = 0;
                    }
                }
                break;
            }
        }
    }
}

void main(){
    int n,i,j,op;
    char ans='y';
    printf("\nEnter the No. of Vertices : ");
    scanf("%d", &n);
    int adj[n][n],value[n];
    printf("\nEnter the Vertices : \n");
    for(i=0; i<n; i++){
        scanf("%d", &value[i]);
    }
    printf("\nEnter the Adjacency Matrix of the Graph:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }
    printf("\n--- OPERATION ON GRAPH --- \n\n");
    printf(" 1. DFS TRAVERSAL\n");
    printf(" 2. BFS TRAVERSAL\n");
    printf(" 3. EXIT \n");
    while(ans=='y'){
        printf("\nEnter the Choice (1/2/3): ");
        scanf("%d",&op);
        switch(op){
                case 1:printf("--- DFS TRAVERSAL ---\n\n");
                       dfs_traversal(n,value,adj);
                       break;
                case 2:printf("--- BFS TRAVERSAL ---\n\n");
                       bfs_traversal(n,value,adj);
                       break;
                case 3:ans='n';
                       break;
                default:printf("Enter a Valid Input\n");
        }
    }
}