#include<stdio.h>
#include<stdlib.h>

 struct list{
    int *arr;
    struct list *link;
    int size;
};


void insert(msll **Header, int data, int size){
    msll *ptr = (*Header)->link;
    int flag=0;
    if((*Header)->link==NULL){
        msll node = (msll) malloc(sizeof(msll));
        node->arr = (int*)malloc(sizeof(int)*size);
        node->size = 0;
        node->arr[node->size] = data;
        (*Header) ->link = node;
    }
    else{

        while(ptr->link!=NULL){
            if(ptr -> size<size){
                flag = 1;
                break;
            }
            ptr=ptr->link;
        }
        if(flag){
            ptr->arr[ptr->size] = data;
            ptr->size=ptr->size+1;
        }
        else{
            msll node = (msll) malloc(sizeof(msll));
            node->arr = (int*)malloc(sizeof(int)*size);
            node->size = 0;
            node->arr[node->size] = data;
            ptr ->link = node;
        }
    }

}

void display(msll * Header,int size){
    msll *ptr = Header->link;
    while(ptr!=NULL){
        int i=0;
        while(i<ptr->size){
            printf("%d ",ptr->arr[i]);
            i++;
        }
        printf("\n");
        ptr = ptr->link;
    }
}

int main(){
    int n = 4;
    int m = 5;

    msll Header = (msll)malloc(sizeof(msll));
    insert(&Header,4,m);
    insert(&Header,4,m);
    insert(&Header,4,m);
    insert(&Header,4,m);
    insert(&Header,4,m);

    display(Header,m);
}