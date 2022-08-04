#include <stdio.h>
void main(){
  int arr[100], n,i, j, pos,c=0,s=0,temp;

  printf("Enter number of elements\n");
  scanf("%d",&n);
  for (i=0;i< n;i++){
    scanf("%d", &arr[i]);
    }
  for (i=0;i<n-1;i++){
    pos = i;
    for (j=i+1;j<n;j++){
        c++;
      if (arr[pos]> arr[j])
        pos=j;
    }
    if (pos!=i){
      temp = arr[i];
      arr[i] = arr[pos];
      arr[pos] = temp;
      s++;
    }
  }

  printf("Sorted Array:\n");

  for (i=0;i<n; i++){
    printf("%d ",arr[i]);
    }
  printf("\nThe No. of Comparisons :%d\n", c);
  printf("The No. of Swaps :%d\n", s);
  return 0;
}