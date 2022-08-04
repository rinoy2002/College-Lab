#include<stdio.h>
#include<stdlib.h>

struct node{
    int *data;
    int size;
    struct node *link;
};

void createLinkedList(int *arr ,int start,int end,int size ,struct node* header){
    struct node* ptr=header;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=malloc(size*sizeof(int));
    int i=0,j;
    for(j=start;j<=end;j++){
         new->data[i]=arr[j];
         i++;
    }
    new->size = i;
    new->link = NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=new;
}

void sort_array(struct node* header){
    struct node* ptr=header->link;
    while(ptr!=NULL){
        for(int i=0;i<ptr->size;i++){
            for(int j=0;j<ptr->size-1;j++){
                if(ptr->data[j]>ptr->data[j+1]){
                    int temp = ptr->data[j];
                    ptr->data[j]=ptr->data[j+1];
                    ptr->data[j+1]=temp;
                }
            }
        }
        ptr=ptr->link;
    }
}
void sort_node(struct node* header){
    struct node* ptr1=header->link;
    struct node* ptr2=ptr1->link;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->data[0]>ptr2->data[0]){
            for(int i=0;i<ptr1->size;i++){
                int temp = ptr1->data[i];
                ptr1->data[i]=ptr2->data[i];
                ptr2->data[i]=temp;
            }
            int temp1=ptr1->size;
            ptr1->size=ptr2->size;
            ptr2->size=temp1;
        }
        ptr1=ptr1->link;
        ptr2=ptr2->link;
    }
}

void display(struct node* header){
    struct node* ptr=header->link;
    while(ptr!=NULL){
        for(int i=0;i<ptr->size;i++){
           printf(" %d ",ptr->data[i]);
        }
        if(ptr->link!=NULL){
            printf(" --->  ");
        }
        ptr=ptr->link;
    }
}

void main(){
 int n,m;
 struct node* header = (struct node*)malloc(sizeof(struct node));
 header->link=NULL;
 printf("\n Enter the value of n :");
 scanf("%d",&n);
 printf("\n Enter the value of m :");
 scanf("%d",&m);
 int arr[n];
 printf("\n Enter the Element  :");
 for(int i=0;i<n;i++){
     scanf("%d", &arr[i]);
 }
 for(int i=0;i<n;i=i+m){
    if(i+m-1<n){
        createLinkedList(arr,i,i+m-1,m,header);
    }else{
        createLinkedList(arr,i,n-1,m,header);
    }
 }
  display(header);
  sort_array(header);
  printf("\n");
  display(header);
  sort_node(header);
  printf("\n");
  display(header);
}
