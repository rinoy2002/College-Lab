#include<stdio.h>
void main()
 {
    struct process{
        int no;
        float bt;
        float at;
        float tat;
        float wt;
        int pr;
    };
    int n,i,j,d,k=1,min,temp4;
    float time=0,temp1,temp2,temp3,avgtat,avgwt,stat=0,swt=0,sum,btime;
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
    printf("priority for the processes :\n");
    for(i=0;i<n;i++){
        printf("p[%d] : ",i+1);
        scanf("%d",&p[i].pr);
    }
    for(i=0;i<n;i++){
        p[i].no = i+1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
           if(p[j].pr>p[j+1].pr){
               temp1 = p[j].no;
               temp2 = p[j].bt;
               temp3 = p[j].at;
               temp4 = p[j].pr;
               p[j].no = p[j+1].no;
               p[j].bt = p[j+1].bt;
               p[j].at = p[j+1].at;
               p[j].pr = p[j+1].pr;
               p[j+1].no = temp1;
               p[j+1].bt = temp2;
               p[j+1].at = temp3;
               p[j+1].pr = temp4;
           }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
           if(p[j].at>p[j+1].at){
               temp1 = p[j].no;
               temp2 = p[j].bt;
               temp3 = p[j].at;
               temp4 = p[j].pr;
               p[j].no = p[j+1].no;
               p[j].bt = p[j+1].bt;
               p[j].at = p[j+1].at;
               p[j].pr = p[j+1].pr;
               p[j+1].no = temp1;
               p[j+1].bt = temp2;
               p[j+1].at = temp3;
               p[j+1].pr = temp4;
           }
        }
    }
    for(j=0;j<n;j++){
        btime=btime+p[j].bt;
        min=p[k].pr;
        for(i=k;i<n;i++){
            if ((btime>=p[i].at) && (p[i].pr<min)){
                min = p[i].pr;
                temp1 = p[i].no;
                temp2 = p[i].bt;
                temp3 = p[i].at;
                temp4 = p[i].pr;
                p[i].no = p[k].no;
                p[i].bt = p[k].bt;
                p[i].at = p[k].at;
                p[i].pr = p[k].pr;
                p[k].no = temp1;
                p[k].bt = temp2;
                p[k].at = temp3;
                p[k].pr = temp4;
            }
        }
        k++;
    }
    sum = p[0].at;
    for(i=0;i<n;i++){
        if(sum<p[i].at){
            sum=p[i].at;
        }
        sum = sum + p[i].bt;
    p[i].tat=sum-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
    stat=stat+p[i].tat;
    swt=swt+p[i].wt;
    }
    avgtat = stat/n;
    avgwt = swt/n;
    printf("\n process | burst time  |  arrival time  |   priority   |  turn-around time  |  waiting time \n");
    printf(" -------------------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("  p[%d] : ",p[i].no);
        printf("   %.3f ns",p[i].bt);
        printf("       %.3f ns",p[i].at);
         printf("          %d",p[i].pr);
        printf("              %.3f ns",p[i].tat);
        printf("             %.3f ns\n\n",p[i].wt);
    }
    printf(" average turn-around time : %.3f ns\n",avgtat);
    printf(" average waiting time     : %.3f ns\n",avgwt);
}