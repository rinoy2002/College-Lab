#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#define PORT 9000
#define MAX_SIZE 50

int conn = 0;

typedef struct
{
    char to[40];
    char from[40];
    char message[1024];
}mail;

mail *queue[50];
int front = -1;
int back = -1;

int enqueue(mail *m){
    if(back+1 == MAX_SIZE) return -1;
    if(front == -1){
        front = 0;
    }
    queue[++back] = m;
    return 1;

}

mail* dequeue(char *mailid){
    if(front == -1) return NULL;
    int found = 0;
    int i;
    for( i=front;i<=back;i++){
        if(!strcmp(queue[i]->to,mailid)){
            found = 1;
            break;
        } 
    }
    if(found == 1){
        if(front == back){
            front = -1;
            back = -1;
        }
        else{
            for(int j = i; j<back;j++){
                queue[j] = queue[j+1];
            }
            back--;
        }
        return queue[i];
    }
    return NULL;
}

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddress;
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = INADDR_ANY;
    serveraddress.sin_port = htons(PORT);
    
    if (bind(sockfd, (struct sockaddr *)&serveraddress, sizeof(serveraddress)) == -1)
    {
        perror("Bind failed;");
        exit(1);
    }

    if (listen(sockfd, 4) == -1)
    {
        perror("Listen failed");
        exit(1);
    }
    printf("SMTP Server\n");

    while (1)
    {
        printf("\n");
        mail *m;
        char command[48];
        struct sockaddr_in client_addr;
        socklen_t client_len;
        int clientfd = accept(sockfd,(struct sockaddr *)& client_addr, &client_len);

        recv(clientfd,(void*)command,10*sizeof(char),0);
        if(!strcmp(command,"HELO")){
            char user_email[40];
            char buffer[40];
            char name[40];
            int i;
            int rv = recv(clientfd, (void*)user_email,40*sizeof(char),0);
            if(rv < 0){
                perror("Can't recive from client...\n");
                continue;
            }
            for(i = 0; user_email[i]!='@';i++){
                name[i] = user_email[i];
            }
            name[i] = '\0';

            sprintf(buffer,"HELLO USER: %s",name);
            rv = send(clientfd,(void*)buffer,40*sizeof(buffer),0);
            printf("Recived HELO from %s\n",name);
            if(rv<0){
                perror("Cant send the acknowledgement\n"); 
                continue;
            }
        }
        else if(!strcmp(command,"SND")){
            printf("MAIL SEND\n\n");
            m = (mail*) malloc(sizeof(mail));
            recv(clientfd,(void*)m,sizeof(mail),0);

            printf("TO: %s\nFROM: %s\nBODY: %s\n",m->to,m->from,m->message);
            if(enqueue(m) == -1){
                printf("\nSMTP Server is full\n");
                free(m);
            }
            else{
                printf("ADDED TO MAIL QUEUE\n");
            }
        }else if(!strcmp(command,"GET")){
            printf("MAIL GET\n");
            char mail_id[40];
            int rv = recv(clientfd,(void*)mail_id,sizeof(char)*40,0);
            m = dequeue(mail_id);
            rv  = send(clientfd, (void*)m,sizeof(mail),0);
            free(m);
        }
        close(clientfd);
    }
}