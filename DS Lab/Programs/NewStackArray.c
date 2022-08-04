#include <stdio.h>
#include <stdlib.h>
int size;
int top;
int *arr;

int isFull(){
    if(top==size-1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void push(int item){
    if(isFull()){
        printf("\nStack Overflow\n\n");
    }
    else {
        arr[++top] = item;
    }
}
void pop(){
    if(isEmpty()){
        printf("\nStack Underflow\n\n");
    }else{
        int item = arr[top];
        top--;
        printf("\nElement %d DELETED ",item);
    }
}

void display(){
    printf("\nCurrent STACK :\n");
    if(isEmpty()){
        printf("\nStack is Empty \n");
    }else{
        for(int i=top; i>-1; i--){
        printf(" %d \n",arr[i]);
        }
    }
}

void deleteOccurence(int item){
    if(isEmpty()){
        printf("\nStack Underflow\n\n");
    }else{
        int count = 0;
        int frequency=0;
         for(int i=top;i>-1;i--){
            if(arr[i]==item){
                frequency++;
            }
         }
         if(frequency>1){
             for(int i=top;i>-1;i--){
                 if(arr[i]==item){
                     for (int j=i;j<size-1;j++){
                         arr[j]=arr[j+1];
                     }
                     count++;
                     if(count==2){
                         top=top-2;
                         break;
                     }
                 }
             }
         }else if (frequency == 0){
             printf("\n Value doesn't exists \n\n");
         }else{
             printf("\n Value doesn't occur more than 1 times \n\n");
         }
    }

}

void bottomElementReturn(){
    if(isEmpty()){
        printf("\nStack Underflow\n\n");
    }else{
        int ptr = 0;
        printf("Bottom Element : %d ",arr[ptr]);
    }
}

void fifthElementReturn(){
    if(isEmpty()){
        printf("\nStack Underflow\n\n");
    }else if(top<4){
        printf("\nStack doesn't contains five elements\n\n");
    }else{
        int ptr = top;
        ptr = ptr - 4;
        printf("Fifth Element : %d ",arr[ptr]);
    }
}

void main(){
 int n,x,y;
 char ans='y';
 printf("Enter Stack size :");
 scanf("%d", &size);
 arr = (int*) malloc (size * sizeof(int));
 top=-1;
 printf("\n--- OPERATION ON STACK --- \n\n");
 printf(" 1. PUSH \n");
 printf(" 2. POP\n");
 printf(" 3. DELETE OCCURENCE OF X \n");
 printf(" 4. RETURN BOTTOM ELEMENT \n");
 printf(" 5. RETURN FIVTH ELEMENT \n");
 printf(" 6. DISPLAY\n");
 printf(" 7. EXIT\n");
 while(ans=='y'){
     printf("\nEnter the Choice (1/2/3/4/5/6/7): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- PUSH ---\n");
                printf("Enter element to be Inserted :");
                scanf("%d", &x);
                push(x);
                break;
         case 2:printf("--- POP ---\n");
                pop();
                break;
         case 3:printf("--- DELETE OCCURENCE OF X---\n");
                printf("Enter element to be Deleted :");
                scanf("%d", &x);
                deleteOccurence(x);
                break;
         case 4:printf("--- RETURN BOTTOM ELEMENT ---\n");
                bottomElementReturn();
                break;
         case 5:printf("--- RETURN FIVTH ELEMENT ---\n");
                fifthElementReturn();
                break;
         case 6:printf("--- DISPLAY ---\n");
                display();
                break;
         case 7:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
 }
}
