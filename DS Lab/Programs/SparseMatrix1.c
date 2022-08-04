#include<stdio.h>
int a[10][10],b[10][10],sa[50][3],sb[50][3],tsa[50][3],tsb[50][3];
int i,j,col1,col2,row1,row2,count1=0,count2=0;
void tupletransform(){
    int k=1,l=1;
    tsa[0][0]=sa[0][1];
    tsa[0][1]=sa[0][0];
    tsa[0][2]=sa[0][2];
    tsb[0][0]=sb[0][1];
    tsb[0][1]=sb[0][0];
    tsb[0][2]=sb[0][2];
    for(i=0;i<sa[0][1];i++){
        for(j=1;j<=sa[0][2];j++){
            if(i==sa[j][1]){
                tsa[k][0]=sa[j][1];
                tsa[k][1]=sa[j][0];
                tsa[k][2]=sa[j][2];
                k++;
            }
        }
    }
    for(i=0;i<sb[0][1];i++){
        for(j=1;j<=sb[0][2];j++){
            if(i==sb[j][1]){
                tsb[l][0]=sb[j][1];
                tsb[l][1]=sb[j][0];
                tsb[l][2]=sb[j][2];
                l++;
            }
        }
    }
    printf("\nTranspose of Sparse Matrix 1 : \n\n");
    for(i=0;i<=sa[0][2];i++){
        printf("%d  ",tsa[i][0]);
        printf("%d  ",tsa[i][1]);
        printf("%d  \n",tsa[i][2]);
    }
    printf("\n\nTranspose of Sparse Matrix 2 : \n\n");
    for(i=0;i<=sb[0][2];i++){
        printf("%d  ",tsb[i][0]);
        printf("%d  ",tsb[i][1]);
        printf("%d  \n",tsb[i][2]);
    }
}
void matrixtupleform(){
    int k=1,l=1;
    sa[0][0]=row1;sa[0][1]=col1;
    sb[0][0]=row2;sb[0][1]=col2;
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            if(a[i][j]!=0){
                sa[k][0]=i;
                sa[k][1]=j;
                sa[k][2]=a[i][j];
                k++;
            }
        }
    }
    sa[0][2]=k-1;
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++){
            if(b[i][j]!=0){
                sb[l][0]=i;
                sb[l][1]=j;
                sb[l][2]=b[i][j];
                l++;
            }
        }
    }
    sb[0][2]=l-1;
    printf("\nTuple Representation Matrix 1 : \n\n");
    for(i=0;i<k;i++){
        printf("%d  ",sa[i][0]);
        printf("%d  ",sa[i][1]);
        printf("%d  \n",sa[i][2]);
    }
    printf("\n\nTuple Representation Matrix 2 : \n\n");
    for(i=0;i<l;i++){
        printf("%d  ",sb[i][0]);
        printf("%d  ",sb[i][1]);
        printf("%d  \n",sb[i][2]);
    }
}

void main(){
    printf("Enter the No. of Rows in Matrix 1 : ");
    scanf("%d",&row1);
    printf("Enter the No. of Coloumn in Matrix 1 : ");
    scanf("%d",&col1);
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){
                count1++;
            }
        }
    }
    printf("Enter the No. of Rows in Matrix 2 : ");
    scanf("%d",&row2);
    printf("Enter the No. of Coloumn in Matrix 2 : ");
    scanf("%d",&col2);
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++){
            scanf("%d",&b[i][j]);
            if(b[i][j]!=0){
                count2++;
            }
        }
    }
    matrixtupleform();
    tupletransform();
}