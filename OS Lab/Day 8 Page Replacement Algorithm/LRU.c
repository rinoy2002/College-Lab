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
    int pgsize,fsize,pstring[50],i,j,nfault=0,k,past_index[50],page,found,min,index;
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
    }
    for(i=0; i<pgsize; i++){
        printf("\nFor %d :",pstring[i]);
        if(isHit(pstring[i],frame,fsize)==0){
            for(j=0; j<fsize;j++){
                page = frame[j];
                found=0;
                for(k=i-1;k>=0;k--){
                    if(page==pstring[k]){
                        past_index[j]=k;
                        found=1;
                        break;
                    }
                    else{
                        found=0;
                    }
                }
                if(found==0){
                    past_index[j]=-9999;
                }
            }
            min=9999;
           /*printf("\n");
            for(int l=0;l<fsize;l++){
                printf(" %d ",past_index[l]);
            }
            printf("\n");*/
            for(j=0; j<fsize; j++)
            {
                if(past_index[j]<min)
                {
                    min=past_index[j];
                    index=j;
                }
            }
            frame[index]=pstring[i];
            nfault++;
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