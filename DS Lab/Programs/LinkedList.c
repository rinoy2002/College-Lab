#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void insert_front(struct node* header,int x){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    if(new==NULL){
        printf("\nMEMORY Underflow\n");
    }else{
        if(header->link==NULL){
            header->link=new;
        }else{
            new->link=header->link;
            header->link=new;
            }
    }
}

void insert_rear(struct node* header,int x){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    if(new==NULL){
        printf("\nMEMORY Underflow\n");
    }else{
        if(header->link==NULL){
            header->link=new;
        }else{
            struct node* ptr=header;
            while(ptr->link!=NULL){
                ptr=ptr->link;
            }
            ptr->link=new;
        }
    }
}
void insert_any(struct node* header,int x,int key){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    if(new==NULL){
        printf("\nMEMORY Underflow\n");
    }else{
        if(header->link==NULL){
            printf("KEY Not Found\n");
        }else{
            struct node* ptr=header;
            while(ptr->data!=key && ptr->link!=NULL){
                ptr=ptr->link;
            }
            if(ptr->data==key){
                new->link=ptr->link;
                ptr->link=new;
            }else{
                printf("KEY Not Found\n");
            }

        }
    }
}
void delete_front(struct node* header){
     struct node* ptr=header->link;
      if(ptr==NULL){
        printf("\n List is EMPTY\n");
     }else{
          header->link=ptr->link;
          printf("\nDATA : %d DELETED\n",ptr->data);
          free(ptr);
      }
}
void delete_rear(struct node* header){

     struct node* ptr=header;
     struct node* ptr1;
      if(ptr->link==NULL){
        printf("\n List is EMPTY\n");
      }else{
           while(ptr->link!=NULL){
                ptr1=ptr;
                ptr=ptr->link;
            }
          ptr1->link=NULL;
          printf("\nDATA : %d DELETED\n",ptr->data);
          free(ptr);
      }
}
void delete_any(struct node* header,int key){
     struct node* ptr1=header;
     struct node* ptr=ptr1->link;
     if(ptr==NULL){
        printf("\n List is EMPTY\n");
     }else{
        while(ptr->data!=key && ptr->link!=NULL){
            ptr1=ptr;
            ptr=ptr->link;
         }
      if(ptr->data==key){
         ptr1->link=ptr->link;
         printf("\nDATA : %d DELETED\n",ptr->data);
         free(ptr);
      }else{
          printf("\nKEY Not Found\n");
      }
     }
}
void display(struct node* header){
    struct node* ptr=header;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        printf(" DATA : %d\n",ptr->data);
    }
}

void main(){
 int n,x,y,key;
 char ans='y';
 struct node* header = (struct node*)malloc(sizeof(struct node));
 header->link=NULL;
 printf("\n--- OPERATION ON LINKED LIST --- \n\n");
 printf(" 1. INSERT FRONT \n");
 printf(" 2. INSERT REAR \n");
 printf(" 3. INSERT ANY \n");
 printf(" 4. DELETE FRONT \n");
 printf(" 5. DELETE REAR \n");
 printf(" 6. DELETE ANY \n");
 printf(" 7. DISPLAY\n");
 printf(" 8. EXIT\n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4/5/6/7/8): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- INSERT FRONT ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                insert_front(header,x);
                break;
         case 2:printf("--- INSERT REAR ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                insert_rear(header,x);
                break;
         case 3:printf("--- INSERT ANY ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                printf("Enter KEY value :");
                scanf("%d", &key);
                insert_any(header,x,key);
                break;
         case 4:printf("--- DELETE FRONT ---\n");
                delete_front(header);
                break;
         case 5:printf("--- DELETE REAR ---\n");
                delete_rear(header);
                break;
         case 6:printf("--- DELETE ANY ---\n");
                printf("Enter KEY value to be DELETED:");
                scanf("%d", &key);
                delete_any(header,key);
                break;
         case 7:printf("--- DISPLAY ---\n");
                display(header);
                break;
         case 8:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
  }
}
