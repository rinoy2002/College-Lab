#include <stdio.h>
void main(){
    int n,m,i,j,k,flag1=1,flag2=1,pno,l=0;
    char ans='n';
    printf("\n Enter total number of processes : ");
    scanf("%d", &n);
    printf("\n Enter total number of resources : ");
    scanf("%d", &m);
    int Alloc[n][m],Max[n][m],Need[n][m],Avail[m],Request[m],Finish[n],Work[m],count=0,flag,sequence[n];
    for(i = 0; i < n; i++){
        printf("\n Process %d\n", i);
        for(j = 0; j < m; j++){
            printf(" Allocation for resource %d : ", j+1 );
            scanf("%d", &Alloc[i][j]);
            printf(" Maximum for resource %d : ", j+1 );
            scanf("%d", &Max[i][j]);
        }
    }
    printf("\n Available Resources : \n");
    for (j = 0; j < m; j++){
        printf(" Resource %d : ", j+1);
        scanf("%d", &Avail[j]);
    }
    for(i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            Need[i][j] = Max[i][j] - Alloc[i][j];
        }
    }
    printf("\n Whether want to raise a resource request(y/n) : ");
    scanf("%c", &ans);
    scanf("%c", &ans);
    if(ans=='y'){
        printf("\n Enter the process no. for resource request : ");
        scanf("%d", &pno);
        for(j = 0; j < m; j++){
            printf(" Request for resource %d : ", j+1 );
            scanf("%d", &Request[j]);
        }
        for(j = 0; j < m; j++){
           if(Request[j]>Need[pno][j]){
               flag1=0;
               break;
           }
           if(Request[j]>Avail[j]){
               flag2=0;
               break;
           }
        }
        if((flag1==1) && (flag2==1)){
            for (j = 0; j < m; j++){
                   Avail[j] = Avail[j]-Request[j];
                   Alloc[pno][j] = Alloc[pno][j]+Request[j];
                   Need[pno][j] =  Need[pno][j]-Request[j];
            }
            printf("\n Request Granted ");
        }else{
            printf("\n Request can't be Granted ");
        }
    }
    printf("\n Allocation Matrix : \n");
    for(i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf(" %d ",Alloc[i][j]);
        }
        printf("\n");
    }
    printf("\n Maximum Matrix : \n");
    for(i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf(" %d ",Max[i][j]);
        }
        printf("\n");
    }
    printf("\n Available Matrix : \n");
        for (j = 0; j < m; j++){
            printf(" %d ",Avail[j]);
        }

    printf("\n\n Need Matrix : \n");
    for(i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf(" %d ",Need[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        Finish[i]=0;
    }
    for(j=0;j<m;j++){
        Work[j]=Avail[j];
    }
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            if (Finish[i] == 0){
                flag = 0;
                for (j = 0; j < m; j++){
                    if (Need[i][j] > Work[j]){
                        flag = 1;
                    }
                }
                if (flag== 0 && Finish[i] == 0){
                    for (j = 0; j < m; j++){
                        Work[j] += Alloc[i][j];
                    }
                    Finish[i] = 1;
                    count++;
                    sequence[l]=i;
                    l++;
               }
            }
        }
    }
    if(count==n){
        printf(" Safe Sequence : ");
        for(i=0;i<l;i++){
        printf(" P%d ",sequence[i]);
        }
    }else{
        printf(" Deadlock Occurs ");
    }
}
