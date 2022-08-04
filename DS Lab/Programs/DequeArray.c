#include <stdio.h>
#include <stdlib.h>
int size;
int front;
int rear;
int *arr;

void insertFront(int item){
    if(front==0){
        printf("\n  Insertion Not Possible \n\n");
    }
    else if(front==-1){
        arr[++front] = item;
        rear++;
    }
    else {
        arr[--front] = item;
    }
    printf("\n FRONT : %d   REAR : %d \n",front,rear);
}
void insertRear(int item){
    if(rear==size-1){
        printf("\n  Queue is FULL\n\n");
    }
    else if(front==-1){
        arr[++front] = item;
        ++rear;
    }
    else {
        arr[++rear] = item;
    }
   printf("\n FRONT : %d   REAR : %d \n",front,rear);
}
void deleteFront(){
    if(front==-1){
        printf("\n  Queue is EMPTY\n\n");
    }
    else if(front==rear){
        int item = arr[front];
        printf("\n  DELETED : %d  ",item);
        front=-1;
        rear=-1;

    }else{
        int item = arr[front];
        front++;
        printf("\n  DELETED : %d  ",item);
    }
    printf("\n FRONT : %d   REAR : %d \n",front,rear);
}
void deleteRear(){
    if(rear==-1){
        printf("\n  Queue is EMPTY\n\n");
    }
    else if(front==rear){
        int item = arr[front];
        printf("\n  DELETED : %d  ",item);
        front=-1;
        rear=-1;

    }else{
        int item = arr[rear];
        --rear;
        printf("\n  DELETED : %d  ",item);
    }
   printf("\n FRONT : %d   REAR : %d \n",front,rear);
}
void display(){
    printf("\n  Current QUEUE :\n");
    if(front==-1){
        printf("\n  Queue is EMPTY \n");
    }else{
        for(int i=front; i<=rear; i++){
        printf("    %d \n",arr[i]);
        }
    }
}

void main(){
 int n,x,y;
 char ans='y';
 printf("Enter Queue size :");
 scanf("%d", &size);
 arr = (int*) malloc (size * sizeof(int));
 front=-1,rear=-1;
 printf("\n--- OPERATION ON DEQUE --- \n\n");
 printf(" 1. INSERT FRONT \n");
 printf(" 2. INSERT REAR\n");
 printf(" 3. DELETE FRONT\n");
 printf(" 4. DELETE REAR\n");
 printf(" 5. DISPLAY\n");
 printf(" 6. EXIT\n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4/5/6): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- INSERT FRONT ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                insertFront(x);
                break;
         case 2:printf("--- INSERT REAR ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                insertRear(x);
                break;
         case 3:printf("--- DELETE FRONT ---\n");
                deleteFront();
                break;
         case 4:printf("--- DELETE REAR ---\n");
                deleteRear();
                break;
         case 5:printf("--- DISPLAY ---\n");
                display();
                break;
         case 6:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
 }
}
