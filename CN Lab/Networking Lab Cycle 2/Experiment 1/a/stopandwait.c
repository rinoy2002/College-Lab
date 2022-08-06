#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int windowsize;
void transmit(int *sent)
{
    int ack;
    printf("\nFrame %d has been transmitted.\n", *sent);
    l1:
    printf("\nLast ACK Received (-1 to Exit):");
    scanf("%d", &ack);
    if(ack==-1){
        exit(0);
    }
    while (ack != *sent)
    {

        printf("Invalid ACK");
        goto l1;
    }
    *sent = *sent + 1;
}

int main()
{
    int sent = 0, ack, packets;
    printf("Enter no of Frames :");
    scanf("%d", &packets);

    while (sent < packets)
    {
        transmit(&sent);
    }
    return 0;
}