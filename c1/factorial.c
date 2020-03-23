/*
 * factorial.c: Iteration vs recursion
 *
 * n! = 1        if n = 0 or n = 1
 * n! = n(n-1)!  if n > 1
 */

#include <stdio.h>

double factorial_rec(double n)
{
  return n > 1 ? n * factorial_rec(n-1) : 1.0;
}

double factorial_it(double n)
{
  double result = 1.0;

  while(n > 1) result *= n--;

  return result;
}

int main()
{
  int n;

  printf("Enter an integer: ");
  scanf("%d", &n);

  printf("%d! = %f\n", n, factorial_it(n));
  printf("%d! = %f\n", n, factorial_rec(n));

  return 0;
}

