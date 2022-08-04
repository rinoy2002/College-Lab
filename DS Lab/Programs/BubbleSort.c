#include <stdio.h>
void main(){
  int arr[100], i,j, n,temp,s=0,c=0;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  for (i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  for (i=0 ; i<n-1;i++){
     for (j=0 ; j<n-i-1;j++){
         c++;
        if (arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            s++;
         }
       }
    }

  printf("Sorted Array:\n");
  for (i=0;i< n;i++){
      printf("%d  ", arr[i]);
  }
  printf("\nThe No. of Comparisons :%d\n", c);
  printf("The No. of Swaps :%d\n", s);
}