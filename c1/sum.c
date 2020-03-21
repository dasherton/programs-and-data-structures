/* sum.c: Compute the sum of a sequence of intergers, provided through stdin */

#include <stdio.h>

int main()
{
  int i, s = 0;

  printf("Enter space separated integers, followed by any"
    "nonnumerical character: ");

  while (scanf("%d", &i) == 1) s += i;

  printf("The sum is: %d\n", s);

  return 0;
}

