#include<stdio.h>
#include<stdlib.h>
struct node {
    int value;
    struct node *link;
};
void insert(struct node hash_table[],int value){
    int index = value%10;
    struct node *ptr = hash_table;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    new->value = value;
    ptr=ptr+index;
    if(ptr->link==NULL){
        ptr->link=new;
    }else{
        while(ptr->link != NULL){
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}
void display(struct node hash_table[]){
    struct node *ptr = hash_table;
    for(int i=0;i<10;i++){
        if(ptr->link==NULL){
            printf(" [%d] -> EMPTY ",i);
        }else{
            printf(" [%d] ",i);
            struct node *ptr1=ptr;
            while(ptr1->link!=NULL){
                ptr1=ptr1->link;
                printf("-> %d ",ptr1->value);
            }
        }
        printf("\n");
        ptr++;
    }

}
void main(){
    int ans=1,op,value,i;
    struct node hash_table[10];
    for(i=0;i<10;i++){
      hash_table[i].link=NULL;
    }
    printf("\n --- HASHING USING CHAINING --- \n\n");
    printf("    1. INSERT \n");
    printf("    2. DISPLAY \n");
    printf("    3. EXIT \n\n");
    while(ans==1){
        printf(" Enter your choice : ");
        scanf("%d",&op);
        switch(op){
            case 1 : printf("\n --- INSERT ---\n\n");
                     printf("Enter the Value : ");
                     scanf("%d",&value);
                     insert(hash_table,value);
                     break;
            case 2 : printf("\n --- DISPLAY ---\n\n");
                     display(hash_table);
                     break;
            case 3 : ans=0;
                     break;
            default : printf("\n Enter a Valid Input \n");
        }
    }
}