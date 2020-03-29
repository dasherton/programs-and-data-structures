/* euclid.c: Euclid's greatest common divisor algorithm */

#include <stdio.h>

/* Iterative implementation (includes provision for -ve args) */
int gcdit(int x, int y)
{
  int tmp;

  if(x < 0) x = -x;
  if(y < 0) y = -y;

  while(y)
  {
    tmp = x % y;
    x = y;
    y = tmp;
  }

  return x; 
}

/* Recursive implementation */
int gcdrec(int x, int y)
{
  return y ? gcdrec(y, x % y) : x;
}

int main()
{
  int x, y;

  printf("Enter 1st integer: ");
  scanf("%d", &x);

  printf("Enter 2nd integer: ");
  scanf("%d", &y);

  printf("gcd(%d, %d) = %d\n", x, y, gcdit(x, y));

  return 0;
}
