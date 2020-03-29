/*
 * euclidtime.c: A timed test against the iterative and recursive
 *               implementations of Euclid's GCD algorithm
*/

#include <stdio.h>
#include <time.h>

int gcdrec(int x, int y)
{
  return y ? gcdrec(y, x % y) : x;
}

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

int main()
{
  int res, x, y, k, i;
  clock_t t0, t1;

  printf("Enter 1st integer: ");
  scanf("%d", &x);

  printf("Enter 2nd integer: ");
  scanf("%d", &y);

  printf("How many times do you want to compute gcd(%d, %d)? ", x, y);
  scanf("%d", &k);

  t0 = clock();
  for(i = 0; i < k; ++i) res = gcdit(x, y);
  t1 = clock();

  printf("Iteration: gcd((%d, %d) = %d  time = %-.2f s\n",
    x, y, res, (t1-t0)/(float)CLOCKS_PER_SEC);

  t0 = clock();
  for(i = 0; i < k; ++i) res = gcdrec(x, y);
  t1 = clock();

  printf("Recursion: gcd(%d, %d) = %d  time = %-.2f s\n",
    x, y, res, (t1-t0)/(float)CLOCKS_PER_SEC);

  return 0;
}
