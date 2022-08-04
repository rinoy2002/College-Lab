#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void insert(struct node* front,struct node* rear,int x){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    if(new==NULL){
        printf("\nMEMORY Underflow\n");
    }else{
        if(front->link==NULL){
            front->link=new;
            rear->link=new;
        }else{
            rear->link->link=new;
            rear->link=new;
        }
    }
}
void delete(struct node* front,struct node* rear){
     struct node* ptr=front->link;
      if(ptr==NULL){
        printf("\n Queue is EMPTY\n");
     }else{
          front->link=ptr->link;
          printf("\nDATA : %d DELETED\n",ptr->data);
          free(ptr);
      }
}
void display(struct node* front,struct node* rear){
    struct node* ptr=front;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        printf(" DATA : %d\n",ptr->data);
    }
}

void main(){
 int n,x,y;
 char ans='y';
 struct node* front = (struct node*)malloc(sizeof(struct node));
 struct node* rear = (struct node*)malloc(sizeof(struct node));
 front->link=NULL;
 rear->link=NULL;
 printf("\n--- OPERATION ON QUEUE --- \n\n");
 printf(" 1. INSERT \n");
 printf(" 2. DELETE \n");
 printf(" 3. DISPLAY\n");
 printf(" 4. EXIT\n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- INSERT \n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                insert(front,rear,x);
                break;
         case 2:printf("--- DELETE  ---\n");
                delete(front,rear);
                break;
         case 3:printf("--- DISPLAY ---\n");
                display(front,rear);
                break;
         case 4:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
  }
}
