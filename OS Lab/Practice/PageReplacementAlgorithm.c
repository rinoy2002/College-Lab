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
    int i,j=0,k,pgfault=0;
    for(i=0; i<pgsize; i++){
        printf("\n For %d :",pstring[i]);
        if(isHit(pstring[i],frame,fsize)==0){
            frame[j]=pstring[i];
            j++;
            if(j==fsize){
                j=0;
            }
            pgfault++;
            for (k=0; k<fsize; k++){
                if(frame[k]!=9999){
                    printf(" %d ",frame[k]);
                }
            }
        }
        else{
            printf(" No page fault ");
        }
    }
    printf("\n Total no of page faults: %d",pgfault);
}

void lifo(int pstring[],int frame[],int pgsize,int fsize){
    int i,j=0,k,pgfault=0;
    for(i=0; i<pgsize; i++){
        printf("\n For %d :",pstring[i]);
        if(isHit(pstring[i],frame,fsize)==0){
            frame[j]=pstring[i];
            j++;
            if(j==fsize){
                j=0;
            }
            pgfault++;
            for (k=0; k<fsize; k++){
                if(frame[k]!=9999){
                    printf(" %d ",frame[k]);
                }
            }
        }
        else{
            printf(" No page fault ");
        }
    }
    printf("\n Total no of page faults: %d",pgfault);
}

void lru(int pstring[],int frame[],int pgsize,int fsize){
    int i,j,k,pgfault=0,index[fsize],page,min,found,in=0;
    for(i=0; i<pgsize; i++){
        printf("\n For %d :",pstring[i]);
        if(isHit(pstring[i],frame,fsize)==0){
            for(j=0;j<fsize;j++){
               page = frame[j];
               found = 0;
               for(k=i-1;k>=0;k--){
                   if(page==pstring[k]){
                       index[j]=k;
                       found=1;
                       break;
                   }else{
                       found=0;
                   }
               }
               if(found==0){
                   index[j]=-9999;
               }
            }
            min=9999;
            for(j=0;j<fsize;j++){
                if(min>index[j]){
                    min=index[j];
                    in=j;
                }
            }
            frame[in]=pstring[i];
            pgfault++;
            for (k=0; k<fsize; k++){
                if(frame[k]!=9999){
                    printf(" %d ",frame[k]);
                }
            }
        }
        else{
            printf(" No page fault ");
        }
    }
    printf("\n Total no of page faults: %d",pgfault);
}

void lfu(int pstring[],int frame[],int pgsize,int fsize){
    int i,j=0,k,l=0,pgfault=0,count[fsize],page,min,found,in=0;
    for(i=0; i<pgsize; i++){
        printf("\n For %d :",pstring[i]);
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
                        in=k;
                        if(count[in]==1){
                            break;
                        }
                    }
                }
                frame[in]=pstring[i];
                count[in]=1;
            }
            for (k=0; k<fsize; k++){
                if(frame[k]!=9999){
                    printf(" %d",frame[k]);
                }
            }
            pgfault++;
        }
        else{
            for(k=0; k<fsize; k++){
                if(frame[k]==pstring[i]){
                    in=k;
                    break;
                }
            }
            count[k]=count[k]+1;
            printf(" No page fault");
        }
    }
    printf("\n Total no of page faults: %d",pgfault);
}

void optimal(int pstring[],int frame[],int pgsize,int fsize){
    int i,j,k,l=0,pgfault=0,index[fsize],page,max,found,in=0;
    for(i=0; i<pgsize; i++){
        printf("\n For %d :",pstring[i]);
        if(isHit(pstring[i],frame,fsize)==0){
            if(l<fsize){
                frame[l]=pstring[i];
                l++;
            }else{
                for(j=0;j<fsize;j++){
                    page = frame[j];
                    found = 0;
                    for(k=i+1;k<pgsize;k++){
                        if(page==pstring[k]){
                            index[j]=k;
                            found=1;
                            break;
                        }else{
                            found=0;
                        }
                    }
                    if(found==0){
                        index[j]=9999;
                    }
                }
                max=-9999;
                for(j=0;j<fsize;j++){
                    if(max<index[j]){
                        max=index[j];
                        in=j;
                        if(index[in]==9999){
                            break;
                        }
                    }
                }
                frame[in]=pstring[i];
            }
            pgfault++;
            for (k=0; k<fsize; k++){
                if(frame[k]!=9999){
                    printf(" %d ",frame[k]);
                }
            }

        }
        else{
            printf(" No page fault ");
        }
    }
    printf("\n Total no of page faults: %d",pgfault);
}


void main(){
    int pgsize,fsize,pstring[50],i,pgfault=0,k;
    printf("\n Enter length of page reference string:");
    scanf("%d",&pgsize);
    printf("\n Enter the page reference string:");
    for(i=0; i<pgsize; i++){
        scanf("%d",&pstring[i]);
    }
    printf("\n Enter no of frames:");
    scanf("%d",&fsize);
    int frame[fsize];
    for(i=0; i<fsize; i++){
        frame[i]=9999;
    }
    //fifo(pstring,frame,pgsize,fsize);
    //lru(pstring,frame,pgsize,fsize);
    //lifo(pstring,frame,pgsize,fsize);
    //optimal(pstring,frame,pgsize,fsize);
    lfu(pstring,frame,pgsize,fsize);
}

