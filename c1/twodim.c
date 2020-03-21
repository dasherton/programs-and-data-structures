/* twodim.c: A pointer to a pointer, used as a 2D array */

#include <stdio.h>
#include <stdlib.h>

void *getmemory(int n)
{
  void *p = malloc(n);
  if(p ==NULL) puts("Memory allocation failure"), exit(1);
  return p;
}

int main()
{
  int i, j, r, c;
  double **matrix;

  printf("How many columns? ");
  scanf("%d", &c);

  printf("How many rows? ");
  scanf("%d", &r);

  matrix = (double**)getmemory(r * sizeof(double*));

  for(i = 0; i < r; ++i)
    matrix[i] = (double*)getmemory(c * sizeof(double));

  for(i = 0; i < r; ++i)
    for(j = 0; j < c; ++j)
      matrix[i][j] = i + 0.01 * j;

  puts("Matrix contents:");

  for(i = 0; i < r; ++i)
  {
    for(j = 0; j < c; ++j)
      printf("%5.2f", matrix[i][j]);

    puts(" ");
  }

  return 0;
}
