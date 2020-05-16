/* qsort.c: Quicksort with a limited recursion depth */

#include <stdlib.h>
#include <stdio.h>

void q_sort(int *a, int n)
{
  int i, j, x, t;

  do
  {
    i = 0, j = n-1;
    x = a[j/2];

    /* The partitioning process */
    do
    {
      while(a[i] < x) ++i;
      while(a[j] > x) --j;
      if (i < j) { t = a[i]; a[i] = a[j]; a[j] = t; }
    } while (++i <= --j);

    /* Reverse unexpected increment/decrement in certain scenarios */
    if (i == j + 3) { --i; ++j; }

    /* Apply recursion to smallest subset only. Modify vars a and n to apply iteration to largest subset */
    if (j+1 < n-i)
    {
      if (j>0) q_sort(a, j+1);
      a += i;
      n -= i;
    }
    else
    {
      if (i < n-1) q_sort(a+i, n-i);
      n = j + 1;
    }
  } while (n > 1); /* Repeat iterative solution on larger subset */
}

int main()
{
  int a[] = {6, 9, 1, 5, 2, 9}, i;
  int n = sizeof(a) / sizeof(a[0]);

  printf("Before: ");
  for(i = 0; i < n; ++i) printf("%d ", a[i]);
  puts("");

  q_sort(a, n);

  printf("After: ");
  for(i = 0; i < n; ++i) printf("%d ", a[i]);
  puts("");

  return 0;
}
