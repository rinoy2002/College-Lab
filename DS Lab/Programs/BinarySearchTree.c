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

void preorder_traversal(struct node* root){
    struct node* ptr;
    ptr = root;
    if(ptr!=NULL){
        printf("%d  ",ptr->data);
        preorder_traversal(ptr->lchild);
        preorder_traversal(ptr->rchild);
    }
}

void postorder_traversal(struct node* root){
    struct node* ptr;
    ptr = root;
    if(ptr!=NULL){
        postorder_traversal(ptr->lchild);
        postorder_traversal(ptr->rchild);
        printf("%d  ",ptr->data);
    }
}

struct node* successor(struct node* ptr){
    struct node* ptr1;
    ptr1=ptr->rchild;
    if(ptr1!=NULL){
        while(ptr1->lchild!=NULL){
            ptr1=ptr1->lchild;
        }
    }
    return(ptr1);
}

void Delete(struct node* root,int item){
    struct node* ptr=root;
    struct node* ptr1;
    struct node* parent=NULL;
    int flag=0,temp;
    while(ptr!=NULL && flag == 0){
        if(item<ptr->data){
            parent=ptr;
            ptr=ptr->lchild;
        }else if(item>ptr->data){
            parent=ptr;
            ptr=ptr->rchild;
        }else{
            flag=1;
        }
    }
    if(flag==0){
         printf(" \nITEM doesn't exists\n");
    }else{
       if(ptr->lchild==NULL && ptr->rchild==NULL){
            if(parent->lchild==ptr){
                parent->lchild=NULL;
            }
            if(parent->rchild==ptr){
                parent->rchild=NULL;
            }
            free(ptr);
        }else if(ptr->lchild!=NULL && ptr->rchild!=NULL){
            ptr1 = successor(ptr);
            temp =ptr1->data;
            Delete(root,temp);
            ptr->data=temp;
            free(ptr1);
        }else{
            if(parent->lchild==ptr){
                if(ptr->lchild==NULL){
                    parent->lchild=ptr->rchild;
                }else{
                    parent->lchild=ptr->lchild;
                }
            }else if(parent->rchild==ptr){
                if(ptr->lchild==NULL){
                    parent->rchild=ptr->rchild;
                }else{
                    parent->rchild=ptr->lchild;
                }
            }
            free(ptr);
        }
    }
}

int no_of_leaf_nodes(struct node* root){
    struct node* ptr;
    ptr = root;
    if(ptr == NULL){
        return 0;
    }else if(ptr->lchild == NULL && ptr->rchild == NULL){
        return 1;
    }else{
        return no_of_leaf_nodes(ptr->lchild)+no_of_leaf_nodes(ptr->rchild);
    }
}

void main(){
 int n,item,var=0;
 char ans='y';
 struct node* root = NULL;
 printf("\n--- OPERATION ON BINARY SEARCH TREE --- \n\n");
 printf(" 1. INSERT \n");
 printf(" 2. INORDER TRAVERSAL\n");
 printf(" 3. PREORDER TRAVERSAL\n");
 printf(" 4. POSTORDER TRAVERSAL\n");
 printf(" 5. DELETE \n");
 printf(" 6. NO. OF LEAF NODES \n");
 printf(" 7. EXIT \n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4/5/6/7): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- INSERT ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &item);
                if(root==NULL){
                    root = (struct node*)malloc(sizeof(struct node));
                    root->lchild=NULL;
                    root->rchild=NULL;
                    root->data=item;
                }else{
                    Insert(root,item);
                }
                var++;
                break;
         case 2:printf("--- INORDER TRAVERSAL ---\n\n");
                if(root!=NULL){
                    inorder_traversal(root);
                }else{
                    printf("\n Tree is empty \n");
                }
                break;
         case 3:printf("--- PREORDER TRAVERSAL ---\n\n");
                if(root!=NULL){
                    preorder_traversal(root);
                }else{
                    printf("\n Tree is empty \n");
                }
                break;
         case 4:printf("--- POSTORDER TRAVERSAL ---\n\n");
                if(root!=NULL){
                    postorder_traversal(root);
                }else{
                    printf("\n Tree is empty \n");
                }
                break;
         case 5:printf("--- DELETE ---\n");
                if(root!=NULL){
                    printf("Enter the element to be deleted :");
                    scanf("%d", &item);
                    if(root->data==item && root->lchild==NULL && root->rchild == NULL){
                        root = NULL;
                    }else if(root->data==item && root->lchild==NULL){
                        root=root->rchild;
                    }else if(root->data==item && root->rchild==NULL){
                        root=root->lchild;
                    }else{
                         Delete(root,item);
                    }
                }else{
                    printf("\n Tree is empty \n");
                }
                break;
         case 6:printf("--- NO. OF LEAF NODES ---\n");
                printf("\nLeaf count of the binary search tree is : %d\n",no_of_leaf_nodes(root));
                break;
         case 7:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
  }
}
