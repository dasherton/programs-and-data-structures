/*
 * rec1.c: First example of reursion
 */

#include <stdio.h>

void p(int n)
{
  if(n > 0)
  {
    p(n-2);
    printf("%3d", n);
    p(n-1); 
  }
}

int main()
{
  p(4);

  puts("");

  return 0;  
}
