#include<arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(){
    int sock =0, valread;
    struct sockaddr_in serv_addr;
    int send_buffer[10] = {10,5,3,4,2,9,10,8,7,1};
    int read_buffer[3] = { 0 };

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0){
        printf("\n Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1",&serv_addr.sin_addr) <= 0){
        printf("\nInvalid address/ Address not supported");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0){
        printf("\nConnection failed\n");
        return -1;
    }

    send(sock, send_buffer, 10* sizeof(int),0);
    valread = read(sock, read_buffer,3*sizeof(int));
    printf("Mean = %d\nMin = %d\nMax = %d\n",read_buffer[0], read_buffer[1],read_buffer[2]);

    return 0;
}
