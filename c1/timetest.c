/*
 * timetest.c: Computing time used by a recursive facotrial
 *             function, compared with the time needed by an
 *             equivalent iterative function
 */

#include <stdio.h>
#include <time.h>

double recfac(int n)
{
  return n > 1 ? n * recfac(n-1) : 1.0;
}

double itfac(int n)
{
  double result = 1.0;

  while(n > 1) result *= n--;

  return result;
}

int main()
{
  clock_t t0, t1;
  int n, k, i;
  double f;

  printf("Enter the value of n, to compute n!: ");
  scanf("%d", &n);

  printf("How many times do you want %d! to be computed? ", n);
  scanf("%d", &k);

  t0 = clock();
  for(i = 0; i < k; ++i) f = recfac(n);
  t1 = clock();

  printf("Recursion: %d! = %1.0f  time = %-.2f s\n",
    n, f, (t1-t0)/(float)CLOCKS_PER_SEC);

  t0 = clock();
  for(i = 0; i < k; ++i) itfac(n);
  t1 = clock();

  printf("Iteration: %d! = %1.0f  time = %-.2f s\n",
    n, f, (t1-t0)/(float)CLOCKS_PER_SEC);

  return 0;
}
