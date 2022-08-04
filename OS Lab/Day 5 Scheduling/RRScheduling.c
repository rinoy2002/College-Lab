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
    int n,i,j,quantum,count,var;
    float time=0,temp1,temp2,temp3,temp4,avgtat,avgwt,stat=0,swt=0,sum;
    printf(" no. of processes :");
    scanf("%d",&n);
    struct process p[n];
    float temp[n];
    printf(" burst time for the processes :\n");
    for(i=0;i<n;i++){
        printf(" p[%d] : ",i+1);
        scanf("%f",&p[i].bt);
        temp[i]=p[i].bt;
    }
    printf(" arrival time for the processes :\n");
    for(i=0;i<n;i++){
        printf(" p[%d] : ",i+1);
        scanf("%f",&p[i].at);
    }
    for(i=0;i<n;i++){
        p[i].no = i+1;
    }
    printf(" time quantum for the processes: ");
    scanf("%d", &quantum);
   for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
           if(p[j].at>p[j+1].at){
               temp1 = p[j].no;
               temp2 = p[j].bt;
               temp3 = p[j].at;
               temp4 = temp[j];
               p[j].no = p[j+1].no;
               p[j].bt = p[j+1].bt;
               p[j].at = p[j+1].at;
               temp[j] = temp[j+1];
               p[j+1].no = temp1;
               p[j+1].bt = temp2;
               p[j+1].at = temp3;
               temp[j+1] = temp4;
           }
        }
    }
    sum=p[0].at;
    var=n;
    for( i = 0; var!=0; ){
        if(temp[i] <= quantum && temp[i] > 0){
            sum = sum + temp[i];
            temp[i] = 0;
            count=1;
        }
        else if(temp[i] > 0){
            temp[i] = temp[i] - quantum;
            sum = sum + quantum;
        }
        if(temp[i]==0 && count==1){
            var--;
            p[i].tat=sum-p[i].at;
            p[i].wt=sum-p[i].at-p[i].bt;
            swt = swt+p[i].wt;
            stat = stat+p[i].tat;
            count =0;
        }
        if(i==n-1){
            i=0;
        }
        else if(p[i+1].at<=sum){
            i++;
        }
        /*else if(p[i+1].at>=sum){
            sum=p[i+1].at;
            i++;
        }*/
        else{
            i=0;
        }
    }
    avgtat = stat/n;
    avgwt = swt/n;
       printf("\n  process | burst time  |  arrival time  |  turn-around time  |  waiting time \n");
        printf("  ------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("  p[%d] : ",p[i].no);
        printf("   %.3f ms",p[i].bt);
        printf("       %.3f ms",p[i].at);
        printf("            %.3f ms",p[i].tat);
        printf("            %.3f ms\n\n",p[i].wt);
    }
    printf(" average turn-around time : %.3f ms\n",avgtat);
    printf(" average waiting time     : %.3f ms\n",avgwt);
 }