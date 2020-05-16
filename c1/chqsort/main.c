#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void chqsort(char **a, int n)
{
  int i, j;
  char *x, *w;

  do
  {
    i = 0; j = n-1;
    x = a[j/2];
    do
    {
      while(strcmp(a[i], x) < 0) ++i;
      while(strcmp(a[j], x) > 0) --j;
      if (i < j) { w = a[i]; a[i] = a[j]; a[j] = w; }
    } while (++i <= --j);
    if (i == j+3) {--i;  ++j; }

    if (j+1 < n-i)
    {
      if (j > 0) chqsort(a, j+1);
      a += i;
      n -= i;
    }
    else
    {
      if (i < n-1) chqsort(a+i, n-i);
      n = j + 1;
    }
  } while(n > 1);
}

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    puts("Usage: chqsort inputFile outputFile");
    exit(1);
  }

  return 0;
}
