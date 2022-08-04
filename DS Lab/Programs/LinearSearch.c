#include <stdio.h>

int main()
{
  int arr[100], search, i, n;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  for (i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  printf("Enter a number to be searched \n");
  scanf("%d", &search);

  for (i = 0; i < n; i++)
  {
    if (arr[i] == search)
    {
      printf("%d is present at location %d.\n", search, i+1);
      break;
    }
  }
  if (i == n)
    printf("%d isn't present in the array.\n", search);

  return 0;
}