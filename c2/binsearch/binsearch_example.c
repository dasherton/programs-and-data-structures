/* binsearch_example.c: Demonstrate the use of binsearch */

#include <stdio.h>

#include "binsearch.h"

int main()
{
  /* Numbers in array must be in increasing order */
  int a[] = {1, 3, 6, 8, 11}, i, n = sizeof(a)/sizeof(a[0]), x=6;

  printf("Array: ");
  for(i = 0; i < n; ++i) printf("%d ", a[i]);
  puts("");

  i = binsearch(x, a, n);

  if (i < n && x == a[i])
    printf("Found %d at index: %d\n", x, i);
  else
    printf("%d not in sequence, should be placed at index: %d\n", x, i);

  return 0;
}
