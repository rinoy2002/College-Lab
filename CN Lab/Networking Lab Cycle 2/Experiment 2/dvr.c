#include <stdlib.h>
#include <stdio.h>


struct node
{
    int dist[20];
    int from[20];
} route[10];

int main()
{
    int dm[20][20], no;
    printf("Enter no of nodes: ");
    scanf("%d", &no);
    printf("Enter the distance matrix (enter 999 if no path exists): ");
    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < no; j++)
        {
            scanf("%d", &dm[i][j]);
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do
    {
        flag = 0;
        for (int i = 0; i < no; i++)
        {
            for (int j = 0; j < no; j++)
            {
                for (int k = 0; k < no; k++)
                {
                    int sum = (route[i].dist[k] + route[k].dist[j]);
                    if ((route[i].dist[j]) > sum)
                    {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < no; i++)
    {
        printf("Router Information for router: %d\n", i);
        printf("Destination\tNext Hop\tDistance\n");
        for (int j = 0; j < no; j++)
            printf("%d\t%d\t\t%d\n", j+1, route[i].from[j] + 1, route[i].dist[j]);
        printf("\n");
    }
    return 0;
}
