#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

char stack[50];
int top = -1;
void push(char x){
    stack[++top] = x;
}

char pop(){
     if(top == -1)
         return -1;
     else
        return stack[top--];
}

int Istack[50];
int Itop = -1;

void Ipush(int x){
    Istack[++Itop] = x;
}

int Ipop(){
    if(Itop == -1)
        return 0;
    else
        return Istack[Itop--];
}

int ISP(char y){
    if(y == '(')
         return 0;
    if(y == '+' || y == '-')
         return 1;
    if(y == '*' || y == '/')
         return 4;
    if(y =='^')
         return 5;
    return 0;
}
int ICP(char y){
    if(y == '(')
        return 0;
    if(y == '+' || y == '-')
        return 1;
    if(y == '*' || y == '/')
        return 3;
    if(y =='^')
        return 6;
    return 0;
}

void main()
{
    char input[100];
    char postfix[100];
    char *p,*t,x;
    char ans[5]="no";
    // INFIX TO POSTFIX CONVERSION

    printf("NOTE : Please Enter Only Single Digit Numbers !\n");
    printf("Enter the Arithematic expression [Please end with \')\']: ");
    scanf("%s",input);
    printf("\n");
    p=input;
    t=postfix;
    push('(');
    printf(" INFIX   : (%s",input);
    printf("\n POSTFIX : ");
    while(top!=-1){
        if(isalnum(*p)){

            printf("%c",*p);
            *t=*p;
            t++;

        }else{
            x=pop();
            if(*p == '('){

                push(*p);

            }else if(*p == ')'){

            while( x!= '('){
                printf("%c",x);
                *t=x;
                t++;
                x=pop();
                }

            }else if(ISP(x)>= ICP(*p)){

            while(ISP(x)>=ICP(*p)){
                printf("%c",x);
                *t=x;
                t++;
                x=pop();
                }
            push(x);
            push(*p);

        }else if(ISP(x) < ICP(*p)){
            push(x);
            push(*p);

        }else{

            printf("Invalid Expression");

        }
        }

        p++;

    }


    *t='\0';
  printf("\n");


  // POSTFIX EVALUATION
     printf(" If you want to Evalute the Expression [yes/no] : ");
     scanf("%s",ans);
     if(strcmp(ans,"yes")==0){
        t = postfix;
        int a,b,c;
        while(*t!='\0'){
            if(isdigit(*t)){
                Ipush(*t-48);
            }else{
                b= Ipop();
                a= Ipop();
                switch(*t)
                {
                    case '+': c=a+b;

                          break;


                    case '-': c=a-b;

                          break;

                    case '*': c=a*b;

                          break;

                    case '/': c=a/b;

                          break;

                    case '^': c=pow(a,b);

                          break;
            }

            Ipush(c);
        }
        t++;
    }
    int result=Ipop();
    printf("\n RESULT  : %d",result);
     }
}