/* binsearch.c: Function for binary search */

#include <stdio.h>

#include "binsearch.h"

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
