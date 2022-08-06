#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#define PORT 9000
typedef struct
{
    char to[40];
    char from[40];
    char message[1024];
} mail;

char sender_name[30];
char domain_name[30];

int check_email(char *email)
{
    int name_found = -1;
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@' && name_found == -1)
        {
            name_found = i;
        }
        else if (email[i] == '@' && name_found != -1)
        {
            return 0;
        }
    }
    if (name_found == -1)
        return 0;
    return 1;
}

void current_user(char* email){
    int name_found = -1;
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@' && name_found == -1)
        {
            name_found = i;
        }
        else if (email[i] == '@' && name_found != -1)
        {
            return ;//0;
        }
    }
    if (name_found == -1)
        return ;
    int email_length = strlen(email);
    for (int i = 0; i < email_length; i++)
    {
        if (i < name_found)
        {
            sender_name[i] = email[i];
        }
        else if (i == name_found)
        {
            sender_name[i + 1] = '\0';
        }
        else if (i < email_length)
        {
            domain_name[i - name_found - 1] = email[i];
        }
    }
    return; 
}

int server_connect(struct sockaddr* serveraddress, socklen_t serv_len){

    int opt = 1;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    int rt = 0;
    while ((connect(sockfd, serveraddress, serv_len) == -1) && rt < 5)
    {
        perror("connection to server failed, retrying.....\n");
        sleep(1);
        rt++;
        if (rt >= 5)
        {
            perror("retried too mainy times exiting");
            close(sockfd);
            exit(1);
        }
    }
    rt = 0;

    return sockfd;
    
}

void send_mail(struct sockaddr *server_address, socklen_t ser_len)
{
    mail to_send;
    char from_addr[40];
    char cmd[] = "SND";
    int flag = 0;
    int rv;
    do{
        printf("TO: ");
        fgets(to_send.to, 40, stdin);
        to_send.to[strlen(to_send.to)-1] = '\0';

        if(check_email(to_send.to) == 0){
            printf("Wrong Email!\n");
            continue;
        }
        else{
            break;
        }
    }while(!flag);
    printf("BODY: ");
    fgets(to_send.message,1024,stdin);
    to_send.message[strlen(to_send.message)-1] = '\0';

    sprintf(to_send.from,"%s@%s",sender_name,domain_name);
    int sockfd = server_connect(server_address, ser_len);
    
    rv = send(sockfd,(void*)cmd,sizeof(char)*10,0);
    if(rv<0){
        printf("Send failed\n");
        exit(1);
    }
    rv = send(sockfd, (void*)&to_send,sizeof(to_send),0);
    if(rv<0){
        printf("Send failed\n");
        exit(1);
    }
    printf("MAIL SENT \n");
}

void show_mail(struct sockaddr* server_addr, socklen_t len){
    int sockfd = server_connect(server_addr,len);
    int rv;
    char email[40]; 
    char cmd[] = "GET";
    mail m;
    sprintf(email,"%s@%s",sender_name,domain_name);
    rv = send(sockfd,(void*)cmd,sizeof(char)*10,0);
    rv = send(sockfd,(void*)email,sizeof(char)*40,0);
    if(rv<0){
        perror("cant send data");
        exit(1);
    }

    rv = recv(sockfd,(void*)&m,sizeof(mail),0);
    if(rv <0){
        printf("Can't recive mail\n");
    }
    else if(rv == 0){
        printf("INBOX EMPTY\n");
    }else{
        printf("TO: %s\nFROM: %s\nBODY: %s\n",m.to,m.from,m.message);
    }

    close(sockfd);
}

int main()
{
    int rv = 0;
    int rt = 0;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddress;
    char email_address[40];
    char buffer[100];

    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = INADDR_ANY;
    serveraddress.sin_port = htons(PORT);


    int flag;
    do{
        flag = 1;
        printf("\nSMTP Client\n\n");
        printf("\nEnter your Email Address: ");
        fgets(email_address, 40, stdin);
        email_address[strlen(email_address) - 1] = '\0';

        if (check_email(email_address) == 0)
        {
            printf("Wrong email error\n");
            continue;
        }
        flag = 0;
    }while(flag);

    current_user(email_address);
    while ((connect(sockfd, (struct sockaddr *)&serveraddress, sizeof(serveraddress)) == -1) && rt < 5)
    {
        printf("connection to server failed, retrying.....\n");
        sleep(1);
        rt++;
        if (rt >= 5)
        {
            printf("retried too mainy times exiting");
            close(sockfd);
            exit(1);
        }
    }
    rt = 0;
    sprintf(buffer,"HELO");
    rv = send(sockfd,(void*)buffer,sizeof(char)*10,0);
    if(rv<0){
        printf("Cant send HELO message");
        exit(1);
    }
    rv = send(sockfd,(void*)email_address,sizeof(char)*40,0);
    if(rv<0){
        printf("Cant send HELO message");
        exit(1);
    }
    
    rv = recv(sockfd,(void*)buffer,sizeof(char)*40,0);
    if(rv<0){
        printf("Cant recieve reply from server");
        exit(1);
    }

    printf("%s\n",buffer);
    close(sockfd);

    int run = 1;
    while (run)
    {
        rt = 0;
        int ch;
        printf("\n 1.Send Mail\n 2.Recive Mail\n 3.Exit\nEnter Choice: ");
        scanf("%d%*c", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            send_mail((struct sockaddr *)&serveraddress, sizeof(serveraddress));
            break;
        case 2:
            show_mail((struct sockaddr*)&serveraddress, sizeof(serveraddress));
            break;
        case 3:
            run = 0;
            break;
        default:
            printf("Enter a proper choice\n");
            break;
        }
        close(sockfd);
    }
}
