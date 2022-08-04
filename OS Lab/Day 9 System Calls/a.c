#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void fibonacci(int n){
    int a =0 ,b = 1,c,i;
    printf(" %d  %d ",a,b);
    c=a+b;
    while(a+b<=n) {
        c = a + b;
        printf(" %d ",c);
        a = b;
        b = c;
   }
}

void prime(int n){
    int i,j,flag;
    for (i=2; i<=n; i++){
        flag=1;
        for (j=2; j<=i/2; j++){
            if(i%j == 0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            printf(" %d ",i);
        }
    }
}

int main(){
    int n;
    printf("\n\nEnter the value of n :");
	scanf("%d",&n);
	if(fork() ==0 ){
	    printf("\n\nChild Process : Fibonacci Series \n");
	    fibonacci(n);
	}else{
	    wait(NULL);
	    printf("\n\nParent Process : Prime Numbers \n");
	    prime(n);
	}
	printf("\n");

}