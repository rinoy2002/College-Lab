#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *st){
    if(st->top >= st->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *st){
    if(st->top == -1){
        return 1;
    }
    return 0;
}

void push(struct stack *st,int pushitem){
    if(isFull(st)){
        printf("\nStack Overflow\n\n");
    }
    else{
        st->arr[++st->top] = pushitem;
    }
}
void pop(struct stack *st){
    if(isEmpty(st)){
        printf("\nStack Underflow\n\n");
    }
    else{
        int popitem = st->arr[st->top];
        st->top--;
        printf("\nElement %d POPED ",popitem);
    }
}

void display(struct stack *st){
    printf("\nCURRENT STACK:\n");
    for(int i=st->top; i>=0; i--){
        printf("%d\n", st->arr[i]);
        printf("\n");
    }
}

void main(){
 struct stack st;
 int n,x,y;
 char ans='y';
 printf("Enter stack size :");
 scanf("%d", &st.size);
 st.arr = (int*) malloc (st.size * sizeof(int));
 st.top = -1;
 while(ans=='y'){
     printf("\n--- OPERATION ON STACK --- \n\n");
     printf(" 1. PUSH \n");
     printf(" 2. POP\n");
     printf(" 3. DISPLAY\n");
     printf(" 4. EXIT\n");
     printf("Enter the Choice (1/2/3/4): ");
     scanf("%d",&n);
     switch(n){
         case 1:printf("--- PUSH ---\n");
                printf("\nEnter element to be PUSHED :");
                scanf("%d", &x);
                push(&st,x);
                break;
         case 2:printf("--- POP ---\n");
                pop(&st);
                break;
         case 3:printf("--- DISPLAY ---\n");
                display(&st);
                break;
         case 4:ans='n';
                break;
        default:printf("Enter a Valid Input\n");
     }
 }
}
