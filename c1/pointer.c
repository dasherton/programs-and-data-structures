#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i, *a;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  a = (int*)malloc(n * sizeof(int));
  if(a == NULL) printf("Memory allocation problem"), exit(1);

  printf("Enter %d numbers: ", n);
  for(i = 0; i < n; ++i) scanf("%d", a+i);

  printf("Your numbers in reverse order are:\n");
  for(i = n-1; i >= 0; --i) printf("  %d\n", a[i]);

  return 0;
}

