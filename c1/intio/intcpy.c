#include <stdio.h>
#include <stdlib.h>

#include "intio.h"

int main(int argc, char *argv[])
{
  FILE *fin, *fout;
  int x, status;

  if (argc != 3)
  {
    puts("Usage: INTCPY inputFile outputFile");
    exit(1);
  }

  if ((fin = fopen(argv[1], "r")) == NULL)
  {
    printf("Cannot open input file: %s\n", argv[1]);
    exit(1);
  }

  if ((fout = fopen(argv[2], "w")) == NULL)
  {
    printf("Cannot open output file: %s\n", argv[2]);
    exit(1);
  }

  while ((status = readint(fin, &x)) == OK)
  {
    /*writeint(fout, 0, x); */
    fprintf(fout, " ");
  }

  if (status == OVFLOW) puts("Integer overflow"), exit(2);
  if (status == INVALID) puts("Invalid character read"), exit(2);

  return 0;
}
