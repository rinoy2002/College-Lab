#include<stdio.h>
void create_heap(int A[],int B[],int n){
    int i=1;
    while(i<=n){
        int x = A[i];
        B[i] = x;
        int j = i;
        while(j>1){
            if(B[j]>B[j/2]){
                int temp = B[j];
                B[j] = B[j/2];
                B[j/2] = temp;
                j = j/2;
            }else{
                j = 1;
            }
        }
        i++;
    }
}

void remove_max(int B[],int i){
    int temp = B[i];
    B[i] = B[1];
    B[1] = temp;
}

void rebuild_heap(int B[],int i){
   if(i!=1){
       int j=1;
       int flag = 1;
       int temp;
       while(flag==1){
           int leftchild = 2*j;
           int rightchild = 2*j+1;
           if(rightchild<=i){
               if((B[j]<=B[leftchild])&&(B[rightchild]<=B[leftchild])){
                   temp = B[j];
                   B[j] = B[leftchild];
                   B[leftchild] = temp;
                   j = leftchild;
               }else if((B[j]<=B[rightchild])&&(B[rightchild]>=B[leftchild])){
                   temp = B[j];
                   B[j] = B[rightchild];
                   B[rightchild] = temp;
                   j = rightchild;
               }else{
                   flag = 0;
               }
           }else if(leftchild<=i){
               if(B[j]<=B[leftchild]){
                   temp = B[j];
                   B[j] = B[leftchild];
                   B[leftchild] = temp;
                   j = leftchild;
               }else{
                   flag = 0;
               }
           }else{
               flag=0;
           }
       }
   }
}

void binary_search(int B[],int n,int item){


  int first = 1;
  int last = n;
  int middle = (first+last)/2;
  while(first<=last) {
    if(B[middle]<item){
      first = middle + 1;
    }
    else if(B[middle] == item) {
      printf("\n %d found at location %d \n", item, middle);
      break;
    }
    else{
      last = middle - 1;
    }
    middle = (first + last)/2;
  }
  if(first>last){
    printf("\nNot found! %d isn't present \n", item);
  }
}

void main(){
    int A[100],B[100],n,i,item;
    char ans;
    printf("Enter the Size of Array : ");
    scanf("%d",&n);
    printf("Enter Elements in Array :\n");
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    create_heap(A,B,n);
    for(i=n;i>1;i--){
        remove_max(B,i);
        rebuild_heap(B,i-1);
    }
    printf("\n\nArray After Heap Sort\n");
    for(i=1;i<=n;i++){
        printf(" %d ",B[i]);
    }
    do{
        printf("\nEnter Element to Searched :");
        scanf("%d", &item);
        binary_search(B,n,item);
        printf("\nWish to Continue (y/n) :");
        scanf("%c",&ans);
        scanf("%c",&ans);
    }while(ans=='y');
}