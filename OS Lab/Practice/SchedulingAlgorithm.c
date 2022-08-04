#include<stdio.h>
struct process{
    int no;
    float bt;
    float at;
    float tat;
    float wt;
    int pr;
};
struct process* swap(struct process p[],int i,int j){
   float temp1,temp2,temp3,temp4,temp5;
   int temp6;
   temp1 = p[i].no;
   temp2 = p[i].bt;
   temp3 = p[i].at;
   temp4 = p[i].tat;
   temp5 = p[i].wt;
   temp6 = p[i].pr;
   p[i].no = p[j].no;
   p[i].bt = p[j].bt;
   p[i].at = p[j].at;
   p[i].tat= p[j].tat;
   p[i].wt = p[j].wt;
   p[i].pr = p[j].pr;
   p[i].pr = p[j].pr;
   p[j].no = temp1;
   p[j].bt = temp2;
   p[j].at = temp3;
   p[j].tat= temp4;
   p[j].wt = temp5;
   p[j].pr = temp6;
   return p;
}

struct process* sort_at(struct process p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                p=swap(p,j,j+1);
            }
        }
    }
    return p;
}
struct process* sort_bt(struct process p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].bt>p[j+1].bt){
                p=swap(p,j,j+1);
            }
        }
    }
    return p;
}
struct process* sort_pr(struct process p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].pr>p[j+1].pr){
                p=swap(p,j,j+1);
            }
        }
    }
    return p;
}
void display(struct process p[],int n,float avgtat ,float avgwt){
     printf("\n process | burst time  |  arrival time  |   priority   |  turn-around time  |  waiting time \n");
     printf(" -------------------------------------------------------------------------------------------\n");
     for(int i=0;i<n;i++){
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
void fcfs(struct process p[],int n){
    int i;
    float stat=0,swt=0,avgtat,avgwt,time=0;
    p=sort_at(p,n);
    for(i=0;i<n;i++){
        if(time<=p[i].at){
            time = p[i].at;
        }
        time=time+p[i].bt;
        p[i].tat=time-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        stat = stat + p[i].tat;
        swt = swt + p[i].wt;
    }
    avgtat = stat/n;
    avgwt = swt/n;
    display(p,n,avgtat,avgwt);
}
void sjf(struct process p[],int n){
    int i,j,k=1;
    float stat=0,swt=0,avgtat=0,avgwt=0,min,time=0;
    p=sort_bt(p,n);
    p=sort_at(p,n);
    for(i=0;i<n;i++){
        time = time + p[i].bt;
        min = p[k].bt;
        for(j=k;j<n;j++){
            if(time>=p[j].at && p[j].bt<min){
                min = p[j].bt;
                p=swap(p,j,k);
            }
        }
        k++;
    }
    time=0;
    for(i=0;i<n;i++){
        if(time<=p[i].at){
            time = p[i].at;
        }
        time=time+p[i].bt;
        p[i].tat=time-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        stat = stat + p[i].tat;
        swt = swt + p[i].wt;
    }
    avgtat = stat/n;
    avgwt = swt/n;
    display(p,n,avgtat,avgwt);
}
void rr(struct process p[],int n){
    int q,count,flag=0,i,j=0;;
    float bt[n],temp[n];
    float stat=0,swt=0,avgtat=0,avgwt=0,time;
    printf("\n time quantum/slice : ");
    scanf("%d",&q);
    p=sort_at(p,n);
    for(i=0;i<n;i++){
        bt[i]=p[i].bt;
    }
    count=n;
    time = p[0].at;
    for(i=0;count!=0;){
        if(bt[i]<=q && bt[i]>0){
            time = time + bt[i];
            bt[i]=0;
            flag=1;
        }else if(bt[i]>0){
            bt[i]=bt[i]-q;
            time = time+q;
        }
        if(bt[i]==0 && flag==1 ){
            count--;
            p[i].tat=time-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            stat = stat + p[i].tat;
            swt = swt + p[i].wt;
            flag=0;
        }else if(i==n-1){
            i=0;
        }else if(p[i+1].at<=time){
            i++;
        }else{
            i=0;
        }
    }
    avgtat = stat/n;
    avgwt = swt/n;
    display(p,n,avgtat,avgwt);
}

void pr(struct process p[],int n){
    int i,j,k=1;
    printf("\n priority for the processes :\n");
    for(i=0;i<n;i++){
        printf(" P[%d] : ",i+1);
        scanf("%d",&p[i].pr);
    }
    float stat=0,swt=0,avgtat=0,avgwt=0,min,time=0;
    p=sort_pr(p,n);
    p=sort_at(p,n);
    for(i=0;i<n;i++){
        time = time + p[i].bt;
        min = p[k].pr;
        for(j=k;j<n;j++){
            if(time>=p[j].at && p[j].pr<min){
                min = p[j].pr;
                p=swap(p,j,k);
            }
        }
        k++;
    }
    time=0;
    for(i=0;i<n;i++){
        if(time<=p[i].at){
            time = p[i].at;
        }
        time=time+p[i].bt;
        p[i].tat=time-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        stat = stat + p[i].tat;
        swt = swt + p[i].wt;
    }
    avgtat = stat/n;
    avgwt = swt/n;
    display(p,n,avgtat,avgwt);
}
void main(){
    int n,i;
    printf("\n no. of processes : ");
    scanf("%d",&n);
    struct process p[n];
    printf("\n burst time of processes :\n");
    for(i=0;i<n;i++){
        p[i].no=i+1;
        p[i].pr=0;
        printf("  P[%d]: ",i+1);
        scanf("%f",&p[i].bt);
    }
    printf("\n arrival time of processes :\n");
    for(i=0;i<n;i++){
        printf("  P[%d]: ",i+1);
        scanf("%f",&p[i].at);
    }
    //fcfs(p,n);
    //sjf(p,n);
    //rr(p,n);
    //pr(p,n);
}