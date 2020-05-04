#include <stdio.h>
#include <stdlib.h>

#include "intio.h"

int main()
{
  int i;

  if (readint(stdin, &i) != OK)
  {
    puts("Read failure");
    exit(-1);
  }

  if (writeint(stdout, 4, i) != OK)
  {
    puts("Write failure");
    exit(-1);
  }

  puts("");
  return 0;
}

