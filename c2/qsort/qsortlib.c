#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
#endif

int floatcmp(const void *a, const void *b)
{
  return *(float *)a < *(float *)b ? -1 :
         *(float *)a > *(float *)b ? +1 : 0;
}

int main(int argc, char **argv)
{
  float a[] = {31.5, 11.1, 67.2, 1.1};
  int n = sizeof(a) / sizeof(a[0]), i;

  printf("Before: ");
  for(i = 0; i < n; ++i) printf("%.1f ", a[i]);

  qsort(a, n, sizeof(float), floatcmp);

  puts("");
  printf("After: ");
  for(i = 0; i < n; ++i) printf("%.1f ", a[i]);

  puts("");

  return 0;
}