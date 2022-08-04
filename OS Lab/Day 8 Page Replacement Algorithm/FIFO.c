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

void fifo(int pstring[],int frame[],int pgsize,int fsize){
    int i,k=0,pgfault=0;
    for(i=0; i<pgsize; i++){
        printf("\n For %d :",pstring[i]);
        if(isHit(pstring[i],frame,fsize)==0){
            frame[k]=pstring[i];
            k++;
            if(i==fsize-1){
                k=0;
            }
            pgfault++;
            for (k=0; k<fsize; k++){
                if(frame[k]!=9999){
                    printf(" %d",frame[k]);
                }
            }
        }
        else{
            printf("No page fault");
        }
    }
    printf("\nTotal no of page faults: %d",nfault);
}

void main(){
    int pgsize,fsize,pstring[50],i,pgfault=0,k;
    printf("\n Enter length of page reference string:");
    scanf("%d",&pgsize);
    printf("\n Enter the page reference string:");
    for(i=0; i<pgsize; i++){
        scanf("%d",&pstring[i]);
    }
    printf("\nEnter no of frames:");
    scanf("%d",&fsize);
    int frame[fsize];
    for(i=0; i<fsize; i++){
        frame[i]=9999;
    }
    fifo(pstring,frame,pgsize,fsize);
}