#include<stdio.h>
void main()
 {
    struct process{
        int no;
        float bt;
        float at;
        float tat;
        float wt;
    };
    int n,i,j;
    float time=0,temp1,temp2,temp3,avgtat,avgwt,stat=0,swt=0;
    printf("no. of processes :");
    scanf("%d",&n);
    struct process p[n];
    printf("burst time for the processes :\n");
    for(i=0;i<n;i++){
        printf("p[%d] : ",i+1);
        scanf("%f",&p[i].bt);
    }
    printf("arrival time for the processes :\n");
    for(i=0;i<n;i++){
        printf("p[%d] : ",i+1);
        scanf("%f",&p[i].at);
    }
    for(i=0;i<n;i++){
        p[i].no = i+1;
    }
   for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
           if(p[j].at>p[j+1].at){
               temp1 = p[j].no;
               temp2 = p[j].bt;
               temp3 = p[j].at;
               p[j].no = p[j+1].no;
               p[j].bt = p[j+1].bt;
               p[j].at = p[j+1].at;
               p[j+1].no = temp1;
               p[j+1].bt = temp2;
               p[j+1].at = temp3;
           }
        }
    }
    for(i=0;i<n;i++){
        if(time<=p[i].at){
            time =p[i].at;
        }
        time = time + p[i].bt;
        p[i].tat = time-p[i].at;
        stat = stat + p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        swt = swt + p[i].wt;
    }
    avgtat = stat/n;
    avgwt = swt/n;
        printf("\n  process | burst time  |  arrival time  |  turn-around time  |  waiting time \n");
        printf("  ------------------------------------------------------------------------------\n");
        for(i=0;i<n;i++){
            printf("  p[%d] : ",p[i].no);
            printf("   %.3f ns",p[i].bt);
            printf("       %.3f ns",p[i].at);
            printf("            %.3f ns",p[i].tat);
            printf("            %.3f ns\n\n",p[i].wt);
        }
    printf(" average turn-around time : %.3f ns\n",avgtat);
    printf(" average waiting time     : %.3f ns\n",avgwt);
 }