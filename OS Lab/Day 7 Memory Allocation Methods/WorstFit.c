#include<stdio.h>
void main(){
    int block[50], process[50], bsize, psize, iscompleted[50], allocation[50],i, j,index;
    printf(" Enter no. of memory blocks: ");
    scanf("%d", &bsize);
    printf("\n Enter size of each memory block: ");
    for(i = 0; i < bsize; i++){
        scanf("%d", &block[i]);
    }
    printf("\n Enter no. of processes: ");
    scanf("%d", &psize);
    printf("\n Enter size of each process: ");
    for(i = 0; i < psize; i++){
        scanf("%d", &process[i]);
    }
    for(i = 0; i < bsize; i++){
        allocation[i] = -1;
    }
    for(i = 0; i < psize; i++){
        iscompleted[i] = 0;
    }
    for(i=0;i<psize;i++){
        index =-1;
        for(j=0;j<bsize;j++){
            if((block[j]>=process[i])&&(allocation[j]==-1)){
                if(index==-1){
                    index=j;
                }else if( block[index] < block[j]){
                    index = j;
                }
            }
        }
        if(index!=-1){
            allocation[index] = i;
            iscompleted[i]=1;
        }
    }
    printf("\n Block no.\tsize\t\tprocess no.\t\tsize\t\tunused memory\n");
    for(i = 0; i < bsize; i++){
        printf("\n %d\t\t%dK\t\t", i+1, block[i]);
        if(allocation[i] != -1){
            printf("%d\t\t\t%dK\t\t%dK",allocation[i]+1,process[allocation[i]],block[i]-process[allocation[i]]);
        }else{
            printf("Not allocated\t\t\t\t%dK",block[i]);
        }
    }
    for(i = 0; i < psize; i++){
        if(iscompleted[i] != 1){
            printf("\n process %d can't be allocated",i+1);
        }
    }

}
