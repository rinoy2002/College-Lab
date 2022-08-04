#include<stdio.h>
int isHit(int data,int frame[],int fsize){
    int hit=0;
    for(int j=0; j<fsize; j++){
        if(frame[j]==data){
            hit=1;
            break;
        }
    }
    return hit;
}

void main(){
    int pgsize,fsize,pstring[50],i,j,nfault=0,k,count[50],min,index,val;
    printf("\nEnter length of page reference string:");
    scanf("%d",&pgsize);
    printf("\nEnter the page reference string:");
    for(i=0; i<pgsize; i++){
        scanf("%d",&pstring[i]);
    }
    printf("\nEnter no of frames:");
    scanf("%d",&fsize);
    int frame[fsize];
    for(i=0; i<fsize; i++){
        frame[i]=9999;
        count[i]=0;
    }
    j=0;
    for(i=0; i<pgsize; i++){
        printf("\nFor %d :",pstring[i]);
        if(isHit(pstring[i],frame,fsize)==0){
            if(j<fsize){
                frame[j]=pstring[i];
                count[j]=count[j]+1;
                j++;
            }else{
                min=9999;
                for(k=0; k<fsize; k++){
                    if(count[k]<min){
                        min=count[k];
                        index=k;
                    }
                }
                for(k=index;k<fsize-1;k++){
                    frame[k]=frame[k+1];
                    count[k]=count[k+1];
                }
                frame[fsize-1]=pstring[i];
                val=0;
                for(k=0; k<=i; k++){
                    if(pstring[i]==pstring[k]){
                        val=val+1;
                    }
                }
                count[fsize-1]=val;
            }
            for (k=0; k<fsize; k++){
                if(frame[k]!=9999){
                    printf(" %d",frame[k]);
                }
            }
            nfault++;
        }
        else{
            for(k=0; k<fsize; k++){
                if(frame[k]==pstring[i]){
                    index=k;
                    break;
                }
            }
            count[k]=count[k]+1;
            printf("No page fault");
        }
        printf("\n");
        for(int l=0;l<fsize;l++){
            printf(" %d ",count[l]);
        }
        printf("\n");
    }
    printf("\nTotal no of page faults: %d",nfault);
}