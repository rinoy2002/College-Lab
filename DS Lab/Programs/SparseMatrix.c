#include <stdio.h>
struct sparse{
    int row, col;
    int arr[10][10];
    int sarr[50][3];
    int tarr[50][3];
};


void read(struct sparse *sp){
 printf("Enter No. of Rows of Matrix :");
 scanf("%d", &sp->row);
 printf("Enter No. of Coloumn of Matrix :");
 scanf("%d",&sp->col);
 printf("Enter the Elements of Matrix :\n");
 for(int i=0;i<sp->row;i++){
     for(int j=0;j<sp->col;j++){
         scanf("%d", &sp->arr[i][j]);
     }
 }
}

void tupleRepresentation(struct sparse *sp){
 int k=0;
 sp->sarr[0][0] = sp->row;
 sp->sarr[0][1] = sp->col;
 for(int i=0;i<sp->row;i++){
     for(int j=0;j<sp->col;j++){
         if(sp->arr[i][j] != 0){
            k++;
            sp->sarr[k][0] = i;
            sp->sarr[k][1] = j;
            sp->sarr[k][2] = sp->arr[i][j];
         }
     }
 }
 sp->sarr[0][2] = k;
 for(int i=0;i<=sp->sarr[0][2];i++) {
     printf("%d ", sp->sarr[i][0]);
     printf("%d ", sp->sarr[i][1]);
     printf("%d \n", sp->sarr[i][2]);
 }
}



void transpose(struct sparse *sp){

 if(sp->sarr[0][2] == 0){
    printf("Matrix Cannot be Transposed\n");
 }
 else{
    sp->tarr[0][0] = sp->sarr[0][1];
    sp->tarr[0][1] = sp->sarr[0][0];
    sp->tarr[0][2] = sp->sarr[0][2];
    int k=1;
    for(int i=0;i<sp->sarr[0][1];i++){
        for(int j=1;j<=sp->sarr[0][2];j++){
            if(i == sp->sarr[j][1]){
                sp->tarr[k][0] = sp->sarr[j][1];
                sp->tarr[k][1] = sp->sarr[j][0];
                sp->tarr[k][2] = sp->sarr[j][2];
                k++;
            }
        }
    }
    for(int i=0;i<=sp->tarr[0][2];i++) {
     printf("%d ", sp->tarr[i][0]);
     printf("%d ", sp->tarr[i][1]);
     printf("%d \n", sp->tarr[i][2]);
  }
 }

}


void add(struct sparse *sp1, struct sparse *sp2, struct sparse *sp3){
 int i=1, j=1, k=1;
 if(sp1->sarr[0][0]!=sp2->sarr[0][0]||sp1->sarr[0][1]!= sp2->sarr[0][1]){
     printf("Matrix 1 and Matrix 2 can't be Added\n");
 }
else{
    while(i<=sp1->sarr[0][2]||j<=sp2->sarr[0][2]){
        if(sp1->sarr[i][0]==sp2->sarr[j][0]){
            if(sp1->sarr[i][1]==sp2->sarr[j][1]){
                sp3->sarr[k][2]=sp1->sarr[i][2]+sp2->sarr[j][2];
                sp3->sarr[k][1] = sp1->sarr[i][1];
                sp3->sarr[k][0] = sp1->sarr[i][0];
                k++, i++, j++;
            }
            else if(sp1->sarr[i][1] < sp2->sarr[j][1]){
                sp3->sarr[k][0] = sp1->sarr[i][0];
                sp3->sarr[k][1] = sp1->sarr[i][1];
                sp3->sarr[k][2] = sp1->sarr[i][2];
                k++, i++;
            }
            else{
                sp3->sarr[k][0] = sp2->sarr[j][0];
                sp3->sarr[k][1] = sp2->sarr[j][1];
                sp3->sarr[k][2] = sp2->sarr[j][2];
                k++, j++;
            }
        }
        else if(sp1->sarr[i][0] < sp2->sarr[j][0])
        {
                sp3->sarr[k][0] = sp1->sarr[i][0];
                sp3->sarr[k][1] = sp1->sarr[i][1];
                sp3->sarr[k][2] = sp1->sarr[i][2];
                k++, i++;
        }
        else{
                sp3->sarr[k][0] = sp2->sarr[j][0];
                sp3->sarr[k][1] = sp2->sarr[j][1];
                sp3->sarr[k][2] = sp2->sarr[j][2];
                k++, j++;
        }
    }

    sp3->sarr[0][0] = sp1->sarr[0][0];
    sp3->sarr[0][1] = sp1->sarr[0][1];
    sp3->sarr[0][2] = k-1;
    for(int i=0;i<=sp3->sarr[0][2];i++) {
     printf("%d ", sp3->sarr[i][0]);
     printf("%d ", sp3->sarr[i][1]);
     printf("%d \n", sp3->sarr[i][2]);
 }
 }
}


void main(){
  struct sparse sp1, sp2,sp3;
  printf("--- INPUT MATRIX 1 ---\n\n");
  read(&sp1);
  printf("\n\n--- INPUT MATRIX 2 ---\n\n");
  read(&sp2);
  printf("\n\n--- TUPLE REPRESENTATION  MATRIX 1 ---\n\n");
  tupleRepresentation(&sp1);
  printf("\n\n--- TUPLE REPRESENTATION  MATRIX 2 ---\n\n");
  tupleRepresentation(&sp2);
  printf("\n\n--- TRANSPOSE SPARSE  MATRIX 1 ---\n\n");
  transpose(&sp1);
  printf("\n\n--- TRANSPOSE SPARSE  MATRIX 2 ---\n\n");
  transpose(&sp2);
  printf("\n\n--- SUM OF MATRIX 1 & MATRIX 2 ---\n\n" );
  add(&sp1, &sp2, &sp3);
}
