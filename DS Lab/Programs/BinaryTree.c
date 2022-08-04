#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};

void build_tree(struct node* ptr){
    int item ,ans;
    if(ptr!=NULL){
        printf("Enter the element :");
        scanf("%d", &item);
        ptr->data=item;
        printf("Whether Node{data = %d} has left Subtree (Yes[1]/No[0]) : ",ptr->data);
        scanf("%d", &ans);
        struct node* lcptr = (struct node*)malloc(sizeof(struct node));
        if(ans==1){
            ptr->lchild=lcptr;
            build_tree(lcptr);
        }else{
            lcptr=NULL;
            ptr->lchild=NULL;
            build_tree(lcptr);
        }
        printf("Whether Node{data = %d} has right Subtree (Yes[1]/No[0]) : ",ptr->data);
        scanf("%d", &ans);
        struct node* rcptr = (struct node*)malloc(sizeof(struct node));
        if(ans==1){
            ptr->rchild=rcptr;
            build_tree(rcptr);
        }else{
            rcptr=NULL;
            ptr->rchild=NULL;
            build_tree(rcptr);
        }
    }
}

struct node * search_link(struct node* root ,int key){
	struct node* ptr = root;
    struct node* ptr1;
	if(ptr->data != key){
	    if(ptr->lchild!=NULL){
			ptr1 = search_link(ptr->lchild, key);
			    if(ptr1 != NULL){
			        return ptr1;
				}
		}
		if(ptr->rchild!=NULL){
			ptr1 = search_link(ptr->rchild, key);
			   if(ptr1 != NULL){
			        return ptr1;
				}
		}
		return NULL;
	}
	else{
		return ptr;
	}
}

void insert_tree(struct node* root,int key){
    struct node* ptr;
    int item,ans;
    printf("Enter element to be Inserted :");
    scanf("%d", &item);
    ptr=search_link(root,key);
    if(ptr==NULL){
        printf("\n Search Unsucessful \n");
    }else{
        if((ptr->lchild==NULL)||(ptr->rchild==NULL)){
            printf("Insert as left or right child (left[1]/right[0]) : ");
            scanf("%d", &ans);
            if(ans==1){
                if(ptr->lchild==NULL){
                    struct node* new = (struct node*)malloc(sizeof(struct node));
                    new->data=item;
                    new->lchild=NULL;
                    new->rchild=NULL;
                    ptr->lchild=new;
                }else{
                     printf("\n Insertion not possible as left child \n");
                }
            }
            if(ans==0){
                if(ptr->rchild==NULL){
                    struct node* new = (struct node*)malloc(sizeof(struct node));
                    new->data=item;
                    new->lchild=NULL;
                    new->rchild=NULL;
                    ptr->rchild=new;
                }else{
                     printf("\n Insertion not possible as right child \n");
                }

            }
        }
        else{
            printf("\n Insertion not possible Key Node has left and right child \n");
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

struct node* search_parent(struct node* ptr ,struct node* parent,int item){
	if(ptr->data != item){
	    if(ptr->lchild != NULL){
			parent = search_parent(ptr->lchild,ptr,item);
			if(parent != NULL)
				return parent;
		}
		if(ptr->rchild != NULL)
		{
			parent = search_parent(ptr->rchild,ptr,item);
			if(parent != NULL)
				return parent;
		}
		return NULL;
	}
	else
		return parent;
}


void delete_tree(struct node* root,int item){
    struct node* parent;
    struct node* ptr;
    struct node* ptr1;
    struct node* ptr2;
    ptr=root;
    if(ptr==NULL){
        printf("\n Tree is Empty\n");
    }else if(root->data == item ){
        if(root->lchild==NULL && root->rchild == NULL){
            root=NULL;
        }
        else{
            printf("\n Node is not a leaf Node\n");
        }
    }else{
        parent = search_parent(root,root,item);
        if(parent!=NULL){
            ptr1 = parent->lchild;
            ptr2 = parent->rchild;
            if(ptr1->data==item){
                if((ptr1->lchild==NULL)&&(ptr1->rchild==NULL)){
                    parent->lchild=NULL;
                }else{
                    printf("\n Node is not a leaf Node\n");
                }
            }
            if(ptr2->data==item){
                if((ptr2->lchild==NULL)&&(ptr2->rchild==NULL)){
                    parent->rchild=NULL;
                }else{
                    printf("\n Node is not a leaf Node\n");
                }
            }
        }else{
            printf("\n Node with data item doesn't exists\n");
        }
    }
}

void main(){
 int n,item,key;
 char ans='y';
 struct node* root = (struct node*)malloc(sizeof(struct node));
 root->lchild=NULL;
 root->rchild=NULL;
 printf("\n--- BUILD BINARY TREE --- \n\n");
 build_tree(root);
 printf("\n--- OPERATION ON BINARY TREE --- \n\n");
 printf(" 1. INSERT \n");
 printf(" 2. INORDER TRAVERSAL\n");
 printf(" 3. PREORDER TRAVERSAL\n");
 printf(" 4. POSTORDER TRAVERSAL\n");
 printf(" 5. DELETE \n");
 printf(" 6. EXIT \n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4/5/6): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- INSERT ---\n");
                if(root == NULL){
                     printf("\n Tree is empty \n\n");
                     printf("Enter element to be Inserted :");
                     scanf("%d", &item);
                     root = (struct node*)malloc(sizeof(struct node));
                     root->lchild=NULL;
                     root->rchild=NULL;
                     root->data=item;
                }else{
                    printf("Enter the Key Node  :");
                    scanf("%d", &key);
                    insert_tree(root,key);
                }
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
                    }else if(root->data==item){
                        printf("\n Node is not a leaf Node\n");
                    }else{
                        delete_tree(root,item);
                    }
                }else{
                    printf("\n Tree is empty \n");
                }
                break;
         case 6:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
  }
}
