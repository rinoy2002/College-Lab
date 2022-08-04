#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};


void Insert(struct node* root,int item){
    struct node* ptr=root;
    struct node* ptr1;
    int flag=0;
    while(ptr!=NULL && flag == 0){
        if(item<ptr->data){
            ptr1=ptr;
            ptr=ptr->lchild;
        }else if(item>ptr->data){
            ptr1=ptr;
            ptr=ptr->rchild;
        }else{
            flag=1;
            printf("\n ITEM already exists \n ");
        }
    }
    if(ptr==NULL){
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->data=item;
        new->lchild=NULL;
        new->rchild=NULL;
        if(ptr1->data<item){
            ptr1->rchild=new;
        }
        if(ptr1->data>item){
            ptr1->lchild=new;
        }
    }
}

void inorder_traversal(struct node* root){
    struct node* ptr;
    ptr = root;
    if(ptr!=NULL){
        inorder_traversal(ptr->lchild);
        printf("%d  ",ptr->data);
        inorder_traversal(ptr->rchild);
    }
}


void main(){
 int n,i;
 struct node* root = (struct node*)malloc(sizeof(struct node));
 root->lchild=NULL;
 root->rchild=NULL;
 printf("Enter the count : ");
 scanf("%d", &n);
 if(n>0){
      int* arr = (int*)malloc(sizeof(int)*n);
      for(i=0;i<n;i++){
          printf("Enter the number :");
          scanf("%d",&arr[i]);
      }
      root->data=arr[0];
      for(i=1;i<n;i++){
          Insert(root,arr[i]);
      }
      printf("\n\n--- SORTED NUMBERS ---\n\n");
      inorder_traversal(root);
      printf("\n");
 }else{
      printf("\n Please Enter valid count ");
  }
}
