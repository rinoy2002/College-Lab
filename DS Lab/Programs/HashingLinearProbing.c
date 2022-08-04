#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void insert(int hash_table[],int value,int size){
    int index = value%size;
    if(hash_table[index]==(int)INFINITY){
        hash_table[index]=value;
    }else{
        for(int i= index+1;i<size;i++){
            if(hash_table[i]==(int)INFINITY){
                hash_table[i]=value;
                return;
            }
        }
        for(int i=0;i<index;i++){
            if(hash_table[i]==(int)INFINITY){
                hash_table[i]=value;
                return;
            }
        }
        printf("\n Hash Table is FULL \n");
    }
}
void display(int hash_table[],int size){

    for(int i=0;i<size;i++){
        if(hash_table[i]==(int)INFINITY){
            printf(" [%d] -> EMPTY ",i);
        }else{
            printf(" [%d] -> %d ",i,hash_table[i]);
        }
        printf("\n");
    }

}
void main(){
    int ans=1,op,value,i,size;
    printf(" Enter the size of Hash Table : ");
    scanf("%d",&size);
    int hash_table[size];
    for(i=0;i<size;i++){
        hash_table[i]=(int)INFINITY;
    }
    printf("\n --- HASHING USING LINEAR PROBING --- \n\n");
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
                     insert(hash_table,value,size);
                     break;
            case 2 : printf("\n --- DISPLAY ---\n\n");
                     display(hash_table,size);
                     break;
            case 3 : ans=0;
                     break;
            default : printf("\n Enter a Valid Input \n");
        }
    }
}