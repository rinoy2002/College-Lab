#include <stdio.h>
void main(){
  int n, arr[100], i, j, x,c=0,s=0, flag = 0;
  printf("Enter number of elements\n");
  scanf("%d", &n);

  for (i = 0; i < n; i++){
      scanf("%d", &arr[i]);
   }


  for (i = 1 ; i < n ; i++){
      x = arr[i];
      for (j = i - 1 ; j >= 0; j--){
          c++;
          if (arr[j] > x) {
              s++;
              arr[j+1] = arr[j];
              flag = 1;
          }
          else
              break;

      }

    if (flag==1)
      arr[j+1] = x;
   }

  printf("Sorted list in ascending order:\n");

  for (i = 0; i < n ; i++) {
    printf("%d ", arr[i]);
  }
  printf("\nThe No. of Comparisons :%d\n", c);
  printf("The No. of Swaps :%d\n", s);
}