/*
 * horners.c: Demonstrating Horners rule for efficiently
 *            computing polynominals
 */

#include <stdio.h>

/* Iterative implementation */
double hit(double x, double *a, int n)
{
  double s = a[n];
  while(--n >= 0) s = s * x + a[n];
  return s;
}

/* Recursive implementation */
double hrec(double x, double *a, int n)
{
  return n ? x * hrec(x, a+1, n-1) + *a : *a;
}

int main()
{
  double x = 10.0;
  double arr[] = {1.0, 5.0, 2.0};
  int n = sizeof(arr)/sizeof(arr[0]) - 1;

  printf("Iterative: %.3f\n", hit(x, arr, n));
  printf("Recursive: %.3f\n", hrec(x, arr, n));

  return 0;
}

