#include<stdio.h>
void main(){
    int n,m,i,j,k,flag,var=0;
    printf("\n enter the no. of processes : ");
    scanf("%d",&n);
    printf("\n enter the no. resources : ");
    scanf("%d",&m);
    int maximum[n][m] , need[n][m] , available[1][m] , allocation[n][m] , work[1][m],finish[n],safe[n];
    for(i=0;i<n;i++){
        printf("\n\nprocess %d",i);
        for(j=0;j<m;j++){
            printf("\n allocated for resource %d :",j+1);
            scanf("%d",&allocation[i][j]);
            printf(" maximum for resource %d :",j+1);
            scanf("%d",&maximum[i][j]);
            need[i][j]=maximum[i][j]-allocation[i][j];
        }
        finish[i]=0;
    }
    for(j=0;j<m;j++){
        printf("\n available resource %d :",j+1);
        scanf("%d",&available[0][j]);
    }
    for(j=0;j<m;j++){
        work[0][j] = available[0][j];
    }
    printf("\n allocation  maximum  need \n");
    for(i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf(" %d ",allocation[i][j]);
        }
        printf("  ");
        for (j = 0; j < m; j++){
            printf(" %d ",maximum[i][j]);
        }
        for (j = 0; j < m; j++){
            printf(" %d ",need[i][j]);
        }
        printf("\n");
    }
    printf("\n available  \n");
    for (j = 0; j < m; j++){
        printf(" %d ",available[0][j]);
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            flag=1;
            if(finish[i]==0){
                for(j=0;j<m;j++){
                    if(need[i][j]>work[0][j]){
                        flag=0;
                    }
                }
                if(flag==1){
                    for(j=0;j<m;j++){
                        work[0][j] = work[0][j] + allocation[i][j];
                    }
                    finish[i]=1;
                    safe[var]=i;
                    var++;
                }
            }
        }
    }
    if(var == n){
        printf("\n safe sequence : ");
        for(i=0;i<var;i++){
            printf(" P%d ",safe[i]);
        }
    }else{
        printf("\n system is in deadlock ");
    }
}