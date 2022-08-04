#include<stdio.h>
void main(){
    int a[2][10],b[2][10],c[2][10],i,j,k,t1,t2;
    printf("Enter the No. of Terms in Polynomial 1 : ");
    scanf("%d",&t1);
    for(i=0;i<t1;i++){
        printf("Exponent : ");
        scanf("%d",&a[0][i]);
        printf("Coefficient for Exponent : ");
        scanf("%d",&a[1][i]);
    }
    printf("\nEnter the No. of Terms in Polynomial 2 : ");
    scanf("%d",&t2);
    for(i=0;i<t2;i++){
        printf("Exponent : ");
        scanf("%d",&b[0][i]);
        printf("Coefficient for Exponent : ");
        scanf("%d",&b[1][i]);
    }
    i=0;j=0;k=0;
    while(i<t1 || j<t2){
        if (i>=t1){
            c[0][k] = b[0][j];
            c[1][k] = b[1][j];
            j++, k++;
        }
        else if (j>=t2){
            c[0][k] = a[0][j];
            c[1][k] = a[1][j];
            i++, k++;
        }
        else if (a[0][i]==b[0][j]){
            c[0][k]=a[0][i];
            c[1][k]=a[1][i]+b[1][j];
            i++, j++, k++;
        }
        else if(a[0][i]>b[0][j]){
            c[0][k]=a[0][i];
            c[1][k]=a[1][i];
            i++;
            k++;
        }
        else{
            c[0][k]=b[0][j];
            c[1][k]=b[1][j];
            k++;
            j++;
        }
    }
   printf("\nResultant Polynomial :\n\n");
    for(i=0;i<k;i++){
        printf("(%dx^%d)",c[1][i],c[0][i]);
        if(i!=k-1)
        printf("+");
    }
}





