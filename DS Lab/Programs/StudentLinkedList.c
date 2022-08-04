#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int rollno;
    char name[50];
    float marks;
    struct node *link;
};

void insert(struct node* header){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Roll No. : ");
    scanf("%d",&new->rollno);
    printf("Enter the Name : ");
    scanf("%s",new->name);
    printf("Enter the Marks : ");
    scanf("%f",&new->marks);
    new->link=NULL;
    if(new==NULL){
        printf("\nMemory Underflow\n");
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

void delete(struct node* header,int key){
     struct node* ptr1=header;
     struct node* ptr=ptr1->link;
     if(ptr==NULL){
        printf("\n List is Empty\n");
     }else{
        while(ptr->rollno!=key && ptr->link!=NULL){
            ptr1=ptr;
            ptr=ptr->link;
         }
      if(ptr->rollno==key){
         ptr1->link=ptr->link;
         printf("\n--- DELETED ---\n\n");
         printf(" Roll No.    : %d\n",ptr->rollno);
         printf(" Name        : %s\n",ptr->name);
         printf(" Total Marks : %f\n",ptr->marks);
         free(ptr);
      }else{
          printf("\nRoll No. Not Found\n");
      }
     }
}

void search(struct node* header,int key){
    struct node* ptr=header->link;
    if(ptr==NULL){
        printf("\n List is Empty\n");
    }else{
        while(ptr->rollno!=key && ptr->link!=NULL){
            ptr=ptr->link;
        }
        if(ptr->rollno==key){
         printf("\n--- SEARCH ---\n\n");
         printf(" Roll No.    : %d\n",ptr->rollno);
         printf(" Name        : %s\n",ptr->name);
         printf(" Total Marks : %f\n",ptr->marks);
        }else{
          printf("\nRoll No. Not Found\n");
        }
    }
}
void sort(struct node* header){
    struct node* ptr=header->link;
    struct node* ptr1=header->link;
    int rollno;
    char name[50];
    float marks;
    if(ptr==NULL){
        printf("\n List is Empty\n");
    }else if(ptr->link==NULL){
        printf("\n List has only One Element\n");
    }else{
        while(ptr1->link!=NULL){
            ptr=header->link;
            while(ptr->link!=NULL){
                if(ptr->rollno > ptr->link->rollno){
                    rollno=ptr->rollno;
                    strcpy(name,ptr->name);
                    marks=ptr->marks;
                    ptr->rollno=ptr->link->rollno;
                    strcpy(ptr->name,ptr->link->name);
                    ptr->marks=ptr->link->marks;
                    ptr->link->rollno=rollno;
                    strcpy(ptr->link->name,name);
                    ptr->link->marks=marks;
                }
                ptr=ptr->link;
            }
            ptr1=ptr1->link;
        }
        printf("\n List has been Sorted\n");
    }
}
void display(struct node* header){
    printf("\n");
    struct node* ptr=header;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        printf(" Roll No.    : %d\n",ptr->rollno);
        printf(" Name        : %s\n",ptr->name);
        printf(" Total Marks : %f\n\n",ptr->marks);
    }
}

void main(){
 int n,x,y,key;
 char ans='y';
 struct node* header = (struct node*)malloc(sizeof(struct node));
 header->link=NULL;
 printf("\n--- STUDENT LINKED LIST --- \n\n");
 printf(" 1. INSERT  \n");
 printf(" 2. DELETE \n");
 printf(" 3. SEARCH \n");
 printf(" 4. SORT \n");
 printf(" 5. DISPLAY\n");
 printf(" 6. EXIT\n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4/5/6): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- INSERT ---\n");
                insert(header);
                break;
         case 2:printf("--- DELETE ---\n");
                printf("Enter the Roll No. to be Deleted:");
                scanf("%d", &key);
                delete(header,key);
                break;
         case 3:printf("--- SEARCH ---\n");
                printf("Enter the Roll No. to be Searched :");
                scanf("%d", &key);
                search(header,key);
                break;
         case 4:printf("--- SORT ---\n");
                sort(header);
                break;
         case 5:printf("--- DISPLAY ---\n");
                display(header);
                break;
         case 6:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
  }
}
