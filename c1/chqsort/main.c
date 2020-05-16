/* chqsort.c: Use quick sort algorithm to sort the strings contained
 *            in an input file and write them to an output file
 */

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

#define BUF_LEN 100

int main(int argc, char **argv)
{
  char **a, buf[BUF_LEN + 1];
  FILE *fpin, *fpout;
  unsigned n = 0, len, i = 0;

  if (argc != 3)
  {
    puts("Usage: chqsort inputFile outputFile");
    exit(1);
  }

  fpin = fopen(argv[1], "r");
  if (fpin == NULL) printf("Cannot open input file: %s\n", argv[1]);

  /* Count how many lines there are */
  while (fgets(buf, BUF_LEN, fpin)) if (*buf != '\n') ++n;
  rewind(fpin);

  a = (char**)malloc(n * sizeof(char*));
  if (a == NULL) puts("Memory allocation error"), exit(1);

  fpout = fopen(argv[2], "w");
  if (fpout == NULL) printf("Could not open output file: %s\n", argv[2]), exit(1);

  while (fgets(buf, BUF_LEN, fpin))
  {
    if(*buf == '\n') continue;
    len = strlen(buf);
    buf[len-1] = '\0'; /* Overwrite '\n' */
    a[i] = (char *)malloc(len);
    if (a[i] == NULL) puts("Memory allocation error"), exit(1);
    strcpy(a[i++], buf);
  }

  chqsort(a, n);

  for(i = 0; i < n; ++i) fputs(a[i], fpout), putc('\n', fpout);

  return 0;
}
