/* binsearch.c: Function for binary search */

#include <stdio.h>

/*
 * a[0] ... a[n-1] is searched for x
 * Returned value: 0 if x <= a[0], or
 *                 n if x > a[n-1], or
 *                 i if a[i-1] < x <= a[i]
 */
int binsearch(int x, int *a, int n)
{
  int middle, left=0, right=n-1;
  if (x <= a[left]) return 0;
  if (x > a[right]) return n;

  while (right-left > 1)
  {
    middle = (left + right) / 2;

    if (x <= a[middle]) right = middle;
                    else left = middle;
  }
  return right;
}

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
