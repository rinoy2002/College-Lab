#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int windowsize;
void transmit(int *sent, int limit)
{
    while (*sent < limit)
    {
        printf("Frame %d has been transmitted.\n", *sent);
        *sent = *sent + 1;
    }
}

int main()
{
    int sent = 0, ack, packets, l1;
    printf("Enter Window Size :");
    scanf("%d", &windowsize);
    printf("Enter no of Frames :");
    scanf("%d", &packets);
    l1 = windowsize;
    while (sent < packets)
    {
        if (windowsize > packets)
        {
            windowsize = packets;
        }
        transmit(&sent, windowsize);
        printf("\nLast ACK Received (-1 to Exit):");
        scanf("%d", &ack);
        if(ack==-1){
            exit(0);
        }
        if (ack >= packets)
        {
            printf("Incorrect ACK\n");
            exit(0);
        }
        if (ack < sent)
        {
            windowsize = ack+l1+1;
            sent = ack + 1;
        }
        else
        {
            windowsize += l1;
        }
    }
    return 0;
}