#include <stdio.h>
#include <stdlib.h>
int size;
int front;
int rear;
int *arr;

int isFull(){
    if(front==(rear+1)%size){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front==-1){
        return 1;
    }
    return 0;
}

void insert(int item){
    if(isFull()){
        printf("\nCircular Queue is Full\n\n");
    }
    else if(front==-1){
        arr[++rear] = item;
        front++;
    }
    else {
        rear=(rear+1)%size;
        arr[rear] = item;
    }
    printf("\n   FRONT : %d   REAR : %d \n",front,rear);
}
void delete(){
    if(isEmpty()){
        printf("\nCircular Queue is Empty\n\n");
    }
    else if(front==rear){
        int item = arr[front];
        printf("\nElement %d DELETED ",item);
        front=-1;
        rear=-1;

    }else{
        int item = arr[front];
        front=(front+1)%size;
        printf("\nElement %d DELETED ",item);
    }
    printf("\n   FRONT : %d   REAR : %d \n",front,rear);
}

void display(){
    printf("\nCurrent Circular QUEUE :\n");
    if(isEmpty()){
        printf("\nCircular Queue is Empty \n");
    }else if (rear >= front){
        for(int i=front;i<=rear;i++){
            printf(" %d\n",arr[i]);
            }
    }
    else{
        for(int i=front;i<size;i++){
            printf(" %d\n",arr[i]);
            }
        for(int i=0;i<=rear;i++){
            printf(" %d\n",arr[i]);
        }
      }
}

void main(){
 int n,x,y;
 char ans='y';
 printf("Enter Circular Queue size :");
 scanf("%d", &size);
 arr = (int*) malloc (size * sizeof(int));
 front=-1,rear=-1;
 printf("\n--- OPERATION ON CIRCULAR QUEUE --- \n\n");
 printf(" 1. ENQUEUE \n");
 printf(" 2. DEQUEUE\n");
 printf(" 3. DISPLAY\n");
 printf(" 4. EXIT\n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- ENQUEUE ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                insert(x);
                break;
         case 2:printf("--- DEQUEUE ---\n");
                delete();
                break;
         case 3:printf("--- DISPLAY ---\n");
                display();
                break;
         case 4:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
 }
}
