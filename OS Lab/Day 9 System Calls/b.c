#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


void main(){
    int n,i;
    printf("Enter the value of N : ");
    scanf("%d",&n);
    for(i =0; i<n ; i++){
        if(fork() == 0){
            printf("Level %d:  Child pid: %d   Parent pid: %d \n",i,getpid(),getppid());
        }else{
            wait(NULL);
            break;
        }
    }
}