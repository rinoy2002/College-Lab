#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void push(struct node* top,int x){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    if(new==NULL){
        printf("\nMEMORY Underflow\n");
    }else{
        if(top->link==NULL){
            top->link=new;
        }else{
            new->link=top->link;
            top->link=new;
            }
    }
}

void pop(struct node* top){
     struct node* ptr=top->link;
      if(ptr==NULL){
        printf("\n STACK is EMPTY\n");
     }else{
          top->link=ptr->link;
          printf("\nDATA : %d DELETED\n",ptr->data);
          free(ptr);
      }
}

void display(struct node* top){
    struct node* ptr=top;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        printf(" DATA : %d\n",ptr->data);
    }
}

void main(){
 int n,x,y;
 char ans='y';
 struct node* top = (struct node*)malloc(sizeof(struct node));
 top->link=NULL;
 printf("\n--- OPERATION ON STACK --- \n\n");
 printf(" 1. PUSH \n");
 printf(" 2. POP \n");
 printf(" 3. DISPLAY \n");
 printf(" 4. EXIT \n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- PUSH ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                push(top,x);
                break;
         case 2:printf("--- POP ---\n");
                pop(top);
                break;
         case 3:printf("--- DISPLAY ---\n");
                display(top);
                break;
         case 4:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
  }
}
