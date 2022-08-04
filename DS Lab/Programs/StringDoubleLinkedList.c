#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node *rlink;
    struct node *llink;
};

void insert(struct node* front,struct node* rear,char x){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->rlink=NULL;
    new->llink=NULL;
    if(new==NULL){
        printf("\nMEMORY Underflow\n");
    }else{
        if(front->rlink==NULL){
            front->rlink=new;
            new->llink=front;
            rear->llink=new;
            new->rlink=rear;
        }else{
            new->llink=rear->llink;
            rear->llink->rlink=new;
            new->rlink=rear;
            rear->llink=new;
        }
    }
}


int check_palindrome(struct node* front,struct node* rear){
    struct node* ptr1=front;
    struct node* ptr2=rear;
    while(ptr1!=ptr2){
        if(ptr1->data!=ptr2->data){
            return 0;
        }
        ptr1=ptr1->rlink;
        ptr2=ptr2->llink;
    }
    return 1;
}

void main(){
 char string[50],*arr;
 struct node* front = (struct node*)malloc(sizeof(struct node));
 struct node* rear = (struct node*)malloc(sizeof(struct node));
 front->rlink=NULL;
 front->llink=NULL;
 rear->rlink=NULL;
 rear->llink=NULL;
 printf("\n---- PALINDROME CHECKER ----\n");
 printf("\nEnter the String : ");
 scanf("%s",string);
 arr=string;
    while(*arr!='\0'){
     insert(front,rear,*arr);
     arr++;
    }
 if(check_palindrome(front,rear)){
     printf("\n%s is a PALINDROME \n",string);
 }else{
     printf("\n%s is a NOT A PALINDROME \n",string);
 }
 }










